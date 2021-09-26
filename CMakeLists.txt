cmake_minimum_required(VERSION 3.20)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)


####  linear 线性表
add_executable(sequence_list Linear_list/sequence_list.cpp)

add_executable(sequence_operate Linear_list/sequence_operate.cpp)




add_executable(demo  demo.cpp)
