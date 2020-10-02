/*
 * DWA_ECBS.cpp
 *
 * Purpose: Enhanced Conflict-based Search with weight change(runtime) at each high level node
 *
 * Sharon, G., Stern, R., Felner, A., & Sturtevant, N. R. (2015).
 * Conflict-based search for optimal multi-agent pathfinding.
 *
 * Created by: Keisuke Okumura <okumura.k@coord.c.titech.ac.jp>
 */

#include "dwa_ecbs.h"
#include "../util/util.h"
#include<bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

uint64_t DWA_ECBS::timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
DWA_ECBS::DWA_ECBS(Problem* _P, float _w) : CBS(_P, false), w(_w) {
  init();
}
DWA_ECBS::DWA_ECBS(Problem* _P, float _w, bool _ID) : CBS(_P, _ID), w(_w) {
  init();
}

DWA_ECBS::~DWA_ECBS() {}

void DWA_ECBS::init() {
  for (auto a : A) table_fmin.emplace(a->getId(), 0);
  cnt = 0;
  conflict_cnt = 0;
  //std::cout<<"weight "<< w<<std::endl;
}

// bool compare(Agent* a, Agent* b){
//   return (*a).conf < (*b).conf;
// }

bool DWA_ECBS::solvePart(Paths& paths, Agents& block) {
  //int highLevelNode = 0;
  CTNode* node;
  Constraints constraints;

  int uuid = 0;
  int key, keyF;
  std::unordered_set<int> OPEN;
  std::vector<int> FOCUL;  // for FOCUL search
  float ub;

  bool status = true;
  bool updateMin = true;

  std::vector<CTNode*> table;
  std::vector<int> table_conflict;
  std::map<std::string,double> conflict_weight_table;

  uint64_t total_time = 0;

  uint64_t current_time1 = timeSinceEpochMillisec();


  for(auto a:block){
    //cout<< "conflict " << (*a).conf <<endl;
    (*a).m_w = w;
  }

 // uint64_t current_time2 = timeSinceEpochMillisec();

  CTNode* root = new CTNode { {}, {}, 0, nullptr, true, {}, 0 };
  highLevelNode ++;
  invoke(root, block);
  OPEN.insert(uuid);
  table.push_back(root);
  table_conflict.push_back(h3(root->paths));
  ++uuid;

  int maxi ;
 // uint64_t current_time3 = timeSinceEpochMillisec();

  // for(auto a:block){
  //   auto itr = std::find_if(A.begin(), A.end(),
  //                             [a](Agent* b) { return a == b; });
  //     int d = std::distance(A.begin(), itr);
  //   (*a).conf = h3(a,root->paths[d],root->paths);
  //   maxi = max(maxi,(*a).conf);
  //   //cout << "block size " << block.size() <<endl; 
  // }

  // // sort(block.begin(),block.end(),compare);

  // // cout << "offset " << w <<endl; 

  double offset ;

  // //cout << "offset " << offset <<endl; 
  // // double add = offset;
  // for(auto a:block){
  //   //cout<< "conflict " <<(*a).getId()<< " is " << (*a).conf <<endl;
  //   (*a).m_w = 1 + ((*a).conf * offset);
  //   //add += offset;
  // }

  // uint64_t current_time4 = timeSinceEpochMillisec();

  //cout <<"Time " << (current_time2 - current_time1) + (current_time4 - current_time3)<< endl;

  bool CAT = std::any_of(paths.begin(), paths.end(),
                         [](Nodes p) { return !p.empty(); });

  auto itrO = OPEN.begin();

  while (!OPEN.empty()) {
  maxi = INT_MIN;
  uint64_t current_time2 = timeSinceEpochMillisec();
  if(current_time2-current_time1 >= 180000) 
    return false;

    if (updateMin) {
      itrO = std::min_element(OPEN.begin(), OPEN.end(),
                              [CAT, this, &paths, &table]
                              (int a, int b) {
                                CTNode* nA = table[a];
                                CTNode* nB = table[b];
                                if (CAT && nA->cost == nB->cost) {
                                  return this->countCollisions(nA, paths)
                                    < this->countCollisions(nB, paths);
                                }
                                return nA->cost < nB->cost;
                              });
    }

    key = *itrO;
    node = table[key];

    ub = node->LB * w;
    // update focul
    FOCUL.clear();
    for (auto keyO : OPEN) {
      if ((float)table[keyO]->cost <= ub) FOCUL.push_back(keyO);
    }
    auto itrF = std::min_element(FOCUL.begin(), FOCUL.end(),
                                 [&table, &table_conflict]
                                 (int a, int b) {
                                   int sA = table_conflict[a];
                                   int sB = table_conflict[b];
                                   if (sA == sB) {
                                     return table[a]->cost < table[b]->cost;
                                   }
                                   return sA < sB; });

    keyF = *itrF;
    node = table[keyF];

    //cout << "table size " << table.size() << endl;

    conflict_cnt ++;
    constraints = valid(node, block);

    if (constraints.empty()) break;


    auto constraint = constraints[0];
    string conflict_key = constraint[0]->key; 

   // cout << "conflict_key " << conflict_key << endl;

    std::vector<std::string> fields;
    boost::split(fields, conflict_key, boost::is_any_of("_"));

    Agent *first, *second;

    double max_weight = double(INT_MIN);  


    updateMin = (key == keyF);
    auto itrP = std::find(OPEN.begin(), OPEN.end(), keyF);
    OPEN.erase(itrP);

    //uint64_t current_time1 = timeSinceEpochMillisec();

    for(auto a:block){
    auto itr = std::find_if(A.begin(), A.end(),
                              [a](Agent* b) { return a == b; });
    int d = std::distance(A.begin(), itr);
    (*a).conf = h3(a,node->paths[d],node->paths);
    
    //cout<<"Number of conflict for agent " << (*a).getId() << " is " << (*a).conf <<endl;
    maxi = max(maxi,(*a).conf);
    //cout << "block size " << block.size() <<endl; 
  }

    if(maxi!=0){
    offset = (w-1)/maxi;

    //cout <<"*****ConflictEnd*****"<<endl;
    for(auto a:block){
    //cout<< "conflict " <<(*a).getId()<< " is " << (*a).conf <<endl;
    (*a).m_w = 1 + ((*a).conf * offset);
    if((*a).getId() == atoi(fields[0].c_str())){
      //cout << (*a).getId() << " " << atoi(fields[0].c_str()) << endl;
      max_weight = fmax(max_weight,(*a).m_w);
      first = a;
    }
    else if((*a).getId() == atoi(fields[1].c_str())){
      //cout << (*a).getId() << " " << atoi(fields[1].c_str()) << endl;
      max_weight = fmax(max_weight,(*a).m_w);
      second = a;
    }

    //add += offset;
  }

    //latest modification_starts_here
    if(conflict_weight_table.find(conflict_key)!= conflict_weight_table.end() && conflict_weight_table[conflict_key] >= max_weight){
      double previous_weight = conflict_weight_table[conflict_key];
      if(previous_weight + offset >= w){
      (*first).m_w = w;
      (*second).m_w = w; 
      }
      else{
        (*first).m_w = previous_weight + offset ;
        (*second).m_w = previous_weight + offset ;
      }
      cout << 1 << endl;
    }
    else
    {
      conflict_weight_table[conflict_key] = max_weight;
      //cout << "conflict_weight " << conflict_weight_table[conflict_key] << endl;
    }
    //latest modification_ends_here

    }

    //uint64_t current_time2 = timeSinceEpochMillisec();

    //total_time += (current_time2 - current_time1);

    for (auto constraint : constraints) {
      CTNode* newNode = new CTNode { constraint, node->paths,
                                     0, node, true, {}, 0 };
      highLevelNode ++;
      //std::cout<<" In Loop"<<std::endl;
      // formating
      Node* g;
      Nodes p;
      for (int i = 0; i < node->paths.size(); ++i) {
        p = newNode->paths[i];
        if (p.empty()) continue;
        g = *(p.end() - 1);
        while (*(p.end() - 1) == g) p.erase(p.end() - 1);
        p.push_back(g);
        node->paths[i] = p;
      }
      newNode->fmins = node->fmins;
      invoke(newNode, block);
      if (newNode->valid) {
        OPEN.insert(uuid);
        table.push_back(newNode);
        table_conflict.push_back(h3(newNode->paths));
        ++uuid;
      }
    }
    constraints.clear();
  }

  if (!OPEN.empty()) {  // sucssess
    for (int i = 0; i < paths.size(); ++i) {
      if (!node->paths[i].empty()) {
        paths[i] = node->paths[i];
      }
    }
    status = status && true;
  } else {
    status = false;
  }

  lowlevelnode = cnt;

  //cout << "total_time " << total_time <<endl;

  for(auto a:block){
    cout << (*a).getId() << " " <<mp[(*a).getId()] << endl;
  }

  return status;

}

void DWA_ECBS::invoke(CTNode* node, Agents& block) {
  int d;
  // calc path
  if (node->c.empty()) {  // initail
    Paths paths;
    for (int i = 0; i < A.size(); ++i) {
      paths.push_back({});
      node->fmins.push_back(0);
    }
    for (auto a : block) {
      auto itr = std::find_if(A.begin(), A.end(),
                              [a](Agent* b) { return a == b; });
      int d = std::distance(A.begin(), itr);
      paths[d] = AstarSearch(a, node);
      node->fmins[d] = table_fmin.at(a->getId());
    }
    node->paths = paths;
    node->LB = 0;
  } else {
    Agent* a;
    // error check
    if (node->paths.size() != A.size()) {
      std::cout << "error@ECBS@invoke, "
                << "path size is not equal to the size of agents" << "\n";
      std::exit(1);
    }

    for (auto c : node->c) {
      a = c->a;
      auto itr = std::find_if(A.begin(), A.end(),
                              [a](Agent* b) { return a == b; });
      if (itr == A.end()) {
        std::cout << "error@ECBS@invoke, cannot find1 agent" << "\n";
        std::exit(1);
      }
      d = std::distance(A.begin(), itr);
      node->paths[d].clear();
    }

    for (auto c : node->c) {
      a = c->a;
      auto itr = std::find_if(A.begin(), A.end(),
                              [a](Agent* b) { return a == b; });
      if (itr == A.end()) {
        std::cout << "error@ECBS@invoke, cannot find2 agent" << "\n";
        std::exit(1);
      }
      d = std::distance(A.begin(), itr);
      node->paths[d] = AstarSearch(a, node);
      node->fmins[d] = table_fmin.at(a->getId());
    }
  }
  for (auto i : node->fmins) node->LB += i;

  if (!node->valid) return;
  calcCost(node, block);
  formalizePathAgents(node, block);
}

int DWA_ECBS::h3(Agent* a, Nodes &p1, Paths &paths) {
  if (p1.empty()) return 0;

  int collision = 0;
  Nodes p2;

  for (int i = 0; i < paths.size(); ++i) {
    if (a->getId() == i) continue;
    p2 = paths[i];
    if (p2.empty()) continue;
    for (int t = 0; t < p1.size(); ++t) {
      if (t >= p2.size()) {
        if (p1[t] == p2[p2.size() - 1]) {
          ++collision;
          break;
        }
        continue;
      }
      if (p1[t] == p2[t]) {  // collision
        ++collision;
        break;
      }
      if (t > 0 && p1[t-1] == p2[t] && p1[t] == p2[t-1]) {
        ++collision;
        break;
      }
    }
  }

  // error check
  if (collision > A.size() * (A.size() - 1) / 2) {
    std::cout << "error@ECBS::h3, invalid value, " << collision << "\n";
    std::exit(1);
  }

  return collision;
}

int DWA_ECBS::h3(Paths &paths) {

  int collision = 0;
  Nodes p1, p2;

  for (int i = 0; i < paths.size(); ++i) {
    for (int j = i + 1; j < paths.size(); ++j) {
      if (paths[i].size() >= paths[j].size()) {
        p1 = paths[i];
        p2 = paths[j];
      } else {
        p1 = paths[j];
        p2 = paths[i];
      }

      if (p2.empty()) continue;

      for (int t = 0; t < p1.size(); ++t) {
        if (t >= p2.size()) {
          // goal pos
          if (p1[t] == p2[p2.size() - 1]) {
            ++collision;
            break;
          }
          continue;
        }
        if (p1[t] == p2[t]) {  // collision
          ++collision;
          break;
        }
        // intersection
        if (t > 0 && p1[t-1] == p2[t] && p1[t] == p2[t-1]) {
          ++collision;
          break;
        }
      }
    }
  }

  // error check
  if (collision > A.size() * (A.size() - 1) / 2) {
    std::cout << "error@ECBS::h3, invalid value, " << collision << "\n";
    std::exit(1);
  }

  return collision;
}

struct Fib_FN { // Forcul Node for Fibonacci heap
  Fib_FN(AN* _node, int _h): node(_node), h(_h) {}
  AN* node;
  int h;

  bool operator<(const Fib_FN& other) const {
    if (h != other.h) {
      return h > other.h;
    } else {
      if (node->f != other.node->f) {
        return node->f > other.node->f;
      } else {
        return node->g < other.node->g;
      }
    }
  }
};

Nodes DWA_ECBS::AstarSearch(Agent* a, CTNode* node) {
  Constraint constraints = getConstraintsForAgent(node, a);

  Node* _s = a->getNode();
  Node* _g = a->getGoal();

  Nodes path, tmpPath, C;  // return

  //double bw = w;

  double bw = (*a).m_w;
  mp[(*a).getId()] = (*a).m_w;
  //std::cout<<"weight for agent "<<(*a).getId()<< " is "<<bw<<std::endl;

  // ==== fast implementation ====
  // constraint free
  if (constraints.empty()) {
    path = G->getPath(_s, _g);
    table_fmin.at(a->getId()) = path.size() - 1;
    return path;
  }
  
  //std::cout<<"cnt"<<std::endl;

  // goal condition
  bool existGoalConstraint = false;
  int timeGoalConstraint = 0;
  for (auto c: constraints) {
    if (c->onNode && c->v == _g && c->t > timeGoalConstraint) {
      existGoalConstraint = true;
      timeGoalConstraint = c->t;
    }
  }
  // =============================

  auto paths = node->paths;

  int f, g;
  float ub;
  int ubori;
  std::string key, keyM, keyF;
  bool invalid = true;

  boost::heap::fibonacci_heap<Fib_AN> OPEN;
  std::unordered_map<std::string, boost::heap::fibonacci_heap<Fib_AN>::handle_type> SEARCHED;
  std::unordered_set<std::string> CLOSE;  // key
  AN* n = new AN { _s, 0, pathDist(_s, _g), nullptr };
  //AN* nfocal = new AN { _s, 0, pathDist(_s, _g), nullptr };
  auto handle = OPEN.push(Fib_AN(n));
  key = getKey(n);
  SEARCHED.emplace(key, handle);

  bool updateMin = true;
  std::unordered_map<std::string, int> table_conflict;
  table_conflict.emplace(key, 0);
  // FOCUL
  boost::heap::fibonacci_heap<Fib_FN> FOCUL;
  std::unordered_map<std::string,
                     boost::heap::fibonacci_heap<Fib_FN>::handle_type> SEARCHED_F;
  auto handle2 = FOCUL.push(Fib_FN(n,table_conflict.at(key)));


  while (!OPEN.empty()) {
    if (updateMin || FOCUL.empty()) {
      // argmin
      while (!OPEN.empty()
             && CLOSE.find(getKey(OPEN.top().node)) != CLOSE.end()) OPEN.pop();
      if (OPEN.empty()) break;
      n = OPEN.top().node;
      ubori = n->f;
      keyM = getKey(n);
      ub = n->f * bw;
      // update focul
      FOCUL.clear();
      SEARCHED_F.clear();
      for (auto itr = OPEN.ordered_begin(); itr != OPEN.ordered_end(); ++itr) {
        AN* l = (*itr).node;
        if ((float)l->f <= ub) {
          if (CLOSE.find(getKey(l)) == CLOSE.end()) {
            key = getKey(l);
            auto handle_f = FOCUL.push(Fib_FN(l, table_conflict.at(key)));
            SEARCHED_F.emplace(key, handle_f);
          }
        } else {
          break;
        }
      }
    }

    // argmin in FOCUL
    n = FOCUL.top().node;
    key = getKey(n);
    FOCUL.pop();
    

    // already explored
    if (CLOSE.find(key) != CLOSE.end()) {
      printf("Yes\n");
      continue;
    }

    // check goal
    if (n->v == _g) {
      if (!existGoalConstraint || timeGoalConstraint < n->g) {
        invalid = false;
        break;
      }
    }

    // update list
    updateMin = (key == keyM);
    CLOSE.emplace(key);

    // search neighbor
    C = G->neighbor(n->v);
    C.push_back(n->v);
    // int cnt1 = 0,cnt2 =0,cnt3 =0;

    for (auto m : C) {
      //cnt1++;
      g = n->g + 1;
      key = getKey(g, m);
      if (CLOSE.find(key) != CLOSE.end()) continue;
      //cnt3 ++;
      // check constraints
      auto constraint = std::find_if(constraints.begin(), constraints.end(),
                                     [a, g, m, n] (Conflict* c) {
                                       if (c->a != a) return false;
                                       if (c->t != g) return false;
                                       if (c->onNode) return c->v == m;
                                       return c->v == m && c->u == n->v;
                                     });
      if (constraint != constraints.end()) {
	//cnt1 ++;
	continue;
	}
      f = g + pathDist(m, _g);

      // ==== fast implementation ====
      // when field is huge, this works well
      // if (existGoalConstraint) {
      //   f = pathDist(m, _g) + timeGoalConstraint;
      // }
      // =============================

      auto itrS = SEARCHED.find(key);
      AN* l;
      bool updateH = false;
      if (itrS == SEARCHED.end()) {  // new node
        cnt++;
        l = new AN { m, g, f, n };
        auto handle = OPEN.push(Fib_AN(l));
        SEARCHED.emplace(key, handle);
        getPartialPath(l, tmpPath);
        table_conflict.emplace(key, h3(a, tmpPath, paths));
	//cnt2++;
      } else {
        auto handle = itrS->second;
        l = (*handle).node;
        if (l->f > f) {
          l->g = g;
          l->f = f;
          l->p = n;
          getPartialPath(l, tmpPath);
          table_conflict.at(key) = h3(a, tmpPath, paths);
          OPEN.increase(handle);
          updateH = true;
        }
	//cnt3 ++;
      }

      tmpPath.clear();
      if (f <= ub) {
        auto itrSF = SEARCHED_F.find(key);
        if (itrSF == SEARCHED_F.end()) {
          auto handle_f = FOCUL.push(Fib_FN(l, table_conflict.at(key)));
          SEARCHED_F.emplace(key, handle_f);
        } else {
          if (updateH) {
            auto handle_f = itrSF->second;
            (*handle_f).h = table_conflict.at(key);
            FOCUL.increase(handle_f);
          }
        }
      }
    }
    //std::cout<<" cnt "<<cnt1<<" "<<cnt2<<" "<<cnt3<<std::endl;
  }

  int soln = INT_MAX;

  // while(!OPEN.empty()){
  //   nopen = OPEN.top().node;
  //   if(n->f<= soln){
  //       nfocal = FOCUL.top().node;
  //       OPEN.erase(nfocal);
  //   }
  // }

  // back tracking
  int fmin = 0;
  if (!invalid) {  // check failed or not
    getPartialPath(n, path);
    fmin = ubori;
  } else {
    node->valid = false;
  }
  table_fmin.at(a->getId()) = fmin;

  //cout<<"Number of conflict for agent " << (*a).getId() << " is " << h3(a,path,paths) <<endl;

  return path;
}

void DWA_ECBS::getPartialPath(AN* n, Nodes &path) {
  path.clear();
  AN* m = n;
  while (m != nullptr) {
    path.push_back(m->v);
    m = m->p;
  }
  std::reverse(path.begin(), path.end());
}

std::string DWA_ECBS::logStr() {
  std::string str;
  str += "[solver] type:ECBS\n";
  str += "[solver] w:" + std::to_string(w) + "\n";
  str += "[solver] ID:" + std::to_string(ID) + "\n";
  str += "[solver] Lowlevelnode:" + std::to_string(lowlevelnode) + "\n";
  str += "[solver] ConflictCount:" + std::to_string(conflict_cnt) + "\n";

  str += Solver::logStr();
  return str;
}
