#include "employee.h"
#include <iostream>
using namespace std;

CEmployee::CEmployee(const string& name, vector<CTask>& tasks):
  m_name(name),
  // m_position(position),
  m_tasks(tasks)
{
}

CEmployee::CEmployee(const string& name):
  m_name(name)
  // m_position(position)
{
}

void CEmployee::display() const
{
  cout << " Name: " << m_name << endl;
  // cout << " Working position: " << m_position << endl;
  cout << " Tasks -> " << m_tasks.size() << endl;
  for (const auto &it : m_tasks)
  {
    it.show();
    cout << endl;
  }
}
