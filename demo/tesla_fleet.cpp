#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include "Tesla.h"
int main(){
   // 1. 初始化随机数种子（虽然这次我们主要用物理计算）
      std::srand(static_cast<unsigned int>(std::time(0)));

     // 2. 创建单车模拟：CyberTruck
     // 参数：电量(100), 位置(0,0,0) -> 匹配 CyberTruck(int b, Vector3<T> startPos)
     auto myTruck = std::make_unique<CyberTruck<float>>(100, Vector3<float>(0, 0, 0));
     myTruck->setVelocity(Vector3<float>(20,0,0));// 设定速度 20cm/s
     Vector3<float> wallPos(100,0,0);  // 墙在 100cm 处


     std::cout<<"--- 特斯拉自动泊车系统启动 ---"<<std::endl;
     std::cout<<"目标墙壁位置: "<<wallPos<<"\n"<<std::endl;

     // 5. 模拟 6 秒钟的行驶过程
     for(int sec=1; sec<=6;sec++){
        try{
          std::cout << "\n[时间: " << sec << "s]" << std::endl;
         // A. 物理移动：更新坐标 (P = P + V * dt)
         myTruck->update(1.0f);
         myTruck->showStatus();

          float dist = myTruck->getFilteredDistance(wallPos); // 几何感知+滤波
          std::cout << ">> [决策层] 最终采用距离: " << dist << "cm" << std::endl;
          // C. 决策逻辑：如果距离小于 30cm，触发紧急制动

          if(dist<30.f){
            myTruck->brake();
          }
          else{
            myTruck->drive();
          } std::cout<<"-----------------------"<<std::endl;
        }
        catch(const std::exception & e){// 🚀 如果上面出事了，这里负责接住
            std::cout<< "🚨 [系统熔断] 捕捉到严重错误: "<<e.what()<<std::endl;
            std::cout<< ">> 正在切换至【冗余传感器模式】或强制停车..."<<std::endl;
             myTruck->brake(); 
        }
         
     }
   
    
    std::cout<<"--- 正在初始化特斯拉全球管理系统---"<<std::endl;
    std::vector<std::unique_ptr<TeslaCar<float>>> fleet;
     //创建一个存储【指向车的智能指针】的容器
    // 这样 vector 存的是地址，而不是整辆车，效率极高！

    // 2. 使用 std::make_unique 创建车，并用 std::move 移交给 vector
    // std::move 的意思是：把这辆车的所有权“过户”给 vector，而不是复制它
    fleet.push_back(std::make_unique<TeslaCar<float>>("Model S",100,Vector3<float>(0,0,0)));
    fleet.push_back(std::make_unique<TeslaCar<float>>("Model 3",80,Vector3<float>(10,0,0)));
    fleet.push_back(std::make_unique<CyberTruck<float>>(100, Vector3<float>(100, 100, 0)));
    
    // 3. 遍历时也要注意
    //int radarDate[5]={100,50,15,80,200};

    // 使用 const auto& car 拿到指针的引用
    for (const auto& car : fleet) {
    std::cout << "--------------------------------" << std::endl;
    
    // 1. 先显示当前车辆状态（位置、速度）
    car->showStatus(); 

    // 2. 获取实时传感器数据
    auto data = car->getRawSensorData();

    if (!data.has_value()) {
        std::cout << "⚠️ [紧急警告] " << car->getModel() << " 传感器硬件掉线！" << std::endl;
        car->brake(); 
    } 
    else {
        float currentDist = data.value(); // 获取随机生成的距离
        std::cout << ">> 实时感知距离: " << currentDist << "cm" << std::endl;

        // 3. 统一决策中心
        if (currentDist < 80) {
            car->brake(); // 发现危险
        } else {
            car->drive(); // 路径安全
        }
    }
}
    return 0;
}