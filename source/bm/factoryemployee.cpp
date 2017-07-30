#include "factoryemployee.h"
#include <memory>

void factory_test()
{
    ptr_map<string,EmployeeFactory> factories;

    // [...]

    factories.insert("TechnicalWriter",std::auto_ptr<EmployeeFactory>(
        new CTechnicalWriterFactory));
    factories.insert("Accountant",std::auto_ptr<EmployeeFactory>(
        new CAccountantFactory));

    // [...]

    std::auto_ptr<CConcreateFactory> empl(factories.at("TechnicalWriter").create());
}
