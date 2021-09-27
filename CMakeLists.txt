cmake_minimum_required(VERSION 3.20)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

## 测试 练习使用
add_executable(demo  demo.cpp)


##  linear 线性表
### 顺序表
add_executable(sequence_list Linear_list/sequence_list.cpp )
add_executable(sequence_operate Linear_list/sequence_list.cpp Linear_list/sequence_operate.cpp Linear_list/doublle_link_operate.cpp)

### 链表
add_executable(link_list Linear_list/link_list.cpp )
add_executable(link_operate  Linear_list/link_operate.cpp)
####双向链表
add_executable(double_link  Linear_list/double_link.cpp)
add_executable(double_link_operate  Linear_list/doublle_link_operate.cpp)



## 栈与队列

### 栈
#### 顺序栈
add_executable(sequence_link  stack/sequence_stack.cpp)

#### 链栈
add_executable(link_stack stack/link_stack.cpp)

### 队列
#### 顺序队列
add_executable(sequence_queue queue/sequence_queue.cpp)
#### 循环队列
add_executable(loop_queue queue/loop_queue.cpp)