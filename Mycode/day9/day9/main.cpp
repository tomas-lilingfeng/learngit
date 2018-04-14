//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//void main()
//{
//	Mat dst = imread("2.jpg", 0);
//	imshow("dst", dst);
//
//	MatND dstHist;
//	int dims = 1;
//	int bins[1] = {5};
//	float hranges[] = { 0,50,100,150,200,256 };
//	const float* rangles[] = { hranges };
//	int channels = 0;
//	calcHist(&dst, 1, &channels, Mat(), dstHist, dims, bins, rangles);
//	
//	int scale = 1;
//	int size = 256;
//	Mat dstImg(size * scale, size , CV_8UC3, Scalar(0));
//	double minValue = 0, maxValue = 0;
//	minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
//	int hpt = saturate_cast<int>(0.9*size);
//	int j = 0;
//	for (int i = 0; i < 5; i++)
//	{
//
//		float binValue = dstHist.at<float>(i);
//		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
//		//line(dstImg, Point(j*scale, bins - 1), Point(j*scale, bins - realValue-1),Scalar(rand()%255,rand()%255,rand()%255),1,8);
//		rectangle(dstImg,Point(j*scale,size-1),Point((j+20)*scale,size-realValue-1),Scalar(0,255,0),-1 );
//		j += 50;
//	}
//	imshow("Histogram", dstImg);
//	waitKey(0);
//
//}


//
//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//void main()
//{
//	Mat srcImg = imread("05.jpg",0);
//	Mat dst;
//
//	imshow("src", srcImg);
//	MatND dstHist;
//	int dims = 1;
//	int bins = 256;
//	float hranges[] = { 0,256 };
//	const float* rangles[] = { hranges };
//	int channels = 0;
//	calcHist(&srcImg, 1, &channels, Mat(), dstHist, dims, &bins, rangles);
//		
//	int scale = 1;
//	int size = 256;
//	Mat dstImg(size * scale, size , CV_8UC3, Scalar(0));
//	double minValue = 0, maxValue = 0;
//	minMaxLoc(dstHist, &minValue, &maxValue, 0, 0);
//	int hpt = saturate_cast<int>(0.9*size);
//	//int j = 0;
//	for (int i = 0; i < 256; i++)
//	{
//		float binValue = dstHist.at<float>(i);
//		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
//		line(dstImg, Point(i*scale, bins - 1), Point(i*scale, bins - realValue-1),Scalar(0,255,0),1,8);
//		//rectangle(dstImg,Point(j*scale,size-1),Point((j+20)*scale,size-realValue-1),Scalar(0,255,0),-1 );
//		//j += 50;
//	}
//	imshow("Histogram", dstImg);
//
//	equalizeHist(srcImg, dst);
//	imshow("dst", dst);
//
//	MatND Hist_Img;
//	int dims2 = 1;
//	int bins2 = 256;
//	float hranges2[] = { 0,256 };
//	const float* rangles2[] = { hranges2 };
//	int channels2 = 0;
//	calcHist(&dst, 1, &channels2, Mat(), Hist_Img, dims, &bins2, rangles2);
//
//	int scale2 = 1;
//	int size2 = 256;
//	Mat Histdst(size2 * scale2, size2, CV_8UC3, Scalar(0));
//	double minValue2 = 0, maxValue2 = 0;
//	minMaxLoc(Hist_Img, &minValue2, &maxValue2, 0, 0);
//	int hpt2 = saturate_cast<int>(0.9*size2);
//	//int j = 0;
//	for (int k = 0; k < 256; k++)
//	{
//		float binValue2 = Hist_Img.at<float>(k);
//		int realValue2 = saturate_cast<int>(binValue2*hpt2 / maxValue2);
//		line(Histdst, Point(k*scale2, bins - 1), Point(k*scale2, bins2 - realValue2 - 1), Scalar(0, 255, 0), 1, 8);
//		//rectangle(dstImg,Point(j*scale,size-1),Point((j+20)*scale,size-realValue-1),Scalar(0,255,0),-1 );
//		//j += 50;
//	}
//	imshow("Histdst", Histdst);
//
//
//
//
//	waitKey(0);
//
//
//
//}


//#include"opencv2/opencv.hpp"
//#define WINDOW_NAME1 "【原始图】" 
//
//
//using namespace cv;
//
//Mat g_srcImage; Mat g_hsvImage; Mat g_hueImage;
//int g_bins = 30;//直方图组距
//
//
//void on_BinChange(int, void*);
//
//void main()
//{
//	g_srcImage = imread("1.jpg", 1);
//
//	resize(g_srcImage, g_srcImage, Size(g_srcImage.cols / 4, g_srcImage.rows / 4));
//	cvtColor(g_srcImage, g_hsvImage, CV_BGR2HSV);
//
//	g_hueImage.create(g_hsvImage.size(), g_hsvImage.depth());
//	int ch[] = { 0, 0 };
//	mixChannels(&g_hsvImage, 1, &g_hueImage, 1, ch, 1);
//
//	namedWindow(WINDOW_NAME1, CV_WINDOW_AUTOSIZE);
//	createTrackbar("色调组距 ", WINDOW_NAME1, &g_bins, 180, on_BinChange);
//	on_BinChange(0, 0);
//
//	imshow(WINDOW_NAME1, g_srcImage); 
//
//	waitKey(0);
//
//}
//
//void on_BinChange(int, void*)
//{
//	MatND hist;
//	int histSize = MAX(g_bins, 2);
//	float hue_range[] = { 0, 180 };
//	const float* ranges = { hue_range };
//
//	calcHist(&g_hueImage, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
//	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());
//
//	MatND backproj;
//	calcBackProject(&g_hueImage, 1, 0, hist, backproj, &ranges, 1, true);
//
//	imshow("反向投影图", backproj);
//
//	int w = 400; int h = 400;
//	int bin_w = cvRound((double)w / histSize);
//	Mat histImg = Mat::zeros(w, h, CV_8UC3);
//
//	for (int i = 0; i < g_bins; i++)
//	{
//		rectangle(histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(100, 123, 255), -1);
//	}
//
//	imshow("直方图", histImg);
//}
//
//
//
//

#include"opencv2/opencv.hpp"

































