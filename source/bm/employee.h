#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <vector>
#include <memory>
#include <iostream>
#include <set>
#include <functional>

#include "task.h"

class CEmployee {
protected:
  std::string m_name;
  // список задач работника
  std::vector<shTask> m_tasks;
  // set tasks
  std::set<std::string> m_sTasks;
public:
  CEmployee(const std::string& name);
  void AddTask(const std::string task_name, const std::string& declaration);
  virtual std::string GetPositionName() const { return m_name; }
  void ResolvedTask(unsigned int id){if (m_tasks.size() > id) m_tasks[id]->Resolved();}
  //void RemoveTask(unsigned int id) {if (m_tasks.size() > id) m_tasks[id];}
  virtual void show() const = 0;
  virtual void showTasks() const;
  virtual std::vector<std::string> VTasks() const;
  virtual void display() const;
  virtual ~CEmployee(){}
};

typedef  std::shared_ptr<CEmployee> shEmpl;

#endif // _EMPLOYEE_H_
