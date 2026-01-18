#pragma once
#include <string>
#include <memory>
#include <iostream>
#include"Vector3.h"
#include<optional>// 用于产生随机数模拟噪声
#include<deque>
#include<ctime>
template<typename T>
class TeslaCar {
protected: // 🛡️ 允许子类访问
    std::string model;
    int batteryLevel;
    Vector3<T>position;//🚀 现在位置的精度由 T 决定
    Vector3<T> velocity;
    bool isEmergencyStop =false;// 🚀 新增：是否处于紧急停止状态

    std::deque<T>sensorHistory; // 存储最近几帧的距离数据
    const int filterSize=3;      // 滤波窗口大小

    //Date Time 1.18
    // 🚀 这就是你选择的 SoA 布局：把 X, Y, Z 坐标分三个数组存
    // 这种布局对 5080 显卡和 9800X3D 的并行运算极度友好
    struct TrajectorySoA {
        std::vector<T>x_path;
        std::vector<T>y_path;
        std::vector<T>z_path;
    }history;

public:
    // 🚀 构造函数顺序：名字(m), 电量(b), 位置(startPos)
    TeslaCar(std::string m,int b,Vector3<T>startPos)
    :model(m),position(startPos),batteryLevel(b),velocity(0,0,0),isEmergencyStop(false){
        std::cout<<"---"<<model<<"(驱动已就绪)"<<std::endl;
    }
     virtual ~TeslaCar() {
         std::cout << ">> " << model << " 已安全退出。" << std::endl;
     }
       // 只读接口
    std::string getModel() const { return model; }
     // 物理更新逻辑
    void update(T dt){
        if(isEmergencyStop)return;
        position=position+(velocity*dt);
    }
    void setVelocity(Vector3<T> v){velocity=v;}
     
     virtual void showStatus(){ // 状态显示
        std::cout<<"["<<model<<"]位置:"<<position<<"|速度:"<<velocity<<std::endl;
     }
       
    void brake(){ // 刹车系统
        velocity=Vector3<T>(0,0,0);
        isEmergencyStop=true;
        std::cout<<"🚨"<<model<<" [紧急制动] 物理锁定已启动！"<<std::endl;
    }
    virtual void drive(){
        if(isEmergencyStop){
             std::cout << "❌ " << model << " 已锁定，无法巡航。" << std::endl;
        }
        std::cout<<">>"<<model<<"正在标准巡航"<<std::endl;
    }


    // 核心感知：带滤波的距离计算
     T getFilteredDistance(Vector3<T> target) {
         // 1. 计算真实距离并模拟一点噪声
       T rawDist  = (target - position).length();
       T noisyDist = rawDist  + (static_cast<T>(std::rand() % 10) - 5.0f);

        sensorHistory.push_back(noisyDist);
        if (sensorHistory.size() > filterSize) sensorHistory.pop_front();

    
        T sum = 0; // 3. 计算平均值
        for (T d : sensorHistory) sum += d;
         return (sensorHistory.empty()) ? 0 : (sum / sensorHistory.size());
        
    }
        
        std::optional<T> getRawSensorData() { // 模拟读取传感器
        if ((std::rand() % 100) < 10) return std::nullopt; // 模拟 10% 掉线
        return static_cast<T>(std::rand() % 200);
    }

    //Date Time 1.18
    // 🚀 核心功能：记录当前位置到 SoA 历史中
    void recordCurrentPosition(){
        history.x_path.push_back(position.x);
        history.y_path.push_back(position.y);
        history.z_path.push_back(position.z);
    }
    size_t getHistorySize()const{return history.x_path.size();}
};

// 🚀 2. 子类 CyberTruck 也必须是模板类，并继承自 TeslaCar<T>
template<typename T>
class CyberTruck : public TeslaCar<T> {
public:
// 🚀 这里的调用顺序必须和父类一致：(名字, 电量, 位置)
    CyberTruck(int b, Vector3<T> startPos)  
    :TeslaCar<T>("CyberTruck", b, startPos) {}


     // 重写行驶函数
    void drive() override {
        if (this->isEmergencyStop) {
             std::cout << "❌ [" << this->model << "] 紧急保护中，禁止越野。" << std::endl;
            return;
        }
         std::cout << "🦾 [" << this->model << "] 开启外骨骼防御，正在 4x4 暴力越野！" << std::endl;
        
    }
};
