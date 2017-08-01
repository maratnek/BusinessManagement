cmake_minimum_required(VERSION 2.8)
# project name
project(BusinessManagement)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_LIB
    business-management.cpp
    differents-employee.cpp
    cmdline.cpp
    csvparse.cpp
    employee.cpp
    task.cpp
    director.cpp
  )


set(HEADER_LIB 
	business-management.h
    differents-employee.h
    cmdline.h
    csvparse.h
    employee.h
    task.h
    director.h
  )

add_library(bm STATIC  ${HEADER_LIB} ${SOURCE_LIB})
