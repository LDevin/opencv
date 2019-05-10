// opencv.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "OpenCvSlave.h"

int main(int argc, const char** argv)
{
    std::cout << "Hello World!\n"; 

	OpenCvSlave slave;
	//slave.testImage("aa.jpg");
	slave.roiImages("aa.jpg", "gg.png");
	system("pause");
}
