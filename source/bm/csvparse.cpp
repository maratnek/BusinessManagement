#include <boost/regex.hpp>
// #include <vector>
// #include <string>
#include <iostream>
#include "csvparse.h"

// used to split the file in lines
const boost::regex linesregx("\\r\\n|\\n\\r|\\n|\\r");

// used to split each line to tokens, assuming ',' as column separator
const boost::regex fieldsregx(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");

// typedef std::vector<std::string> Row;

std::vector<Row> parse(const char* data, unsigned int length)
{
    std::vector<Row> result;

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
        if (line.back() == ',') {
            // last character was a separator
            row.push_back("");
        }
        result.push_back(row);
    }
    return result;
}

#include <fstream>
#include <cstring>
void TestCSV(const std::string& fn)
{

  // read example file
  std::ifstream infile;
  infile.open(fn);
  char buffer[1024];
  infile.read(buffer, sizeof(buffer));
  buffer[infile.tellg()] = '\0';

  // parse file
  std::vector<Row> result  = parse(buffer, strlen(buffer));

  // print out result
  for(size_t r=0; r < result.size(); r++) {
    Row& row = result[r];
    for(size_t c=0; c < row.size() - 1; c++) {
      std::cout << row[c] << "\t";
    }
    std::cout << row.back() << std::endl;
  }
}
