#include "task.h"
#include <iostream>
using namespace std;

CTask::CTask(const std::string& name, const std::string& contain, EVid vid)
    : 
	m_name(name),
	m_contain(contain),
	m_eVid(vid),
    m_resolved(false)
{}

void CTask::show() const
{
  cout << "Задача : " << m_name << endl;
  cout << "Содержание : " << m_contain << endl;
  cout << (IsResolved()? "Решен" : "Не решён") << endl;
}
