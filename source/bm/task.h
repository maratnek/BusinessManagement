#ifndef _TASK_H_
#define _TASK_H_
#include <string>

class CTask {
  std::string m_name;
  std::string m_text;
  bool m_resolved;
public:
  CTask(std::string&& name, std::string&& meaning);
  bool IsResolved() const{return m_resolved;}
  void Resolved(){m_resolved = true;}
  void show() const;
  virtual ~CTask(){}
};

#endif // _TASK_H_
