#include<iostream>
#include<thread> // 🚀 多线程核心库
#include<chrono>// 用于模拟耗时操作
#include"Tesla.h"

// 模拟感知线程：不断读取传感器
void sensorTask(std::string name){
    for(int i=0;i<5;i++){
        std::cout<<"[线程:"<<name<<"]正在扫描雷达数据..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 模拟硬件延迟 0.5秒
    }
}

// 模拟动力线程：控制电机
void driveTask(std::string name){
    for(int i=0;i<5;i++){
        std::cout<<"[线程"<<name<<"]电机正在输出动力..."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));// 模拟电机响应 0.7秒
    }
}

int main(){
    std::cout<<"--- 特斯拉双核系统启动 ---"<<std::endl;

    // 1. 创建并启动线程
    //    CPU会立刻分配两个不同的物理核心来跑这两个函数
    std::thread t1(sensorTask,"Perception_Core");
    std::thread t2(driveTask,"Actuator_Core");
     
    // 2. 主线程继续干活
    std::cout<<"[主线程] 正在更新仪表盘显示..."<<std::endl;

    // 3. 等待子线程结束（如果不join，主线程跑完程序会直接崩溃）
    t1.join();
    t2.join();

    std::cout<<"--- 所有系统安全关闭 ---"<<std::endl;
    return 0;
}

