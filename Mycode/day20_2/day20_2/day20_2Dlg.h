
// day20_2Dlg.h : ͷ�ļ�
//

#pragma once


// Cday20_2Dlg �Ի���
class Cday20_2Dlg : public CDialogEx
{
// ����
public:
	Cday20_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DAY20_2_DIALOG };

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
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtoncanny();
};
