#ifndef _DIFFERENTS_EMPLOYEE_H_
#define _DIFFERENTS_EMPLOYEE_H_
#include "employee.h"
#include <string>
#include <iostream>

class CProgrammer : public CEmployee {
public:
  CProgrammer(const std::string name):CEmployee(name){std::cout << "CProgrammer" << std::endl;}
  virtual void show() const {display();}
};


class CTester : public CEmployee {
public:
  CTester(const std::string name):CEmployee(name){std::cout << "CTester" << std::endl;}
  virtual void show() const {display();}
};

class CHeadDepartment : public CEmployee {
public:
  CHeadDepartment(const std::string name):CEmployee(name){std::cout << "CHeadDepartment" << std::endl;}
  virtual void show() const {display();}
};

class CTechnicalWriter : public CEmployee {
public:
  CTechnicalWriter(const std::string name):CEmployee(name){std::cout << "CTechnicalWriter" << std::endl;}
  virtual void show() const {display();}
};

class CAccountant : public CEmployee {
public:
  CAccountant(const std::string name):CEmployee(name){std::cout << "CAccountant" << std::endl;}
  virtual void show() const {display();}
};

#endif // _DIFFERENTS_EMPLOYEE_H_
