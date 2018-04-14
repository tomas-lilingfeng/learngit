//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Mat srcImg, hsv_img;
//int h_min = 0, s_min = 0, v_min = 0;
//int h_max = 180, s_max=255, v_max = 46;
//Mat dstImg = Mat::zeros(srcImg.rows, srcImg.cols, CV_8UC3);
//
//
//void OnChange(int, void*)
//{
//	Scalar hsv_min(h_min, s_min, v_min);
//	Scalar hsv_max(h_max, s_max, v_max);
//	
//	inRange(hsv_img, hsv_min, hsv_max, dstImg);
//
//	imshow("HSV", dstImg);
//}
//
//
//void main()
//{
//	srcImg = imread("rgb.jpg");
//	imshow("src", srcImg);
//	cvtColor(srcImg, hsv_img, CV_BGR2HSV);
//	namedWindow("HSV", CV_WINDOW_NORMAL);
//	createTrackbar("h_min", "HSV", &h_min, 180, OnChange);
//	createTrackbar("s_min", "HSV", &s_min, 255, OnChange);
//	createTrackbar("v_min", "HSV", &v_min, 255, OnChange);
//	createTrackbar("h_max", "HSV", &h_max, 180, OnChange);
//	createTrackbar("s_max", "HSV", &s_max, 255, OnChange);
//	createTrackbar("v_max", "HSV", &v_max, 255, OnChange);
//
//	OnChange(h_min, 0);
//	OnChange(s_min, 0);
//	OnChange(v_min, 0);
//	OnChange(h_max, 0);
//	OnChange(s_max, 0);
//	OnChange(v_max, 0);
//
//	Scalar hsv_min(h_min, s_min, v_min);
//	Scalar hsv_max(h_max, s_max, v_max);
//
//	inRange(hsv_img, hsv_min, hsv_max, dstImg);
//
//	imshow("HSV", dstImg);
//
//	waitKey();
//
//
//
//}
//


//
//#include "opencv2/opencv.hpp"
//#include <iostream>
//using namespace cv;
//using namespace std;
//
/////green hsv min value
//int h_min = 0;
//int s_min = 107;
//int v_min = 68;
/////green hsv max value
//int h_max = 8;
//int s_max = 255;
//int v_max = 255;
//
//void main()
//{
//	///识别图片中颜色物体
//	Mat srcImg = imread("rgb.jpg");
//	imshow("src", srcImg);
//	Mat dstImg = srcImg.clone();
//	Mat hsv_img;  //存储HSV图像
//	cvtColor(srcImg, hsv_img, CV_BGR2HSV); //BGR转到HSV颜色空间
//	Scalar hsv_min(h_min, s_min, v_min);
//	Scalar hsv_max(h_max, s_max, v_max);
//	Mat hsv_green = Mat::zeros(srcImg.size(), CV_8U);
//	inRange(hsv_img, hsv_min, hsv_max, hsv_green);
//	medianBlur(hsv_green, hsv_green, 5);
//	imshow("hsv_green", hsv_green);
//
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarcy;
//
//	findContours(hsv_green, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	vector<Rect> boundRect(contours.size());
//	for (int i = 0; i<contours.size(); i++)
//	{
//		boundRect[i] = boundingRect(Mat(contours[i]));
//		rectangle(dstImg, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 255), 2, 8); //矩形标记
//		Point org = boundRect[i].tl();
//		putText(dstImg, "RED", org, CV_FONT_HERSHEY_SIMPLEX, 1.2f, CV_RGB(0, 255, 0), 2);
//	}
//	imshow("result", dstImg);
//
//	waitKey(0);
//}
//
//


#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//Mat img = imread("1.jpg");
//Mat temp = img.clone();
//Mat ROI;
//Point pt;
//bool flag = false;

double Fps;



int h_min = 0;
int s_min = 107;
int v_min = 68;
///green hsv max value
int h_max = 8;
int s_max = 255;
int v_max = 255;

///鼠标消息回调函数
//void OnMouse(int event, int x, int y, int flag, void* param)
//{
//	switch(event)
//	{
//		case CV_EVENT_LBUTTONDOWN:  //鼠标左键按下
//			//cout<<"left button down"<<endl;
//			flag = true;
//			pt.x = x;
//			pt.y = y;
//			break;
//		case CV_EVENT_MOUSEMOVE:   //鼠标移动
//			//cout<<"mouse move"<<endl;
//			if(flag)
//			{
//				temp.copyTo(img);
//				rectangle(img, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);
//			}
//			break;
//		case CV_EVENT_LBUTTONUP:   //鼠标左键弹起
//			//cout<<"left button up"<<endl;
//			flag = false;
//			ROI = temp(Rect(pt.x, pt.y, x-pt.x, y-pt.y));  //确定ROI区域
//			imshow("ROI", ROI);
//			imwrite("ROI.bmp", ROI);
//			break;
//		default:		
//			break;
//	}
//}
int value;
int framePos;

void OnChange(int, void* param)
{
	VideoCapture cap = *(VideoCapture*)param;
	cap.set(CV_CAP_PROP_POS_FRAMES, value);  //设置视频帧位置
}

void main()
{
	///鼠标截图功能
	//namedWindow("Mouse", CV_WINDOW_AUTOSIZE);
	//setMouseCallback("Mouse", OnMouse, 0);   //设置鼠标回调函数
	//while(1)
	//{
	//	imshow("Mouse", img);
	//	if(27 == waitKey(10))  //Esc跳出循环
	//		break;
	//}
	char strFps[20];
	Mat frame;
	VideoCapture cap("1.mp4");
	if (!cap.isOpened())  //打开视频失败
		return;

	int FrameCount = cap.get(CV_CAP_PROP_FRAME_COUNT);  //获取视频总帧数

	namedWindow("Video", CV_WINDOW_AUTOSIZE);
	createTrackbar("Frame", "Video", &value, FrameCount, OnChange, &cap);

	Fps = cap.get(CV_CAP_PROP_FPS);  //获取视频帧率
	sprintf(strFps, "Fps:%0.1f/s", Fps);  //格式化字符串

	while (1)
	{
		framePos = cap.get(CV_CAP_PROP_POS_FRAMES);  //获取视频帧位置
		setTrackbarPos("Frame", "Video", framePos);  //设置滑动条位置
		cap >> frame;
		if (frame.empty())  //取帧失败
			break;


		Mat srcImg = frame.clone();

		Mat hsv_img;  //存储HSV图像
		cvtColor(srcImg, hsv_img, CV_BGR2HSV); //BGR转到HSV颜色空间
		Scalar hsv_min(h_min, s_min, v_min);
		Scalar hsv_max(h_max, s_max, v_max);
		Mat hsv_red = Mat::zeros(srcImg.size(), CV_8U);
		inRange(hsv_img, hsv_min, hsv_max, hsv_red);
		//medianBlur(hsv_red, hsv_red, 5);

		vector<vector<Point>> contours;
		vector<Vec4i> hierarcy;

		findContours(hsv_red, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		vector<Rect> boundRect(contours.size());
		for (int i = 0; i<contours.size(); i++)
		{
			boundRect[i] = boundingRect(Mat(contours[i]));
			rectangle(srcImg, Point(boundRect[i].x, boundRect[i].y), Point(boundRect[i].x + boundRect[i].width, boundRect[i].y + boundRect[i].height), Scalar(0, 255, 255), 2, 8); //矩形标记		
		}



		putText(srcImg, strFps, Point(5, 30), CV_FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 255, 0), 1, 8);
		imshow("Video", srcImg);
		if (27 == waitKey(1000 / Fps))  //Esc跳出循环退出
			break;
	}

	cap.release();
	destroyAllWindows();
}













