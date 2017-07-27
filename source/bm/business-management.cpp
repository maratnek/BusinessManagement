#include <iostream>
#include "business-management.h"

CBusinessManagement::CBusinessManagement(int ac, char **av)
{
  std::cout << " CBusinessManagement constructor " << std::endl;
}

CBusinessManagement::~CBusinessManagement()
{
  std::cout << " CBusinessManagement destructor " << std::endl;
}
