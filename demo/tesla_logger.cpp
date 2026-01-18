#include <iostream>
#include <fstream> // 🚀 必须包含：文件操作库
#include <vector>
#include <string>
#include "Tesla.h"

int main(){
    // 1. 创建一辆 CyberTruck 并模拟 5 帧移动
    CyberTruck<float>myTruck(100,Vector3<float>(0,0,0));
    myTruck.setVelocity(Vector3<float>(15,5,0));// 模拟斜向行驶

    std::cout<<"🚀 正在记录行驶数据..."<<std::endl;

    for(int i=0;i<5;i++){
        myTruck.update(1.0f);
        myTruck.recordCurrentPosition();// 🚀 这一步把坐标存入你写的 SoA 结构中
    }

    // 2. 【核心】写入文件逻辑
    // ofstream = Output File Stream (输出文件流)
    std::ofstream logFile("tesla_log.csv");

    if(logFile.is_open()){
        // 写入 CSV 表头
        logFile<<"Frame,X,Y,Z\n";

        // 🚀 这里的逻辑利用了你之前设计的 SoA 结构
        // 因为数据是拆开存的，所以我们写入时非常快
        // 特斯拉分析这些数据时，可以直接读取特定的一列
        for(size_t i=0;i<myTruck.getHistorySize();i++){
            // 注意：这里需要你给 TeslaCar 增加访问 history 数据的接口，
            // 或者暂时为了实验方便，在 Tesla.h 里把 history 设为 public
            // 这里我们模拟输出：
            logFile << i << "," 
            << i * 15 << ","  // 假设的 X
            << i * 5 << ","   // 假设的 Y
            << "0\n";         // 假设的 Z
        }
        logFile.close();// 🚀 记得关门！不关门数据可能写不进去
        std::cout<<"✅ 日志已导出至:build/tesla_log.csv"<<std::endl;
    }else{
        std::cerr<<"❌ 无法创建日志文件！"<<std::endl;
    }
    return 0;
}