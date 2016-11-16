cmake_minimum_required(VERSION 3.6)
project(HashTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp HashTable.cpp LinkedList.cpp HashTable.h LinkedList.h)
add_executable(HashTable ${SOURCE_FILES})