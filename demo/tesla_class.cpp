#include<iostream>
#include<string>
#include"Tesla.h"

/* class TeslaCar {
private: // 🔒 只有类内部的函数能改这些，外部程序只能看，不能直接改
    std::string model;
    int batteryLevel;
    float speed;
    public:
     // 构造函数
    TeslaCar(std::string m,int b):model(m),batteryLevel(b),speed(0.0f){
        std::cout<<"--"<<model<<"系统启动"<<std::endl;
    }

    // 紧急制动行为
    void brake(){
        speed=0;
        std::cout<<"🚨 [自动驾驶预警]"<<model<<"检测到危险！已触发紧急制动！"<<std::endl;
    }

    // 【核心黑科技】感知环境接口
    // ptr: 传入雷达数组的指针, size: 传感器数量
    void scanEnvironment(int*ptr,int size){
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
    } */
    // 1. 构造函数 (Constructor)：就像工厂的生产线
    // 只要你写 TeslaCar myCar("Model S", 90); 它就会自动设置这些初值
    /* TeslaCar(std::string m,int b){
        model=m;
        if (b>100)//安全检查：电量最高 100
        {
           batteryLevel=100;
        }
        else if (b<0)
        {
            batteryLevel=0;
        }else{
            batteryLevel=b;
            speed=0.0f;
            std::cout<<"--- 一辆新的"<<model<<" 已下线，电量:"<<batteryLevel<<"%"<<std::endl;
        }
    } */
    // 2. 只读接口 (Getter)：允许外部查看电量，但不准改
    /* int getBattery(){return batteryLevel;}
    
    void drive(){
        if (batteryLevel>=5)
        {
           speed=60.f;
           batteryLevel-=5;
           std::cout<<model<<"正在巡航，电量剩余:"<<batteryLevel<<"%"<<std::endl;
        }else{
            std::cout<<"警告：电量过低，禁止启动！"<<std::endl;
        }   
    } 
};*/
int main(){
   /*  // 现在创建对象更简单了，直接传参数
    TeslaCar myCry("CyberTruck",80);
    // 尝试直接修改会报错：myCar.batteryLevel = 100; // 这一行现在会变红报错

    myCry.drive();
    std::cout<<"当前仪表盘电量:"<<myCry.getBattery()<<"%"<<std::endl;

    return 0; */

      // 1. 初始化车辆
    TeslaCar myTruck("CyberTruck",90);

     // 2. 模拟雷达传感器传回的 5 个数据
    int radarData[5]={150,80,15,200,45};

    myTruck.scanEnvironment(radarData,5);
}