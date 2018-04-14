
// day22Dlg.cpp : 实现文件
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cday22Dlg 对话框




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


// Cday22Dlg 消息处理程序

BOOL Cday22Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	

	//----------用来加载裂缝检测图片---------------//
	CWnd *pWnd = GetDlgItem(IDC_STATIC); 
    pWnd->GetClientRect(&rect); 

	namedWindow("PIC", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND) cvGetWindowHandle("PIC");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_STATIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	//----------用来加载算法检测图片---------------//
	CWnd *pWnd1 = GetDlgItem(IDC_STATIC_PIC1); 
    pWnd1->GetClientRect(&rect1); 
	namedWindow("PIC2", WINDOW_AUTOSIZE);
	HWND hWnd1 = (HWND) cvGetWindowHandle("PIC2");
	HWND hParent1 = ::GetParent(hWnd1);
	::SetParent(hWnd1, GetDlgItem(IDC_STATIC_PIC1)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);
//----------用来显示算法测试结果图片---------------//
	CWnd *pWnd2 = GetDlgItem(IDC_STATIC_PIC2); 
    pWnd2->GetClientRect(&rect2); 
	namedWindow("test", WINDOW_AUTOSIZE);
	HWND hWnd2 = (HWND) cvGetWindowHandle("test");
	HWND hParent2 = ::GetParent(hWnd2);
	::SetParent(hWnd2, GetDlgItem(IDC_STATIC_PIC2)->m_hWnd);
	::ShowWindow(hParent2, SW_HIDE);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cday22Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cday22Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday22Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("图片文件(*.jpg)|*.jpg|图片文件(*.bmp)|*.bmp|图片文件(*.png)|*.png|所有文件(*.*)|*.*||"); 
	//构造打开文件对话框
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	 
	//显示打开文件对话框
	if(IDOK==fileDlg.DoModal())
	{
		//点击"打开"按钮，则将文件路径赋值
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
		AfxMessageBox(_T("裂缝检测图片加载失败！"));
	color_flag=0;
	SetDlgItemText(IDC_EDIT2,_T(""));

}


void Cday22Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cday22Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Mat Img=img.clone();
	Mat gray;
	Mat element0=getStructuringElement(MORPH_RECT, Size(5,5));
	Mat element1=getStructuringElement(MORPH_RECT, Size(7,7));
	cvtColor(Img, gray, COLOR_RGB2GRAY );  
	GaussianBlur(gray, gray, Size(25,25), 0, 0);  //---高斯滤波
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3); //---自适应阈值 
	erode(gray, gray, element0);
	dilate(gray, gray, element1);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	drawContours(img, contours, -1, Scalar(0,0,255), 3, 8, hierarchy );
	if(!(img.empty()))
	{
		resize(img, img, Size(rect.Width(),rect.Height()));   //Resize大小
		imshow("PIC",img);  //显示结果
	}
	if(contours.size()>0)
	{
		color_flag=2;
		SetDlgItemText(IDC_EDIT2,_T("墙面有裂缝"));
	}
	else
	{
		color_flag=1;
		SetDlgItemText(IDC_EDIT2,_T("墙面正常"));
	}



}


void Cday22Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cday22Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	TCHAR szFilter[] = _T("图片文件(*.jpg)|*.jpg|图片文件(*.bmp)|*.bmp|图片文件(*.png)|*.png|所有文件(*.*)|*.*||"); 
	//构造打开文件对话框
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	//CString strFilePath;
	//显示打开文件对话框
	if(IDOK==fileDlg.DoModal())
	{
		//点击"打开"按钮，则将文件路径赋值
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
		AfxMessageBox(_T("算法测试图片加载失败！"));



}


void Cday22Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	
	Mat OutPic; 
	int Median_Size;
	CString strSize;
	GetDlgItemText(IDC_EDIT_MEDIAN_SIZE, strSize);
	Median_Size=_ttoi(strSize);
	if (Median_Size % 2 == 0)
		Median_Size += 1;
	medianBlur ( img2, OutPic, Median_Size);  //中值滤波函数
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",OutPic);  //显示结果
	}


}


void Cday22Dlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cday22Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

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
	blur ( img2, OutPic, Size(Blur_Size_x,Blur_Size_y));  //中值滤波函数
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",OutPic);  //显示结果
	}


}


void Cday22Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

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
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小		
		
		imshow("test",OutPic);  //显示结果
	}

}


void Cday22Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

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
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小		
		
		imshow("test",OutPic);  //显示结果
	}



}


void Cday22Dlg::OnEnChangeEditPoint1X()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码



}


void Cday22Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

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
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小		
		
		imshow("test",OutPic);  //显示结果
	}

}


void Cday22Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cday22Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码

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
	GaussianBlur( img2, OutPic, Size(Blur_Size_x,Blur_Size_y),Sigma);  //中值滤波函数
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",OutPic);  //显示结果
	}


}


void Cday22Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码

	Mat gray;
	cvtColor(img2, gray, COLOR_RGB2GRAY );  //---灰度化
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3); //---自适应阈值 
	if(!(gray.empty()))
	{
		resize(gray, gray, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",gray);  //显示结果
	}


}


void Cday22Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码

	
	Mat OutPic; 
	int thresh;
	CString strThresh;
	GetDlgItemText(IDC_EDIT_THRESH, strThresh);
	thresh=_ttoi(strThresh);
	cvtColor(img2, OutPic, COLOR_RGB2GRAY );  //---灰度化
	threshold ( OutPic, OutPic, thresh,255,CV_THRESH_BINARY);  //二值化函数
	if(!(OutPic.empty()))
	{
		resize(OutPic, OutPic, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",OutPic);  //显示结果
	}

}


void Cday22Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	MatND dstHist;       // 在cv中用CvHistogram *hist = cvCreateHist
	Mat gray;
	int dims = 1;
	float hranges[] = {0, 255};
	const float *ranges[] = {hranges};   // 这里需要为const类型
	int size = 256;
	int channels = 0;

	//【3】计算图像的直方图
	cvtColor(img2, gray, COLOR_RGB2GRAY );  //---灰度化
	calcHist(&gray, 1, &channels, Mat(), dstHist, dims, &size, ranges);    // cv 中是cvCalcHist
	int scale = 1;

	Mat dstImage(size * scale, size, CV_8U, Scalar(0));
	//【4】获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  在cv中用的是cvGetMinMaxHistValue

	//【5】绘制出直方图
	int hpt = saturate_cast<int>(size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);           //   注意hist中是float类型    而在OpenCV1.0版中用cvQueryHistValue_1D
		int realValue = saturate_cast<int>(binValue * hpt/maxValue);
		rectangle(dstImage,Point(i*scale, size - 1), Point((i+1)*scale - 1, size - realValue), Scalar(255));
	}
	if(!(dstImage.empty()))
	{
		resize(dstImage, dstImage, Size(rect2.Width(),rect2.Height()));   //Resize大小
		imshow("test",dstImage);  //显示结果
	}
}
