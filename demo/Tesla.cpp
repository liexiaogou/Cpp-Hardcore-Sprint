/* #include<iostream>
#include"Tesla.h"
#include<string>
#include<memory> 
#include <cstdlib>// 用于产生随机数模拟噪声
TeslaCar::TeslaCar(std::string m,int b,Vector3 startPos)
    :model(m),batteryLevel(b),position(startPos),velocity(0,0,0),sensorDate(nullptr){
    std::cout << "--- " << model << " 已启动，初始位置: " << position << " ---" << std::endl;
    }
 // 完善析构函数实现      
TeslaCar::~TeslaCar(){
    std::cout<<"》》"<<model<<"已安全退出。"<<std::endl;
}

// 🚀 核心物理计算：P_new = P_old + V * dts
void TeslaCar::updatePosition(float deltaTime){
    position=position+(velocity * deltaTime);
}
void TeslaCar::setVelocity(Vector3 newVal){
    velocity=newVal;
}

//检测速度
void TeslaCar::showStatus() {
    std::cout << "[" << model << "] 位置: " << position << " | 速度: " << velocity << std::endl;
}

//刹车系统
void TeslaCar::brake() {
    velocity = Vector3(0, 0, 0); // 物理意义：刹车就是速度归零
    isEmergencyStop=true;// 🚀 刹车时锁死状态
    std::cout << "🚨 [自动驾驶预警] " << model << " 已触发紧急制动！" << std::endl;
}
std::optional<int>TeslaCar::getRawSensorData(){
    int chance=std::rand()%100;// 产生 0-99 的随机数

    if(chance<10){// 模拟 10% 的概率传感器硬件故障，完全没数据
        
        return std::nullopt; // 返回“空”
    }
    // 模拟正常读数
    //原代码会只提示最近障碍物15CM return std::rand()%200;// 返回 0-199 之间的模拟距离
    return 100 + (std::rand() % 200); // 改成这样（生成 100 到 300 之间的数，肯定不会触发 80cm 的刹车）：
}


float TeslaCar::getFilteredDistance(Vector3 targetPos){
     // 1. 计算当前真实距离（含模拟噪声）.计算理论上的“上帝视角”真实距离
     float rwaDist = ( targetPos - position ).length();

    // 2. 🚀 模拟传感器噪声 (Sensor Noise)
    // 现实中的显卡处理图像时，因为光影跳动，数据会有误差
    // 我们产生一个 -5cm 到 +5cm 之间的随机波动 《已做修改》

    // 🚀 模拟一个极端的硬件错误：10% 概率传感器损坏返回负数
    float noisyDist=rwaDist+(std::rand()%11-5);
    if (std::rand() % 100< 10)
    {
        noisyDist=-999.0f;// 故意模拟一个物理上不可能的负距离
    }
    // --- 【新增：异常抛出逻辑】 ---
    // 如果距离是负数，这不属于噪声，这是系统故障！
    if(noisyDist<0&& noisyDist!=-999.0f){
         // 我们不返回这个数，而是“抛出一个警报”
         throw std::runtime_error("传感器读数异常：检测到物理不可能的负距离!");
    }

      //  3. 滑动窗口管理 (Sliding Window Logic)”
      sensorHistory.push_back(noisyDist);// 把带噪声的新数据塞进管道右端

      if(sensorHistory.size()>filterSiz){
        sensorHistory.pop_front(); // // 如果管道里的数据超过 5 个，就把最左边最老的数据扔掉
      }
      // 3. 计算平均值（滤波核心
       // 把管道里现有的 5 个数据加起来求平均，抹平单次跳动的误差）
      float sum=0; 
      for(float d:sensorHistory){
              sum+=d;
      }
      float filteredDist=sum/sensorHistory.size();

      std::cout<<">> [感知层] 原始读数:"<<noisyDist<<"cm | 滤波平滑后: " <<filteredDist<<"cm"<<std::endl;
      
      return filteredDist;

}



std::string TeslaCar::getModel() const {
    return model; 
}
//正常行驶系统
void TeslaCar::drive(){
    if(isEmergencyStop){
        std::cout<<"❌"<<model<<"驱动系统已锁定，请人工介入."<<std::endl;
        return;
    }

    std::cout << ">> " << model << " 正在标准模式下行驶。" << std::endl;
}

float TeslaCar::getDistanceToTarget(Vector3 targetPos){
    // 🚀 核心数学：向量减法得到相对位移，再求模长
    // 这就是你在 Vector3 里重载的 operator- 和 length()
    Vector3 relativePos=targetPos - position;
    return relativePos.length();
}

// 子类 CyberTruck 的暴力行驶
// 💡 注意：这里必须加上 CyberTruck:: 
void CyberTruck::drive() {
    if(isEmergencyStop){
        std::cout << "❌ [" << model << "] 紧急制动保护中，禁止越野。" << std::endl;
        return;
    }
    std::cout << "🦾 [" << model << "] 开启外骨骼防御，正在 4x4 暴力越野！" << std::endl;
}
//检测周围距离
void TeslaCar::scanEnvironment(int * ptr,int size){
    std::cout<<"📡"<<model<<" 正在扫描周围环境..."<<std::endl;

        int getRawSensorData =*ptr;
        for(int i=1;i<size;i++){
            if(*(ptr+i)<getRawSensorData){
                getRawSensorData=*(ptr+i);
            }
        }
         std::cout<<">> 最近障碍物距离:"<<getRawSensorData<<"cm"<<std::endl;
           // 决策层：根据感知结果下达指令
         if(getRawSensorData<80){
            brake();// 直接调用自己的成员函数
         }else{
            std::cout<<">> 路径安全，继续巡航。"<<std::endl;
         }
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

 