#include "factoryemployee.h"

void factory_test()
{
    ptr_map<string,a_factory> factories;

    // [...]

    factories.insert("TechnicalWriter",shared_ptr<EmployeeFactory>(
        new CTechnicalWriterFactory));
    factories.insert("Accountant",shared_ptr<EmployeeFactory>(
        new CAccountantFactory));

    // [...]

    shared_ptr<CEmployee> empl(factories.at("TechnicalWriter").create());
}
