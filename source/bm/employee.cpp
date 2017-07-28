#include "employee.h"
#include <iostream>
using namespace std;

CEmployee::CEmployee(const string& name, const string& position, vector<CTask>& tasks):
  m_name(name),
  m_position(position),
  m_tasks(tasks)
{
  show();
}

CEmployee::CEmployee(const string& name, const string& position):
  m_name(name),
  m_position(position)
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
