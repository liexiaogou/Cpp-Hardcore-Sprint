#include <opencv2/opencv.hpp>
#include <iostream>
int main(){
    // 1. 读取灰度图
    cv::Mat image=cv::imread("../test.jpg",cv::IMREAD_GRAYSCALE);
    if (image.empty())return -1;

    // 2. 创建结果画布
    cv::Mat result=image.clone();

    std::cout<<"🚀 正在进行 3x3 卷积运算（均值平滑降噪）..."<<std::endl;

    // 3. 【核心逻辑】：滑动窗口卷积
    // 我们忽略最外围的 1 像素边缘，防止越界
    for(int y=1;y<image.rows-1;y++){
        for(int x=1;x<image.cols-1;x++){

            // 🚀 特斯拉底层原理：3x3 局部感知野 (Receptive Field)
            // 我们把当前像素及其周围 8 个邻居全部加起来
            float sum=0;

            // 这是一个内部的 3x3 扫描
            for(int ky=-1;ky<=1;ky++){
                for(int kx=-1;kx<=1;kx++){
                    sum+=image.at<uchar>(y+ky,x+kx);
                }
            }


            // 计算平均值：9 个像素的总和除以 9
            // 这会让突出的噪点被周围的像素“稀释”掉
            result.at<uchar>(y,x)=static_cast<uchar>(sum/9.0f);
        }
    }
    cv::imwrite("vision_blurred.jpg",result);
    std::cout<<"✅ 降噪预处理完成：vision_blurred.jpg"<<std::endl;
    return 0;
}