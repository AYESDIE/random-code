cmake_minimum_required(VERSION 3.10)
project(daalabtestpractice)

set(CMAKE_CXX_STANDARD 11)

add_executable(maxmatmul maxmatmul.cpp)

add_executable(lcs longestcommonsubseq.cpp)

add_executable(knapsack01 knapsack01.cpp)

add_executable(huffmancode huffmancode.cpp)

add_executable(dfs dfs.cpp)

add_executable(huffington test/hufftest.cpp)

add_executable(llcs test/lcs.cpp)

add_executable(ks01 test/ks01.cpp)