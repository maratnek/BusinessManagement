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

// ������ �� ����� �������� �� ������������ ������

CBusinessManagement::CBusinessManagement()
{
	std::cout << " CBusinessManagement START " << std::endl;
	Init();
}

void CBusinessManagement::Init()
{
	m_factories["�����������"] = std::bind(boost::factory<CProgrammer*>(), _1);
	//m_factories["��������"] = std::bind(boost::factory<CDirector*>(), _1);
	m_factories["������������ ������"] = std::bind(boost::factory<CHeadDepartment*>(), _1);
	m_factories["����������� ��������"] = std::bind(boost::factory<CTechnicalWriter*>(), _1);
	m_factories["���������� ������������"] = std::bind(boost::factory<CTester*>(), _1);
	m_factories["���������"] = std::bind(boost::factory<CAccountant*>(), _1);
}

int CBusinessManagement::Start(int ac, char** av)
{
	CMDLine cmd(ac, av);
	if (cmd["department"].empty())
		return 1;
	auto vDepName = DownloadDepartment(cmd["department"]);
	if (vDepName.empty())
	{
		cout << " ����� ������. ��������� �����������." << endl;
		return 2;
	}

	for(auto itEmpl : vDepName)
	{
		try {
			m_employeeList.push_back(shEmpl(m_factories[itEmpl[1]]( itEmpl[0] )));
		}
		catch(exception &e)
		{
			cerr << "�� ������� ������� ����������: " << itEmpl[0] << " - " << itEmpl[1] << endl;
			cerr << e.what() << endl;
		}
	}
	cout << " ���������� ������: " << endl;
	for (const auto &it: m_employeeList)
		it->show();
	auto director = make_shared<CDirector>("��������");
	auto showEmployeeList = [&](){
		cout << "�������� ���������� ��� ������������ ������: " << endl;
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
					cout << "������ " << NumEmployee << " ��� � ������, ������� ����� �� ������." << endl;
			} 
			catch( boost::bad_lexical_cast const& ) 
			{
				cout << " ������������ ���� ������, ������ ���� �����. " << str << endl;
			}

		return 0;
	};
	auto showMenu = [&director](){
		cout << endl;
		if (!director->GetGoal().empty())
			cout << "����� ���� �����������: " << director->GetGoal() << endl;
		cout << " *** ���� *** " << endl;
		cout << " ��������� ����� ������ � ������� ����: " << endl;
		cout << " 1. ��������� ���� ��� ����� �����������. " << endl;
		cout << " 2. ��������� ������ ���������� ��� ������(���.���.). " << endl;
		cout << " 3. ����� �� ������ ��� �������� �� ����������. " << endl;
		cout << " �������� Quit(Q) ��� ������. " << endl;
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
			// ���������� ������ ��� ����� �����������
			if (getline(cin, str, '\n'))
				director->SetGoal(str);
		}
		else if (str == "2")
		{
			// ��������� ������ ����������
			showEmployeeList();
			unsigned NumEmployee = getNum(m_employeeList.size());
			if (NumEmployee > 0)
			{
				cout << "�������� ��������� ������ ��� ����������: " << endl;
				// �������� ������ �� ���������� ���������� ��������� �� ������
				m_employeeList[NumEmployee-1]->showTasks();
				auto VTasks = m_employeeList[NumEmployee-1]->VTasks();
				unsigned NumTask = getNum(VTasks.size());
				if (NumTask > 0)
				{
					cout << "������� ���������� ������." << endl;
					if (getline(cin, str, '\n'))
						director->SetTask(m_employeeList[NumEmployee-1], VTasks[NumTask-1], str );
				}
			}
		}
		else if (str == "3")
		{
			// �����
		showEmployeeList();
			unsigned NumEmployee = getNum(m_employeeList.size());
			if (NumEmployee > 0)
				director->ShowReport(m_employeeList[NumEmployee-1]);
		}
		else
		{
			cout << " ������������ ���� ������ " << str << endl;
			cout << " C������� �� ����! " << endl;
		}
		showMenu();
		//EngineEmulate();
		/*
				m_employeeList[NumEmployee-1]->ResolvedTask(0);
				m_employeeList[NumEmployee-1]->show();*/
	}

	return 0;
}
