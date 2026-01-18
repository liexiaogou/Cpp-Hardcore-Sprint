#include <iostream>
#include <opencv2/opencv.hpp>// 🚀 引入 OpenCV 视觉库

int main(){
    // 1. 模拟摄像头读取一张图片
    // 💡 你需要在 /root/projects/learning/ 目录下放一张叫 test.jpg 的图片
    cv::Mat frame = cv::imread("../test.jpg"); 
    
    if(frame.empty()){
        std::cout<<"❌ 无法读取图像！请检查目录下是否有 test.jpg"<<std::endl;
        return -1;
    }

    // 2. 打印图像的基本物理属性
    // 这对于特斯拉感知算法非常重要，因为分辨率决定了计算量
    std::cout<<">> 图像宽度:"<<frame.cols<<"像素"<<std::endl;
    std::cout<<">> 图像高度:"<<frame.rows<<"像素"<<std::endl;

    // 3. 图像预处理：灰度化 (Grayscale)
    // 在自动驾驶中，识别车道线或障碍物边缘时，灰度图比彩色图处理速度快 3 倍
    cv::Mat grayFrame;
    cv::cvtColor(frame,grayFrame,cv::COLOR_BGR2GRAY);

    // 4. 保存处理后的结果
    cv::imwrite("vision_output.jpg",grayFrame);
    std::cout<<"✅ 视觉处理成功！已生成灰度图: build/vision_output.jpg"<<std::endl;

    return 0;
}