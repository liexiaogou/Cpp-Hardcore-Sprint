#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

int main(){
    // 1. 读取灰度图
    cv::Mat image=cv::imread("../test.jpg",cv::IMREAD_GRAYSCALE);
    if(image.empty())return-1;

    // 创建结果画布（存放梯度强度）
    cv::Mat result=cv::Mat::zeros(image.size(),CV_8U);

    std::cout<<"🚀 特斯拉高级感知：正在执行 Sobel 算子提取边缘特征..."<<std::endl;

    // 2. 🚀 定义 Sobel 卷积核（特征提取模板）
    // 这个矩阵专门检测“垂直方向”的线条变化
    int Gx[3][3]={
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    // 3. 开始全图扫描
    for(int y=1;y<image.rows-1;y++){
        for(int x=1;x<image.cols;x++){

            float sumX=0;

            // 🚀 核心数学：将 3x3 区域的像素与 Sobel 模板进行“加权求和”
            for(int ky=-1;ky<=1;ky++){
                for(int kx=1;kx<=1;kx++){
                    // 获取当前领域的像素值
                    uchar pixel=image.at<uchar>(y+ky,x+kx);
                    // 按照权重叠加
                    sumX+=pixel*Gx[kx+1][ky+1];
                }
            }
            // 4. 计算最终像素：取绝对值，代表边缘的“强度”
            int magintude=static_cast<int>(std::abs(sumX));

            // 归一化到 0-255（C++ 的安全检查）
            if(magintude>255)magintude=255;
            result.at<uchar>(y,x)=static_cast<uchar>(magintude);
        }
    }
    cv::imwrite("vision_sobel_output.jpg",result);
    std::cout<<"✅ 特征提取完成：vision_sobel_output.jpg"<<std::endl;
    return 0;

}