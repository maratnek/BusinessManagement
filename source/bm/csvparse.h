#ifndef _CSV_PARSE_H_
#define _CSV_PARSE_H_

#include <vector>
#include <string>

typedef std::vector<std::string> Row;
typedef std::vector<Row> VRow;

VRow parse(const char* data, unsigned int length);

VRow DownloadDepartment(const std::string& fn);

#endif // _CSV_PARSE_H_
