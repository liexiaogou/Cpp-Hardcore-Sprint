#include<iostream>
#include<vector>
#include<algorithm>// 🚀 包含 C++ 标准算法库
#include<memory>
#include"Tesla.h"

int main(){
    // 1. 模拟一个大型车队
    std::vector<std::unique_ptr<TeslaCar<float>>>fleet;
    fleet.push_back(std::make_unique<TeslaCar<float>>("Model 3", 100, Vector3<float>(0,0,0)));
    fleet.push_back(std::make_unique<TeslaCar<float>>("Model S",20,Vector3<float>(10,10,0)));// 电量低
    fleet.push_back(std::make_unique<TeslaCar<float>>("Model Y",5,Vector3<float>(50,50,0)));// 电量极低

    std::cout<<"--- 特斯拉云端数据分析中心 ---"<<std::endl;

    // 2. 🚀 使用 Lambda 表达式找出所有“低电量（< 10%）”的车辆
    // 语法解释：[ ] 捕获变量，( ) 参数，{ } 函数体
    int lowBatterLimit=10;

    // std::count_if 是标准库里的“计数器”
    int dangerCount=std::count_if(fleet.begin(),fleet.end(),[lowBatterLimit](const auto& car){
    // 这里假设你在 Tesla.h 里写了 getBattery() 函数
    // 为了演示，我们直接写判断逻辑
    return true;
    });

    // 3. 🚀 另一个 Lambda 实验：打印所有 Model 3
    std::for_each(fleet.begin(),fleet.end(),[](const auto& car){
        if(car->getModel()=="Model 3"){
            std::cout<<"[找到目标] 正在监控 Model 3 的实时数据..."<<std::endl;
        }
    });
    return 0;
}