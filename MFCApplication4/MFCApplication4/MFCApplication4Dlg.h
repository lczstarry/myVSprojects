
// MFCApplication4Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

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
	CString op;
	afx_msg void OnBnClickedButton1();
	CListBox m_listbox;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeEdit1();
	CString display;
	CString m_curfruit;
	afx_msg void OnSelchangeCombo1();
	CComboBox m_combo;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit3();
};
