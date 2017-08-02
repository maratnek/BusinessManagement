#include "director.h"
#include <algorithm>
using namespace std;
//поставить задачу для всего предпр
void CDirector::SetGoal(const string& goal)
{
	m_tasks.push_back( make_shared<CTask>("Постановка общей цели предприятия",goal) );
}

string CDirector::GetGoal() const 
{ 
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

void CDirector::ShowReport(shEmpl empl)
{ 
	empl->show();
}

void CDirector::ShowReports(std::vector<shEmpl> vempl)
{
	std::cout << ">>> Отчет по отделу <<<" << std::endl; for(const auto &it : vempl) it->show();
}

void CDirector::SetTask(shEmpl empl, const string& t_name, const string& decl)
{ 
	empl->AddTask(t_name, decl);
}