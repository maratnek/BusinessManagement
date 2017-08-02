#ifndef _DIFFERENTS_EMPLOYEE_H_
#define _DIFFERENTS_EMPLOYEE_H_
#include "employee.h"
#include <string>
#include <iostream>

class CProgrammer : public CEmployee {
public:
	CProgrammer(const std::string name) : CEmployee(name)
	{
		//���������� ������ ���������
		m_sTasks.insert("����������������");
		m_sTasks.insert("����������");
	}
	virtual void show() const
	{
		std::cout << "*** ����������� ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("����������� -> " + m_name); }

};


class CTester : public CEmployee {
public:
	CTester(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("�����������");
		m_sTasks.insert("���������� �������� �����");
	}
	virtual void show() const
	{
		std::cout << "*** ������ ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("������ -> " + m_name); }
};

class CHeadDepartment : public CEmployee {
public:
	CHeadDepartment(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("�������� ������");
	}
	virtual void show() const
	{
		std::cout << "*** ������������ ������ ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("������������ ������ -> " + m_name); }
};

class CTechnicalWriter : public CEmployee {
public:
	CTechnicalWriter(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("���������� ������");
	}
	virtual void show() const
	{
		std::cout << "*** ����������� �������� ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("����������� �������� -> " + m_name); }
};

class CAccountant : public CEmployee {
public:
	CAccountant(const std::string name):CEmployee(name)
	{
		m_sTasks.insert("��������� ��������");
		m_sTasks.insert("��������� ����������� �����");
	}
	virtual void show() const
	{
		std::cout << "*** ��������� ***" << std::endl;
		display();
	}
	virtual std::string GetPositionName() const { return move("��������� -> " + m_name); }
};

#endif // _DIFFERENTS_EMPLOYEE_H_
