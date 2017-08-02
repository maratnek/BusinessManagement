#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"

class CDirector : public CEmployee {
public:
	CDirector(const std::string& name) : CEmployee(name) 
	{
		m_sTasks.insert("Постановка общей цели предприятия");
	}
	virtual void show() const
	{
		std::cout << "*** Директор ***" << std::endl;
		display();
	}
	//поставить задачу для всего предпр
	void SetGoal(const std::string& goal);
	std::string GetGoal() const;
	//получить отчет от сотрудника о выполнении задачи
	void ShowReport(shEmpl empl);
	//получить отчет от сотрудников о выполнении задач
	void ShowReports(std::vector<shEmpl> vempl);
	//поставить задачу для отдела или сотрудника
	void SetTask(shEmpl empl, const std::string& t_name, const std::string& decl);
};

#endif // _EMPLOYEE_H_
