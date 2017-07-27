cmake_minimum_required(VERSION 2.8)
# project name
project(BusinessManagement)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_LIB business-management.cpp cmdline.cpp csvparse.cpp)

add_library(bm STATIC ${SOURCE_LIB})
