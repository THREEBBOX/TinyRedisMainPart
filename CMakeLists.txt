cmake_minimum_required(VERSION 3.16)
project(TinyRedis)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinyRedis main.cpp sds.cpp sds.h adlist.cpp adlist.h)
add_executable(sds test.cpp)