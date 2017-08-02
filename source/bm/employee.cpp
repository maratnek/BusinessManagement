#include "employee.h"
#include <iostream>
#include <algorithm>
#include <boost/functional/factory.hpp>
#include <utility>

using namespace std;

CEmployee::CEmployee(const string& name):
	m_name(name)
{
	// общие задачи для каждого работника
	m_factTasks["Общие задачи"] = std::bind(boost::factory<CALLTask*>(), _1);
	m_factTasks["убрать рабочее место"] = std::bind(boost::factory<CALLTask*>(), _1);
	m_factTasks["отпуск"] = std::bind(boost::factory<CALLTask*>(), _1);

	m_tasks.push_back(shTask( m_factTasks["Общие задачи"]("Отпуск") ));
}

void CEmployee::AddTask(const string task_name, const string& declaration)
{ 
	m_tasks.push_back(shTask( m_factTasks[task_name](declaration) ));
}


void CEmployee::display() const
{
	cout << " Name: " << m_name << endl;
	// cout << " Working position: " << m_position << endl;
	cout << " Tasks -> " << m_tasks.size() << endl;
	for (const auto &it : m_tasks)
	{
		it->show();
		cout << endl;
	}
}


void CEmployee::showTasks() const
{
	unsigned i = 0;
	cout << "Задачи для сотрудника: " << endl;
	for (const auto &it : m_factTasks)
	{
		cout << ++i << ": " << it.first << endl;
	}
}

vector<string> CEmployee::VTasks() const
{
	vector<string> VStr;
	for (const auto &it : m_factTasks)
	{
		VStr.push_back( it.first );
	}
	return VStr;
}

