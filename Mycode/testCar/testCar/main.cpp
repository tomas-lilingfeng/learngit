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
	//bilateralFilter(src, lvbo, 3, 300, 300, BORDER_DEFAULT);//˫���˲�
	//imshow("lvbo",lvbo);
	//Mat gray;
	//cvtColor(lvbo, gray, CV_BGR2GRAY);//�Ҷ�ת��
	//imshow("GRAY",gray);
	//medianBlur(gray, gray, 3);//��ֵ�˲�
	//Sobel(gray, gray, 0, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	//imshow("Sobel",gray);
	//GaussianBlur(gray, gray, Size(5, 1), 0, 0);
	//threshold(gray, gray, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU); //��ֵ��
	////��̬ѧ����
	//Mat element=getStructuringElement(MORPH_RECT,Size(3,3));//Ԫ�ؽṹ
	//Mat elementtwo=getStructuringElement(MORPH_RECT,Size(9,3));
	//Mat dilation;
	//Mat erosion;
	//erode(gray, erosion, element,Point(-1,-1), 1);//��ʴ1��
	//imshow("erosion",erosion);
	//dilate(erosion, dilation, elementtwo,Point(-1,-1),5);//����5��
	//imshow("dilate",dilation);

	//int thresh = 100;
	//int max_thresh = 255;
	//RNG rng(12345);                      //vector<Vec4i>hierarchy�Ƕ���Ĳ㼶
	//Mat threshold_output;               //contours������ɶ�ά�����������������潫����洢�ҵ��ı߽�ģ�x,y������
	//vector<vector<Point> > contours;//vector������ ��������һ���ɱ䳤������ ��һ������һ��point�͵Ķ�ά�������contours��ÿһά���Ⱦ��ɱ䣩
	//vector<Vec4i> hierarchy;//����һ��Vec4i�͵�һά����hierarchy <>����д������������������ Vec4iָ�����ĸ�������
	//threshold( dilation, threshold_output, thresh, 255, THRESH_BINARY );
	//imshow("��Ե���ͼ",threshold_output);
	////waitKey(0);
	////destroyWindow( "��Ե���ͼ" );
	//findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );/// �ҵ�����
	//imshow("�������ͼ",threshold_output);
	////waitKey(0);
	////destroyWindow( "�������ͼ" );

	////����αƽ����� + ��ȡ����
	//vector<vector<Point> > contours_poly( contours.size() );
	//vector<Rect> boundRect( contours.size() );//bounkRect�ǻ�ȡ���γߴ��һ��������һ����4������eg����0��0��344��,567��

	//for( int i = 0; i < contours.size(); i++ )
	//{ 
	//   approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );    //�ƽ����������
 //      boundRect[i] = boundingRect( Mat(contours_poly[i]) );           //�����ⲿ���α߽�
	//}
 // // ����������� + ��Χ�ľ��ο� ������ʡ�ԣ��������ڼ��ʶ�������
	//Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	//Mat lvb=lvbo.clone();
	//for( int i = 0; i< contours.size(); i++ )
	//{
 //      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//������ɫ
 //      //rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//������
	//   rectangle( lvb, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//������
	//}
	//imshow( "����ͼ", lvb );
	////waitKey(0);
	////destroyWindow( "����ͼ" );
	////����λ�ô���ȡ
	//int area=drawing.rows*drawing.cols;
	////cout<<"ͼ�������"<<area<<endl;
	//int j,squ=0,num=(-1);
	//int width[3333],height[3333];
	//for(j=0;j<contours.size();j++)
	//{
	//	//boundRect[j].tl()
	//	width[j]=boundRect[j].br().x-boundRect[j].tl().x;
	//	height[j]=boundRect[j].br().y-boundRect[j].tl().y;
	//	float abc=width[j]/height[j];
	//	if(abc>=2.2&&abc<=4)//�߳���ɸѡ�����ɸѡ
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
	//if(num<0)//������ֹ���
	//{
	//	//cout<<"û�����ջ�δ��ʶ�𣨴�����룺001��"<<endl;//û��ʶ���roi����
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
	//imshow( "���ƴֶ�λ", lvbo );
	////imshow( "���ƴֶ�λ", check );
	////waitKey(0);
	////destroyWindow( "���ƴֶ�λ" );//���ƴֶ�λ
 //   
	////����RGB��Ϣ��ȷ��ȡԤ����
	//Mat liuzhe;
	//liuzhe=check.clone();
	//unsigned char R = 28,G = 63,B = 130;//90<B<125;0<G<40;0<R15...R = 50,G = 75,B = 145
	//for (int i = 0; i < check.cols; i++) 
	//{
	//	for (int j = 0; j < check.rows; j++) 
	//	{
	//		Vec3b &intensity = check.at<Vec3b>(j, i);
	//		if(intensity.val[0]-B<40&&intensity.val[1]-G<30&&intensity.val[2]-R<30)// R = 50,G = 75,B = 145����55.35.40
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
	//imshow("RGB����", check);
	////waitKey(0);
	////destroyWindow( "RGB����" );



	////��RGB������ͼ����Ϊ����
	//Mat try1;
	//liuzhe.copyTo(try1, check);
	//imshow("try1", try1);
	//
	////���ƴ���λ��ͼ��Ԥ����
	//Mat hbcp;
	//cvtColor(try1,hbcp,CV_BGR2GRAY);

	//imshow( "hbcp",hbcp );
	//Mat threshold_outputtwo;
	//vector<vector<Point> > contoursb;
	//vector<Vec4i> hierarchyb;
	//// ʹ��Threshold��ֵ������Ե
	////threshold( hbcp, threshold_outputtwo, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU );
	//adaptiveThreshold(hbcp, threshold_outputtwo, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 35, 3); //---����Ӧ��ֵ 
	//imshow( "���ƶ�ֵ��",threshold_outputtwo );
	////waitKey(0);
	////destroyWindow( "���ƶ�ֵ��" );

	////Mat element1=getStructuringElement(MORPH_RECT,Size(3,3));
	////erode(threshold_outputtwo, threshold_outputtwo, element1,Point(-1,-1), 1);//��ʴ1��?????????????
	////imshow("fushi",threshold_outputtwo);
	///// �ҵ�����
	//findContours(threshold_outputtwo , contoursb, hierarchyb, CV_RETR_TREE ,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );// CV_RETR_LIST
	//imshow("�ּ�ͼ",threshold_outputtwo);
	////waitKey(0);
	////destroyWindow( "�ּ�ͼ" );// CV_RETR_EXTERNAL, //��ȡ�����ķ����������ȡ��Χ������  
	////  CV_CHAIN_APPROX_NONE //�������Ƶķ��������ﲻ���ƣ���ȡȫ��������  
	//// minAreaRect
	//// ��ÿ���ҵ���������������б�ı߽�����Բ
 //   vector<RotatedRect> minRect( contoursb.size() );

 //   for( int i = 0; i < contoursb.size(); i++ )
 //      { 
	//	 minRect[i] = minAreaRect( Mat(contoursb[i]) );
 //      }

 //   // ��������������б�ı߽��ͱ߽���Բ
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

	////��ȷ��ȡ�㷨 ��ɸѡ
	//int cpsqu;
	//cpsqu=chanx*chany;
 //  // cout<<"�������"<<cpsqu<<endl;//60822
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
	//	if(bizhi>=3&&bizhi<=28/7)//�߳���ɸѡ�����ɸѡ   ***��ע��������ȦͼƬ������ֵ3.332  ��Ȧ3.5��  ��ʵ�ʲ���������
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
	//	//cout<<"û�����ջ�δ��ʶ�𣨴�����룺002��"<<endl;//roi����û�з��ϱ���������
	//	//exit(1);
	//	//retString = _T("");
	//	//return retString;
	//}

	////ƫ�ƽǶȼ���
	//double jiaodu;//������б��
	//double jiaj;//�Խ��� ��� �н�
	//double duiq;//�Խ�����б�Ƕ�
	//minRect[numb].points( rect_points );
	//int xa=rect_points[1].x;//����������ʼ��
	//int ya=rect_points[1].y;
	//int xb=rect_points[3].x;//����������ֹ��
	//int yb=rect_points[3].y;
	//double cha=yb-ya;
	//double chb=xb-xa;
	//double he=gaodub[numb];//��
	//double wi=kuandub[numb];//��
	//double ss=cha/chb;//(yb-ya)/(xb-xa);
	//jiaj=0;//atan(he/wi)*180/3.1416;
	//duiq=0;//atan(ss)*180/3.1416;
	//jiaodu=duiq-jiaj;

	////cout<<"�Ƕ�"<<jiaodu<<endl;
	////cout<<"�н�"<<jiaj<<endl;
	////cout<<"�Խ�����б"<<duiq<<endl;

	//Point2f centers[4];
	//minRect[numb].points(centers);
	//Mat rot_mat;
	//double scale=1;
	//rot_mat= getRotationMatrix2D( centers[1],jiaodu , scale );//minRect[numb].center
	//Mat centermat;
	//warpAffine(liuzhe,centermat, rot_mat,liuzhe.size());//��rgb����ͼ��ת
	//imshow( "��ת��", centermat );
	////waitKey(0);
	////destroyWindow("��ת��");
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
	cvtColor(lvbo, gray, CV_BGR2GRAY);//�Ҷ�ת��
	medianBlur(gray, gray, 3);
	Sobel(gray, gray, 0, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	GaussianBlur(gray, gray, Size(5, 1), 0, 0);
	threshold(gray, gray, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU); 
	//��̬ѧ����
	Mat element=getStructuringElement(MORPH_RECT,Size(3,3));//Ԫ�ؽṹ
	Mat elementtwo=getStructuringElement(MORPH_RECT,Size(9,3));
	Mat dilation;
	Mat erosion;
	erode(gray, erosion, element,Point(-1,-1), 1);
	dilate(erosion, dilation, elementtwo,Point(-1,-1),5);

	int thresh = 100;
	int max_thresh = 255;
	RNG rng(12345);                      //vector<Vec4i>hierarchy�Ƕ���Ĳ㼶
	Mat threshold_output;               //contours������ɶ�ά�����������������潫����洢�ҵ��ı߽�ģ�x,y������
	vector<vector<Point> > contours;//vector������ ��������һ���ɱ䳤������ ��һ������һ��point�͵Ķ�ά�������contours��ÿһά���Ⱦ��ɱ䣩
	vector<Vec4i> hierarchy;//����һ��Vec4i�͵�һά����hierarchy <>����д������������������ Vec4iָ�����ĸ�������
	threshold( dilation, threshold_output, thresh, 255, THRESH_BINARY );
	imshow("��Ե���ͼ",threshold_output);
	//waitKey(0);
	//destroyWindow( "��Ե���ͼ" );
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );/// �ҵ�����
	imshow("�������ͼ",threshold_output);
	//waitKey(0);
	//destroyWindow( "�������ͼ" );

	//����αƽ����� + ��ȡ����
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );//bounkRect�ǻ�ȡ���γߴ��һ��������һ����4������eg����0��0��344��,567��

	for( int i = 0; i < contours.size(); i++ )
	{ 
	   approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
	}
  // ����������� + ��Χ�ľ��ο� ������ʡ�ԣ��������ڼ��ʶ�������
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
	{
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//������ɫ
       rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );//������
	}
	imshow( "����ͼ", drawing );
	//waitKey(0);
	//destroyWindow( "����ͼ" );

	//����λ�ô���ȡ
	int area=drawing.rows*drawing.cols;
	//cout<<"ͼ�������"<<area<<endl;
	int j,squ=0,num=(-1);
	int width[3333],height[3333];
	for(j=0;j<contours.size();j++)
	{
		//boundRect[j].tl()
		width[j]=boundRect[j].br().x-boundRect[j].tl().x;
		height[j]=boundRect[j].br().y-boundRect[j].tl().y;
		float abc=width[j]/height[j];
		if(abc>=2.2&&abc<=4)//�߳���ɸѡ�����ɸѡ
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
	if(num<0)//������ֹ���
	{
		cout<<"û�����ջ�δ��ʶ�𣨴�����룺001��"<<endl;//û��ʶ���roi����
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
	//imshow( "���ƴֶ�λ", lvbo );
	//waitKey(0);
	//destroyWindow( "���ƴֶ�λ" );//���ƴֶ�λ
    
	//����RGB��Ϣ��ȷ��ȡԤ����
	Mat liuzhe;
	liuzhe=check.clone();
	unsigned char R = 28,G = 63,B = 130;//90<B<125;0<G<40;0<R15...R = 50,G = 75,B = 145
	for (int i = 0; i < check.cols; i++) 
	{
		for (int j = 0; j < check.rows; j++) 
		{
			Vec3b &intensity = check.at<Vec3b>(j, i);
			if(intensity.val[0]-B<40&&intensity.val[1]-G<30&&intensity.val[2]-R<30)// R = 50,G = 75,B = 145����55.35.40
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
	imshow("RGB����", check);
	//waitKey(0);
	//destroyWindow( "RGB����" );

	//���ƴ���λ��ͼ��Ԥ����
	Mat hbcp;
	cvtColor(check,hbcp,CV_BGR2GRAY);
	Mat threshold_outputtwo;
	vector<vector<Point> > contoursb;
	vector<Vec4i> hierarchyb;
	// ʹ��Threshold��ֵ������Ե
	threshold( hbcp, threshold_outputtwo, 30, 255, CV_THRESH_BINARY|CV_THRESH_OTSU );
	imshow( "���ƶ�ֵ��",threshold_outputtwo );
	//waitKey(0);
	//destroyWindow( "���ƶ�ֵ��" );

	/// �ҵ�����
	findContours(threshold_outputtwo , contoursb, hierarchyb, CV_RETR_TREE ,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );// CV_RETR_LIST
	//imshow("�ּ�ͼ",threshold_outputtwo);
	//waitKey(0);
	//destroyWindow( "�ּ�ͼ" );// CV_RETR_EXTERNAL, //��ȡ�����ķ����������ȡ��Χ������  
	//  CV_CHAIN_APPROX_NONE //�������Ƶķ��������ﲻ���ƣ���ȡȫ��������  
	// minAreaRect
	// ��ÿ���ҵ���������������б�ı߽�����Բ
    vector<RotatedRect> minRect( contoursb.size() );

    for( int i = 0; i < contoursb.size(); i++ )
       { 
		 minRect[i] = minAreaRect( Mat(contoursb[i]) );
       }

    // ��������������б�ı߽��ͱ߽���Բ
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

	//��ȷ��ȡ�㷨 ��ɸѡ
	int cpsqu;
	cpsqu=chanx*chany;
   // cout<<"�������"<<cpsqu<<endl;//60822
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
		if(bizhi>=3&&bizhi<=28/7)//�߳���ɸѡ�����ɸѡ   ***��ע��������ȦͼƬ������ֵ3.332  ��Ȧ3.5��  ��ʵ�ʲ���������
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
		cout<<"û�����ջ�δ��ʶ�𣨴�����룺002��"<<endl;//roi����û�з��ϱ���������
		exit(1);
		/*retString = _T("");
		return retString;*/
	}
	//ƫ�ƽǶȼ���
	double jiaodu;//������б��
	double jiaj;//�Խ��� ��� �н�
	double duiq;//�Խ�����б�Ƕ�
	minRect[numb].points( rect_points );
	int xa=rect_points[1].x;//����������ʼ��
	int ya=rect_points[1].y;
	int xb=rect_points[3].x;//����������ֹ��
	int yb=rect_points[3].y;
	double cha=yb-ya;
	double chb=xb-xa;
	double he=gaodub[numb];//��
	double wi=kuandub[numb];//��
	double ss=cha/chb;//(yb-ya)/(xb-xa);
	jiaj=0;//atan(he/wi)*180/3.1416;
	duiq=0;//atan(ss)*180/3.1416;
	jiaodu=duiq-jiaj;

	cout<<"�Ƕ�"<<jiaodu<<endl;
	cout<<"�н�"<<jiaj<<endl;
	cout<<"�Խ�����б"<<duiq<<endl;

	Point2f centers[4];
	minRect[numb].points(centers);
	Mat rot_mat;
	double scale=1;
	rot_mat= getRotationMatrix2D( centers[1],jiaodu , scale );//minRect[numb].center
	Mat centermat;
	warpAffine(liuzhe,centermat, rot_mat,liuzhe.size());//��rgb����ͼ��ת
	imshow( "��ת��", centermat );
	//waitKey(0);
	//destroyWindow("��ת��");
	
	//��ȡ�Ż�
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
	cvtColor(youwudi,huiwudi,CV_BGR2GRAY);//�Ҷ�ת��
	Mat erwudi;
	threshold( huiwudi,erwudi,30,255, CV_THRESH_BINARY|CV_THRESH_OTSU); 
	imshow( "���ƾ���λ", erwudi);
	//waitKey(0);
	//destroyWindow("���ƾ���λ");

	//�ָ���ַ�
	//cout<<"����ͼ��߶�"<<chanyb<<endl;
	//����1�߶�74  ��ʴԪ��1.6һ��(6*1)
	//����2�߶�32  ��ʴԪ�� ���ԣ�1.3һ�Σ�3*1��
	//chepai5 63  δ���� 6*1
	int suanzi;
	suanzi=chanyb/14;
	//��̬ѧ����
	Mat elementc=getStructuringElement(MORPH_RECT,Size(1,7));
	Mat elementd=getStructuringElement(MORPH_RECT,Size(1,suanzi));
	Mat zxdilate;
	Mat zxerode;
	erode(erwudi,zxerode,elementd,Point(-1,-1),1);//dilate����erode��ʴ
	dilate(zxerode,zxdilate,elementc,Point(-1,-1),9);//zxdilate�������ʹ���ͼ
	//imshow("�����ַ�����ͼ",zxdilate);
	//waitKey(0);
	//destroyWindow( "�����ַ�����ͼ" );

	vector<vector<Point> > contoursc;
	vector<Vec4i> hierarchyc;
	findContours( zxdilate, contoursc, hierarchyc, CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	/// ����αƽ����� + ��ȡ����
	vector<vector<Point> > contours_polyc( contoursc.size() );
	vector<Rect> boundRectc( contoursc.size() );//bounkRect�ǻ�ȡ���γߴ��һ��������һ����4������eg����0��0��344��,567��

	for( int i = 0; i < contoursc.size(); i++ )
	{
		approxPolyDP( Mat(contoursc[i]), contours_polyc[i], 3, true );
       boundRectc[i] = boundingRect( Mat(contours_polyc[i]) );
	}


  /// ����������� + ��Χ�ľ��ο� 
	Mat drawingc = Mat::zeros( zxdilate.size(), CV_8UC3 );
	for( int i = 0; i<contoursc.size(); i++ )
	{
       //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );//������ɫ
		Scalar color = Scalar(0, 0, 255);
       //drawContours( drawingb, contours_polyb, i, color, 1, 8, vector<Vec4i>(), 0, Point() );//������
       //rectangle( drawingc, boundRectc[i].tl(), boundRectc[i].br(), color, 2, 8, 0 );//������youwudi
	   rectangle( youwudi, boundRectc[i].tl(), boundRectc[i].br(), color, 2, 8, 0 );
	}

	Mat temp2;
	resize(youwudi, temp2, Size(rect3.Width(),rect3.Height())); 
	imshow("char", temp2);
	//imshow( "���Ƶ�����ͼ", drawingc);
	//waitKey(0);
	//destroyWindow("���Ƶ�����ͼ");

	int m=-1;
	int kuanc[100],gaoc[100];
	int qidianx[10],qidiany[10],zhongdianx[10],zhongdiany[10],juxing[10];//��ʵ������8��9�͹���
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
	//cout<<"��ѡ�ַ�����"<<m<<endl;
	if(m<0)
	{
		cout<<"δ��ʶ�𣨴�����룺003��"<<endl;
		system("pause");
		exit(1);
		/*retString = _T("");
		return retString;*/
	}

	//ɸѡ���������7��
	int ca,cb,cc[7];//ѭ������
	int k=-1;
	int l=m;
	int wud[7];//���ڳ�װ7���������
	for(ca=0;ca<7;ca++)//ɸѡ����ѡ������ �������7��
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
		//cout<<"������"<<wud[ca]<<endl;
		//cout<<"����juxing���"<<k<<endl;
		cc[ca]=k;
		
	}
	if(k<0)
	{
		//cout<<"δ��ʶ�𣨴�����룺004��"<<endl;
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
		//cout<<"��С����"<<munn[nb]<<endl;//4
		//cout<<"���Ķ�Ӧ���"<<k<<endl;//6
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
	
	//namedWindow( "һ���ַ�");
	//imshow( "һ���ַ�",zifua[0] );
	//waitKey(0);

	//namedWindow( "�����ַ�");
	//imshow( "�����ַ�",zifua[1] );
	//waitKey(0);

	//namedWindow( "�����ַ�");
	//imshow( "�����ַ�",zifua[2] );
	//waitKey(0);

	//namedWindow( "�ĺ��ַ�");
	//imshow( "�ĺ��ַ�",zifua[3] );
	//imwrite("E:\\VSproject\\11\\11\\�����ַ�\\4���ַ�.jpg",zifua[3]);
	//waitKey(0);

	//namedWindow( "����ַ�");
	//imshow( "����ַ�",zifua[4] );
	//waitKey(0);

	//namedWindow( "�����ַ�");
	//imshow( "�����ַ�",zifua[5] );
	//waitKey(0);


	//namedWindow( "�ߺ��ַ�");
	//imshow( "�ߺ��ַ�",zifua[6] );
	//waitKey(0);

	///////////////////////////////////////////////////////////////////////////////////////    ͼ���һ��
	//�ߴ����Ϊ20*20
	Mat outt[7];

	//cout<<"zifu"<<endl<<zifua[0].cols<<endl<<zifua[0].rows<<endl;
	//Mat CharsChuli(Mat);
	for(int i=0;i<7;i++)
	{
		outt[i]=CharsChuli(zifua[i]);
		//threshold( outt[i],outt[i], 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);
	}
	
	//imshow("sdfs",outt[0]);
	//namedWindow("һ��");
		//namedWindow("����");
			//namedWindow("����");
				//namedWindow("�ĺ�");
					//namedWindow("���");
						//namedWindow("����");
							//namedWindow("�ߺ�");
	//imshow( "һ��",outt[0] );
	    //imshow( "����",outt[1] );
	        //imshow( "����",outt[2] );
	            //imshow( "�ĺ�",outt[3] );
	                //imshow( "���",outt[4] );
	                    //imshow( "����",outt[5] );
	                        //imshow( "�ߺ�",outt[6] );
	
	double qq=zifua[0].cols;
	double ww=zifua[0].rows;
	double bi=qq/ww*20;//8.8^
	int ci;
	int di=bi;//doubleת��int
	if((bi-di)>=0.5){ci=di+1;}
	else {ci=di;}
	resize(zifua[0],outt[0],Size(ci,20),0,0,INTER_LINEAR);//ԭͼ��ת��Ϊ��20��x��ԭ����ͼ��������Ϻڱߣ���Ϊ20*20ͼ��
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
	/////////////////////////////////////////////////////////////////////////////////////////    ������ȡ
	Mat features[7];
	for(int p=0;p<7;p++)
	{
		Mat outtt=outt[p];
		//imshow("outtt",outtt);
		//waitKey(0);
		Mat vhist;
		Mat hhist;
		//Mat ReturnMat(Mat,int);////////////////��������
		vhist=ReturnMat(outt[p],0);
		hhist=ReturnMat(outt[p],1);
		Mat lowData;
		resize(outtt, lowData, Size(10, 10) );
		//Last 10 is the number of moments components
		int numCols=vhist.cols+hhist.cols+lowData.cols*lowData.cols;//////////////��140ά������
		Mat out=Mat::zeros(1,numCols,CV_32F);
		//Asign values to feature,ANN����������Ϊˮƽ����ֱֱ��ͼ�͵ͷֱ���ͼ������ɵ�ʸ��
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
////////////////////////////////////////////////////////////////////     ����ANNģ��
	ann.clear();
	ann.load("ann.xml","ann");//װ��
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
