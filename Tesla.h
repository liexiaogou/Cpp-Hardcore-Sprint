#pragma once
#include <string>
#include <memory>
#include <iostream>

class TeslaCar {
protected: // 🛡️ 允许子类访问
    std::string model;
    int batteryLevel;
    float speed;
    float x, y, z;
    TeslaCar(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
    std::unique_ptr<int[]> sensorDate;

public:
    TeslaCar(std::string m, int b);
    virtual ~TeslaCar() { std::cout << ">> " << model << " 已安全退出。" << std::endl; }

    virtual void drive(); // 🚀 只写一遍声明！
    void brake();
    void scanEnvironment(int* ptr, int size);
};

// 子类 CyberTruck
class CyberTruck : public TeslaCar {
public:
    CyberTruck(int b) : TeslaCar("CyberTruck", b) {}
    
    // 🚀 只声明，不在这里写 { } 里的内容
    void drive() override; 
};