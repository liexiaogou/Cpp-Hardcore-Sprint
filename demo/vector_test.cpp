#include<iostream>
#include<vector>
#include<string>
int main(){
     // 1. 定义一个可以自动伸缩的“特斯拉车辆列表”
     std::vector<std::string>carQueue;

     //2. 动态添加数据
     carQueue.push_back("Model 3");
     carQueue.push_back("Model Y");
     carQueue.push_back("CyberTruck");

     std::cout<<"当前充电站等待车辆数:"<<carQueue.size()<<std::endl;

     //3.遍历列表
     for(const std::string& car:carQueue){
        std::cout<<"正在为"<<car<<"充电:"<<std::endl;
     }
     return 0;

}