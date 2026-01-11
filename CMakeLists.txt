cmake_minimum_required(VERSION 3.10) # 要求 CMake 的最低版本
set(CMAKE_BUILD_TYPE Debug)
project(TeslaLearning)               # 项目名字

#add_executable(my_tesla_app hello_Tesla.cpp log.cpp Math.cpp ) # 告诉它：用这两个文件生成一个叫 my_tesla_app 的程序
#add_executable(pointer_study pointer_test.cpp)
#add_executable(tesla_Car tesla_class.cpp Tesla.cpp)
#add_executable(smart_study smart_pointer.cpp)
#add_executable(int int.cpp log.cpp)
#add_executable(vect vector_test.cpp)
add_executable(tesla_fleet tesla_fleet.cpp Tesla.cpp)
add_executable(physics physics_test.cpp)
