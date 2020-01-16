
// mfc_testDlg.h : 头文件
//

#pragma once


// Cmfc_testDlg 对话框
class Cmfc_testDlg : public CDialogEx
{
// 构造
public:
	Cmfc_testDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_TEST_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedOk4();
	afx_msg void getInfo(int Info[4][20], int &eventFlag, int &turns, int &appFlag, int &times,int &x,int &y);
	afx_msg void OnBnClickedOk5();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit48();
	afx_msg void OnBnClickedOk6();
	afx_msg void OnBnClickedOk7();
	afx_msg void OnEnChangeEdit52();
};
