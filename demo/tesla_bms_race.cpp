#include<iostream>
#include<thread>
#include<vector>
#include<mutex>// 🚀 引入锁库

int batteryLevl=5000;// 共享的全局变量：电量
std::mutex batteryMutex;//🚀 创建一把名为“电池锁”的锁

// 模拟电机耗电
void motorTask(){
    for(int i=0;i<1000000;i++){
        // 🔒 就像进厕所要锁门一样
        // lock_guard 在创建时自动加锁，出大括号时自动解锁
        std::lock_guard<std::mutex>lock(batteryMutex);
        batteryLevl--;// 🚀 没有任何保护，直接修改内存
    }
}

// 模拟动能回收充电
void regenTask(){
    for(int i=0;i<1000000;i++){
        std::lock_guard<std::mutex>_IO_lock_t(batteryMutex);
        batteryLevl++;//🚀 没有任何保护，直接修改内存
    }
}

int main(){
    batteryLevl = 5000;

    std::cout<<"--- 正在进行百万级并发压力测试 (无锁模式) ---"<<std::endl;

    std::thread t1(motorTask);
    std::thread t2(regenTask);

    t1.join();
    t2.join();

    std::cout<<"最终计算电量: "<<batteryLevl<<std::endl;
    std::cout << "理论预期值: 5000" << std::endl;

    if(batteryLevl !=5000){
        std::cout<<"🚩 捕捉到 Race Condition!数据已损坏。"<<std::endl;
    }else{
        std::cout<<"✅ 竟然没出错？再运行一次试试！"<<std::endl;
    }
    return 0;
}