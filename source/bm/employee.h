#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <vector>
#include <memory>
#include <iostream>
#include "task.h"


class CEmployee {
protected:
  std::string m_name;
  std::vector<CTask> m_tasks;
public:
  CEmployee(const std::string& name, std::vector<CTask>& tasks);
  CEmployee(const std::string& name);
  void AddTask(const CTask& task){ m_tasks.push_back(task);}
  void ResolvedTask(unsigned int id){if (m_tasks.size() > id) m_tasks[id].Resolved();}
  // void RemoveTask(unsigned int id) {if (m_tasks.size() > id) m_tasks[id];}
  virtual void show() const = 0;
  virtual void display() const;
  virtual ~CEmployee(){}
};

typedef  std::shared_ptr<CEmployee> shEmpl;

#endif // _EMPLOYEE_H_
