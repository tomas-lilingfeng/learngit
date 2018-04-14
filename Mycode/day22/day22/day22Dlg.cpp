
// day22Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "day22.h"
#include "day22Dlg.h"
#include "afxdialogex.h"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<cmath>
using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString StrPath0, StrPath1;
unsigned char color_flag=0;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cday22Dlg �Ի���




Cday22Dlg::Cday22Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday22Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cday22Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cday22Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cday22Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &Cday22Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cday22Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &Cday22Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cday22Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cday22Dlg::OnBnClickedButton4)
	
	ON_BN_CLICKED(IDC_BUTTON8, &Cday22Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &Cday22Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &Cday22Dlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT_POINT1_X, &Cday22Dlg::OnEnChangeEditPoint1X)
	ON_BN_CLICKED(IDC_BUTTON6, &Cday22Dlg::OnBnClickedButton6)
	
	ON_BN_CLICKED(IDC_BUTTON9, &Cday22Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &Cday22Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &Cday22Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &Cday22Dlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// Cday22Dlg ��Ϣ�������

BOOL Cday22Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	

	//----------���������ѷ���ͼƬ---------------//
	CWnd *pWnd = GetDlgItem(IDC_STATIC); 
    pWnd->GetClientRect(&rect); 

	namedWindow("PIC", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND) cvGetWindowHandle("PIC");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	//----------���������㷨���ͼƬ---------------//
	CWnd *pWnd1 = GetDlgItem(IDC_STATIC_PIC1); 
    pWnd1->GetClientRect(&rect1); 
	namedWindow("PIC2", WINDOW_AUTOSIZE);
	HWND hWnd1 = (HWND) cvGetWindowHandle("PIC2");
	HWND hParent1 = ::GetParent(hWnd1);
	::SetParent(hWnd1, GetDlgItem(IDC_STATIC_PIC1)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);
//----------������ʾ�㷨���Խ��ͼƬ---------------//
	CWnd *pWnd2 = GetDlgItem(IDC_STATIC_PIC2); 
    pWnd2->GetClientRect(&rect2); 
	namedWindow("test", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND) cvGetWindowHandle("test");
	HWND hParent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(IDC_STATIC_PIC2)->m_hWnd);
	::ShowWindow(hParent2, SW_HIDE);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cday22Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cday22Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cday22Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday22Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("ͼƬ�ļ�(*.jpg)|*.jpg|ͼƬ�ļ�(*.bmp)|*.bmp|ͼƬ�ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||"); 
	//������ļ��Ի���
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	 
	//��ʾ���ļ��Ի���
	if(IDOK==fileDlg.DoModal())
	{
		//���"��"��ť�����ļ�·����ֵ
		StrPath0 = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, StrPath0);		
	}
	USES_CONVERSION; 
	string PicPath(W2A(StrPath0));
	src1 = imread(PicPath);
	if(!(src1.empty()))
	{
		img = src1.clone();
		resize(img, img, Size(rect.Width(),rect.Height())); 
		imshow("PIC",img);
	}
	else
		AfxMessageBox(_T("�ѷ���ͼƬ����ʧ�ܣ�"));
	color_flag=0;
	SetDlgItemText(IDC_EDIT2,_T(""));

}


void Cday22Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cday22Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat Img=img.clone();
	Mat gray;
	Mat element0=getStructuringElement(MORPH_RECT, Size(5,5));
	Mat element1=getStructuringElement(MORPH_RECT, Size(7,7));
	cvtColor(Img, gray, COLOR_RGB2GRAY );  
	GaussianBlur(gray, gray, Size(25,25), 0, 0);  //---��˹�˲�
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3); //---����Ӧ��ֵ 
	erode(gray, gray, element0);
	dilate(gray, gray, element1);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	drawContours(img, contours, -1, Scalar(0,0,255), 3, 8, hierarchy );
	if(!(img.empty()))
	{
		resize(img, img, Size(rect.Width(),rect.Height()));   //Resize��С
		imshow("PIC",img);  //��ʾ���
	}
	if(contours.size()>0)
	{
		color_flag=2;
		SetDlgItemText(IDC_EDIT2,_T("ǽ�����ѷ�"));
	}
	else
	{
		color_flag=1;
		SetDlgItemText(IDC_EDIT2,_T("ǽ������"));
	}



}


void Cday22Dlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cday22Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	TCHAR szFilter[] = _T("ͼƬ�ļ�(*.jpg)|*.jpg|ͼƬ�ļ�(*.bmp)|*.bmp|ͼƬ�ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||"); 
	//������ļ��Ի���
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	//CString strFilePath;
	//��ʾ���ļ��Ի���
	if(IDOK==fileDlg.DoModal())
	{
		//���"��"��ť�����ļ�·����ֵ
		StrPath1 = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT3, StrPath1);		
	}
	USES_CONVERSION; 
	string PicPath(W2A(StrPath1));
	src2 = imread(PicPath);
	if(!(src2.empty()))
	{
		img2 = src2.clone();
		resize(img2, img2, Size(rect1.Width(),rect1.Height())); 
		imshow("PIC2",img2);
	}
	else
		AfxMessageBox(_T("�㷨����ͼƬ����ʧ�ܣ�"));



}


void Cday22Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	Mat OutPic; 
	int Median_Size;
	CString strSize;
	GetDlgItemText(IDC_EDIT_MEDIAN_SIZE, strSize);
	Median_Size=_ttoi(strSize);
	if (Median_Size % 2 == 0)
		Median_Size += 1;
	medianBlur ( img2, OutPic, Median_Size);  //��ֵ�˲�����
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",OutPic);  //��ʾ���
	}


}


void Cday22Dlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cday22Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat OutPic; 
	int Blur_Size_x,Blur_Size_y;
	CString strSize_x,strSize_y;
	GetDlgItemText(IDC_EDIT_SIZE_X, strSize_x);
	GetDlgItemText(IDC_EDIT_SIZE_Y, strSize_y);
	Blur_Size_x=_ttoi(strSize_x);
	Blur_Size_y=_ttoi(strSize_y);
	if (Blur_Size_x % 2 == 0)
		Blur_Size_x += 1;
	if (Blur_Size_y % 2 == 0)
		Blur_Size_y += 1;
	blur ( img2, OutPic, Size(Blur_Size_x,Blur_Size_y));  //��ֵ�˲�����
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",OutPic);  //��ʾ���
	}


}


void Cday22Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat OutPic;
	OutPic=img2.clone();
	int blue,green,red;
	int Point1_x,Point1_y,Point2_x,Point2_y;
	CString strPoint1_x,strPoint1_y,strPoint2_x,strPoint2_y;
	CString strBlue,strGreen,strRed;


	GetDlgItemText(IDC_EDIT_BLUE, strBlue);
	blue=_ttoi(strBlue);
	GetDlgItemText(IDC_EDIT_GREEN, strGreen);
	green=_ttoi(strGreen);
	GetDlgItemText(IDC_EDIT_RED, strRed);
	red=_ttoi(strRed);

	GetDlgItemText(IDC_EDIT_POINT1_X, strPoint1_x);
	Point1_x=_ttoi(strPoint1_x);
	GetDlgItemText(IDC_EDIT_POINT1_Y, strPoint1_y);
	Point1_y=_ttoi(strPoint1_y);
	GetDlgItemText(IDC_EDIT_POINT2_X, strPoint2_x);
	Point2_x=_ttoi(strPoint2_x);
	GetDlgItemText(IDC_EDIT_POINT2_Y, strPoint2_y);
	Point2_y=_ttoi(strPoint2_y);

	rectangle(OutPic,Point(Point1_x,Point1_y),Point(Point2_x,Point2_y),Scalar(blue,green,red),2,8);
	
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С		
		
		imshow("test",OutPic);  //��ʾ���
	}

}


void Cday22Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat OutPic;
	OutPic=img2.clone();
	int blue,green,red;
	int Point1_x,Point1_y,Point2_x,Point2_y;
	CString strPoint1_x,strPoint1_y,strPoint2_x,strPoint2_y;
	CString strBlue,strGreen,strRed;


	GetDlgItemText(IDC_EDIT_BLUE, strBlue);
	blue=_ttoi(strBlue);
	GetDlgItemText(IDC_EDIT_GREEN, strGreen);
	green=_ttoi(strGreen);
	GetDlgItemText(IDC_EDIT_RED, strRed);
	red=_ttoi(strRed);

	GetDlgItemText(IDC_EDIT_POINT1_X, strPoint1_x);
	Point1_x=_ttoi(strPoint1_x);
	GetDlgItemText(IDC_EDIT_POINT1_Y, strPoint1_y);
	Point1_y=_ttoi(strPoint1_y);
	GetDlgItemText(IDC_EDIT_POINT2_X, strPoint2_x);
	Point2_x=_ttoi(strPoint2_x);
	GetDlgItemText(IDC_EDIT_POINT2_Y, strPoint2_y);
	Point2_y=_ttoi(strPoint2_y);

	line(OutPic,Point(Point1_x,Point1_y),Point(Point2_x,Point2_y),Scalar(blue,green,red),2,8);
	
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С		
		
		imshow("test",OutPic);  //��ʾ���
	}



}


void Cday22Dlg::OnEnChangeEditPoint1X()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������



}


void Cday22Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat OutPic;
	OutPic=img2.clone();
	int blue,green,red;
	double Point1_x,Point1_y,Point2_x,Point2_y;
	CString strPoint1_x,strPoint1_y,strPoint2_x,strPoint2_y;
	CString strBlue,strGreen,strRed;


	GetDlgItemText(IDC_EDIT_BLUE, strBlue);
	blue=_ttoi(strBlue);
	GetDlgItemText(IDC_EDIT_GREEN, strGreen);
	green=_ttoi(strGreen);
	GetDlgItemText(IDC_EDIT_RED, strRed);
	red=_ttoi(strRed);

	GetDlgItemText(IDC_EDIT_POINT1_X, strPoint1_x);
	Point1_x=_ttoi(strPoint1_x);
	GetDlgItemText(IDC_EDIT_POINT1_Y, strPoint1_y);
	Point1_y=_ttoi(strPoint1_y);
	GetDlgItemText(IDC_EDIT_POINT2_X, strPoint2_x);
	Point2_x=_ttoi(strPoint2_x);
	GetDlgItemText(IDC_EDIT_POINT2_Y, strPoint2_y);
	Point2_y=_ttoi(strPoint2_y);

	circle(OutPic,Point(Point1_x,Point1_y),sqrt((Point2_x-Point1_x)*(Point2_x-Point1_x)+(Point2_y-Point1_x)*(Point2_y-Point1_x)),Scalar(blue,green,red),2,8);
	circle(OutPic,Point(Point2_x,Point2_y),3,Scalar(blue,green,red),-1,8);
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С		
		
		imshow("test",OutPic);  //��ʾ���
	}

}


void Cday22Dlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cday22Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat OutPic; 
	int Blur_Size_x,Blur_Size_y,Sigma;
	CString strSize_x,strSize_y,strSigma;
	GetDlgItemText(IDC_EDIT_SIZE_X, strSize_x);
	GetDlgItemText(IDC_EDIT_SIZE_Y, strSize_y);
	GetDlgItemText(IDC_EDIT_SIGMA, strSigma);
	Blur_Size_x=_ttoi(strSize_x);
	Blur_Size_y=_ttoi(strSize_y);
	Sigma=_ttoi(strSigma);
	if (Blur_Size_x % 2 == 0)
		Blur_Size_x += 1;
	if (Blur_Size_y % 2 == 0)
		Blur_Size_y += 1;
	GaussianBlur( img2, OutPic, Size(Blur_Size_x,Blur_Size_y),Sigma);  //��ֵ�˲�����
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",OutPic);  //��ʾ���
	}


}


void Cday22Dlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Mat gray;
	cvtColor(img2, gray, COLOR_RGB2GRAY );  //---�ҶȻ�
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3); //---����Ӧ��ֵ 
	if(!(gray.empty()))
	{
		resize(gray, gray, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",gray);  //��ʾ���
	}


}


void Cday22Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	Mat OutPic; 
	int thresh;
	CString strThresh;
	GetDlgItemText(IDC_EDIT_THRESH, strThresh);
	thresh=_ttoi(strThresh);
	cvtColor(img2, OutPic, COLOR_RGB2GRAY );  //---�ҶȻ�
	threshold ( OutPic, OutPic, thresh,255,CV_THRESH_BINARY);  //��ֵ������
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",OutPic);  //��ʾ���
	}

}


void Cday22Dlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MatND dstHist;       // ��cv����CvHistogram *hist = cvCreateHist
	Mat gray;
	int dims = 1;
	float hranges[] = {0, 255};
	const float *ranges[] = {hranges};   // ������ҪΪconst����
	int size = 256;
	int channels = 0;

	//��3������ͼ���ֱ��ͼ
	cvtColor(img2, gray, COLOR_RGB2GRAY );  //---�ҶȻ�
	calcHist(&gray, 1, &channels, Mat(), dstHist, dims, &size, ranges);    // cv ����cvCalcHist
	int scale = 1;

	Mat dstImage(size * scale, size, CV_8U, Scalar(0));
	//��4����ȡ���ֵ����Сֵ
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  ��cv���õ���cvGetMinMaxHistValue

	//��5�����Ƴ�ֱ��ͼ
	int hpt = saturate_cast<int>(size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);           //   ע��hist����float����    ����OpenCV1.0������cvQueryHistValue_1D
		int realValue = saturate_cast<int>(binValue * hpt/maxValue);
		rectangle(dstImage,Point(i*scale, size - 1), Point((i+1)*scale - 1, size - realValue), Scalar(255));
	}
	if(!(dstImage.empty()))
	{
		resize(dstImage, dstImage, Size(rect2.Width(),rect2.Height()));   //Resize��С
		imshow("test",dstImage);  //��ʾ���
	}
}
