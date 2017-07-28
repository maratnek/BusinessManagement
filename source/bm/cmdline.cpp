#include "cmdline.h"
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/cmdline.hpp>
#include <string>

CMDLine::CMDLine(int ac, char **av){
  std::cout << "CMDLine START!" << std::endl;
  try {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("department", po::value<string>(), "Department file with employees")
    ;

    po::store(po::parse_command_line(ac, av, desc), m_vm);
    po::notify(m_vm);

    if (m_vm.count("help")) {
      cout << desc << "\n";
      return;
    }

    if (m_vm.count("department")) {
      cout << "Department file with employees: "
      << operator[]("department") << ".\n";
    } else {
      cout << "Department file was not declared.\n";
    }
  }
  catch(exception & e)
  {
    cout << "Error parse command line: " << e.what() << endl;
  }
}


string CMDLine::operator[](const char* val)
{
  return !m_vm[val].empty()? m_vm[val].as<string>() : "";
}
