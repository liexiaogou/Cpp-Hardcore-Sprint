#include<iostream>
#include<memory> //🚀 必须包含这个头文件
class RadarSensor {
    public:
    RadarSensor(){std::cout<<"📡 雷达硬件已启动"<<std::endl;}
    ~RadarSensor(){std::cout<<"💀 雷达硬件已安全断电"<<std::endl;}
    void scan(){std::cout<< ">> 正在扫描 360 度环境数据..."<<std::endl;}
};
int main(){
    std::cout<<"--- 智能指针实验开始 ---"<<std::endl;
    {
         // 1. 创建一个智能指针，指向一个新的 RadarSensor 对象
        // 不需要写 new，不需要写 delete！

        std::unique_ptr<RadarSensor>myRadar=std::make_unique<RadarSensor>();

        myRadar->scan();// 像普通指针一样使用 -> 调用成员
    }
    // <--- 重点！当程序运行到这里，myRadar 超出了大括号范围
      // 它会自动调用 RadarSensor 的析构函数，不需要你写 delete！
      std::cout<<"--- 实验结束 ---"<<std::endl;
      return 0;
}