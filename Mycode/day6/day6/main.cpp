//

#include"opencv2/opencv.hpp"

using namespace cv;

Mat srcImg, dst1,dst2;

int valueT = 20;
int BlockSize = 3;
int C0 = 10;

void OnThreshold(int, void*)
{
	threshold(srcImg, dst1, valueT, 255, CV_THRESH_BINARY);
	imshow("src", srcImg);
	imshow("ｹﾌｶｨ耙ﾖｵ", dst1);
}

void OnAdaptive(int, void*)
{
	if (BlockSize % 2 == 0)
		BlockSize++;
	adaptiveThreshold(srcImg, dst2, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, BlockSize, C0);
	imshow("ﾗﾔﾊﾊﾓｦ耙ﾖｵ", dst2);
}

void OnC0(int, void*)
{
	adaptiveThreshold(srcImg, dst2, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, BlockSize, C0);
	imshow("ﾗﾔﾊﾊﾓｦ耙ﾖｵ", dst2);
}

void main()
{
	 srcImg=imread("5.jpg", 0);
	 medianBlur(srcImg, srcImg, 5);

	namedWindow("ｹﾌｶｨ耙ﾖｵ", WINDOW_AUTOSIZE);
	namedWindow("ﾗﾔﾊﾊﾓｦ耙ﾖｵ", WINDOW_AUTOSIZE);

	createTrackbar("Threshold", "ｹﾌｶｨ耙ﾖｵ", &valueT, 255, OnThreshold, 0);
	createTrackbar("BlockSize", "ﾗﾔﾊﾊﾓｦ耙ﾖｵ", &BlockSize, 255, OnAdaptive, 0);
	createTrackbar("C", "ﾗﾔﾊﾊﾓｦ耙ﾖｵ", &C0, 255, OnC0, 0);

	OnThreshold(valueT, 0);
	OnAdaptive(BlockSize, 0);
	OnC0(C0, 0);



	waitKey(0);


}













