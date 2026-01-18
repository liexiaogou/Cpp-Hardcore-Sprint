#include<iostream>
#include<unordered_map>//这里的底层是哈希表，搜索速度极快
#include<string>
#include<memory>
#include"Tesla.h"

int main(){
     // 1. 定义一个以 VIN (字符串) 为 Key，车辆指针为 Value 的容器
     std::unordered_map<std::string,std::unique_ptr<TeslaCar<float>>> teslaRegistry;

     // 2. 注册车辆
     std::string vinl="TSLA_001";
     teslaRegistry[vinl]=std::make_unique<CyberTruck<float>>(100,Vector3<float>(0,0,0));

     std::string vin2="TSLA_002";
     teslaRegistry[vin2]=std::make_unique<TeslaCar<float>>("Model 3",100,Vector3<float>(10,0,0));

      // 3. 🚀 极致性能查找：不需要循环！
      std::string searchVin="TSLA_001";
      if(teslaRegistry.find(searchVin)!=teslaRegistry.end()){
      std::cout<<"找到车辆:"<<teslaRegistry[searchVin]->getModel()<<std::endl;
      }
      
      return 0;
}