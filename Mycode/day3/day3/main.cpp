//#include"opencv2/opencv.hpp"
////#include<iostream>
//
//using namespace cv;
////using namespace std;
//
//void main()
//{
//	Mat img=imread("1.jpg");
//	line(img,Point(10,10),Point (200,200),Scalar(0,255,255),1,1);
//	circle(img,Point(150,150),100,Scalar(255,255,0),1,8);
//	rectangle(img,Point(10,10),Point(240,200),Scalar(0,255,0),2,8);
//	rectangle(img,Rect(10,10,230,190),Scalar(0,0,255),-1,8);
//	ellipse(img,Point(250,250),Size(200,100),45,0,360,Scalar(0,0,255),-1,8);
//	ellipse(img,RotatedRect(Point(150,150),Size(100,50),0),Scalar(0,0,255),-1,8);
//
//	Point ppt[]={Point(120,50),Point(180,50),Point(210,100),Point(180,150),Point(120,150),Point(90,100)};
//	const Point* pts[]={ppt};
//	int npt[]={6};
//	fillPoly(img,pts,npt,1,Scalar(255,255,255),8 );
//	polylines(img,pts,npt,1,true,Scalar(0,134,243),2,8);
//
//	putText(img,"China",Point(120,120),CV_FONT_HERSHEY_COMPLEX,2,Scalar(0,255,255),2,8);
//
//	imshow("img",img);
//
//	waitKey(0);
//
//}






//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//Point pt;
//
//int no=0;
//
//void OnMouse(int event,int x,int y,int flags,void* param)
//{
//	Mat img=*(Mat*)param;
//	
//	switch(event)
//	{
//		case CV_EVENT_LBUTTONDOWN:
//			pt.x=x;
//			pt.y=y;
//			break;
//		case CV_EVENT_LBUTTONUP:
//			no++;
//			cout<<"Mouse down : "<<no<<endl;
//			rectangle(img,pt,Point(x,y),Scalar(0,255,0));
//			break;
//	}
//
//
//	/*if(event==CV_EVENT_LBUTTONDOWN)
//	{
//		no++;
//		cout<<"Nouse down : "<<no<<endl;
//		circle(img,Point(x,y),80,Scalar(255,0,0),2,8);
//	}*/
//}
//
//void main()
//{
//	
//	Mat img(500,500,CV_8UC3,Scalar(255,255,255));
//	namedWindow("Mouse",CV_WINDOW_AUTOSIZE);
//	setMouseCallback("Mouse",OnMouse,&img);
//	while(1)
//	{
//		imshow("Mouse",img);
//
//		if(waitKey(10)==27)
//			break;
//
//	}
//
//}
//


//
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//
//Mat dstImg;
//
//int value=120;
//
//void OnChange(int ,void* param)
//{
//	Mat srcImg=*(Mat*)param;
//	//threshold(srcImg,dstImg,value,255,THRESH_BINARY);
//	Canny(srcImg,dstImg,value,255);
//	imshow("TrackBar",dstImg);
//}
//
//void main()
//{
//	Mat srcImg=imread("1.jpg",0);
//	namedWindow("TrackBar",CV_WINDOW_AUTOSIZE);
//	createTrackbar("Threshold","TrackBar",&value,255,OnChange,&srcImg);
//	//threshold(srcImg,dstImg,value,255,THRESH_BINARY);
//	Canny(srcImg,dstImg,value,255);
//	imshow("TrackBar",dstImg);
//
//
//	waitKey(0);
//
//
//}


///////////////////////////////
/*

Êó±ê½ØÍ¼Ó¦ÓÃ

*/
///////////////////////////////

#include"opencv2/opencv.hpp"


using namespace cv;

Mat img=imread("1.jpg");
Mat temp=img.clone();
Mat ROI; 
Point pt;
bool flag=false;

void OnMouse(int event,int x,int y,int flag,void* param)
{
	switch(event)
	{
		case CV_EVENT_LBUTTONDOWN:
			flag=true;
			pt.x=x;
			pt.y=y;
		
			break;
		case CV_EVENT_MOUSEMOVE:
			if(flag)
			{
				temp.copyTo(img);
				rectangle(img,pt,Point(x,y),Scalar(0,255,0),2,8);
			}
				
			break;
		case CV_EVENT_LBUTTONUP:
			flag=false;
			ROI=temp(Rect(pt.x,pt.y,x-pt.x,y-pt.y));
			imshow("ROI",ROI);
			imwrite("ROI.bmp",ROI);
		
			break;
		default:
			break;
	}
}

void main()
{
	namedWindow("Mouse",CV_WINDOW_AUTOSIZE);
	setMouseCallback("Mouse",OnMouse,0);


	while(1)
	{
		imshow("Mouse",img);
		
		if(27==waitKey(10))
			break;

	}

}








//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//double Fps;
//int value;
//int FramePos;
//
//void OnChange(int,void* param)
//{
//	VideoCapture cap=*(VideoCapture*)param;
//	cap.set(CV_CAP_PROP_POS_FRAMES,value);
//}
//
//void main()
//{
//
//	Mat frame;
//	char strFps[20];
//	VideoCapture cap("1.avi");
//	if(!cap.isOpened())
//		return;
//
//	int FrameCount=cap.get(CV_CAP_PROP_FRAME_COUNT);
//
//	namedWindow("Video",CV_WINDOW_AUTOSIZE);
//	createTrackbar("Frame","Video",&value,FrameCount,OnChange,&cap);
//
//
//	Fps=cap.get(CV_CAP_PROP_FPS);
//	sprintf(strFps,"Fps:%0.1f/s",Fps);
//	
//	while(1)
//	{
//		FramePos=cap.get(CV_CAP_PROP_POS_FRAMES);
//		setTrackbarPos("Frame","Video",FramePos);
//		cap>>frame;
//		if(frame.empty())
//			break;
//		putText(frame,strFps,Point(5,30),CV_FONT_HERSHEY_COMPLEX_SMALL,1,Scalar(0,255,0),1,8);
//		imshow("Video",frame);
//		if(27==waitKey(1000/Fps))
//			return;
//	}
//	cap.release();
//	destroyAllWindows();
//
//
//}











