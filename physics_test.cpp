#include<iostream>
#include<cmath>//引入数学库，计算平方根

class Vector3{
    public:
      float x, y, z;

      Vector3(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}
      
    // 【核心黑科技】运算符重载：重载减法符号 "-"
    // 这允许你直接写 vec1 - vec2
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    // 计算向量的长度（也就是距离）
    float length() const{
        return std::sqrt(x*x+y*y+z*z);
    }
    void print()const{
        std::cout<<"("<<x<<","<<y<<","<<z<<")"<<std::endl;
    }
};

int main(){

    

    // 模拟：特斯拉在原点 (0,0,0)，障碍物在 (10, 10, 5)
    Vector3 teslaPos(0,0,0);
    Vector3 obstaclePos(10,10,5);

     // 🚀 像数学一样运算！计算相对位置向量
     Vector3 relativePos=obstaclePos-teslaPos;

     std::cout<<"障碍物相对位置:";
     relativePos.print();

     //计算直线距离
     float distance=relativePos.length();
     std::cout<<"直线距离"<<distance<<"cm"<<std::endl;

     if(distance<20.0f){
        std::cout<<"🚨 警报：空间距离过近！"<<std::endl;
     }
     return 0;
}