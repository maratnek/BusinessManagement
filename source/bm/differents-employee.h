#ifndef _DIFFERENTS_EMPLOYEE_H_
#define _DIFFERENTS_EMPLOYEE_H_
#include "employee.h"
#include <string>
#include <iostream>

class CProgrammer : public CEmployee {
public:
	CProgrammer(const std::string name) : CEmployee(name)
	{
		//определяем задачи работника
		m_sTasks.insert("Программирование");
		m_sTasks.insert("Разработка");
	}
	virtual void show() const
	{
		std::cout << "*** Программист ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("Программист -> " + m_name); }

};


class CTester : public CEmployee {
public:
	CTester(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("Тестировать");
		m_sTasks.insert("Составлять тестовые планы");
	}
	virtual void show() const
	{
		std::cout << "*** Тестер ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("Тестер -> " + m_name); }
};

class CHeadDepartment : public CEmployee {
public:
	CHeadDepartment(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("Контроль отдела");
	}
	virtual void show() const
	{
		std::cout << "*** Руководитель отдела ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("Руководитель отдела -> " + m_name); }
};

class CTechnicalWriter : public CEmployee {
public:
	CTechnicalWriter(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("Переводить тексты");
	}
	virtual void show() const
	{
		std::cout << "*** Технический писатель ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("Технический писатель -> " + m_name); }
};

class CAccountant : public CEmployee {
public:
	CAccountant(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("Начислять зарплату");
		m_sTasks.insert("Составить квартальный отчет");
	}
	virtual void show() const
	{
		std::cout << "*** Бухгалтер ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("Бухгалтер -> " + m_name); }
};

#endif // _DIFFERENTS_EMPLOYEE_H_
