//#include"opencv2/opencv.hpp"
//#include"opencv2/legacy/legacy.hpp"
//#include"opencv2/nonfree/nonfree.hpp"
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//
//void main()
//{
//	Mat srcImg1=imread("00.jpg");
//	Mat srcImg2=imread("11.jpg");
//	//定义SIFT特征检测类的对象
//	SiftFeatureDetector siftDetector1;
//	SiftFeatureDetector siftDetector2;
//	//定义KeyPoint变量
//	vector<KeyPoint>keyPoints1;
//	vector<KeyPoint>keyPoints2;
//	//特征点检测
//	siftDetector1.detect(srcImg1,keyPoints1);
//	siftDetector2.detect(srcImg2,keyPoints2);
//	//绘制特征点
//	Mat feature_pic1,feature_pic2;
//	drawKeypoints(srcImg1,keyPoints1,feature_pic1,Scalar::all(-1));
//	drawKeypoints(srcImg2,keyPoints2,feature_pic2,Scalar::all(-1));
//
//	imshow("src1",srcImg1);
//	imshow("src2",srcImg2);
//
//	imshow("feature1",feature_pic1);
//	imshow("feature2",feature_pic2);
//	//提取特征描述符
//	SiftDescriptorExtractor descriptor;
//	Mat description1;
//	descriptor.compute(srcImg1,keyPoints1,description1);
//	Mat description2;
//	descriptor.compute(srcImg2,keyPoints2,description2);
//
//	BruteForceMatcher<L2<float>>matcher;
//	vector<DMatch>matches;
//	matcher.match(description1,description2,matches);
//
//	std::nth_element(matches.begin(),matches.begin()+9,matches.end());
//	matches.erase(matches.begin()+10,matches.end());
//	
//	Mat result;
//	drawMatches(srcImg1,keyPoints1,srcImg2,keyPoints2,matches,result,Scalar(0,0,255));
//	imshow("Match",result);
//	waitKey(0);
//	
//}
//
//


#include <iostream>
#include "Sales_item.h"

int main() 
{
    Sales_item book;

    // read ISBN, number of copies sold, and sales price
    std::cin >> book;
    // write ISBN, number of copies sold, total revenue, and average price
    std::cout << book << std::endl;

    return 0;
}




