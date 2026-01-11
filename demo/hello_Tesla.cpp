#include"log.h"
#include<iostream>
#include"Math.h"
int main (){

    

    int distance=0;
    bool keep_running=true;
    
    while (keep_running)
    {
        std::cout<<"\n请输入障碍物距离 (输入 -999 退出):";

        if (!(std::cin>>distance))
        {
            Log("输入非法，请重新输入数字！");
            std::cin.clear(); // 清除错误标记
            std::cin.ignore(100,'\n'); // 跳过坏数据
            continue; // 跳过本次循环，重新开始
        }
        
        if (distance== -999)
        {
            Log("系统关闭...");
            keep_running=false;
            break;
        }
        if (distance<20)
        {
            Log("!!!!STOP!!!!!!!!");
        }
        else if (distance<50)
        {
            Log("Caution: Slow Down");
            
        }else
        {
            Log("Safe: Keep Moving");
        }
        
    }
      return 0; 
        
        
    
    
    
    
    


   /*  int re=Multiply(5,8);
    std::cout<<"Result: " <<re<<std::endl; */
    
   /*  int distance =0;
    std::cout<<"输入障碍物距离";
    // 如果 cin 发现输入不是数字，它会返回 false
    if (!(std::cin>>distance))
    {
        Log("CRITICAL ERROR: Invalid sensor data (not a number)!");
        return -1;
    }
    if (distance<0)
    {
        Log("ERROR: Negative distance is impossible!");
        return -1;
    }
    
    // 只有数据完全合法，才会走到这一步
    
    // 4. 全部通过，执行逻辑
    std::cout << "数据合法，当前距离: " << distance << std::endl;
    
    return 0; */
    



   /*  if (distance<20)
    {
        Log("!!!! STOP !!!! - Collision Imminent");
        
    }
    else if (distance<=50)  // 走到这一步，说明 distance 肯定 >= 20
    {
       Log("Caution: Slow Down - Obstacle Ahead");
    }
    else
    {
        Log("Safe: Keep Moving");
    }
    
    return 0; */
    
}
