#ifndef _CMDLINE_H_
#define __CMDLINE_H_
#include <iostream>
#include <boost/program_options/variables_map.hpp>
using namespace std;
namespace po = boost::program_options;

class CMDLine {
  po::variables_map m_vm;
public:
    CMDLine (int ac, char **av);
    string operator[](const char* val);
};

#endif //_CMDLINE_H_
