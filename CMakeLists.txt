cmake_minimum_required(VERSION 3.7)
project(CodeJam)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cipher.cpp)
add_executable(CodeJam ${SOURCE_FILES})