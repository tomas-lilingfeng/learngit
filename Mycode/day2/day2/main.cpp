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

	cout<<"��Ƶ���="<<width<<endl;
	cout<<"��Ƶ�߶�="<<height<<endl;
	cout<<"��Ƶ��֡��="<<totalFrames<<endl;
	cout<<"֡��="<<frameRate<<endl;


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
////�򿪵�һ������ͷ
////VideoCapture cap(0);
////����Ƶ�ļ�
//VideoCapture cap("2.avi");
//
////����Ƿ�ɹ���
//if(!cap.isOpened())
//{
//cerr << "Can not open a camera or file." << endl;
//return -1;
//}
//Mat edges;
////��������
//namedWindow("edges",1);
//for(;;)
//{
//Mat frame;
////�� cap �ж�һ֡���浽 frame
//cap >> frame;
////���δ����ͼ��
//if(frame.empty())
//break;
////��������ͼ��תΪ�Ҷ�ͼ
//cvtColor(frame, edges, CV_BGR2GRAY);
////���б�Ե��ȡ����
//Canny(edges, edges, 0, 30, 3);
////��ʾ���
//imshow("edges", edges);
////�ȴ� 30 �룬����������Ƴ�ѭ��
//if(waitKey(30) == 27)
//break;
//}
////�˳�ʱ���Զ��ͷ� cap ��ռ����Դ
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
////������ȡͼƬ
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
