#include "employee.h"
#include <utility>
#include <iostream>
using namespace std;

CEmployee::CEmployee(std::string&& name, std::string&& position):
  m_name(move(name)),
  m_position(move(position))
{
  show();
}


CEmployee::CEmployee(const std::string& name, const std::string& position):
  m_name(move(name)),
  m_position(move(position))
{
  show();
}

void CEmployee::show()
{
  cout << " Name: " << m_name << endl;
  cout << " Working position: " << m_position << endl;
  cout << " Tasks -> " << m_tasks.size() << endl;
  for (const auto &it : m_tasks)
  {
    it.show();
    cout << endl;
  }
}
