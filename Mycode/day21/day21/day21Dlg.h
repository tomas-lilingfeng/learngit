
// day21Dlg.h : ͷ�ļ�
//

#pragma once
#include"opencv2/opencv.hpp"
#include "afxwin.h"
using namespace cv;

// Cday21Dlg �Ի���
class Cday21Dlg : public CDialogEx
{
// ����
public:
	Cday21Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DAY21_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedPic1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	
	CRect rect, rect1,rect2;
	Mat src1, src2;
	Mat img, img2;
	CFont m_font;
	CEdit m_Result;
	afx_msg void OnEnChangeEditPath0();
	afx_msg void OnBnClickedButton3();
};
