cmake_minimum_required(VERSION 3.20)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

add_executable(sequence_list Linear_list/sequence_list.cpp)

add_executable(Link_list  Linear_list/link_list.cpp demo.cpp)

add_executable(demo  demo.cpp)
