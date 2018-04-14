

/*滑动条控制亮度和对比度*/
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//#define WIN_NAME "输出图像"
//
//int Contrase_Value = 20;
//int Bright_Value = 20;
//
//Mat srcImg = imread("1.jpg");
//Mat dstImg = Mat::zeros(srcImg.size(), srcImg.type());
//
//void OnChange(int, void*)
//{
//	for (int i = 0; i < srcImg.rows; i++)
//	{
//		for (int j = 0; j < srcImg.cols; j++)
//		{
//			dstImg.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(0.01*Contrase_Value*srcImg.at<Vec3b>(i, j)[0] + Bright_Value);
//			dstImg.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(0.01*Contrase_Value*srcImg.at<Vec3b>(i, j)[1] + Bright_Value);
//			dstImg.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(0.01*Contrase_Value*srcImg.at<Vec3b>(i, j)[2] + Bright_Value);
//		}
//	}
//	imshow("SRCIMG", srcImg);
//	imshow(WIN_NAME, dstImg);
//	
//}
//
//void main()
//{
//	
//
//	namedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
//
//	createTrackbar("对比度", WIN_NAME, &Contrase_Value, 300, OnChange,0);
//	createTrackbar("亮度", WIN_NAME, &Bright_Value, 200, OnChange, 0);
//
//	
//	OnChange(Contrase_Value, 0);
//	OnChange(Bright_Value, 0);
//	
//
//	if(27==waitKey(0))
//		return;
//
//
//}
//


//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//Mat img = imread("4.bmp");
//Mat temp = img.clone();
//Mat ROI;
//Point pt;
//bool flag = false;
//
//void OnMouse(int event, int x, int y, int flag, void* param)
//{
//	switch (event)
//	{
//	case CV_EVENT_LBUTTONDOWN:
//		flag = true;
//		pt.x = x;
//		pt.y = y;
//		cout << "left button down" << endl;
//		break;
//	case CV_EVENT_MOUSEMOVE:
//		if (flag)
//		{
//			temp.copyTo(img);
//			rectangle(img, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);
//		}
//		cout << "mouse move" << endl;
//		break;
//	case CV_EVENT_LBUTTONUP:
//		flag = false;
//		ROI = temp(Rect(pt.x, pt.y, x - pt.x, y - pt.y));
//		imshow("ROI", ROI);
//		imwrite("ROI.bmp", ROI);
//		cout << "left button up" << endl;
//		break;
//	default:
//		break;
//	}
//}
//
//void main()
//{
//	namedWindow("Mouse", CV_WINDOW_AUTOSIZE);
//	setMouseCallback("Mouse", OnMouse, 0);
//
//
//	while (1)
//	{
//		imshow("Mouse", img);
//
//		if (27 == waitKey(10))
//			break;
//
//	}
//
//}

/*图像融合LOGO*/

//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//void main()
//{
//	Mat img = imread("2.jpg");
//	Mat logo = imread("ROI.bmp");
//	//Mat mask = imread("mask.jpg",0);
//	//Mat mask = Mat::zeros(logo.size(), CV_8UC1);
//
//	//circle(mask, Point(mask.rows / 2, mask.cols / 2), 100, Scalar(255), -1, 8);
//	Mat mask = imread("ROI.bmp");
//	bitwise_not(mask, mask);
//	imshow("mask", mask);
//	threshold(mask, mask, 200, 255, THRESH_BINARY);
//	imshow("mask1", mask);
//	//Mat imgROI = img(Rect(20, 20, 200, 200));
//	//Mat imgROI = img(Range(20, 220), Range(20, 220));
//	Mat imgROI = img(Rect(20, 20, logo.cols, logo.rows));
//
//	logo.copyTo(imgROI, mask);
//
//	
//	imshow("dsr", img);
//	if (27 == waitKey(0))
//		return;
//
//
//
//}

//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//Mat imgTranslate(Mat &srcImg, int xOffset, int yOffset)
//{
////	int rows = srcImg.rows;
////	int cols = srcImg.cols;
//
//	int rows = srcImg.rows+abs(yOffset);
//	int cols = srcImg.cols+abs(xOffset);
//
//
//	Mat dstImg = Mat::zeros(rows,cols, srcImg.type());
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			int x = j + xOffset;
//			int y = i + yOffset;
//			if (x >= 0 && y >= 0 && x < cols&&y < rows)
//			{
//				dstImg.at<Vec3b>(y, x) = srcImg.at<Vec3b>(i, j);
//			}
//		}
//	}
//	return dstImg;
//}
//
//void main()
//{
//	Mat srcImg = imread("1.jpg");
//	Mat dstImg;
//	//resize(srcImg, dstImg, Size(),0.5,0.5,3);
//	
//
//	dstImg = imgTranslate(srcImg, 50, 50);
//
//	imshow("src", srcImg);
//	imshow("dst", dstImg);
//	waitKey(0);
//}
//
//
//


#include"opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat dstImg;

	Mat img = imread("1.jpg");
//	Point2f center = Point2f(img.cols / 2, img.rows / 2);
//Mat  roateM= getRotationMatrix2D(center, 45, 1);
//	warpAffine(img, dstImg, roateM,Size(700,500) );

	Mat xMat(img.size(), CV_32FC1);
	Mat yMat(img.size(), CV_32FC1);

	int rows = img.rows;
	int cols = img.cols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			xMat.at<float>(i, j) = j;   //保持列不变
			yMat.at<float>(i, j) = i + 5 * sin(j / 10.0);//行变换
		}
	}

	remap(img, dstImg, xMat, yMat,CV_INTER_LINEAR);



	imshow("src", img);
	imshow("dst", dstImg);
	waitKey(0);

}






















