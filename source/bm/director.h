#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"

// �����
struct Report {};

class CDirector : public CEmployee {
public:
  CDirector(const std::string& name) : CEmployee(name) {}
  virtual void show() const
  {
    std::cout << "*** �������� ***" << std::endl;
    display();
  }
  //��������� ������ ��� ����� ������
  void SetGoal(const std::string& goal){ m_tasks.push_back(CTask("���������� ����� ���� �����������",goal,CTask::SPECIFIC));}
  //�������� ����� �� ���������� � ���������� ������
  void ShowReport(shEmpl empl){ empl->show();}
  //�������� ����� �� ����������� � ���������� �����
  void ShowReports(std::vector<shEmpl> vempl){ std::cout << ">>> ����� �� ������ <<<" << std::endl; for(const auto &it : vempl) it->show();}
  //��������� ������ ��� ������ ��� ����������
  void SetTask(shEmpl empl, const CTask& task){ empl->AddTask(task);};
};

#endif // _EMPLOYEE_H_
