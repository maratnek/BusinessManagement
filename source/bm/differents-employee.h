#ifndef _DIFFERENTS_EMPLOYEE_H_
#define _DIFFERENTS_EMPLOYEE_H_
#include "employee.h"
#include <string>
#include <iostream>

class CProgrammer : public CEmployee {
public:
  CProgrammer(const std::string name) : CEmployee(name){}
  virtual void show() const
  {
    std::cout << "*** Программист ***" << std::endl;
    display();
  }
};


class CTester : public CEmployee {
public:
  CTester(const std::string name):CEmployee(name){}
  virtual void show() const
  {
    std::cout << "*** Тестер ***" << std::endl;
    display();
  }
};

class CHeadDepartment : public CEmployee {
public:
  CHeadDepartment(const std::string name):CEmployee(name){}
  virtual void show() const
  {
    std::cout << "*** Руководитель отдела ***" << std::endl;
    display();
  }
};

class CTechnicalWriter : public CEmployee {
public:
  CTechnicalWriter(const std::string name):CEmployee(name){}
  virtual void show() const
  {
    std::cout << "*** Технический писатель ***" << std::endl;
    display();
  }
};

class CAccountant : public CEmployee {
public:
  CAccountant(const std::string name):CEmployee(name){}
  virtual void show() const
  {
    std::cout << "*** Бухгалтер ***" << std::endl;
    display();
  }
};

#endif // _DIFFERENTS_EMPLOYEE_H_
