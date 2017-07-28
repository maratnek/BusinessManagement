#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>
#include <vector>
#include "task.h"

class CEmployee {
  std::string m_name;
  std::string m_position;
  std::vector<CTask> m_tasks;
public:
  CEmployee(const std::string& name, const std::string& position, std::vector<CTask>& tasks);
  CEmployee(const std::string& name, const std::string& position);
  void show();
  virtual ~CEmployee(){}
};

#endif // _EMPLOYEE_H_
