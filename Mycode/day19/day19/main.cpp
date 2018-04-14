
#include"opencv2/opencv.hpp"
#include<iostream>

using namespace cv;
using namespace std;

void main()
{
		Mat frame;
	char outfile[50];
	VideoCapture cap("bike.avi");
	if(!cap.isOpened())
		return;
	int totalFrame=cap.get(CV_CAP_PROP_FRAME_COUNT);
	
	for(int i=1;i<=totalFrame;i++)
	{
		sprintf(outfile,"E:\\pict\\%d.bmp",i);
		cap>>frame;
		if(frame.empty())
			break;
		imwrite(outfile,frame);
		imshow("video",frame);
		waitKey(15);

	}
	cap.release();
	destroyAllWindows();


}











//#include"opencv2/opencv.hpp"
//#include<iostream>
//
//using namespace cv;
//using namespace std;
//
//void main()
//{
//	Mat img1=imread("");
//	Mat img2=imread("");
//	imshow("img1",img1);
//	imshow("img2",img2);
//
//	Mat gray1,gray2;
//	cvtColor(img1,img1,CV_BGR2GRAY);
//	cvtColor(img2,img2,CV_BGR2GRAY);
//
//	Mat diff;
//	absdiff(img1,img2,diff);
//	threshold(diff,diff,45,255,CV_THRESH_BINARY);
//	imshow("threshold",diff);
//
//	waitKey(0);
//
//}
