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

	/****
	*	@brief
		@test static util
	****/
public:
	static void testOpenCvImage(const string& imgSrc);

	static void accessPixelByPtr(const string& imgSrc);

	static void accessPixelByIter(const string& imgSrc);

	static void accessPixelByAt(const string& imgSrc);

	/****
	*	@brief
		 @ LUT Look Up Table
 	****/
	static void accessPixelByLUT(const string& imgSrc);


private:

};