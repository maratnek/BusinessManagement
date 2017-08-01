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

// ������ �� ����� �������� �� ������������ ������

CBusinessManagement::CBusinessManagement()
{
  std::cout << " CBusinessManagement START " << std::endl;
  Init();
}

void CBusinessManagement::Init()
{
  m_factories["�����������"] = std::bind(boost::factory<CProgrammer*>(), _1);
  m_factories["��������"] = std::bind(boost::factory<CDirector*>(), _1);
  m_factories["������������ ������"] = std::bind(boost::factory<CHeadDepartment*>(), _1);
  m_factories["����������� ��������"] = std::bind(boost::factory<CTechnicalWriter*>(), _1);
  m_factories["���������� ������������"] = std::bind(boost::factory<CTester*>(), _1);
  m_factories["���������"] = std::bind(boost::factory<CAccountant*>(), _1);
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
      cerr << "�� ������� ������� ����������: " << itEmpl[0] << " - " << itEmpl[1] << endl;
      cerr << e.what() << endl;
    }
  }
  auto director = static_pointer_cast<CDirector>(shEmpl(m_factories["��������"]("�����")));
  // ���������� ������ ��� ����� �����������
  director->SetGoal("������� ���� � ����������� ������.");
  // ��������� ������ ���������� 1
  director->SetTask(m_employeeList[1], CTask("Develop", "Develop BusinessManagement"));
  director->ShowReport(m_employeeList[1]);
  director->SetTask(m_employeeList[1], CTask("Develop", "Project new module for the BusinessManagement"));
  m_employeeList[1]->ResolvedTask(0);
  // �������� ����� �� ����� ������
  director->ShowReports(m_employeeList);
  return 0;
}
