cmake_minimum_required(VERSION 3.16)
project(TinyRedis)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinyRedis main.cpp sds.cpp sds.h)
add_executable(sds sds.cpp sds.h)