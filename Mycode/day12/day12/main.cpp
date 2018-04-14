//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//void main()
//{
//	Mat srcImg=imread("car5.jpg");
//	Mat dstImg=srcImg.clone();
//
//	medianBlur(srcImg,srcImg,5);
//	cvtColor(srcImg,srcImg,CV_BGR2GRAY);
//	threshold(srcImg,srcImg,100,255,CV_THRESH_BINARY);
//
//	Mat element=getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));
//	dilate(srcImg,srcImg,element);
//	imshow("srcImg",srcImg);
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarcy;
//	findContours(srcImg,contours,hierarcy,CV_RETR_TREE,CHAIN_APPROX_NONE);
//	vector<Rect> boundRect(contours.size());
//	//drawContours(dstImg,contours,-1,Scalar(0,0,255),2,8);
//	int y0=0,x0=0,w0=0,h0=0;
//	Mat img=dstImg.clone();
//	for(int i=0;i<contours.size();i++)
//	{
//		char str[10];
//		sprintf(str,"%d",i);
//		boundRect[i]=boundingRect(Mat(contours[i]));
//		//drawContours(dstImg,contours,i,Scalar(0,0,255),2,8);
//		x0=boundRect[i].x;
//		y0=boundRect[i].y;
//		w0=boundRect[i].width;
//		h0=boundRect[i].height;
//		if(w0>srcImg.cols/12 && h0>srcImg.rows/6 && w0<srcImg.cols/6 && h0<srcImg.rows*5/6)
//		{
//			rectangle(dstImg,Point(x0,y0),Point(x0+w0,y0+h0),Scalar(0,255,0),2,8);
//			Mat imgageROI=img(Rect(x0,y0,w0,h0));
//			imshow(str,imgageROI);
//		}
//	}
//	imshow("boundRect",dstImg);
//	waitKey(0);
//
//
//}






//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//
//void main()
//{
//	Mat srcImg=imread("10.png");
//	imshow("src",srcImg);
//	Mat dstImg=srcImg.clone();
//	medianBlur(srcImg,srcImg,3);
//	GaussianBlur(srcImg,srcImg,Size(3,3),0,0);
//	cvtColor(srcImg,srcImg,CV_BGR2GRAY);
//	threshold(srcImg,srcImg,100,255,CV_THRESH_BINARY);
//	imshow("threshold",srcImg);
//
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarcy;
//
//	findContours(srcImg,contours,hierarcy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
//	cout<<"num = "<<contours.size()<<endl;
//
//	vector<Rect> boundRect(contours.size());
//	vector<RotatedRect> box(contours.size());
//	Point2f rect[4];
//	for(int i=0;i<contours.size();i++)
//	{
//		box[i]=minAreaRect(Mat(contours[i]));
//		boundRect[i]=boundingRect(Mat(contours[i]));
//		cout<<"angle : "<<box[i].angle<<endl;
//		cout<<"center : "<<box[i].center<<endl;
//		cout<<"height : "<<box[i].size.height<<endl;
//		cout<<"width : "<<box[i].size.width<<endl<<endl;
//		circle(dstImg,Point(box[i].center.x,box[i].center.y),5,Scalar(0,255,0),-1,8);
//
//		char width[20],height[20];
//		sprintf(width,"width = %0.2f",box[i].size.width);
//		sprintf(height,"height = %0.2f",box[i].size.height);
//
//		box[i].points(rect);
//
//		rectangle(dstImg,Point(boundRect[i].x,boundRect[i].y),Point(boundRect[i].x+boundRect[i].width,boundRect[i].y+boundRect[i].height),Scalar(0,255,0),2,8);
//
//		for(int j=0;j<4;j++)
//		{
//			line(dstImg,rect[j],rect[(j+1)%4],Scalar(0,0,255),2,8);
//
//		}
//		
//		putText(dstImg,width,box[i].center,CV_FONT_HERSHEY_COMPLEX_SMALL,0.85,Scalar(0,0,255),1,8);
//		putText(dstImg,height,Point(box[i].center.x,box[i].center.y+20),CV_FONT_HERSHEY_COMPLEX_SMALL,0.85,Scalar(0,0,255),1,8);
//	}
//
//	imshow("dst",dstImg);
//	waitKey(0);
//
//
//
//}




















#include"opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat srcImg=imread("qrcode.jpg");
	imshow("src",srcImg);
	Mat dstImg=srcImg.clone();
	
	GaussianBlur(srcImg,srcImg,Size(3,3),0,0);
	cvtColor(srcImg,srcImg,CV_BGR2GRAY);
	Canny(srcImg,srcImg,100,200);

	imshow("threshold",srcImg);
	Mat element=getStructuringElement(MORPH_RECT,Size(11,11),Point(-1,-1));
	dilate(srcImg,srcImg,element);
	imshow("dilate",srcImg);
	erode(srcImg,srcImg,element);
	imshow("erode",srcImg);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;

	findContours(srcImg,contours,hierarcy,CV_RETR_TREE,CV_CHAIN_APPROX_NONE);
	
	vector<Rect> boundRect(contours.size());
	vector<RotatedRect> box(contours.size());
	Point2f rect[4];
	float angle=0;
	for(int i=0;i<contours.size();i++)
	{
		box[i]=minAreaRect(contours[i]);
		boundRect[i]=boundingRect(Mat(contours[i]));
		if(box[i].size.width<100||box[i].size.height<100)
			continue;
		angle=box[i].angle;

		box[i].points(rect);
		rectangle(dstImg,Point(boundRect[i].x,boundRect[i].y),Point(boundRect[i].x+boundRect[i].width,boundRect[i].y+boundRect[i].height),Scalar(0,255,0),2,8);
		for(int j=0;j<4;j++)
		{
			line(dstImg,rect[j],rect[(j+1)%4],Scalar(0,0,255),2,8);

		}
		imshow("temp",dstImg);
		if(0<abs(angle)&&abs(angle)<=45)
			angle=angle;
		else if(45<abs(angle)&&abs(angle)<=90)
			angle=90-abs(angle);
		Point2f center=box[i].center;
		double angle0=angle;
		double scale=0.6;
		Mat roateM;
		roateM=getRotationMatrix2D(center,angle,scale);
		warpAffine(dstImg,dstImg,roateM,Size(dstImg.size().width*1.5,dstImg.size().height*1.5));		
	}

	imshow("roateM",dstImg);
	Mat dst1=dstImg.clone();

	GaussianBlur(dstImg,dstImg,Size(3,3),0,0);
	cvtColor(dstImg,dstImg,CV_BGR2GRAY);
	Canny(dstImg,dstImg,100,200);

	
	Mat element1=getStructuringElement(MORPH_RECT,Size(11,11),Point(-1,-1));
	dilate(dstImg,dstImg,element1);
	
	erode(dstImg,dstImg,element1);
	




	vector<vector<Point>> contours1;
	vector<Vec4i> hierarcy1;

	findContours(dstImg,contours1,hierarcy1,CV_RETR_TREE,CV_CHAIN_APPROX_NONE);
	
	vector<Rect> boundRect1(contours.size());
	vector<RotatedRect> box1(contours.size());
	
	Mat imgageROI;
	for(int i=0;i<contours1.size();i++)
	{
		box1[i]=minAreaRect(contours1[i]);
		boundRect1[i]=boundingRect(Mat(contours1[i]));
		if(box1[i].size.width<100||box1[i].size.height<100)
			continue;
	
		int x0=boundRect1[i].x;
		int y0=boundRect1[i].y;
		int w0=boundRect1[i].width;
		int h0=boundRect1[i].height;
		
		
		imgageROI=dst1(Rect(x0,y0,w0,h0));
		
	}
	imshow("ROI",imgageROI);
	
	waitKey(0);




}




















