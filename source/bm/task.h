#ifndef _TASK_H_
#define _TASK_H_
#include <string>

class CTask {
public:
  // вид задачи общий или специфический
  enum EVid { ALL, SPECIFIC };
private:
  EVid m_eVid;
  std::string m_name;
  std::string m_contain;
  bool m_resolved;
public:
  CTask(const std::string& name, const std::string& meaning, EVid vid = EVid::ALL);
  bool IsResolved() const{return m_resolved;}
  void Resolved(){m_resolved = true;}
  void show() const;
  virtual ~CTask(){}
};

#endif // _TASK_H_
