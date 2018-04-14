#include"opencv2/opencv.hpp"
#include<iostream>
using namespace cv;
using namespace std;

void main()
{
	//Mat temp = imread("temp.png");
	//Mat src = imread("src.png");
	//imshow("temp", temp);
	//imshow("src", src);
	//Mat dst = src.clone();//原图备份
	//int width = src.cols - temp.cols + 1;
	//int height = src.cols - temp.cols + 1;
	//Mat result(height, height, CV_32FC1);
	//matchTemplate(src, temp, result, CV_TM_CCOEFF_NORMED);
	//imshow("result", result);
	//normalize(result, result, 0, 1, NORM_MINMAX, -1);

	//double minValue, maxValue;
	//Point minLoc, maxLoc;
	//minMaxLoc(result, &minValue, &maxValue, &minLoc, &maxLoc);

	//cout << "minValue = " << minValue << endl;
	//cout << "maxValue = " << maxValue << endl;

	//rectangle(dst, maxLoc, Point(maxLoc.x + temp.cols, maxLoc.y + temp.rows), Scalar(0, 255, 0), 2, 8);

	//imshow("dst", dst);

	//waitKey(0);

	//Mat frame;
	//Mat templateImg = imread("green.jpg");
	//Mat resultImg;
	//VideoCapture cap("1.mp4");
	//if (!cap.isOpened())
	//	return;
	//int resultImg_cols;
	//int resultImg_rows;

	//while (1)
	//{
	//	cap >> frame;
	//	if (frame.empty())
	//		break;
	//	Mat showImg = frame.clone();
	//	resultImg_cols = frame.cols - templateImg.cols + 1;
	//	resultImg_rows = frame.rows - templateImg.rows + 1;
	//	resultImg.create(resultImg_cols, resultImg_rows, CV_32FC1);
	//	matchTemplate(frame, templateImg, resultImg, CV_TM_CCOEFF_NORMED); //化相关系数匹配法(最好匹配1)
	//	normalize(resultImg, resultImg, 0, 1, NORM_MINMAX, -1);

	//	double minValue, maxValue;
	//	Point minLoc, maxLoc;
	//	Point matchLoc;

	//	minMaxLoc(resultImg, &minValue, &maxValue, &minLoc, &maxLoc);
	//	//cout<<"max_value= "<<maxValue<<endl;
	//	//cout<<"min_value= "<<minValue<<endl;
	//	if (maxValue >= 0.8)
	//		rectangle(showImg, maxLoc, Point(maxLoc.x + templateImg.cols, maxLoc.y + templateImg.rows), Scalar(0, 255, 0), 2);

	//	//imshow("frame", frame);
	//	imshow("result", showImg);
	//	if (27 == waitKey(10))
	//		break;
	//}
	//destroyAllWindows();


	//Mat srcImg = imread("src.png");
	//Mat templateImg = imread("temp.png");
	//Mat resultImg;
	//Mat showImg = srcImg.clone();

	//int resultImg_cols = srcImg.cols - templateImg.cols + 1;
	//int resultImg_rows = srcImg.rows - templateImg.rows + 1;

	//resultImg.create(resultImg_cols, resultImg_rows, CV_32FC1);
	//matchTemplate(srcImg, templateImg, resultImg, CV_TM_CCOEFF_NORMED);
	//normalize(resultImg,resultImg,0,1,NORM_MINMAX);
	//Mat midImg = resultImg.clone();
	//double matchValue;
	//int count0 = 0;
	//int tempW = 0, tempH = 0;
	//char matchRate[10];
	//for (int i = 0; i < resultImg_rows; i++)
	//{
	//	for (int j = 0; j < resultImg_cols; j++)
	//	{
	//		matchValue = resultImg.at<float>(i, j);
	//		sprintf(matchRate, "%0.2f", matchValue);
	//		if (matchValue >= 0.98 && (abs(j - tempW) > 5) && (abs(i - tempH) > 5))
	//		{
	//			count0++;
	//			putText(showImg, matchRate, Point(j +templateImg.cols, i + 15),CV_FONT_HERSHEY_COMPLEX,1, Scalar(0, 255, 0), 1, 8);
	//			rectangle(showImg, Point(j,i),Point(j+templateImg.cols,i+templateImg.rows) ,Scalar(0, 255, 0),2,8);
	//			tempW = j;
	//			tempH = i;
	//		}
	//	}
	//}
	//cout << "count = " << count0 << endl;
	//imshow("resultImg", resultImg);
	//imshow("dst", showImg);

	//waitKey(0);


	Mat srcImg = imread("src.png");
	Mat tempImg = srcImg.clone();
	Mat draw(srcImg.rows, srcImg.cols, CV_8UC1);
	cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	threshold(srcImg, srcImg, 100, 255, CV_THRESH_BINARY);
	imshow("srcImg", srcImg);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//findContours(srcImg, contours, CV_RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//findContours(srcImg, contours, CV_RETR_LIST, CHAIN_APPROX_SIMPLE);
	//findContours(srcImg, contours, CV_RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	findContours(srcImg, contours, CV_RETR_TREE, CHAIN_APPROX_);


	drawContours(tempImg, contours, -1, Scalar(0, 255, 0), 2, 8);
	cout << "NUM = " << contours.size() << endl;
	imshow("contours", tempImg);

	waitKey(0);


		

}