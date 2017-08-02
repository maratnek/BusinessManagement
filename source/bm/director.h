#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"

class CDirector : public CEmployee {
public:
	CDirector(const std::string& name) : CEmployee(name) 
	{
		m_sTasks.insert("���������� ����� ���� �����������");
	}
	virtual void show() const
	{
		std::cout << "*** �������� ***" << std::endl;
		display();
	}
	//��������� ������ ��� ����� ������
	void SetGoal(const std::string& goal);
	std::string GetGoal() const;
	//�������� ����� �� ���������� � ���������� ������
	void ShowReport(shEmpl empl);
	//�������� ����� �� ����������� � ���������� �����
	void ShowReports(std::vector<shEmpl> vempl);
	//��������� ������ ��� ������ ��� ����������
	void SetTask(shEmpl empl, const std::string& t_name, const std::string& decl);
};

#endif // _EMPLOYEE_H_
