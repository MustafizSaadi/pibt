/*
 * ecbs.h
 *
 * Purpose: Enhanced Conflict-based Search with weight change(runtime) at each high level node
 * Created by: Keisuke Okumura <okumura.k@coord.c.titech.ac.jp>
 */

#pragma once
#include "cbs.h"
#include <map>


class DWA_ECBS_2 : public CBS {
protected:
  float w;  // sub-optimal factor
  std::unordered_map<int, int> table_fmin;  // record min of f-value

  virtual void init();
  int h3(Paths &paths);
  int h3(Agent* a, Nodes& p1, Paths &paths);
  bool solvePart(Paths& paths, Agents& block);
  void invoke(CTNode* node, Agents& block);
  virtual Nodes AstarSearch(Agent* a, CTNode* node);
  void getPartialPath(AN* n, Nodes &path);
  int bin_search(std::vector<conflicted_node*> & conflicted_list, int st, int en, int time); 

public:
  DWA_ECBS_2(Problem* _P, float _w);
  DWA_ECBS_2(Problem* _P, float _w, bool _ID);
  ~DWA_ECBS_2();
  int lowlevelnode;
  int conflict_cnt;
  int cnt;
  int thrashing_nodes;
  std::map< int, double > mp;

  virtual std::string logStr();
  uint64_t timeSinceEpochMillisec();
  void print_paths(Paths &paths);
};
