#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

int main(){
    // 1. 【加载数据】：以灰度模式读取图片 (每个像素只有一个 0-255 的值)
    // 💡 为什么用灰度？因为识别形状不需要颜色，灰度能减少 5080 显卡 2/3 的计算量。
    cv::Mat image=cv::imread("../test.jpg",cv::IMREAD_GRAYSCALE);

    if ((image.empty()))
    {
        std::cout<<"❌ 错误：找不到 test.jpg"<<std::endl;
        return -1;
    }

    // 2. 【准备画布】：创建一个和原图一样大的全黑图片，用来存放我们找到的“边缘”
    cv::Mat result=cv::Mat::zeros(image.size(),image.type());

    std::cout<<"🚀 特斯拉感知算法：正在扫描 800 万像素..."<<std::endl;

    // 3. 【核心算法】：像素级双重循环
    // 我们要遍历图像的每一行 (y) 和每一列 (x)
    // 注意：从 1 开始到 rows-1 结束，是为了防止计算左右邻居时越界（撞墙）
    for(int y=0;y<image.rows;y++){
        for(int x=1;x<image.cols-1;x++){
            // --- 这里的逻辑是自动驾驶的基石 ---
            
            // 读取当前像素左边和右边的值
            // .at<uchar>(y, x) 本质上是访问内存地址：数据首地址 + (y * 宽度 + x)
            uchar leftPixel=image.at<uchar>(y,x-1);
            uchar rightPixel=image.at<uchar>(y,x+1);

            // 计算“梯度（Gradient）”：即左右像素的差值
            // 如果差值很大，说明这里颜色发生了突变
            int deltaX=std::abs(leftPixel-rightPixel);

            // 4. 【决策】：设定一个“敏感度门槛（Threshold）”
            // 如果差值大于 50，我们认为这是一个“边缘点”
            if(deltaX>50){
                result.at<uchar>(y,x)=255;// 在结果图中点亮这个像素（白色）
            }else{
                result.at<uchar>(y,x)=0; // 否则保持黑暗（黑色）
            }
        }
    }

    // 5. 【输出结果】：将你的感知结果存入硬盘
    cv::imwrite("vision_edge_manual.jpg",result);

    std::cout<<"✅ 处理完成!"<<std::endl;
    std::cout<<">> 原始分辨率:"<<image.cols<<"x"<<image.rows<<std::endl;
    std::cout<<">> 请查看 build/vision_edge_manual.jpg"<<std::endl;
    return 0;
}