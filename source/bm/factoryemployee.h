#ifndef _FACTORY_EMPLOYEE_H_
#define _FACTORY_EMPLOYEE_H_
#include <boost/functional/factory.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include "employee.h"
#include <string>
#include <iostream>
using namespace boost;
using namespace std;

template <typename TAbstractClass>
class  a_factory
{
  public:
    virtual  TAbstractClass *  create()  const  =  0;
    virtual  ~a_factory() {}
};

typedef a_factory<CEmployee> EmployeeFactory;

template <typename TClass, typename TAbstractClass>
class CConcreateFactory :  public  EmployeeFactory
{
  public :
    virtual  TAbstractClass*  create()  const
    {
        return  new  TClass();
    }
};

class CTechnicalWriter : public CEmployee {
public:
  CTechnicalWriter(){cout << "CTechnicalWriter" << endl;}
};

class CAccountant : public CEmployee {
public:
  CAccountant(){cout << "CAccountant" << endl;}
};

typedef CConcreateFactory<CTechnicalWriter,CEmployee> CTechnicalWriterFactory;
typedef CConcreateFactory<CAccountant,CEmployee> CAccountantFactory;

#endif //_FACTORY_EMPLOYEE_H_
