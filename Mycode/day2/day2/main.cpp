#include"opencv2/opencv.hpp"
#include<iostream>

using namespace cv;
using namespace std;

void main()
{
	VideoCapture cap;
	cap.open("2.avi");
	//VideoCapture cap("1.avi");
	
	if(!cap.isOpened())
		return;
	int width=cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int height=cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	int frameRate=cap.get(CV_CAP_PROP_FPS);
	int totalFrames=cap.get(CV_CAP_PROP_FRAME_COUNT);

	cout<<"视频宽度="<<width<<endl;
	cout<<"视频高度="<<height<<endl;
	cout<<"视频总帧数="<<totalFrames<<endl;
	cout<<"帧率="<<frameRate<<endl;


	Mat frame;
	while(1)
	{
		cap>>frame;
		if(frame.empty())
			break;
		//cap.read(frame);
		imshow("video",frame);
		if(waitKey(30)==27)
			break;
	}
	cap.release();
}


//#include <iostream>
//#include "opencv2/opencv.hpp"
//using namespace std;
//using namespace cv;
//int main(int argc, char** argv)
//{
////打开第一个摄像头
////VideoCapture cap(0);
////打开视频文件
//VideoCapture cap("2.avi");
//
////检查是否成功打开
//if(!cap.isOpened())
//{
//cerr << "Can not open a camera or file." << endl;
//return -1;
//}
//Mat edges;
////创建窗口
//namedWindow("edges",1);
//for(;;)
//{
//Mat frame;
////从 cap 中读一帧，存到 frame
//cap >> frame;
////如果未读到图像
//if(frame.empty())
//break;
////将读到的图像转为灰度图
//cvtColor(frame, edges, CV_BGR2GRAY);
////进行边缘提取操作
//Canny(edges, edges, 0, 30, 3);
////显示结果
//imshow("edges", edges);
////等待 30 秒，如果按键则推出循环
//if(waitKey(30) == 27)
//break;
//}
////退出时会自动释放 cap 中占用资源
//return 0;
//}

//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//void main()
//{
////批量读取图片
//
///*
//	char filename[50];
//	char winname[50];
//	Mat srcImg;
//	for(int i=1;i<100;i++)
//	{
//		sprintf(filename,"%d.bmp",i);
//		sprintf(winname,"NO--%d",i);
//		srcImg=imread(filename);
//
//		if(srcImg.empty())
//			break;
//
//		imshow(winname,srcImg); 
//	}
//
//	
//	waitKey(0);
//	destroyAllWindows();
//	*/
////
//
///*	Mat frame;
//	char outfile[50];
//	VideoCapture cap("2.avi");
//	if(!cap.isOpened())
//		return;
//	int totalFrame=cap.get(CV_CAP_PROP_FRAME_COUNT);
//	
//	for(int i=1;i<=totalFrame;i++)
//	{
//		sprintf(outfile,"E:\\pic\\%d.bmp",i);
//		cap>>frame;
//		if(frame.empty())
//			break;
//		imwrite(outfile,frame);
//		imshow("video",frame);
//		waitKey(15);
//
//	}
//	cap.release();
//	destroyAllWindows();
//*/
//
//VideoWriter writer("E:\\out.avi",CV_FOURCC('X','V','I','D'),30,Size(568,320),true);
//VideoCapture cap;
//char filename[50];
//Mat frame;
//for(int i=1;i<644;i++)
//{
//	sprintf(filename,"E:\\pic\\%d.bmp",i);
//	//frame=imread(filename);
//	cap.open(filename);
//	if(!cap.isOpened())
//		break;
//	cap>>frame;
//	if(frame.empty())
//		break;
//	writer<<frame;
//}
//
//cout<<"write end!"<<endl;
//destroyAllWindows();
//
//
//}
//
//
//
//
