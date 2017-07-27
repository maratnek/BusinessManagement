#include "task.h"
#include <iostream>
using namespace std;

CTask::CTask(std::string&& name, std::string&& meaning)
  : m_name(name),
    m_text(meaning),
    m_resolved(false)
{}

void CTask::show()const
{
  cout << "Task : " << m_name << endl;
  cout << "Explain : " << m_text << endl;
  cout << (IsResolved()? "Resolved" : "NotResolved") << endl;
}
