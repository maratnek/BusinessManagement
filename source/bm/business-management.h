#ifndef _BUSINESS_MANAGEMENT_H_
#define _BUSINESS_MANAGEMENT_H_
#include <memory>
#include <map>
#include <functional>
#include "employee.h"

using shEmpl = std::shared_ptr<CEmployee>;

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
  virtual ~CBusinessManagement();
};

#endif // _BUSINESS_MANAGEMENT_H_
