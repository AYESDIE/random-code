cmake_minimum_required(VERSION 3.13)
project(mlpacktesttest)

set(CMAKE_CXX_STANDARD 11)
find_library(ARMADILLO_LIBRARY_PATH armadillo HINTS /usr/lib)

add_executable(mt main.cpp)
target_link_libraries(mt ${ARMADILLO_LIBRARY_PATH})
