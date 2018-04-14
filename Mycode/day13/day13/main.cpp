#include"opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

void main()
{
	//Mat srcImg = imread("10.png");
	//imshow("src", srcImg);
	//Mat dstImg = srcImg.clone();
	//GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0);
	//cvtColor(srcImg, srcImg, CV_BGR2GRAY);
	//Canny(srcImg, srcImg, 100, 200);
	//imshow("Canny", srcImg);

	//vector<vector<Point>> contours;
	//vector<Vec4i> hierarcy;
	//
	//findContours(srcImg, contours, hierarcy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
	//cout<<"num="<<contours.size()<<endl;

	//Point2f center;  //定义圆中心坐标
	//float radius;  //定义圆半径
	//for(int i=0; i<contours.size(); i++)  //依次遍历每个轮廓
	//{
	//	minEnclosingCircle(Mat(contours[i]), center, radius);
	//	drawContours(dstImg, contours, i, Scalar(0, 0, 255), 2, 8);
	//	circle(dstImg, center, radius, Scalar(0, 255, 0), 2, 8);  //绘制第i个轮廓的最小外接圆
	//}	
	//imshow("dst", dstImg);
 //
	//waitKey(0);



	//Mat srcImg = imread("10.png");
	//imshow("src", srcImg);
	//Mat dstImg = srcImg.clone();
	//GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0);
	//cvtColor(srcImg, srcImg, CV_BGR2GRAY);
	//Canny(srcImg, srcImg, 100, 200);
	//imshow("Canny", srcImg);

	//vector<vector<Point>> contours;
	//vector<Vec4i> hierarcy;
	//
	//findContours(srcImg, contours, hierarcy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
	//cout<<"num="<<contours.size()<<endl;
	//vector<RotatedRect> box(contours.size());
	//Point2f rect[4];
	//for(int i=0; i<contours.size(); i++)
	//{
	//	box[i] = fitEllipse(Mat(contours[i]));
	//	//ellipse(dstImg, box[i].center, Size(box[i].size.width/2, box[i].size.height/2), box[i].angle, 0, 360, Scalar(0, 255, 0), 2, 8);
	//	ellipse(dstImg, box[i], Scalar(0, 255, 0), 2, 8);
	//	
	//}	
	//
	//imshow("dst", dstImg);
 //
	//waitKey(0); 

	//Mat srcImg = imread("22.jpg");
	//imshow("src", srcImg);
	//Mat dstImg = srcImg.clone();
	//Mat dstImg2(srcImg.size(), CV_8UC3, Scalar::all(0));

	//GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0);
	//cvtColor(srcImg, srcImg, CV_BGR2GRAY);
	////Canny(srcImg, srcImg, 100, 200);
	//threshold(srcImg, srcImg, 200, 255, CV_THRESH_BINARY_INV);
	//imshow("threshold", srcImg);

	//vector<vector<Point>> contours;
	//vector<Vec4i> hierarcy;
	//findContours(srcImg, contours, hierarcy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
	//cout<<"num="<<contours.size()<<endl;
	//vector<vector<Point>> contours_poly(contours.size());
	//
	//for(int i=0; i<contours.size(); i++)
	//{		 
	//	approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
	//	drawContours(dstImg, contours, i, Scalar(0, 255, 0), 2, 8);
	//	drawContours(dstImg2, contours_poly, i, Scalar(0, 255, 255), 2, 8);  //绘制多边形逼近
	//}	
	// 
	//imshow("dst", dstImg);
	//imshow("approx", dstImg2);
 //
	//waitKey(0);

	Mat srcImg = imread("220.jpg");
	imshow("src", srcImg);
	Mat dstImg = srcImg.clone();  //原图备份
	Mat tempImg = srcImg.clone();  //原图备份
	Mat tempImg2(srcImg.rows, srcImg.cols, CV_8UC3, Scalar::all(0));  //定义全黑的和原图一样大小的图像
	Mat draw(srcImg.rows, srcImg.cols, CV_8UC3, Scalar::all(0)); //定义全黑的和原图一样大小的图像
	Mat tempImg3(srcImg.rows, srcImg.cols, CV_8UC3, Scalar::all(0)); //定义全黑的和原图一样大小的图像

	GaussianBlur(srcImg, srcImg, Size(3, 3), 0, 0);
	cvtColor(srcImg, srcImg, CV_BGR2GRAY);
	threshold(srcImg, srcImg, 100, 255, CV_THRESH_BINARY); //二值化
	imshow("threshold", srcImg);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarcy;

	findContours(srcImg, contours, hierarcy, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
	cout<<"num="<<contours.size()<<endl;
	while(1)
	{
		for(int i=0; i<contours.size(); i++)
		{
			tempImg2.copyTo(draw);  //每次进入将draw清空为全黑
			tempImg2 .copyTo(tempImg3); //每次进入将tempImg3清空为全黑
			//drawContours(dstImg, contours, i, Scalar(0, 255, 0), 5, 8);	
			drawContours(draw, contours, i, Scalar(255, 255, 255), -1, 8);	
			Mat mask;  //定义掩码
			cvtColor(draw, mask, CV_BGR2GRAY);
			tempImg.copyTo(tempImg3, mask);  //将tempImg 复制到tempImg3(只有mask部分被复制)
			imshow("draw", draw);
			imshow("result", tempImg3);
			char key = waitKey();
			if(key==27)  //按下Esc键跳出for循环
				break;
		}	
		break;
	}
 




}