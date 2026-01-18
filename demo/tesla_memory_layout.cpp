#include <iostream>
#include <vector>
#include <chrono>
// 1. AoS 布局 (我之前的写法)
struct Vec3_AoS
{
    float x,y,z;
};
// 2. SoA 布局 (工业级优化写法)
struct Vec3_SoA{
    std::vector<float>x;
    std::vector<float>y;
    std::vector<float>z;

    Vec3_SoA(int size):x(size),y(size),z(size){}
};

int main(){
    const int N=1000000;// 增加到 100 万个点，拉开差距

    // 初始化 AoS
    std::vector<Vec3_AoS>aos_date(N,{1.0f,2.0f,3.0f});

    // 初始化 SoA
    Vec3_SoA soa_date(N);
    for(int i=0;i<N;i++){
        soa_date.x[i]=1.0f;
        soa_date.y[i]=2.0f;
        soa_date.z[i]=3.0f;
    }

    // --- 测试 AoS 性能 ---
    auto s1=std::chrono::high_resolution_clock::now();
    for(int i=0;i<N;++i){
        aos_date[i].x*=2.0f;
        aos_date[i].y*=2.0f;
        aos_date[i].z*=2.0f;
    }
    auto e1=std::chrono::high_resolution_clock::now();

    // --- 测试 SoA 性能 ---
    auto s2=std::chrono::high_resolution_clock::now();
    // 🚀 这里 SoA 可以被编译器极速向量化
    for(int i=0;i<N;++i)soa_date.x[i]*=2.0f;
    for(int i=0;i<N;++i)soa_date.y[i]*=2.0f;
    for(int i=0;i<N;++i)soa_date.z[i]*=2.0f;
    auto e2=std::chrono::high_resolution_clock::now();

    std::chrono::duration<double,std::milli>t1=e1-s1;
    std::chrono::duration<double,std::milli>t2=e2-s2;

    std::cout<<"AoS (普通版) 耗时:"<<t1.count()<<"ms"<<std::endl;
    std::cout<<"SoA (普通版) 耗时:"<<t2.count()<<"ms"<<std::endl;
    return 0;
}
