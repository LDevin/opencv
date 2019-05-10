#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class OpenCvSlave
{
public:
	OpenCvSlave();
	~OpenCvSlave();

	/****
	*	@brief
		@test image
	****/
	void testImage(const string& image);

	void roiImages(const string& src, const string& roi);


private:

};