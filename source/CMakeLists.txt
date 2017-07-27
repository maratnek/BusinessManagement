cmake_minimum_required(VERSION 2.8)
# project name
project(TESTBM)

#boost
# set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS regex program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_EXE main.cpp)

include_directories(bm)

add_executable(BusinessManagement ${SOURCE_EXE})

add_subdirectory(bm)

target_link_libraries(BusinessManagement bm ${Boost_LIBRARIES})
