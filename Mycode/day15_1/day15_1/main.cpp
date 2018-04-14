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

///�����Ϣ�ص�����
//void OnMouse(int event, int x, int y, int flag, void* param)
//{
//	switch(event)
//	{
//		case CV_EVENT_LBUTTONDOWN:  //����������
//			//cout<<"left button down"<<endl;
//			flag = true;
//			pt.x = x;
//			pt.y = y;
//			break;
//		case CV_EVENT_MOUSEMOVE:   //����ƶ�
//			//cout<<"mouse move"<<endl;
//			if(flag)
//			{
//				temp.copyTo(img);
//				rectangle(img, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);
//			}
//			break;
//		case CV_EVENT_LBUTTONUP:   //����������
//			//cout<<"left button up"<<endl;
//			flag = false;
//			ROI = temp(Rect(pt.x, pt.y, x-pt.x, y-pt.y));  //ȷ��ROI����
//			imshow("ROI", ROI);
//			imwrite("ROI.bmp", ROI);
//			break;
//		default:		
//			break;
//	}
//}
int value;
int framePos; 

void OnChange(int , void* param)
{
	VideoCapture cap = *(VideoCapture*)param;
	cap.set(CV_CAP_PROP_POS_FRAMES, value);  //������Ƶ֡λ��
}

void main()
{
	///����ͼ����
	//namedWindow("Mouse", CV_WINDOW_AUTOSIZE);
	//setMouseCallback("Mouse", OnMouse, 0);   //�������ص�����
	//while(1)
	//{
	//	imshow("Mouse", img);
	//	if(27 == waitKey(10))  //Esc����ѭ��
	//		break;
	//}
	char strFps[20];
	Mat frame;
	VideoCapture cap("1.mp4");
	if(!cap.isOpened())  //����Ƶʧ��
		return;

	int FrameCount = cap.get(CV_CAP_PROP_FRAME_COUNT);  //��ȡ��Ƶ��֡��

	namedWindow("Video", CV_WINDOW_AUTOSIZE);
	createTrackbar("Frame", "Video", &value, FrameCount, OnChange, &cap);

	Fps = cap.get(CV_CAP_PROP_FPS);  //��ȡ��Ƶ֡��
	sprintf(strFps, "Fps:%0.1f/s", Fps);  //��ʽ���ַ���

	while(1)
	{
		framePos = cap.get(CV_CAP_PROP_POS_FRAMES);  //��ȡ��Ƶ֡λ��
		setTrackbarPos("Frame", "Video", framePos);  //���û�����λ��
		cap>>frame;
		if(frame.empty())  //ȡ֡ʧ��
			break;


		Mat srcImg = frame.clone();
		
		Mat hsv_img;  //�洢HSVͼ��
		cvtColor(srcImg, hsv_img, CV_BGR2HSV); //BGRת��HSV��ɫ�ռ�
		Scalar hsv_min(h_min, s_min, v_min);
		Scalar hsv_max(h_max, s_max, v_max);
		Mat hsv_red = Mat::zeros(srcImg.size(), CV_8U);
		inRange(hsv_img, hsv_min, hsv_max, hsv_red);
		medianBlur(hsv_red, hsv_red, 5);
		
		vector<vector<Point>> contours;
		vector<Vec4i> hierarcy;
		
		findContours(hsv_red, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		vector<Rect> boundRect(contours.size());
		for (int i = 0; i<contours.size(); i++)
		{
			
			boundRect[i] = boundingRect(Mat(contours[i]));
			if(boundRect[i].area()>10*10)
				rectangle(srcImg, Point(boundRect[i].x, boundRect[i].y), Point(boundRect[i].x+ boundRect[i].width, boundRect[i].y+ boundRect[i].height), Scalar(0, 255, 255), 2, 8); //���α��		
		}



		putText(srcImg, strFps, Point(5, 30), CV_FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 255, 0), 1, 8);
		imshow("Video", srcImg);
		if(27 == waitKey(1000/Fps) )  //Esc����ѭ���˳�
			break;
	}

	cap.release();
	destroyAllWindows();
}