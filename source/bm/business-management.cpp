#include <iostream>
#include "business-management.h"
#include "cmdline.h"
#include "csvparse.h"
#include "employee.h"
#include <utility>


CBusinessManagement::CBusinessManagement(int ac, char **av)
{
  std::cout << " CBusinessManagement START " << std::endl;
  CMDLine cmd(ac, av);
  cout << cmd["department"] << endl;
  std::vector<CEmployee> vEmpl;

  for(auto itEmpl : DownloadDepartment(cmd["department"]))
    vEmpl.push_back(CEmployee(itEmpl[0], itEmpl[1]));
  cout << "debug test " << endl;

  // CEmployee director("Rock", "Director");
}

CBusinessManagement::~CBusinessManagement()
{
  std::cout << " CBusinessManagement END " << std::endl;
}
