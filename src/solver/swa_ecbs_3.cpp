/*
 * ecbs.cpp
 *
 * Purpose: Enhanced Conflict-based Search with weight change only at the root of high level node
 *
 * Sharon, G., Stern, R., Felner, A., & Sturtevant, N. R. (2015).
 * Conflict-based search for optimal multi-agent pathfinding.
 *
 * Created by: Keisuke Okumura <okumura.k@coord.c.titech.ac.jp>
 */

#include "swa_ecbs_3.h"
#include "../util/util.h"
#include<bits/stdc++.h>
using namespace std;

uint64_t SWA_ECBS_3::timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

SWA_ECBS_3::SWA_ECBS_3(Problem* _P, float _w) : CBS(_P, false), w(_w) {
  init();
}
SWA_ECBS_3::SWA_ECBS_3(Problem* _P, float _w, bool _ID) : CBS(_P, _ID), w(_w) {
  init();
}

SWA_ECBS_3::~SWA_ECBS_3() {}

void SWA_ECBS_3::init() {
  for (auto a : A) table_fmin.emplace(a->getId(), 0);
  //std::cout<<"weight "<< w<<std::endl;
  cnt = 0;
  conflict_cnt = 0;
  thrashing_nodes = 0;
}

// bool compare(Agent* a, Agent* b){
//   return (*a).conf < (*b).conf;
// }

bool SWA_ECBS_3::solvePart(Paths& paths, Agents& block) {
  //int highLevelNode = 0;

  string write = "";
  ofstream outfile;
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

  /**** SWA mean breakpoint started****/

  int maxi = INT_MIN;
  int avg = 0;
  uint64_t current_time3 = timeSinceEpochMillisec();

  for(auto a:block){
    auto itr = std::find_if(A.begin(), A.end(),
                              [a](Agent* b) { return a == b; });
    int d = std::distance(A.begin(), itr);
    (*a).conf = h3(a,root->paths[d],root->paths);
    avg += (*a).conf;
    maxi = max(maxi,(*a).conf);
    //cout << "block size " << block.size() <<endl; 
  }

  avg /= block.size();

  // // sort(block.begin(),block.end(),compare);
  // cout << "block size " << block.size() <<endl; 
  // cout << "average conf " << maxi <<endl; 

  double offset1 = (w-1)/(2*avg);
  double offset2 = (w-1)/(2*maxi);

  cout << "offset1 " << offset1 <<endl; 
  cout << "offset2 " << offset2 <<endl; 
  double add = 0;
  
  for(auto a:block){
    //cout<< "conflict " <<(*a).getId()<< " is " << (*a).conf <<endl;
    //(*a).m_w = ((1 + w)/2) + ((*a).conf * offset);
    // add += (*a).m_w;
    if((*a).conf <= avg){
      (*a).m_w = 1 + ((*a).conf * offset1);
    }
    else{
      (*a).m_w = ((1 + w)/2) + ((*a).conf * offset2);
    }
    
    cout << (*a).m_w << endl;
  }

  /**** SWA mean breakpoint ended****/

  uint64_t current_time4 = timeSinceEpochMillisec();

  // double mean_w = add/block.size();

  // //cout <<"Time " << (current_time4 - current_time3)<< endl;

  // cout<<mean_w << " mean weight " << endl;

  // if(mean_w > w){
  //   cout<<mean_w<< " ********Over computed****"<< endl;

  //   double residual = (mean_w - w)/block.size();

  //   for(auto a:block){
  //   //cout<< "conflict " <<(*a).getId()<< " is " << (*a).conf <<endl;
  //   if((*a).m_w - residual >= 1){
  //     (*a).m_w -= residual;
  //     cout << (*a).m_w << endl;
  //   }
    
  // }

  // }

  bool CAT = std::any_of(paths.begin(), paths.end(),
                         [](Nodes p) { return !p.empty(); });

  auto itrO = OPEN.begin();

  while (!OPEN.empty()) {
  //maxi = INT_MIN;
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
    int lb = node->LB;
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

    write += "Paths start\n";
    for (int i = 0; i < paths.size(); ++i) {
      write += to_string(block[i]->getId()) + " " + to_string(block[i]->m_w);
      if (!node->paths[i].empty()) {
        for(auto p : node->paths[i]){
          write += "-> (" +  to_string(p->getPos().y) + " " + to_string(p->getPos().x) + ")";
        }
      }
      write += "\n";
    }
    write += "Paths end\n" ;


    conflict_cnt ++;
    constraints = valid(node, block);
    if (constraints.empty()) break;

    updateMin = (key == keyF);
    auto itrP = std::find(OPEN.begin(), OPEN.end(), keyF);
    OPEN.erase(itrP);

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
        cout << newNode->cost << " " << ub << " " << lb << endl;
        if(newNode->cost > ub){
          //FOCUL.push_back(uuid);
          thrashing_nodes ++;
        }
        ++uuid;
      }
    }
    constraints.clear();
  }

  outfile.open("/home/mustafizur/pibt/swa_path.txt");

  outfile << write << endl;

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

  for(auto a:block){
    cout << (*a).getId() << " " <<(*a).m_w << " " <<(*a).conf<< endl;
  }

  return status;

}

void SWA_ECBS_3::invoke(CTNode* node, Agents& block) {
  int d;
  cout << "invoke" << endl;
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
    cout << "before loop" <<endl;
    // print_paths(node->paths);
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
  cout << "after_loop" << endl;
  // print_paths(node->paths);
}

int SWA_ECBS_3::h3(Agent* a, Nodes &p1, Paths &paths) {
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

int SWA_ECBS_3::h3(Paths &paths) {

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
      /* shouldn't it be distance to go */
      if (node->f != other.node->f) {
        return node->f > other.node->f;
      } else {
        return node->g < other.node->g;
      }
    }
  }
};

void SWA_ECBS_3::print_paths(Paths &paths){
  for(int i=0; i<paths.size();i++){
    Nodes p2 = paths[i];
    cout << "******paths_start******agent "<< i  <<endl;
    for(int j=0; j<p2.size(); j++){
      cout << p2[j]->getId() << " ";
    }
    cout << endl;
  }
  cout << endl;
}

Nodes SWA_ECBS_3::AstarSearch(Agent* a, CTNode* node) {
  Constraint constraints = getConstraintsForAgent(node, a);

  Node* _s = a->getNode();
  Node* _g = a->getGoal();

  Nodes path, tmpPath, C;  // return

  //double bw = w;

  double bw = (*a).m_w;
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
      // cnt++;
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
        //vec[a->getId()].push_back({int(m->getPos().y),int(m->getPos().x)});
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

void SWA_ECBS_3::getPartialPath(AN* n, Nodes &path) {
  path.clear();
  AN* m = n;
  while (m != nullptr) {
    path.push_back(m->v);
    m = m->p;
  }
  std::reverse(path.begin(), path.end());
}

std::string SWA_ECBS_3::logStr() {
  std::string str;
  str += "[solver] type:ECBS\n";
  str += "[solver] w:" + std::to_string(w) + "\n";
  str += "[solver] ID:" + std::to_string(ID) + "\n";
  str += "[solver] Lowlevelnode:" + std::to_string(lowlevelnode) + "\n";
  str += "[solver] Highlevelnode:" + std::to_string(highLevelNode) + "\n";
  str += "[solver] ConflictCount:" + std::to_string(conflict_cnt) + "\n";
  str += "[solver] ThrashingNodes:" + std::to_string(thrashing_nodes) + "\n";

  str += Solver::logStr();
  return str;
}
