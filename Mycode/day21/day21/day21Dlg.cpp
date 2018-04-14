
// day21Dlg.cpp : ʵ���ļ�
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


// Cday21Dlg �Ի���




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


// Cday21Dlg ��Ϣ�������

BOOL Cday21Dlg::OnInitDialog()
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
	/*m_font.CreatePointFont(160, _T("����"), NULL); 
	m_Result.SetFont(&m_font,true);  */

	CWnd *pWnd1 = GetDlgItem(IDC_PIC1); 
	pWnd1->GetClientRect(&rect); 
	namedWindow("PIC", WINDOW_AUTOSIZE);
	HWND hWnd1 = (HWND) cvGetWindowHandle("PIC");
	HWND hParent1 = ::GetParent(hWnd1);
	::SetParent(hWnd1, GetDlgItem(IDC_PIC1)->m_hWnd);
	::ShowWindow(hParent1, SW_HIDE);





	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cday21Dlg::OnPaint()
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
HCURSOR Cday21Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cday21Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



}


void Cday21Dlg::OnStnClickedPic1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cday21Dlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Cday21Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cday21Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);
}


void Cday21Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	/*Mat img1=imread("1.jpg");
	resize(img1,img1,Size(rect1.Width(),rect1.Height()));
	imshow("src1",img1);*/

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("ͼƬ�ļ�(*.jpg)|*.jpg|ͼƬ�ļ�(*.bmp)|*.bmp|ͼƬ�ļ�(*.png)|*.png|�����ļ�(*.*)|*.*||"); 
	//������ļ��Ի���
	CFileDialog fileDlg(TRUE, NULL, NULL, 0, szFilter, this);
	 
	//��ʾ���ļ��Ի���
	if(IDOK==fileDlg.DoModal())
	{
		//���"��"��ť�����ļ�·����ֵ
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
		AfxMessageBox(_T("�ѷ���ͼƬ����ʧ�ܣ�"));
	color_flag=0;
	SetDlgItemText(IDC_EDIT2,_T(""));


}


void Cday21Dlg::OnEnChangeEditPath0()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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


void Cday21Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
