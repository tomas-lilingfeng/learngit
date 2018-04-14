//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace std;
//using namespace cv;
//#define N 8
//
//void main()
//{
//
//	Mat img=imread("1.jpg");
//	imshow("src",img);
//	Mat dst=img.clone();
////动态地址访问
//	/*int rowNumber=img.rows;
//	int colNumber=img.cols;
//
//	for(int i=0;i<rowNumber;i++)
//	{
//		for(int j=0;j<colNumber;j++)
//		{
//			dst.at<Vec3b>(i,j)[0]=255;
//			dst.at<Vec3b>(i,j)[1]=0;
//			dst.at<Vec3b>(i,j)[2]=0;
//		}
//	}*/
//	
//	//int rowNumber=img.rows;
//	//int colNumber=img.cols*img.channels();
//	//for(int i=0;i<rowNumber;i++)
//	//{
//	//	uchar* data=dst.ptr<uchar>(i);//获取每一行首地址
//	//	for(int j=0;j<colNumber;j++)
//	//	{
//	//		switch(j%3)
//	//		{
//	//		case 0:
//	//			data[j]=data[j]/N*N+N/2;
//	//			break;
//	//		case 1:
//	//			data[j]=data[j]/N*N+N/2;
//	//			break;
//	//		case 2:
//	//			data[j]=data[j]/N*N+N/2;
//	//			break;
//	//		default:
//	//			break;
//	//		}
//	//	}
//	//}
//
//	int rowNumber=img.rows;
//	int colNumber=img.cols*img.channels();
//	int i,j;
//	for(int k=0;k<1000;k++)
//	{
//		i=rand()%rowNumber;
//		j=rand()%colNumber/3*3;
//		uchar* data=dst.ptr<uchar>(i);//获取每一行首地址
//		data[j]=255;
//		data[++j]=255;
//		data[++j]=255;
//	}
//		
//		
//	
//
//
//
//	imshow("dst",dst);
//	//cout<<dst<<endl;
//
//	if(27==waitKey(0))
//		return;
//
//}


#include"opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat src1=imread("73.bmp");
	Mat src2=imread("82.bmp");
	Mat dst;

	addWeighted(src1,0.5,src2,0.5,0,dst);
	
	//absdiff(src1,src2,dst);
	imshow("dst",dst);
	if(27==waitKey(0))
		return;




}












