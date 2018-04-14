
// day23Dlg.h : 头文件
//

#pragma once

#include"opencv2/opencv.hpp"
using namespace cv;
// Cday23Dlg 对话框
class Cday23Dlg : public CDialogEx
{
// 构造
public:
	Cday23Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DAY23_DIALOG };

	CString StrPath;
	Mat src, img;
	CRect rect,rect2,rect3;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString CarNumDetect(Mat &src, Mat &result)
};
