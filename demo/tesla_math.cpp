#include<iostream>
#include<vector>
#include"Vector3.h"// 🚀 引用我们之前写的模板向量类

// 为了演示方便，我们先固定使用 float
typedef Vector3<float>Vec3;

class Matrix3x3{
    public:
   // 3x3 矩阵，存储在二维数组里
   float m[3][3];

    // 初始化：默认创建一个单位矩阵（对角线为1，相当于数学里的数字1）
    Matrix3x3(){
        for(int i=0;i<3;i++)
         
        for(int j=0;j<3;j++)
        m[i][j]=(i==j)?1.0f:0.0f;
    }
    // 【核心算法】矩阵乘以向量
    // 公式：结果向量的每一个分量 = 矩阵对应行 与 向量列 的点积

    Vec3 multiply(const Vec3 & v)const{
        return Vec3(
            m[0][0]*v.x+m[0][1]*v.y+m[0][2]*v.z,
            m[1][0]*v.x+m[1][1]*v.y+m[1][2]*v.z,
            m[2][0]*v.x+m[2][1]*v.y+m[2][2]*v.z
        );
    }
    // 🚀 运算符重载：让我们直接写 matrix * vector
    Vec3 operator*(const Vec3 & v)const{
        return multiply(v);
    }
};

int main(){
    // 1. 定义一个障碍物在车前方 (10, 0, 0)
    Vec3 obstaclePos(10,0,0);
    std::cout<<">> 障碍物原始坐标: "<<obstaclePos<<std::endl;

    // 2. 模拟车辆向左转弯 90 度 (旋转矩阵)
    // 这里的数学意义是：坐标系发生了变换

    Matrix3x3 rotate90;
    rotate90.m[0][0]=0;rotate90.m[0][1]=-1;// X 轴新映射
    rotate90.m[1][0]=1;rotate90.m[1][1]=0; // Y 轴新映射

    // 3. 计算旋转后的相对位置
    Vec3 newPos=rotate90*obstaclePos;
    std::cout<<">> 车辆转弯 90 度后，障碍物相对位置:"<<newPos<<std::endl;
    std::cout<<"(预期结果应该是: (0, 10, 0) - 即障碍物现在到了车的右侧)"<<std::endl;
    return 0;

}



