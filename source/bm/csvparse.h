#ifndef _CSV_PARSE_H_
#define _CSV_PARSE_H_

#include <vector>
#include <string>

typedef std::vector<std::string> Row;
std::vector<Row> parse(const char* data, unsigned int length);

void TestCSV(const std::string& fn);

#endif // _CSV_PARSE_H_
