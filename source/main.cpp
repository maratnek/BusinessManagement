#include <iostream>
#include "cmdline.h"
#include "business-management.h"
#include "csvparse.h"

int main(int ac, char**av)
{
  // CBusinessManagement bm(ac, av);
  CMDLine cmd(ac, av);
  cout << cmd["department"] << endl;
  TestCSV(cmd["department"]);
}
