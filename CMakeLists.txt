cmake_minimum_required(VERSION 3.15)
project(SearchTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchTree main.cpp Node.h Node.cpp Tree.cpp Tree.h Balance.h BalanceTree.h BalanceTree.cpp)