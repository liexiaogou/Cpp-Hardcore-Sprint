#include<iostream>
void WrongSwap(int a,int b);
void RealSwap(int*a,int*b);
void ReferenceSwap(int&a,int&b);
int FindMinDistance(int* ptr, int size) 
{

    int minVal=*ptr;// 先假设第一个是最短的

    for(int i=1;i<size;i++){
     // 使用指针算术移动到下一个位置
     if (*(ptr+i)<minVal)
     {
        minVal=*(ptr+i);
     }
     
    }
    return minVal;
}
int main(){
    /* 
    int val=100;

     // 1. 声明一个指针 p，它指向一个整数
    // &val 意思是：把 val 的地址拿出来，塞给 p
    int*p=&val;

    std::cout<<"变量val的值是:"<<val<<std::endl;
    std::cout<<"变量val的内存地址是:"<<&val<<std::endl;
    std::cout<<"指针p存储的内容(也就是地址)是:"<<p<<std::endl;

    // 2. 解引用：通过指针 p 修改 val 的值
    // *p 意思是：去 p 指向的那个地址，把里面的东西改成 200
    *p=200;
    std::cout<<"修改后,val的值变成了:"<<val<<std::endl;

    int a=10;
    int& ref=a;  // ref 是 a 的引用（绰号）
    ref=50;  // 修改绰号，本质上就是在改 a 本身
    std::cout<<"a的值限制是:"<<a<<std::endl;
    return 0;
    */
 /*    int x=10 , y=20;

     std::cout<<"交换前:x="<<x<<",y="<<y<<std::endl;

    //  // 尝试 1：错误的交换
    WrongSwap(x,y);
    std::cout<<"WrongWsap后:x="<<x<<",y="<<y<<"(没变！)"<<std::endl;

    // 尝试 2：正确的交换
    // 注意：我们要把 x 和 y 的地址（&）传进去
    RealSwap(&x,&y);
    std::cout<<"RealSwap后:x="<<x<<",y="<<y<<"(成功了！)"<<std::endl;


    ReferenceSwap(x,y);
    std::cout<<"ReferenceSwap后:x="<<x<<",y"<<y<<"(也成功了)"<<std::endl;

    int nums[3]={10,20,30};
    std::cout<<"数组首地址:"<<nums<<std::endl;
    std::cout<<"第二个元素地址:"<<(nums+1)<<std::endl;


 */
     // 模拟传感器传回的 5 个方向的距离 (cm)
    int sensors[5]={120,88,92,200,15};
    
     // 调用函数，把数组名（本质就是首地址）传进去
    int closest=FindMinDistance(sensors,5);

    std::cout<<"检测完毕！最近障碍物距离:"<<closest<<"cm"<<std::endl;

    if (closest<20)
    {
        std::cout<<"警告：触发紧急制动！"<<std::endl;
    }
    






   
}


// 这是一个“特斯拉级”的感知处理函数
// ptr: 指向数组开头的指针
// size: 数组的大小





// 错误的尝试：按值传递（就像复制了两个假存折）
void WrongSwap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
// 正确的尝试：按指针传递（直接操作银行金库的地址）
void RealSwap(int*a,int*b){
    int temp=*a;// 把 a 指向的那个房子的东西先搬到临时仓库
    *a=*b; // 把 b 指向的房子的东西搬到 a 的房子
    *b=temp;// 把临时仓库的东西搬到 b 的房子
}
// 引用交换：看起来像普通变量，但背后操作的是内存
void ReferenceSwap(int&a,int&b){
    int temp=a;
    a=b;
    b=temp;
}

