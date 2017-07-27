#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <string>

class CEmployee {
  std::string m_name;
  std::string m_position;
public:
  CEmployee();
  virtual ~CEmployee(){}
};

#endif // _EMPLOYEE_H_
