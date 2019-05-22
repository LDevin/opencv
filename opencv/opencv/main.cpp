// opencv.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "OpenCvSlave.h"

int main(int argc, const char** argv)
{
    std::cout << "Hello World!\n"; 

	/****
	OpenCvSlave slave;
	slave.roiImages("aa.jpg", "gg.png");
	*****/

// 	OpenCvSlave::testOpenCvImage("aa.jpg");
// 	OpenCvSlave::accessPixelByPtr("aa.jpg");
// 	OpenCvSlave::accessPixelByAt("aa.jpg");
// 	OpenCvSlave::accessPixelByIter("aa.jpg");
// 	OpenCvSlave::accessPixelByLUT("aa.jpg");

	//OpenCvSlave::imageAffine("aa.jpg", -90.0);
	OpenCvSlave::imageFlip180("aa.jpg");
	system("pause");
}
