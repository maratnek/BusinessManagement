#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <vector>
#include "task.h"

class CEmployee {
protected:
  std::string m_name;
  std::string m_position;
  std::vector<CTask> m_tasks;
public:
  CEmployee(const std::string& name, const std::string& position, std::vector<CTask>& tasks);
  CEmployee(const std::string& name, const std::string& position);
  void AddTask(const CTask& task){ m_tasks.push_back(task);}
  void ResolvedTask(unsigned int id){if (m_tasks.size() > id) m_tasks[id].Resolved();}
  void show();
  virtual ~CEmployee(){}
};

#endif // _EMPLOYEE_H_
