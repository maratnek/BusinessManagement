#ifndef _TASK_H_
#define _TASK_H_
#include <string>
#include <memory>
#include <iostream>

class CTask {
public:
  // вид задачи общий или специфический
  enum EVid { ALL, SPECIFIC };
protected:
  EVid m_eVid;
  std::string m_name;
  std::string m_contain;
  bool m_resolved;
public:
  CTask(const std::string& name, const std::string& contain, EVid vid = EVid::ALL);
  virtual const std::string& GetName() const {return m_name;};
  const std::string& GetContain() const {return m_contain;}
  bool IsResolved() const{return m_resolved;}
  void Resolved(){m_resolved = true;}
  virtual void show() const;
  virtual ~CTask(){}
};

typedef std::shared_ptr<CTask> shTask;
//using namespace std;
//class CALLTask : public CTask {
//public:
//  CALLTask(const std::string contain)
//	  : CTask(contain)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Общие задачи: " << endl;
//	CTask::display();
//  }
//};
//
//class CDirectorTask : public CTask {
//public:
//  CDirectorTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задачи директора: " << endl;
//	CTask::display();
//  }
//};
//
//class CTWTask : public CTask {
//public:
//  CTWTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задачи технического писателя: " << endl;
//	CTask::display();
//  }
//};
//
//class CProgrammerTask : public CTask {
//public:
//  CProgrammerTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задача программиста: " << endl;
//	CTask::display();
//  }
//};
//
//class CTesterTask : public CTask {
//public:
//  CTesterTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задача тестера: " << endl;
//	CTask::display();
//  }
//};
//
//class CHDTask : public CTask {
//public:
//  CHDTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задача руководителя отдела: " << endl;
//	CTask::display();
//  }
//};
//
//class CAccountantTask : public CTask {
//public:
//  CAccountantTask(const std::string contain)
//	  : CTask(contain, EVid::SPECIFIC)
//  {}
//  virtual void show() const
//  {
//    std::cout << "Задача бухгалтера: " << endl;
//	CTask::display();
//  }
//};

#endif // _TASK_H_
