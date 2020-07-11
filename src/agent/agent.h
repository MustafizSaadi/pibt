#pragma once

#include "../graph/node.h"
#include "../task/task.h"

// history of agent
struct AgentStatus {
  Node* v;
  Node* g;
  Task* tau;
};

class Agent {
private:
  int id;
  static int cntId;  // for uuid
  Node* v;           // current node
  Node* g;           // current goal
  Task* tau;         // task
  std::vector<AgentStatus*> hist;  // agent history
  
  bool updated;      // whether goal is updated or not
  Node* beforeNode;  // previous location node, auto updated

public:
  Agent();
  Agent(Node* v);  // initial location
  ~Agent();

  int conf;          //current conflict count
  double m_w = 1;           // current suboptimal bound


  int getId() { return id; }

  void setTask(Task* _t) { tau = _t; }
  Task* getTask() { return tau; }
  bool hasTask() { return !(tau == nullptr); }

  void releaseTask();
  void releaseTaskOnly();
  void releaseGoalOnly();

  void setGoal(Node* _g) { g = _g; }
  Node* getGoal() { return g; }
  bool hasGoal() { return !(g == nullptr); }

  Node* getNode() { return v; }
  void setNode(Node* _v);
  Node* getBeforeNode() { return beforeNode; }
  void setBeforeNode(Node* _v) { beforeNode = _v; }

  void goalUpdated(bool flg) { updated = flg; }
  bool isUpdated() { return updated; }

  void updateHist();
  std::vector<AgentStatus*> getHist() { return hist; }

  std::string logStr();

  bool operator==(Agent* a) const { return a->getId() == id; };
  bool operator!=(Agent* a) const { return a->getId() != id; };
  bool operator==(Agent& a) const { return a.getId() == id; };
  bool operator!=(Agent& a) const { return a.getId() != id; };
};
