#include <iostream>
#include <vector>
#include <chrono> // 用于高精度计时
#include "Vector3.h"
#include "Tesla.h" // 假设 Matrix3x3 你已经整理进去了，或者直接写在上面

typedef Vector3<float>Vec3;
// 假设这是你刚才写的 Matrix3x3
class Matrix3x3 {
public:
    float m[3][3];
    Matrix3x3() { /* 初始化为单位阵 */ 
        for(int i=0; i<3; i++) for(int j=0; j<3; j++) m[i][j] = (i==j);
    }
    Vec3 operator*(const Vec3& v) const {
        return Vec3(
            m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z,
            m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z,
            m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z
        );
    }
};

int main(){
    const int POINT_COUNT=100000; // 模拟 10 万个感知点
    std::vector<Vec3>pointCloud;

    // 1. 初始化点云（模拟 5080 传回的原始数据）
    for(int i=1;i<POINT_COUNT;i++){
        pointCloud.push_back(Vec3(i*0.1f,5.0f,0.0f));
    }

    // 2. 定义旋转矩阵（转向 45 度）
    Matrix3x3 transfrom;
    float angle=0.707f;// sin(45) and cos(45)
    transfrom.m[0][1]=angle;transfrom.m[0][1]=-angle;
    transfrom.m[1][0]=angle;transfrom.m[1][1]=angle;

    std::cout<<"🚀 正在处理"<<POINT_COUNT<<"个点的坐标变换..."<<std::endl;

    // 3. 【高精度计时开始】
    auto strat=std::chrono::high_resolution_clock::now();

    // 批量计算逻辑
    for(auto&pt:pointCloud){
        pt=transfrom*pt;// 🚀 这里的 * 运算符是你刚才重载的
    }

    auto end=std::chrono::high_resolution_clock::now();
    // 【高精度计时结束】

    std::chrono::duration<double,std::milli>elapsed=end-strat;

    std::cout<<">> 处理完成！"<<std::endl;
    std::cout<<">> 9800X3D 耗时:"<<elapsed.count()<<"毫秒"<<std::endl;
    std::cout<<">> 平均每个点耗时:"<<(elapsed.count()*1000000)/POINT_COUNT<<"纳秒"<<std::endl;
    return 0;
}