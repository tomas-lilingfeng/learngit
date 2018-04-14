//#include"opencv2/opencv.hpp"
//
//using namespace cv;
//
//
//void main()
//{
//	Mat src=imread("1.jpg");
//	imshow("src",src);
	//Mat lvbo;
	//bilateralFilter(src, lvbo, 3, 300, 300, BORDER_DEFAULT);//双边滤波
	//imshow("lvbo",lvbo);
	//Mat gray;
	//cvtColor(lvbo, gray, CV_BGR2GRAY);//灰度转换
	//imshow("GRAY",gray);
	//medianBlur(gray, gray, 3);//中值滤波
	//Sobel(gray, gray, 0, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	//imshow("Sobel",gray);
	//GaussianBlur(gray, gray, Size(5, 1), 0, 0);
	//threshold(gray, gray, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU); //二值化
	////形态学处理
	//Mat element=getStructuringElement(MORPH_RECT,Size(3,3));//元素结构
	//Mat elementtwo=getStructuringElement(MORPH_RECT,Size(9,3));
	//Mat dilation;
	//Mat erosion;
	//erode(gray, erosion, element,Point(-1,-1), 1);//腐蚀1次
	//imshow("erosion",erosion);
	//dilate(erosion, dilation, elementtwo,Point(-1,-1),5);//膨胀5次
	//imshow("dilate",dilation);

	//int thresh = 100;
	//int max_thresh = 255;
	//RNG rng(12345);                      //vector<Vec4i>hierarchy是定义的层级
	//Mat threshold_output;               //contours被定义成二维浮点型向量，这里面将来会存储找到的边界的（x,y）坐标
	//vector<vector<Point> > contours;//vector是容器 可以理解成一个可变长的数组 第一句生成一个point型的二维数组变量contours（每一维长度均可变）
	//vector<Vec4i> hierarchy;//生成一个Vec4i型的一维数组hierarchy <>里面写的是容器的数据类型 Vec4i指的是四个整形数
	//threshold( dilation, threshold_output, thresh, 255, THRESH_BINARY );
	//imshow("边缘检测图",threshold_output);
	////waitKey(0);
	////destroyWindow( "边缘检测图" );
	//findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );/// 找到轮廓
	//imshow("轮廓检测图",threshold_output);
	////waitKey(0);
	////destroyWindow( "轮廓检测图" );

	////多边形逼近轮廓 + 获取矩形
	//vector<vector<Point> > contours_poly( contours.size() );
	//vector<Rect> boundRect( contours.size() );//bounkRect是获取矩形尺寸的一个函数，一般有4个参数eg：（0，0，344，,567）

	//for( int i = 0; i < contours.size(); i++ )
	//{ 
	//   approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );    //逼近多边形曲线
 //      boundRect[i] = boundingRect( Mat(contours_poly[i]) );           //返回外部矩形边界
	//}
 // // 画多边形轮廓 + 包围的矩形框 （可以省略，暂留用于检查识别情况）
	//Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	//Mat lvb=lvbo.clone();
	//for( int i = 0; i< contours.size(); i++ )
	//{
 //      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//定义颜色
 //      //rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//画矩形
	//   rectangle( lvb, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//画矩形
	//}
	//imshow( "轮廓图", lvb );
	////waitKey(0);
	////destroyWindow( "轮廓图" );
	////车牌位置粗提取
	//int area=drawing.rows*drawing.cols;
	////cout<<"图像总面积"<<area<<endl;
	//int j,squ=0,num=(-1);
	//int width[3333],height[3333];
	//for(j=0;j<contours.size();j++)
	//{
	//	//boundRect[j].tl()
	//	width[j]=boundRect[j].br().x-boundRect[j].tl().x;
	//	height[j]=boundRect[j].br().y-boundRect[j].tl().y;
	//	float abc=width[j]/height[j];
	//	if(abc>=2.2&&abc<=4)//边长比筛选、面积筛选
	//	{
	//		if(width[j]*height[j]>squ)
	//		{
	//			if(width[j]*height[j]<=area/12)
	//			{
	//			squ=width[j]*height[j];
	//			num=j;
	//			}
	//		}
	//	}
	//}
	//if(num<0)//条件中止语句
	//{
	//	//cout<<"没有牌照或未能识别（错误代码：001）"<<endl;//没有识别出roi区域
	//	//system("pause");
	//	//exit(1);
	//	//retString = _T("");
	//	//return retString;
	//	
	//}
	//int qix,qiy,chanx,chany;
	//qix=boundRect[num].tl().x;//+(kuandu[num]/9);
	//qiy=boundRect[num].tl().y;//+(gaodu[num]/9);
	//chanx=width[num];//*7/9;
	//chany=height[num];//*7/9;
	//
	//Mat check=lvbo(Rect(qix,qiy,chanx,chany));
	//imshow( "车牌粗定位", lvbo );
	////imshow( "车牌粗定位", check );
	////waitKey(0);
	////destroyWindow( "车牌粗定位" );//车牌粗定位
 //   
	////车牌RGB信息精确提取预处理
	//Mat liuzhe;
	//liuzhe=check.clone();
	//unsigned char R = 28,G = 63,B = 130;//90<B<125;0<G<40;0<R15...R = 50,G = 75,B = 145
	//for (int i = 0; i < check.cols; i++) 
	//{
	//	for (int j = 0; j < check.rows; j++) 
	//	{
	//		Vec3b &intensity = check.at<Vec3b>(j, i);
	//		if(intensity.val[0]-B<40&&intensity.val[1]-G<30&&intensity.val[2]-R<30)// R = 50,G = 75,B = 145、、55.35.40
	//		{
	//			for(int k = 0; k < check.channels(); k++)
	//			{// calculate pixValue
	//				intensity.val[k] =0;
	//			}
	//		}else
	//		{
	//			for(int k = 0; k < check.channels(); k++)
	//			{// calculate pixValue
	//				intensity.val[k] =255;
	//			}
	//		}
	//	}
	//}
	//imshow("RGB处理", check);
	////waitKey(0);
	////destroyWindow( "RGB处理" );



	////由RGB处理后的图像作为掩码
	//Mat try1;
	//liuzhe.copyTo(try1, check);
	//imshow("try1", try1);
	//
	////车牌大致位置图的预处理
	//Mat hbcp;
	//cvtColor(try1,hbcp,CV_BGR2GRAY);

	//imshow( "hbcp",hbcp );
	//Mat threshold_outputtwo;
	//vector<vector<Point> > contoursb;
	//vector<Vec4i> hierarchyb;
	//// 使用Threshold二值化检测边缘
	////threshold( hbcp, threshold_outputtwo, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU );
	//adaptiveThreshold(hbcp, threshold_outputtwo, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 35, 3); //---自适应阈值 
	//imshow( "车牌二值化",threshold_outputtwo );
	////waitKey(0);
	////destroyWindow( "车牌二值化" );

	////Mat element1=getStructuringElement(MORPH_RECT,Size(3,3));
	////erode(threshold_outputtwo, threshold_outputtwo, element1,Point(-1,-1), 1);//腐蚀1次?????????????
	////imshow("fushi",threshold_outputtwo);
	///// 找到轮廓
	//findContours(threshold_outputtwo , contoursb, hierarchyb, CV_RETR_TREE ,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );// CV_RETR_LIST
	//imshow("轮检图",threshold_outputtwo);
	////waitKey(0);
	////destroyWindow( "轮检图" );// CV_RETR_EXTERNAL, //获取轮廓的方法（这里获取外围轮廓）  
	////  CV_CHAIN_APPROX_NONE //轮廓近似的方法（这里不近似，获取全部轮廓）  
	//// minAreaRect
	//// 对每个找到的轮廓创建可倾斜的边界框和椭圆
 //   vector<RotatedRect> minRect( contoursb.size() );

 //   for( int i = 0; i < contoursb.size(); i++ )
 //      { 
	//	 minRect[i] = minAreaRect( Mat(contoursb[i]) );
 //      }

 //   // 绘出轮廓及其可倾斜的边界框和边界椭圆
 //   Mat drawingb = Mat::zeros( threshold_outputtwo.size(), CV_8UC3 );
 //   for( int i = 0; i< contoursb.size(); i++ )
 //    {
 //      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
 //      drawContours( drawingb, contoursb, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
 //      Point2f rect_points[4];
	//   minRect[i].points( rect_points );
 //      for( int j = 0; j < 4; j++ )
 //        line( drawingb, rect_points[j], rect_points[(j+1)%4], color, 2, 8 );
 //    }

 //   imshow( "Contours", drawingb );
	////waitKey(0);
	////destroyWindow("Contours");

	////精确提取算法 及筛选
	//int cpsqu;
	//cpsqu=chanx*chany;
 //  // cout<<"车牌面积"<<cpsqu<<endl;//60822
	//int h,squb=999999,numb=(-1);
	//float kuandub[3333];
	//float gaodub[3333];
	//Point2f rect_points[4];
	//for(h=0;h<contoursb.size();h++)
	//{
	//	minRect[h].points( rect_points );
	//	int rep[4],nuk=99999,kk;
	//	for(int i=0;i<4;i++)
	//	rep[i]=rect_points[i].x+rect_points[i].y;
	//	for(int j=0;j<4;j++)
	//	{
	//		if(rep[j]<nuk)
	//		{nuk=rep[j];
	//		kk=j;}
	//	}
	//	if(kk%2==1)
	//	{
	//		kuandub[h]=sqrt(pow(rect_points[1].x-rect_points[2].x,2)+pow(rect_points[1].y-rect_points[2].y,2));
	//		gaodub[h]=sqrt(pow(rect_points[1].x-rect_points[0].x,2)+pow(rect_points[1].y-rect_points[0].y,2));
	//	}
	//	else
	//	{
	//		gaodub[h]=sqrt(pow(rect_points[1].x-rect_points[2].x,2)+pow(rect_points[1].y-rect_points[2].y,2));
	//		kuandub[h]=sqrt(pow(rect_points[1].x-rect_points[0].x,2)+pow(rect_points[1].y-rect_points[0].y,2));
	//	}
	//	
	//	float bizhi=kuandub[h]/gaodub[h];
	//	if(bizhi>=3&&bizhi<=28/7)//边长比筛选、面积筛选   ***备注：车牌外圈图片测量比值3.332  内圈3.5整  需实际测量调整。
	//	{
	//		if(kuandub[h]*gaodub[h]>cpsqu/2&&kuandub[h]*gaodub[h]<squb)
	//		{
	//			squb=kuandub[h]*gaodub[h];
	//			numb=h;
	//		}
	//	}
	//}

	//if(numb<0)//
	//{
	//	//cout<<"没有牌照或未能识别（错误代码：002）"<<endl;//roi区域没有符合比例的区域
	//	//exit(1);
	//	//retString = _T("");
	//	//return retString;
	//}

	////偏移角度计算
	//double jiaodu;//矩形倾斜角
	//double jiaj;//对角线 横边 夹角
	//double duiq;//对角线倾斜角度
	//minRect[numb].points( rect_points );
	//int xa=rect_points[1].x;//矩形左上起始点
	//int ya=rect_points[1].y;
	//int xb=rect_points[3].x;//矩形右下终止点
	//int yb=rect_points[3].y;
	//double cha=yb-ya;
	//double chb=xb-xa;
	//double he=gaodub[numb];//高
	//double wi=kuandub[numb];//宽
	//double ss=cha/chb;//(yb-ya)/(xb-xa);
	//jiaj=0;//atan(he/wi)*180/3.1416;
	//duiq=0;//atan(ss)*180/3.1416;
	//jiaodu=duiq-jiaj;

	////cout<<"角度"<<jiaodu<<endl;
	////cout<<"夹角"<<jiaj<<endl;
	////cout<<"对角线倾斜"<<duiq<<endl;

	//Point2f centers[4];
	//minRect[numb].points(centers);
	//Mat rot_mat;
	//double scale=1;
	//rot_mat= getRotationMatrix2D( centers[1],jiaodu , scale );//minRect[numb].center
	//Mat centermat;
	//warpAffine(liuzhe,centermat, rot_mat,liuzhe.size());//将rgb留存图旋转
	//imshow( "旋转后", centermat );
	////waitKey(0);
	////destroyWindow("旋转后");
//
//
//
//
//	waitKey();
//
//}




#include"opencv2/opencv.hpp"
#include<iostream>
#include "afxwin.h"
#include<stdlib.h>


using namespace std;
using namespace cv;

    CRect rect, rect2, rect3;
	CString StrPath;
	Mat src, img;
	CFont m_font;
int main()
{

	//CString retString = _T("");
	//Mat bgImage(Size(rect2.Width()-2, rect2.Height()-2), CV_8UC3, Scalar(240, 240, 240));
	//imshow("region", bgImage);
	//imshow("char", bgImage);


	src=imread("1.jpg");
	Mat lvbo;
	bilateralFilter(src, lvbo, 3, 300, 300, BORDER_DEFAULT);
	Mat gray;
	cvtColor(lvbo, gray, CV_BGR2GRAY);//灰度转换
	medianBlur(gray, gray, 3);
	Sobel(gray, gray, 0, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	GaussianBlur(gray, gray, Size(5, 1), 0, 0);
	threshold(gray, gray, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU); 
	//形态学处理
	Mat element=getStructuringElement(MORPH_RECT,Size(3,3));//元素结构
	Mat elementtwo=getStructuringElement(MORPH_RECT,Size(9,3));
	Mat dilation;
	Mat erosion;
	erode(gray, erosion, element,Point(-1,-1), 1);
	dilate(erosion, dilation, elementtwo,Point(-1,-1),5);

	int thresh = 100;
	int max_thresh = 255;
	RNG rng(12345);                      //vector<Vec4i>hierarchy是定义的层级
	Mat threshold_output;               //contours被定义成二维浮点型向量，这里面将来会存储找到的边界的（x,y）坐标
	vector<vector<Point> > contours;//vector是容器 可以理解成一个可变长的数组 第一句生成一个point型的二维数组变量contours（每一维长度均可变）
	vector<Vec4i> hierarchy;//生成一个Vec4i型的一维数组hierarchy <>里面写的是容器的数据类型 Vec4i指的是四个整形数
	threshold( dilation, threshold_output, thresh, 255, THRESH_BINARY );
	imshow("边缘检测图",threshold_output);
	//waitKey(0);
	//destroyWindow( "边缘检测图" );
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );/// 找到轮廓
	imshow("轮廓检测图",threshold_output);
	//waitKey(0);
	//destroyWindow( "轮廓检测图" );

	//多边形逼近轮廓 + 获取矩形
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );//bounkRect是获取矩形尺寸的一个函数，一般有4个参数eg：（0，0，344，,567）

	for( int i = 0; i < contours.size(); i++ )
	{ 
	   approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
	}
  // 画多边形轮廓 + 包围的矩形框 （可以省略，暂留用于检查识别情况）
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
	{
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//定义颜色
       rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//画矩形
	}
	imshow( "轮廓图", drawing );
	//waitKey(0);
	//destroyWindow( "轮廓图" );

	//车牌位置粗提取
	int area=drawing.rows*drawing.cols;
	//cout<<"图像总面积"<<area<<endl;
	int j,squ=0,num=(-1);
	int width[3333],height[3333];
	for(j=0;j<contours.size();j++)
	{
		//boundRect[j].tl()
		width[j]=boundRect[j].br().x-boundRect[j].tl().x;
		height[j]=boundRect[j].br().y-boundRect[j].tl().y;
		float abc=width[j]/height[j];
		if(abc>=2.2&&abc<=4)//边长比筛选、面积筛选
		{
			if(width[j]*height[j]>squ)
			{
				if(width[j]*height[j]<=area/12)
				{
				squ=width[j]*height[j];
				num=j;
				}
			}
		}
	}
	if(num<0)//条件中止语句
	{
		cout<<"没有牌照或未能识别（错误代码：001）"<<endl;//没有识别出roi区域
		//system("pause");
		//exit(1);
		/*retString = _T("");
		return retString;*/
	}
	int qix,qiy,chanx,chany;
	qix=boundRect[num].tl().x;//+(kuandu[num]/9);
	qiy=boundRect[num].tl().y;//+(gaodu[num]/9);
	chanx=width[num];//*7/9;
	chany=height[num];//*7/9;
	
	Mat check=lvbo(Rect(qix,qiy,chanx,chany));
	//imshow( "车牌粗定位", lvbo );
	//waitKey(0);
	//destroyWindow( "车牌粗定位" );//车牌粗定位
    
	//车牌RGB信息精确提取预处理
	Mat liuzhe;
	liuzhe=check.clone();
	unsigned char R = 28,G = 63,B = 130;//90<B<125;0<G<40;0<R15...R = 50,G = 75,B = 145
	for (int i = 0; i < check.cols; i++) 
	{
		for (int j = 0; j < check.rows; j++) 
		{
			Vec3b &intensity = check.at<Vec3b>(j, i);
			if(intensity.val[0]-B<40&&intensity.val[1]-G<30&&intensity.val[2]-R<30)// R = 50,G = 75,B = 145、、55.35.40
			{
				for(int k = 0; k < check.channels(); k++)
				{// calculate pixValue
					intensity.val[k] =0;
				}
			}else
			{
				for(int k = 0; k < check.channels(); k++)
				{// calculate pixValue
					intensity.val[k] =255;
				}
			}
		}
	}
	imshow("RGB处理", check);
	//waitKey(0);
	//destroyWindow( "RGB处理" );

	//车牌大致位置图的预处理
	Mat hbcp;
	cvtColor(check,hbcp,CV_BGR2GRAY);
	Mat threshold_outputtwo;
	vector<vector<Point> > contoursb;
	vector<Vec4i> hierarchyb;
	// 使用Threshold二值化检测边缘
	threshold( hbcp, threshold_outputtwo, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU );
	imshow( "车牌二值化",threshold_outputtwo );
	//waitKey(0);
	//destroyWindow( "车牌二值化" );

	/// 找到轮廓
	findContours(threshold_outputtwo , contoursb, hierarchyb, CV_RETR_TREE ,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );// CV_RETR_LIST
	//imshow("轮检图",threshold_outputtwo);
	//waitKey(0);
	//destroyWindow( "轮检图" );// CV_RETR_EXTERNAL, //获取轮廓的方法（这里获取外围轮廓）  
	//  CV_CHAIN_APPROX_NONE //轮廓近似的方法（这里不近似，获取全部轮廓）  
	// minAreaRect
	// 对每个找到的轮廓创建可倾斜的边界框和椭圆
    vector<RotatedRect> minRect( contoursb.size() );

    for( int i = 0; i < contoursb.size(); i++ )
       { 
		 minRect[i] = minAreaRect( Mat(contoursb[i]) );
       }

    // 绘出轮廓及其可倾斜的边界框和边界椭圆
    Mat drawingb = Mat::zeros( threshold_outputtwo.size(), CV_8UC3 );
    for( int i = 0; i< contoursb.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawingb, contoursb, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       Point2f rect_points[4];
	   minRect[i].points( rect_points );
       for( int j = 0; j < 4; j++ )
         line( drawingb, rect_points[j], rect_points[(j+1)%4], color, 2, 8 );
     }

    imshow( "Contours", drawingb );
	//waitKey(0);
	//destroyWindow("Contours");

	//精确提取算法 及筛选
	int cpsqu;
	cpsqu=chanx*chany;
   // cout<<"车牌面积"<<cpsqu<<endl;//60822
	int h,squb=999999,numb=(-1);
	float kuandub[3333];
	float gaodub[3333];
	Point2f rect_points[4];
	for(h=0;h<contoursb.size();h++)
	{
		minRect[h].points( rect_points );
		int rep[4],nuk=99999,kk;
		for(int i=0;i<4;i++)
		rep[i]=rect_points[i].x+rect_points[i].y;
		for(int j=0;j<4;j++)
		{
			if(rep[j]<nuk)
			{nuk=rep[j];
			kk=j;}
		}
		if(kk%2==1)
		{
			kuandub[h]=sqrt(pow(rect_points[1].x-rect_points[2].x,2)+pow(rect_points[1].y-rect_points[2].y,2));
			gaodub[h]=sqrt(pow(rect_points[1].x-rect_points[0].x,2)+pow(rect_points[1].y-rect_points[0].y,2));
		}
		else
		{
			gaodub[h]=sqrt(pow(rect_points[1].x-rect_points[2].x,2)+pow(rect_points[1].y-rect_points[2].y,2));
			kuandub[h]=sqrt(pow(rect_points[1].x-rect_points[0].x,2)+pow(rect_points[1].y-rect_points[0].y,2));
		}
		
		float bizhi=kuandub[h]/gaodub[h];
		if(bizhi>=3&&bizhi<=28/7)//边长比筛选、面积筛选   ***备注：车牌外圈图片测量比值3.332  内圈3.5整  需实际测量调整。
		{
			if(kuandub[h]*gaodub[h]>cpsqu/2&&kuandub[h]*gaodub[h]<squb)
			{
				squb=kuandub[h]*gaodub[h];
				numb=h;
			}
		}
	}

	if(numb<0)//
	{
		cout<<"没有牌照或未能识别（错误代码：002）"<<endl;//roi区域没有符合比例的区域
		exit(1);
		/*retString = _T("");
		return retString;*/
	}
	//偏移角度计算
	double jiaodu;//矩形倾斜角
	double jiaj;//对角线 横边 夹角
	double duiq;//对角线倾斜角度
	minRect[numb].points( rect_points );
	int xa=rect_points[1].x;//矩形左上起始点
	int ya=rect_points[1].y;
	int xb=rect_points[3].x;//矩形右下终止点
	int yb=rect_points[3].y;
	double cha=yb-ya;
	double chb=xb-xa;
	double he=gaodub[numb];//高
	double wi=kuandub[numb];//宽
	double ss=cha/chb;//(yb-ya)/(xb-xa);
	jiaj=0;//atan(he/wi)*180/3.1416;
	duiq=0;//atan(ss)*180/3.1416;
	jiaodu=duiq-jiaj;

	cout<<"角度"<<jiaodu<<endl;
	cout<<"夹角"<<jiaj<<endl;
	cout<<"对角线倾斜"<<duiq<<endl;

	Point2f centers[4];
	minRect[numb].points(centers);
	Mat rot_mat;
	double scale=1;
	rot_mat= getRotationMatrix2D( centers[1],jiaodu , scale );//minRect[numb].center
	Mat centermat;
	warpAffine(liuzhe,centermat, rot_mat,liuzhe.size());//将rgb留存图旋转
	imshow( "旋转后", centermat );
	//waitKey(0);
	//destroyWindow("旋转后");
	
	//截取优化
	int qixb,qiyb,chanxb,chanyb;
	qixb=centers[1].x+(width[num]*2/100);
	qiyb=centers[1].y+(gaodub[numb]*16/100);//gaodu[num]*3/26
	chanxb=kuandub[numb]*96/100;
	chanyb=gaodub[numb]*72/100;//9/13;//*7/9;
	if(qixb>centermat.cols||qiyb>centermat.rows||chanxb>centermat.cols||chanyb>centermat.rows)
	{
		return 0;
	}
	
	Mat youwudi=centermat(Rect(qixb,qiyb,chanxb,chanyb));//hbcp
	Mat temp1;
	resize(youwudi, temp1, Size(rect2.Width(),rect2.Height())); 
	imshow("region", temp1);
	//imshow("11", youwudi);

	Mat huiwudi;
	cvtColor(youwudi,huiwudi,CV_BGR2GRAY);//灰度转换
	Mat erwudi;
	threshold( huiwudi,erwudi,30,255, CV_THRESH_BINARY|CV_THRESH_OTSU); 
	imshow( "车牌精定位", erwudi);
	//waitKey(0);
	//destroyWindow("车牌精定位");

	//分割车牌字符
	//cout<<"车牌图像高度"<<chanyb<<endl;
	//车牌1高度74  腐蚀元素1.6一次(6*1)
	//车牌2高度32  腐蚀元素 尝试：1.3一次（3*1）
	//chepai5 63  未尝试 6*1
	int suanzi;
	suanzi=chanyb/14;
	//形态学处理
	Mat elementc=getStructuringElement(MORPH_RECT,Size(1,7));
	Mat elementd=getStructuringElement(MORPH_RECT,Size(1,suanzi));
	Mat zxdilate;
	Mat zxerode;
	erode(erwudi,zxerode,elementd,Point(-1,-1),1);//dilate膨胀erode腐蚀
	dilate(zxerode,zxdilate,elementc,Point(-1,-1),9);//zxdilate纵向膨胀处理图
	//imshow("车牌字符处理图",zxdilate);
	//waitKey(0);
	//destroyWindow( "车牌字符处理图" );

	vector<vector<Point> > contoursc;
	vector<Vec4i> hierarchyc;
	findContours( zxdilate, contoursc, hierarchyc, CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	/// 多边形逼近轮廓 + 获取矩形
	vector<vector<Point> > contours_polyc( contoursc.size() );
	vector<Rect> boundRectc( contoursc.size() );//bounkRect是获取矩形尺寸的一个函数，一般有4个参数eg：（0，0，344，,567）

	for( int i = 0; i < contoursc.size(); i++ )
	{
		approxPolyDP( Mat(contoursc[i]), contours_polyc[i], 3, true );
       boundRectc[i] = boundingRect( Mat(contours_polyc[i]) );
	}


  /// 画多边形轮廓 + 包围的矩形框 
	Mat drawingc = Mat::zeros( zxdilate.size(), CV_8UC3 );
	for( int i = 0; i<contoursc.size(); i++ )
	{
       //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//定义颜色
		Scalar color = Scalar(0, 0, 255);
       //drawContours( drawingb, contours_polyb, i, color, 1, 8, vector<Vec4i>(), 0, Point() );//画轮廓
       //rectangle( drawingc, boundRectc[i].tl(), boundRectc[i].br(), color, 2, 8, 0 );//画矩形youwudi
	   rectangle( youwudi, boundRectc[i].tl(), boundRectc[i].br(), color, 2, 8, 0 );
	}

	Mat temp2;
	resize(youwudi, temp2, Size(rect3.Width(),rect3.Height())); 
	imshow("char", temp2);
	//imshow( "车牌的轮廓图", drawingc);
	//waitKey(0);
	//destroyWindow("车牌的轮廓图");

	int m=-1;
	int kuanc[100],gaoc[100];
	int qidianx[10],qidiany[10],zhongdianx[10],zhongdiany[10],juxing[10];//其实数组用8或9就够了
	for(int k=0;k<contoursc.size();k++)
	{
		kuanc[k]=boundRectc[k].br().x-boundRectc[k].tl().x;
		gaoc[k]=boundRectc[k].br().y-boundRectc[k].tl().y;
		if(kuanc[k]*gaoc[k]>chanxb*chanyb/60)
		{
			m++;
			qidianx[m]=boundRectc[k].tl().x;
			qidiany[m]=boundRectc[k].tl().y;
			zhongdianx[m]=boundRectc[k].br().x;
			zhongdiany[m]=boundRectc[k].br().y;
			juxing[m]=(boundRectc[k].br().x-boundRectc[k].tl().x)*(boundRectc[k].br().y-boundRectc[k].tl().y);
		}
	}
	m=m+1;
	//cout<<"候选字符区域"<<m<<endl;
	if(m<0)
	{
		cout<<"未能识别（错误代码：003）"<<endl;
		system("pause");
		exit(1);
		/*retString = _T("");
		return retString;*/
	}

	//筛选出面积最大的7个
	int ca,cb,cc[7];//循环参数
	int k=-1;
	int l=m;
	int wud[7];//用于承装7个矩形面积
	for(ca=0;ca<7;ca++)//筛选出候选矩形中 面积最大的7个
	{
		wud[ca]=0;//juxing[0];
		for(cb=0;cb<l;cb++)
		{
			
			if(wud[ca]<juxing[cb])//&&k!=cb
			{
				wud[ca]=juxing[cb];//342 434 753
				k=cb;//1 2 3
			}
			else k=k;//3
		}
		juxing[k]=0;
		//cout<<"最大面积"<<wud[ca]<<endl;
		//cout<<"他的juxing序号"<<k<<endl;
		cc[ca]=k;
		
	}
	if(k<0)
	{
		//cout<<"未能识别（错误代码：004）"<<endl;
		//system("pause");
		exit(1);
	}

	int munn[7];
	int nb,mb;
	int a[7];
	for(nb=0;nb<7;nb++)
	{
		munn[nb]=100000;//
		for(mb=0;mb<7;mb++)
		{
			
			if(munn[nb]>qidianx[cc[mb]] )//&&k!=cb
			{
				munn[nb]=qidianx[cc[mb]];//342 434 753
				k=cc[mb];//1 2 3
			}
			else k=k;//3
		}
		qidianx[k]=100000;
		//cout<<"最小坐标"<<munn[nb]<<endl;//4
		//cout<<"他的对应序号"<<k<<endl;//6
		a[nb]=k;
		
	}
	//system("pause");
	int aaa[7],bbb[7],ccc[7],ddd[7];
	Mat zifua[7];
	for(int ii=0;ii<7;ii++)
	{
		aaa[ii]=munn[ii];
		bbb[ii]=qidiany[a[ii]];
		ccc[ii]=zhongdianx[a[ii]]-munn[ii];
		ddd[ii]=zhongdiany[a[ii]]-qidiany[a[ii]];
		zifua[ii] =erwudi(Rect(aaa[ii],bbb[ii],ccc[ii],ddd[ii]));
	}//system("pause");
	
	//namedWindow( "一号字符");
	//imshow( "一号字符",zifua[0] );
	//waitKey(0);

	//namedWindow( "二号字符");
	//imshow( "二号字符",zifua[1] );
	//waitKey(0);

	//namedWindow( "三号字符");
	//imshow( "三号字符",zifua[2] );
	//waitKey(0);

	//namedWindow( "四号字符");
	//imshow( "四号字符",zifua[3] );
	//imwrite("E:\\VSproject\\11\\11\\车牌字符\\4号字符.jpg",zifua[3]);
	//waitKey(0);

	//namedWindow( "五号字符");
	//imshow( "五号字符",zifua[4] );
	//waitKey(0);

	//namedWindow( "六号字符");
	//imshow( "六号字符",zifua[5] );
	//waitKey(0);


	//namedWindow( "七号字符");
	//imshow( "七号字符",zifua[6] );
	//waitKey(0);

	///////////////////////////////////////////////////////////////////////////////////////    图像归一化
	//尺寸调整为20*20
	Mat outt[7];

	//cout<<"zifu"<<endl<<zifua[0].cols<<endl<<zifua[0].rows<<endl;
	//Mat CharsChuli(Mat);
	for(int i=0;i<7;i++)
	{
		outt[i]=CharsChuli(zifua[i]);
		//threshold( outt[i],outt[i], 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);
	}
	
	//imshow("sdfs",outt[0]);
	//namedWindow("一号");
		//namedWindow("二号");
			//namedWindow("三号");
				//namedWindow("四号");
					//namedWindow("五号");
						//namedWindow("六号");
							//namedWindow("七号");
	//imshow( "一号",outt[0] );
	    //imshow( "二号",outt[1] );
	        //imshow( "三号",outt[2] );
	            //imshow( "四号",outt[3] );
	                //imshow( "五号",outt[4] );
	                    //imshow( "六号",outt[5] );
	                        //imshow( "七号",outt[6] );
	
	double qq=zifua[0].cols;
	double ww=zifua[0].rows;
	double bi=qq/ww*20;//8.8^
	int ci;
	int di=bi;//double转换int
	if((bi-di)>=0.5){ci=di+1;}
	else {ci=di;}
	resize(zifua[0],outt[0],Size(ci,20),0,0,INTER_LINEAR);//原图像转换为高20宽x的原比例图像，两侧加上黑边，成为20*20图。
	int al=(20-ci)/2;
	int ar=20-al-ci;
	copyMakeBorder( outt[0],outt[0],0,0,al,ar,BORDER_CONSTANT,0);
	threshold( outt[0],outt[0], 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);
	
	for(int i=1;i<7;i++)
	{
		//if(zifua[i].rows/zifua[i].cols>=3)
		//{
			int aa=20*zifua[i].cols/zifua[i].rows;
			resize(zifua[i],outt[i],Size(aa,20),0,0,INTER_LINEAR);

			int xl=(20-aa)/2;
			int xr=20-xl-aa;
			copyMakeBorder( outt[i],outt[i],0,0,xl,xr,BORDER_CONSTANT,0);

		//cvtColor(outt[i], outt[i], CV_RGB2GRAY);
		threshold( outt[i],outt[i], 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);

	}
	//cout<<outt[0]<<"/////"<<endl;;
	/////////////////////////////////////////////////////////////////////////////////////////    特征提取
	Mat features[7];
	for(int p=0;p<7;p++)
	{
		Mat outtt=outt[p];
		//imshow("outtt",outtt);
		//waitKey(0);
		Mat vhist;
		Mat hhist;
		//Mat ReturnMat(Mat,int);////////////////函数声明
		vhist=ReturnMat(outt[p],0);
		hhist=ReturnMat(outt[p],1);
		Mat lowData;
		resize(outtt, lowData, Size(10, 10) );
		//Last 10 is the number of moments components
		int numCols=vhist.cols+hhist.cols+lowData.cols*lowData.cols;//////////////【140维向量】
		Mat out=Mat::zeros(1,numCols,CV_32F);
		//Asign values to feature,ANN的样本特征为水平、垂直直方图和低分辨率图像所组成的矢量
		int j=0;
		for(int i=0; i<vhist.cols; i++)
		{
			out.at<float>(j)=vhist.at<float>(i);
			j++;
		}
		for(int i=0; i<hhist.cols; i++)
		{
			out.at<float>(j)=hhist.at<float>(i);
			j++;
		}
		for(int x=0; x<lowData.cols; x++)
		{
			for(int y=0; y<lowData.rows; y++){
				out.at<float>(j)=(float)lowData.at<unsigned char>(x,y);
				j++;
			}
		}
		features[p]=out.clone();
		//cout<<out<<"\n============\n";
		//waitKey(0);
	}
////////////////////////////////////////////////////////////////////     建立ANN模型
	ann.clear();
	ann.load("ann.xml","ann");//装载
	Mat outkk[7];
	for(int i=0;i<7;i++)
	{
		resize(outt[i],outkk[i],Size(70,70),0,0);
	}
	/*imwrite("out_0.jpg",outkk[0]);
	imwrite("out_1.jpg",outkk[1]);
	imwrite("out_2.jpg",outkk[2]);
	imwrite("out_3.jpg",outkk[3]);
	imwrite("out_4.jpg",outkk[4]);
	imwrite("out_5.jpg",outkk[5]);
	imwrite("out_6.jpg",outkk[6]);*/


	int result_one[7];
	//int CharsChinese(Mat);
	//int CharsCharacter(Mat);
	//string InttoChars(int);
	result_one[0]=CharsChinese(features[0]);
	for(int dd=1;dd<7;dd++)
	{
		result_one[dd]=CharsCharacter(features[dd]);
	}
	string outchars="";
	for(int k=0;k<7;k++)
	{

		string outchar=InttoChars(result_one[k]);
		outchars=outchars+outchar;
	}
	cout<<outchars<<endl;
	retString = outchars.c_str();
	result = src.clone();
	return retString;




}
