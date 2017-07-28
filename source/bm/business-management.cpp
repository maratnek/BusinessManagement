#include <iostream>
#include "business-management.h"
#include "cmdline.h"
#include "csvparse.h"
#include "employee.h"
#include "director.h"
#include <utility>


CBusinessManagement::CBusinessManagement(int ac, char **av)
{
  std::cout << " CBusinessManagement START " << std::endl;
  CMDLine cmd(ac, av);
  std::vector<CEmployee> vEmpl;

  for(auto itEmpl : DownloadDepartment(cmd["department"]))
    vEmpl.push_back(CEmployee(itEmpl[0], itEmpl[1]));

  CDirector director("Артур");
  director.SetGoal("Большой рост в направлении продаж.");
  director.ShowReport(vEmpl[2]);
  director.ShowReport(director);
  director.SetTask(vEmpl[1], CTask("Develop", "Develop BusinessManagement"));
  director.SetTask(vEmpl[1], CTask("Develop", "Project new modul for the BusinessManagement"));
  vEmpl[1].ResolvedTask(0);
  director.ShowReport(vEmpl[1]);
}

CBusinessManagement::~CBusinessManagement()
{
  std::cout << " CBusinessManagement END " << std::endl;
}
