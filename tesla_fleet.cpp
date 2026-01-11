#include<iostream>
#include<memory>
#include<vector>
#include"Tesla.h"

int main(){
      // 1. 关键：创建一个存储【指向车的智能指针】的容器
    // 这样 vector 存的是地址，而不是整辆车，效率极高！
    std::vector<std::unique_ptr<TeslaCar>> fleet;

    std::cout<<"--- 正在初始化特斯拉全球管理系统---"<<std::endl;

    // 2. 使用 std::make_unique 创建车，并用 std::move 移交给 vector
    // std::move 的意思是：把这辆车的所有权“过户”给 vector，而不是复制它
    fleet.push_back(std::make_unique<TeslaCar>("Model S",100));
    fleet.push_back(std::make_unique<TeslaCar>("Model 3",80));
    fleet.push_back(std::make_unique<CyberTruck>(100));
    

    // 3. 遍历时也要注意
    int radarDate[5]={100,50,15,80,200};

    // 使用 const auto& car 拿到指针的引用
    for(const auto&car:fleet){
    // 因为 car 是个指针，所以调用函数要用 ->
        car->drive();
    }
    return 0;
}