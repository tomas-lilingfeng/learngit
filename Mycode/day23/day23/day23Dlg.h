
// day23Dlg.h : ͷ�ļ�
//

#pragma once

#include"opencv2/opencv.hpp"
using namespace cv;
// Cday23Dlg �Ի���
class Cday23Dlg : public CDialogEx
{
// ����
public:
	Cday23Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DAY23_DIALOG };

	CString StrPath;
	Mat src, img;
	CRect rect,rect2,rect3;

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
	afx_msg void OnBnClickedButton2();
	CString CarNumDetect(Mat &src, Mat &result)
};
