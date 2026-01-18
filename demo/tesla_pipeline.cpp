#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>// 🚀 引入对讲机库
#include<queue>

std::mutex mtx;
std::condition_variable cv;// 🚀 定义对讲机
std::queue<std::string>dateBuffer;// 模拟图像存储缓冲区
bool isFinished=false;

// 📸 生产者：模拟摄像头抓拍
void cameraTask(){
    std::string frames[]={"Frame_1", "Frame_2", "Frame_3", "STOP"};

    for(const std::string& f:frames){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));// 模拟拍照耗时)
        
        {
            std::lock_guard<std::mutex>lock(mtx);
            dateBuffer.push(f);
            std::cout<<"[摄像头] 抓拍到图像:"<<f<<std::endl;
        }
        cv.notify_one();// 🚀 按下对讲机：告诉 AI 线程有活干了！
        if(f=="STOP")break;
    }
}

// 🧠 消费者：模拟 AI 视觉处理
void aiTask(){
    while (true)
    {
        std::unique_lock<std::mutex>lock(mtx);

        // 🚀 核心逻辑：如果缓冲区是空的，AI 线程就在这里“深度休眠”
        // 只有被 cv.notify_one() 唤醒，且 dataBuffer 不为空时才往下走
        cv.wait(lock,[]{ return !dateBuffer.empty(); });

        std::string date=dateBuffer.front();
        dateBuffer.pop();

        if ((date=="STOP"))
        {
            std::cout<<"[AI核心] 收到停止指令，安全关机。"<<std::endl;
            break;
        }

        std::cout<<"[AI核心] 🚀 正在用 5080 算力分析:"<<std::endl; 
    }
}

int main(){
    std::cout<<"--- 特斯拉自动驾驶流水线启动 ---"<<std::endl;
    
    std::thread t1(cameraTask);
    std::thread t2(aiTask);

    t1.join();
    t2.join();
    return 0;
}