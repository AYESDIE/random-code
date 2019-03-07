cmake_minimum_required(VERSION 3.10)
project(rx)

find_library(BOOST_LIBRARY_PATH boost_serialization HINTS /usr/lib)
set(CMAKE_CXX_STANDARD 11)

add_executable(rx main.cpp)
target_link_libraries(rx ${BOOST_LIBRARY_PATH})
