#include<iostream>
#include<thread>
#include<atomic>// 🚀 引入原子库

// 🚀 将 int 换成 std::atomic<int>
// 这就像是给变量穿上了一层纳米装甲
std::atomic<int>batteryLevel(5000);

void motorTask(){
    for(int i=0;i<1000000;i++){
        batteryLevel--;//🚀 现在的 -- 是原子性的，不需要加锁！
    }
}

void regenTask(){
    for(int i=0;i<1000000;i++){
        batteryLevel++;//🚀 现在的 -- 是原子性的，不需要加锁！
    }
}

int main(){
    std::cout<<"--- 正在进行原子级并发测试 ---"<<std::endl;

    std::thread t1(motorTask);
    std::thread t2(regenTask);

    t1.join();
    t2.join();

    std::cout<<"最终计算电量: "<<batteryLevel<<std::endl;
    std::cout << "理论预期值: 5000" << std::endl;

    if(batteryLevel !=5000){
        std::cout<<"🚩 捕捉到 Race Condition!数据已损坏。"<<std::endl;
    }else{
        std::cout<<"✅ 竟然没出错？再运行一次试试！"<<std::endl;
    }

    return 0;
}
