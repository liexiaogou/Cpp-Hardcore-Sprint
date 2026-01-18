cmake_minimum_required(VERSION 3.10) # 要求 CMake 的最低版本
set(CMAKE_BUILD_TYPE Debug)
project(TeslaLearning)               # 项目名字
find_package(OpenCV REQUIRED)# 1. 寻找 OpenCV 库
#add_executable(vision_study vision_test.cpp)# 2. 定义可执行文件
#add_executable(vision_logic vision_logic.cpp)
#target_link_libraries(vision_logic PRIVATE ${OpenCV_LIBS})
# 3. 🚀 关键：告诉编译器 OpenCV 的头文件在哪，并把库链接进去
#target_include_directories(vision_study PRIVATE ${OpenCV_INCLUDE_DIRS})
#target_link_libraries(vision_study PRIVATE ${OpenCV_LIBS})
#add_executable(my_tesla_app hello_Tesla.cpp log.cpp Math.cpp ) # 告诉它：用这两个文件生成一个叫 my_tesla_app 的程序
#add_executable(pointer_study pointer_test.cpp)
#add_executable(tesla_Car tesla_class.cpp Tesla.cpp)
#add_executable(smart_study smart_pointer.cpp)
#add_executable(int int.cpp log.cpp)
#add_executable(vect vector_test.cpp)
#add_executable(tesla_fleet tesla_fleet.cpp Tesla.cpp)
#add_executable(physics physics_test.cpp Tesla.cpp)
#add_executable(text text.cpp)
#add_executable(TS tesla_fleet.cpp)
#add_executable(mt_tesla multithread_tesla.cpp)
#target_link_libraries(mt_tesla  PRIVATE  pthread) 
#add_executable(map_tesla fleet_map.cpp Tesla.cpp)
#add_executable(BMS tesla_bms_race.cpp)
#add_executable(ATO tesla_bms_atomic.cpp)
#add_executable(AI tesla_pipeline.cpp)
#add_executable(33 tesla_logger.cpp)
#add_compile_options(-03)
#add_executable(vision_conv vision_conv.cpp)
#target_include_directories(vision_conv PRIVATE ${OpenCV_INCLUDE_DIRS})
#target_link_libraries(vision_conv PRIVATE ${OpenCV_LIBS})

add_executable(vision_sobel vision_sobel.cpp)
target_include_directories(vision_sobel PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(vision_sobel PRIVATE ${OpenCV_LIBS})
add_executable(multi_cam tesla_multi_cam.cpp)
target_link_libraries(multi_cam PRIVATE ${OpenCV_LIBS} pthread)
add_compile_options(-O3 -march=native)