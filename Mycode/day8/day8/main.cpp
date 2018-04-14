#include"opencv2/opencv.hpp"

using namespace cv;

void main()
{
	//Mat srcImg = imread("B.jpg", 0);
	//Mat src1,dst;
	//dst = imread("B.jpg");
	////blur(srcImg, srcImg, Size(5, 5), Point(-1, -1));
	//Canny(srcImg, src1, 50, 200, 3);
	//vector<Vec2f>lines;
	//HoughLines(src1, lines, 1, CV_PI / 180, 140);
	//for (size_t i = 0; i < lines.size(); i++)
	//{
	//	float rho = lines[i][0], theta = lines[i][1];
	//	Point pt1, pt2;
	//	double a = cos(theta), b = sin(theta);
	//	double x0 = a*rho, y0 = b*rho;
	//	pt1.x = cvRound(x0 + 1000 * (-b));
	//	pt1.y = cvRound(y0 + 1000 * (a));
	//	pt2.x = cvRound(x0 - 1000 * (-b));
	//	pt2.y = cvRound(y0 - 1000 * (a));
	//	line(dst, pt1, pt2, Scalar(0, 255, 0), 1);
	//}
	//imshow("srcImg", srcImg);
	//imshow("src1", src1);

	//imshow("dst", dst);
	//waitKey(0);
	//destroyAllWindows();
	///HoughLines()用法
	//Mat cannyImg;
	//Mat src = imread("B.png");
	//Mat dstImg = src.clone();
	//imshow("src", src);

	//cvtColor(src, src, CV_BGR2GRAY);
	//Canny(src, cannyImg, 50, 200, 3);
	//imshow("Canny", cannyImg);
	//vector<Vec2f> lines;  //定义矢量结构lines用于存放得到的线段矢量集合
	//HoughLines(cannyImg, lines, 1, CV_PI/180, 150, 0, 0);

	//for(size_t i = 0; i<lines.size(); i++)
	//{
	//	float rho = lines[i][0], theta = lines[i][1];
	//	Point pt1, pt2;
	//	double a = cos(theta), b = sin(theta);
	//	double x0 = a *rho, y0 = b* rho;
	//	pt1.x = cvRound(x0 + 1000*(-b));
	//	pt1.y = cvRound(y0 + 1000*(a));
	//	pt2.x = cvRound(x0 - 1000*(-b));
	//	pt2.y = cvRound(y0 - 1000*(a));
	//	line(dstImg, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	//}
	//imshow("dst", dstImg);

	//waitKey(0);
	//destroyAllWindows();

	Mat src = imread("C.jpg");
	Mat dst = src.clone();
	imshow("src", src);

	cvtColor(src, src, CV_BGR2GRAY);
	GaussianBlur(src, src, Size(3, 3), 2, 2);
	imshow("src1", src);
	vector<Vec3f> circles;
	HoughCircles(src, circles, CV_HOUGH_GRADIENT, 1.5, 30, 250, 100, 40, 70);
	for (size_t i = 0; i<circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(dst, center, 3, Scalar(0, 0, 255), -1, 8, 0);
		circle(dst, center, radius, Scalar(0, 255, 0), 3, 8, 0);
	}
	imshow("dst", dst);
	waitKey(0);



}
