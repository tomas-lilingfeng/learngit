//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//Mat srcImg, dst;
//Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
//int valueI = 1;
//
//void Oniterations(int, void*)
//{
//	dilate(srcImg, dst, element, Point(-1, -1), valueI);  //≈Ú’Õ
// 	//erode(srcImg, dst, element, Point(-1, -1), valueI);     //∏Ø ¥
//	imshow("dst", dst);
//}
//
//void main()
//{
//	srcImg = imread("2.jpg");
//	namedWindow("dst");
//
//	
//	createTrackbar("iterations", "dst", &valueI, 40, Oniterations, 0);
//
//	Oniterations(valueI, 0);
//	
//	imshow("src", srcImg);
//	imshow("dst", dst);
//
//
//
//	waitKey(0);
//}
//
//

//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//void main()
//{
//	Mat img1 = imread("A.bmp");
//	Mat img2 = imread("B.bmp");
//	Mat diff_img = img1 - img2;
//	imshow("diff", diff_img);
//	Mat gray;
//	cvtColor(diff_img, gray, COLOR_BGR2GRAY);
//	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3);
//	imshow("adapt", gray);
//
//	Mat k0 = getStructuringElement(MORPH_RECT, Size(21,21));
//	Mat k1 = getStructuringElement(MORPH_RECT, Size(11, 11));
//	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
//
//	morphologyEx(gray, gray, MORPH_OPEN, element);
//	medianBlur(gray, gray, 9);
//	dilate(gray, gray, k0);
//	imshow("dst", gray);
//
//	waitKey(0);
//
//
//
//
//	waitKey(0);
//
//
//
//}


#include"opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat srcImg=imread("2.jpg",0);
	Mat dst;
	Canny(srcImg,dst,30,100);
	imshow("dst", dst);

	waitKey(0);




}













