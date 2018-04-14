
// day21Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "day21.h"
#include "day21Dlg.h"
#include "afxdialogex.h"
#include"opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

CString StrPath0, StrPath1;
unsigned char color_flag=0;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// Cday21Dlg 对话框




Cday21Dlg::Cday21Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cday21Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cday21Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cday21Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cday21Dlg::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_PIC1, &Cday21Dlg::OnStnClickedPic1)
	ON_EN_CHANGE(IDC_EDIT2, &Cday21Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON9, &Cday21Dlg::OnBnClickedButton9)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &Cday21Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT_Path0, &Cday21Dlg::OnEnChangeEditPath0)
	ON_BN_CLICKED(IDC_BUTTON3, &Cday21Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cday21Dlg 消息处理程序

BOOL Cday21Dlg::OnInitDialog()
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
	/*m_font.CreatePointFont(160, _T("宋体"), NULL); 
	m_Result.SetFont(&m_font,true);  */

	CWnd *pWnd1 = GetDlgItem(IDC_PIC1); 
	pWnd1->GetClientRect(&rect); 
	namedWindow("PIC", WINDOW_AUTOSIZE);
	HWND hWnd1 = (HWND) cvGetWindowHandle("PIC");
	HWND hParent1 = ::GetParent(hWnd1);
	::SetParent(hWnd1, GetDlgItem(IDC_PIC1)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);





	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cday21Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cday21Dlg::OnPaint()
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
HCURSOR Cday21Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday21Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码



}


void Cday21Dlg::OnStnClickedPic1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cday21Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cday21Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cday21Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
}


void Cday21Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	/*Mat img1=imread("1.jpg");
	resize(img1,img1,Size(rect1.Width(),rect1.Height()));
	imshow("src1",img1);*/

	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("图片文件(*.jpg)|*.jpg|图片文件(*.bmp)|*.bmp|图片文件(*.png)|*.png|所有文件(*.*)|*.*||"); 
	//构造打开文件对话框
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	 
	//显示打开文件对话框
	if(IDOK==fileDlg.DoModal())
	{
		//点击"打开"按钮，则将文件路径赋值
		StrPath0 = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_Path0, StrPath0);		
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


void Cday21Dlg::OnEnChangeEditPath0()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

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


void Cday21Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}
