#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"
#include <algorithm>

// Отчет
struct Report {};

class CDirector : public CEmployee {
public:
  CDirector(const std::string& name) : CEmployee(name) 
  {
	  m_factTasks["Постановка общей цели предприятия"] = std::bind(boost::factory<CDirectorTask*>(), _1);
  }
  virtual void show() const
  {
    std::cout << "*** Директор ***" << std::endl;
    display();
  }
  //поставить задачу для всего предпр
  void SetGoal(const std::string& goal){ m_tasks.push_back(shTask(m_factTasks["Постановка общей цели предприятия"](goal)));}
  string GetGoal() const { 
	  auto it = find_if(m_tasks.begin(), m_tasks.end(), 
		  [](shTask t)->bool{
			  if(t->GetName() == "Постановка общей цели предприятия") 
				  return true;
			  return false;
			}
	  );
	  if (it != m_tasks.end())
		  return it->get()->GetContain();
	  return "";
  }
  //получить отчет от сотрудника о выполнении задачи
  void ShowReport(shEmpl empl){ empl->show();}
  //получить отчет от сотрудников о выполнении задач
  void ShowReports(std::vector<shEmpl> vempl){ std::cout << ">>> Отчет по отделу <<<" << std::endl; for(const auto &it : vempl) it->show();}
  //поставить задачу для отдела или сотрудника
  void SetTask(shEmpl empl, const string t_name, const string& decl){ empl->AddTask(t_name, decl);};
};

#endif // _EMPLOYEE_H_
