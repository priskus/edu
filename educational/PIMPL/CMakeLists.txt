cmake_minimum_required(VERSION 3.21)
project(PIMPL)

set(CMAKE_CXX_STANDARD 20)

add_executable(PIMPL main.cpp src/myclass.cpp src/myclassimpl.cpp)
