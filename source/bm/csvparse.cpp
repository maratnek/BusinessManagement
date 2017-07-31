#include <boost/regex.hpp>
#include <fstream>
#include <cstring>
#include <iostream>
#include "csvparse.h"
#include <memory>

// used to split the file in lines
const boost::regex linesregx("\\r\\n|\\n\\r|\\n|\\r");

// used to split each line to tokens, assuming ',' as column separator
const boost::regex fieldsregx(";(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");

// typedef std::vector<std::string> Row;

VRow parse(const char* data, unsigned int length)
{
  VRow result;

  // iterator splits data to lines
  boost::cregex_token_iterator li(data, data + length, linesregx, -1);
  boost::cregex_token_iterator end;

  while (li != end) {
    std::string line = li->str();
    ++li;

    // Split line to tokens
    boost::sregex_token_iterator ti(line.begin(), line.end(), fieldsregx, -1);
    boost::sregex_token_iterator end2;

    std::vector<std::string> row;
    while (ti != end2) {
      std::string token = ti->str();
      ++ti;
      row.push_back(token);
    }
    if (line.back() == ';') {
      // last character was a separator
      row.push_back("");
    }
    result.push_back(row);
  }
  return result;
}

VRow DownloadDepartment(const std::string& fn)
{
  VRow result;
  try {
    // read example file
    std::ifstream infile(fn, std::ios::binary);
    if (!infile.is_open())
    return result;
    // get length of file:
    infile.seekg(0, infile.end);
    int length = infile.tellg();
    infile.seekg(0, infile.beg);
    std::shared_ptr<char> buffer(new char[length+1],
      [](char* p){std::cout<<"Clean buffer."<<std::endl;delete[] p;});
    infile.read(buffer.get(), length);
    buffer.get()[length+1] = '\0';
    infile.close();

    // parse file
    result = parse(buffer.get(), length);

    // print out result
    // for (const auto & itRow: result)
    // {
    //   for (const auto & itCol: itRow)
    //   std::cout << itCol << "\t";
    //   std::cout << std::endl;
    // }
  }
  catch(std::exception &e)
  {
    std::cerr << "Error download department! " << e.what() << std::endl;
  }

  return result;
}
