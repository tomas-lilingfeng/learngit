#include"opencv2/opencv.hpp"
#include<iostream>
#include<iomanip>

using namespace cv;
using namespace std;


void main()
{
	Mat srcImg = imread("1.jpg");  //¶ÁÈ¡Ä£°åÍ¼Ïñ
	imshow("src", srcImg);
	cvtColor(srcImg, srcImg, CV_BGR2GRAY);
	threshold(srcImg, srcImg, 100, 255, CV_THRESH_BINARY); 
	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;	
	findContours(srcImg, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	Mat srcImg2 = imread("2.jpg");  //¶ÁÈ¡´ý²âÊÔÍ¼Æ¬
	imshow("src2", srcImg2);
	Mat dstImg = srcImg2.clone();
	cvtColor(srcImg2, srcImg2, CV_BGR2GRAY);
	threshold(srcImg2, srcImg2, 100, 255, CV_THRESH_BINARY); 

	vector<vector<Point>> contours2;
	vector<Vec4i> hierarcy2;
		
	findContours(srcImg2, contours2, hierarcy2, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	

		for(int i=0; i<contours2.size(); i++)
		{	 
			double matchRate = matchShapes(contours[0], contours2[i], CV_CONTOURS_MATCH_I1, 0.0);
			cout<<"index="<<i<<"---"<<setiosflags(ios::fixed)<<matchRate<<endl;
			if(matchRate<=0.1)
				drawContours(dstImg, contours2, i, Scalar(0, 255, 0), 2, 8);
			
			
		}
	imshow("dst", dstImg);
	waitKey(0);	


}