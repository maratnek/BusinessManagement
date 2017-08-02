#include "task.h"
#include <iostream>
using namespace std;

CTask::CTask(const std::string& meaning, EVid vid)
    : m_contain(meaning),
    m_resolved(false)
{}

void CTask::display() const
{
  cout << "������ : " << m_name << endl;
  cout << "���������� : " << m_contain << endl;
  cout << (IsResolved()? "�����" : "�� �����") << endl;
}
