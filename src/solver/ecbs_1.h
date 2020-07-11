/*
 * ecbs.h
 *
 * Purpose: Enhanced Conflict-based Search with weight change only at the root of high level node
 * Created by: Keisuke Okumura <okumura.k@coord.c.titech.ac.jp>
 */

#pragma once
#include "cbs.h"


class ECBS_1 : public CBS {
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
  ECBS_1(Problem* _P, float _w);
  ECBS_1(Problem* _P, float _w, bool _ID);
  ~ECBS_1();
  int lowlevelnode;
  int cnt;

  virtual std::string logStr();
  uint64_t timeSinceEpochMillisec();
};
