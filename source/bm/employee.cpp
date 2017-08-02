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
	m_sTasks.insert("убрать рабочее место");
	m_sTasks.insert("уйти в отпуск");
}

void CEmployee::AddTask(const string t_name, const string& decl)
{ 
	m_tasks.push_back(make_shared<CTask>(t_name, decl));
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
	for (const auto &it : m_sTasks)
	{
		cout << ++i << ": " << it << endl;
	}
}

vector<string> CEmployee::VTasks() const
{
	vector<string> VStr;
	for (const auto &it : m_sTasks)
	{
		VStr.push_back( it );
	}
	return VStr;
}

