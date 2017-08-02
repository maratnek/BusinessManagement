#include <iostream>
#include <boost/functional/factory.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "business-management.h"
#include "cmdline.h"
#include "csvparse.h"
#include "employee.h"
#include "director.h"
#include "differents-employee.h"
#include <utility>

using namespace std::placeholders;
using namespace std;

// Задача на отдел вешается на руководителя отдела

CBusinessManagement::CBusinessManagement()
{
	std::cout << " CBusinessManagement START " << std::endl;
	Init();
}

void CBusinessManagement::Init()
{
	m_factories["Разработчик"] = std::bind(boost::factory<CProgrammer*>(), _1);
	//m_factories["Директор"] = std::bind(boost::factory<CDirector*>(), _1);
	m_factories["Руководитель отдела"] = std::bind(boost::factory<CHeadDepartment*>(), _1);
	m_factories["Технический писатель"] = std::bind(boost::factory<CTechnicalWriter*>(), _1);
	m_factories["Специалист тестирования"] = std::bind(boost::factory<CTester*>(), _1);
	m_factories["Бухгалтер"] = std::bind(boost::factory<CAccountant*>(), _1);
}

int CBusinessManagement::Start(int ac, char** av)
{
	CMDLine cmd(ac, av);
	if (cmd["department"].empty())
		return 1;
	auto vDepName = DownloadDepartment(cmd["department"]);
	if (vDepName.empty())
	{
		cout << " Отдел пустой. Загрузите сотрудников." << endl;
		return 2;
	}

	for(auto itEmpl : vDepName)
	{
		try {
			m_employeeList.push_back(shEmpl(m_factories[itEmpl[1]]( itEmpl[0] )));
		}
		catch(exception &e)
		{
			cerr << "Не удалось создать сотрудника: " << itEmpl[0] << " - " << itEmpl[1] << endl;
			cerr << e.what() << endl;
		}
	}
	cout << " Сотрудники отдела: " << endl;
	for (const auto &it: m_employeeList)
		it->show();
	auto director = make_shared<CDirector>("Директор");
	auto showEmployeeList = [&](){
		cout << "Выберите сотрудника или руководителя отдела: " << endl;
		int i = 0;
		for (const auto it : m_employeeList)
		{
			cout << ++i << ": " << it->GetPositionName() << endl;
		}
	};
	auto getNum = [&](unsigned size)->unsigned{
		string str;
		getline(cin, str, '\n');
			unsigned NumEmployee = size + 1;
			try {
				NumEmployee = boost::lexical_cast<int>( str );
				if (size > NumEmployee - 1)
					return NumEmployee;
				else
					cout << "Номера " << NumEmployee << " нет в списке, укажите номер из списка." << endl;
			} 
			catch( boost::bad_lexical_cast const& ) 
			{
				cout << " Неправильный ВВОД данных, должно быть число. " << str << endl;
			}

		return 0;
	};
	auto showMenu = [&director](){
		cout << endl;
		if (!director->GetGoal().empty())
			cout << "Общая цель предприятия: " << director->GetGoal() << endl;
		cout << " *** Меню *** " << endl;
		cout << " Выбиерите номер задачи и нажмите ВВОД: " << endl;
		cout << " 1. Назначить цель для всего предприятия. " << endl;
		cout << " 2. Назначить задачу сотруднику или отделу(рук.отд.). " << endl;
		cout << " 3. Отчет по отделу или отдельно по сотруднику. " << endl;
		cout << " Наберите Quit(Q) для выхода. " << endl;
	};
	showMenu();
	string str;
	while (getline(cin, str, '\n'))
	{
		boost::to_upper(str);
		if (str == "QUIT" || str == "Q")
			break;
		else if (str == "1")
		{
			// Постановка задачи для всего предприятия
			if (getline(cin, str, '\n'))
				director->SetGoal(str);
		}
		else if (str == "2")
		{
			// Поставить задачу сотруднику
			showEmployeeList();
			unsigned NumEmployee = getNum(m_employeeList.size());
			if (NumEmployee > 0)
			{
				cout << "Выберите возможные задачи для сотрудника: " << endl;
				// создание задачи по выбранному сотруднику определяя из списка
				m_employeeList[NumEmployee-1]->showTasks();
				auto VTasks = m_employeeList[NumEmployee-1]->VTasks();
				unsigned NumTask = getNum(VTasks.size());
				if (NumTask > 0)
				{
					cout << "Опишите содержание задачи." << endl;
					if (getline(cin, str, '\n'))
						director->SetTask(m_employeeList[NumEmployee-1], VTasks[NumTask-1], str );
				}
			}
		}
		else if (str == "3")
		{
			// ОТЧЕТ
		showEmployeeList();
			unsigned NumEmployee = getNum(m_employeeList.size());
			if (NumEmployee > 0)
				director->ShowReport(m_employeeList[NumEmployee-1]);
		}
		else
		{
			cout << " Неправильный ВВОД данных " << str << endl;
			cout << " Cледуйте по МЕНЮ! " << endl;
		}
		showMenu();
		//EngineEmulate();
		/*
				m_employeeList[NumEmployee-1]->ResolvedTask(0);
				m_employeeList[NumEmployee-1]->show();*/
	}

	return 0;
}
