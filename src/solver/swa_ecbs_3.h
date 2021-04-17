/*
 * ecbs.h
 *
 * Purpose: Enhanced Conflict-based Search with weight change only at the root of high level node
 * Created by: Keisuke Okumura <okumura.k@coord.c.titech.ac.jp>
 */

#pragma once
#include "cbs.h"


class SWA_ECBS_3 : public CBS {
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

public:
  SWA_ECBS_3(Problem* _P, float _w);
  SWA_ECBS_3(Problem* _P, float _w, bool _ID);
  ~SWA_ECBS_3();
  int lowlevelnode;
  int conflict_cnt;
  int cnt;
  int thrashing_nodes;
  std::vector<std::pair<int,int>> vec[50];

  virtual std::string logStr();
  uint64_t timeSinceEpochMillisec();
  void writeDiscoveredPath(int i,std::vector<std::pair<int,int>> & mat);
  void print_paths(Paths &paths);
};
