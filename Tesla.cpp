#include<iostream>
#include"Tesla.h"
#include<string>
#include<memory> 
TeslaCar::TeslaCar(std::string m,int b):model(m),batteryLevel(b),speed(0.0f){
       std::cout << "--- " << model << " 系统启动 ---" << std::endl;
        
}
void TeslaCar::brake(){
        speed=0;
        std::cout<<"🚨 [自动驾驶预警]"<<model<<" 已停车！(来自 Tesla.cpp 的逻辑)"<<std::endl;
}
void TeslaCar::scanEnvironment(int * ptr,int size){
    std::cout<<"📡"<<model<<" 正在扫描周围环境..."<<std::endl;

        int minDistance =*ptr;
        for(int i=1;i<size;i++){
            if(*(ptr+i)<minDistance){
                minDistance=*(ptr+i);
            }
        }


         std::cout<<">> 最近障碍物距离:"<<minDistance<<"cm"<<std::endl;

           // 决策层：根据感知结果下达指令
         if(minDistance<20){
            brake();// 直接调用自己的成员函数
         }else{
            std::cout<<">> 路径安全，继续巡航。"<<std::endl;
         }
}
void TeslaCar::drive(){
    std::cout << ">> " << model << " 正在标准模式下行驶。" << std::endl;
}
// 子类 CyberTruck 的暴力行驶
// 💡 注意：这里必须加上 CyberTruck:: 
void CyberTruck::drive() {
    std::cout << "🦾 [" << model << "] 开启外骨骼防御，正在 4x4 暴力越野！" << std::endl;
    batteryLevel -= 10;
}
void temporaryCalculate(){
     // 1. 借钱（申请堆内存）
     int*date=new int[1000];

     // 2. 花钱（执行计算逻辑）
    // ... 对 data 进行处理 ...
     
    // 3. 还钱（释放内存）
    delete[]date;
}// 函数结束，data 这个指针变量（地址纸条）消失了，但如果不 delete，那 1000 个内存抽屉就永远被霸占了。
/* TeslaCar::~TeslaCar(){
     // 如果你在构造函数里用了 new，这里就必须 delete
     if(sensorDate!=nullptr){
        delete[]sensorDate;
     }
     std::cout<<"析构函数被调用：内存已释放，系统安全关闭。"<<std::endl;
} */