#include "task.h"
#include <iostream>
using namespace std;

CTask::CTask(const std::string& name, const std::string& meaning, EVid vid)
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
