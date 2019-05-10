#include "OpenCvSlave.h"

const string rootDir = "F:\\test\\vs\\git\\OpenCV\\opencv\\x64\\";

OpenCvSlave::OpenCvSlave()
{
}

OpenCvSlave::~OpenCvSlave()
{
}

void OpenCvSlave::testImage(const string& image)
{
	Mat img = imread(rootDir + image);
	imshow("test image", img);
	waitKey(0);
}

void OpenCvSlave::roiImages(const string& src, const string& roi)
{
	Mat srcImg = imread(rootDir + src);
	Mat roiImg = imread(rootDir + roi);

	if (!srcImg.data && !roiImg.data) {
		printf("read image failed\n");
		return;
	}

	Mat roiRect = srcImg(Rect(10, 250, roiImg.cols, roiImg.rows));

	Mat mask = imread(rootDir + roi, 0);

	roiImg.copyTo(roiRect, mask);

	imshow("roi", srcImg);
	waitKey(0);
}