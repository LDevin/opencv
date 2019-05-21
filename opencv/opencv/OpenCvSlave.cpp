#include <Windows.h>
#include <chrono>
#include "OpenCvSlave.h"


/****
	*	@brief
	*	 @modify this rootDir
****/
const string rootDir = "F:\\test\\vs\\git\\OpenCV\\opencv\\x64\\";

using namespace std::chrono;

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

void OpenCvSlave::testOpenCvImage(const string& imgSrc)
{
	Mat img = imread(rootDir + imgSrc);

	if (!img.data) {
		printf("read image failed\n");
		return;
	}

	printf("rows:%d, cols:%d, channels:%d", img.rows, img.cols, img.channels());
}

/****
	*@brief
	* @ in opencv, the color is BGR
****/
void OpenCvSlave::accessPixelByPtr(const string& imgSrc)
{
	Mat img = imread(rootDir + imgSrc);
	
	if (img.empty()) {
		printf("read image failed, is empty\n");
		return;
	}

	Mat array(3, 3, CV_8UC3, Scalar(2, 3, 240));

	cout << "Array=" << endl << array << endl;

	Mat dstImg = img.clone();

#if 1
	steady_clock::time_point t1 = steady_clock::now();

	for (auto i = 0; i < dstImg.rows; ++i) {
		
		for (auto j = 0; j < dstImg.cols; ++j) {
			dstImg.ptr<Vec3b>(i)[j][2] = 0;
		}
	}
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	cout << "accessPixelByPtr took " << time_span.count() << "seconds" << endl;
#endif

#if 0
	for (size_t i = 0; i < length; i++)
	{

	}
#endif

// 	imshow("image", dstImg);
// 	waitKey(0);

}

void OpenCvSlave::accessPixelByIter(const string& imgSrc)
{
	Mat img = imread(rootDir + imgSrc);

	if (img.empty()) {
		printf("read image failed, is empty\n");
		return;
	}

	Mat dstImg = img.clone();

#if 1
	steady_clock::time_point t1 = steady_clock::now();

	Mat_<Vec3b>::iterator it = dstImg.begin<Vec3b>();
	while (it != dstImg.end<Vec3b>())
	{
		(*it)[2] = 0;
		++it;
	}
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "accessPixelByIter took " << time_span.count() << "seconds" << endl;
#endif
	//imshow("image", dstImg);
	//waitKey(0);
}

void OpenCvSlave::accessPixelByAt(const string& imgSrc)
{
	Mat img = imread(rootDir + imgSrc);

	if (img.empty()) {
		printf("read image failed, is empty\n");
		return;
	}

	Mat dstImg = img.clone();

#if 1
	steady_clock::time_point t1 = steady_clock::now();

	for (auto i = 0; i < dstImg.rows; ++i) {

		for (auto j = 0; j < dstImg.cols; ++j) {
			dstImg.at<Vec3b>(i, j)[2] = 0;
		}
	}
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "accessPixelByAt took " << time_span.count() << "seconds" << endl;
#endif

// 	imshow("image", dstImg);
// 	waitKey(0);
}

/****
*	@brief 
		we can use GetTickCount();
	              getTickFrequency()
***/
void OpenCvSlave::accessPixelByLUT(const string& imgSrc)
{
	int type = CV_LOAD_IMAGE_GRAYSCALE;
#if 1
	type = CV_LOAD_IMAGE_ANYCOLOR;
#endif

	Mat img = imread(rootDir + imgSrc, type);

	if (img.empty()) {
		printf("read image failed, is empty\n");
		return;
	}

	Mat dstImg;


	//single channel
	// lut
#if 0
	steady_clock::time_point t1 = steady_clock::now();

	uchar lutData[256];
	for (auto i = 0; i < 256; ++i) {
		if (i <= 100) {
			lutData[i] = 0;
		} else if (i > 100 && i <= 200) {
			lutData[i] = 100;
		} else {
			lutData[i] = 255;
		}
	}

	Mat lut(1, 256, CV_8UC1, lutData);
	LUT(img, lut, dstImg);

	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "accessPixelByLUT took " << time_span.count() << "seconds" << endl;
#endif


	//3 channels
		// lut
#if 1
	steady_clock::time_point t1 = steady_clock::now();

	uchar lutData[256 * 3];
	for (auto i = 0; i < 256; ++i) {
		if (i <= 100) {
			lutData[i * 3] = 0;
			lutData[i * 3 + 1] = 50;
			lutData[i * 3 + 2] = 50;
		}
		else if (i > 100 && i <= 200) {
			lutData[i * 3] = 100;
			lutData[i * 3 + 1] = 10;
			lutData[i * 3 + 2] = 200;
		}
		else {
			lutData[i * 3] = 255;
			lutData[i * 3 + 1] = 200;
			lutData[i * 3 + 2] = 100;
		}
	}

	Mat lut(1, 256, CV_8UC3, lutData);
	LUT(img, lut, dstImg);

	steady_clock::time_point t2 = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	cout << "accessPixelByLUT took " << time_span.count() << "seconds" << endl;

#endif 

	imshow("lut image", dstImg);
	imshow("normal", img);

	waitKey();
}

void OpenCvSlave::imageAffine(const string& imgSrc, double angle, int type /* = 0 */)
{
	Mat img = imread(rootDir + imgSrc);
	
	Mat dst;

	Point center(img.cols / 2, img.rows / 2);
	Mat rotMat = getRotationMatrix2D(center, angle, 1.0);

	warpAffine(img, dst, rotMat, img.size());
	
	imshow("rotate", dst);
	imshow("normal", img);

	waitKey();
}

/****
*	@brief
		f: 1, 0, -1
***/

void OpenCvSlave::imageFlip(const string& imgSrc, int f, int type /* = 0 */)
{
	Mat img = imread(rootDir + imgSrc);

	Mat dst, temp;

	transpose(img, temp);
	flip(temp, dst, f);

	imshow("rotate", dst);
	imshow("normal", img);

	CHAR currentPath[MAX_PATH];

	DWORD dwCurDirPathLen;
	dwCurDirPathLen = GetCurrentDirectoryA(MAX_PATH, currentPath);
	cout << "当前目录为：" << currentPath << endl;

	imwrite(string(currentPath) + "\\image.jpg", dst);

	waitKey();
}