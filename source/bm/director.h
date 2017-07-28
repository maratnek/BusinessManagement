#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_
#include "employee.h"

// Отчет
struct Report {};

class CDirector : public CEmployee {
public:
  CDirector(const std::string& name) :
    CEmployee(name, "Директор")
  {
      cout << "Director create!" << endl;
      show();
  }
  //поставить задачу для всего предпр
  void SetGoal(const std::string& goal){ m_tasks.push_back(CTask("Постановка общей цели предприятия",goal,CTask::SPECIFIC));}
  //получить отчет от сотрудника о выполнении задачи
  void ShowReport(CEmployee& empl){ empl.show();};
  //поставить задачу для отдела или сотрудника
  void SetTask(CEmployee& empl, const CTask& task){ empl.AddTask(task);};
  virtual ~CDirector(){}
};

#endif // _EMPLOYEE_H_
