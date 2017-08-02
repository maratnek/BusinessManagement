#ifndef _BUSINESS_MANAGEMENT_H_
#define _BUSINESS_MANAGEMENT_H_
#include <map>
#include <functional>
#include "employee.h"

class CBusinessManagement {
  // objects factory
  std::map<std::string, std::function<CEmployee* (const std::string&)>> m_factories;
  // список работников отдела
  std::vector<shEmpl> m_employeeList;
public:
  CBusinessManagement();
  // инициализация из файла
  void Init();
  // начало работы
  int Start(int ac, char** av);
};

#endif // _BUSINESS_MANAGEMENT_H_
