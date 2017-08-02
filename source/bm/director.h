#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"
#include <algorithm>

// �����
struct Report {};

class CDirector : public CEmployee {
public:
  CDirector(const std::string& name) : CEmployee(name) 
  {
	  m_factTasks["���������� ����� ���� �����������"] = std::bind(boost::factory<CDirectorTask*>(), _1);
  }
  virtual void show() const
  {
    std::cout << "*** �������� ***" << std::endl;
    display();
  }
  //��������� ������ ��� ����� ������
  void SetGoal(const std::string& goal){ m_tasks.push_back(shTask(m_factTasks["���������� ����� ���� �����������"](goal)));}
  string GetGoal() const { 
	  auto it = find_if(m_tasks.begin(), m_tasks.end(), 
		  [](shTask t)->bool{
			  if(t->GetName() == "���������� ����� ���� �����������") 
				  return true;
			  return false;
			}
	  );
	  if (it != m_tasks.end())
		  return it->get()->GetContain();
	  return "";
  }
  //�������� ����� �� ���������� � ���������� ������
  void ShowReport(shEmpl empl){ empl->show();}
  //�������� ����� �� ����������� � ���������� �����
  void ShowReports(std::vector<shEmpl> vempl){ std::cout << ">>> ����� �� ������ <<<" << std::endl; for(const auto &it : vempl) it->show();}
  //��������� ������ ��� ������ ��� ����������
  void SetTask(shEmpl empl, const string t_name, const string& decl){ empl->AddTask(t_name, decl);};
};

#endif // _EMPLOYEE_H_
