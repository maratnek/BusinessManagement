#include <iostream>
#include <boost/functional/factory.hpp>
#include "business-management.h"
#include "cmdline.h"
#include "csvparse.h"
#include "employee.h"
#include "director.h"
#include "differents-employee.h"
#include <utility>

using namespace std::placeholders;
using namespace std;

// Задача на отдел вешается на руководителя отдела

CBusinessManagement::CBusinessManagement()
{
  std::cout << " CBusinessManagement START " << std::endl;
  Init();
}

void CBusinessManagement::Init()
{
  m_factories["Разработчик"] = std::bind(boost::factory<CProgrammer*>(), _1);
  m_factories["Директор"] = std::bind(boost::factory<CDirector*>(), _1);
  m_factories["Руководитель отдела"] = std::bind(boost::factory<CHeadDepartment*>(), _1);
  m_factories["Технический писатель"] = std::bind(boost::factory<CTechnicalWriter*>(), _1);
  m_factories["Специалист тестирования"] = std::bind(boost::factory<CTester*>(), _1);
  m_factories["Бухгалтер"] = std::bind(boost::factory<CAccountant*>(), _1);
}

int CBusinessManagement::Start(int ac, char** av)
{
  CMDLine cmd(ac, av);
  if (cmd["department"].empty())
    return 1;
  auto vDepName = DownloadDepartment(cmd["department"]);
  if (vDepName.empty())
    return 2;

  for(auto itEmpl : vDepName)
  {
    try {
      m_employeeList.push_back(shEmpl(m_factories[itEmpl[1]]( itEmpl[0] )));
    }
    catch(exception &e)
    {
      cerr << "Не удалось создать сотрудника: " << itEmpl[0] << " - " << itEmpl[1] << endl;
      cerr << e.what() << endl;
    }
  }
  auto director = static_pointer_cast<CDirector>(shEmpl(m_factories["Директор"]("Артур")));
  // Постановка задачи для всего предприятия
  director->SetGoal("Большой рост в направлении продаж.");
  // Поставить задачу сотруднику 1
  director->SetTask(m_employeeList[1], CTask("Develop", "Develop BusinessManagement"));
  director->ShowReport(m_employeeList[1]);
  director->SetTask(m_employeeList[1], CTask("Develop", "Project new module for the BusinessManagement"));
  m_employeeList[1]->ResolvedTask(0);
  // Показать отчет по всему отделу
  director->ShowReports(m_employeeList);
  return 0;
}
