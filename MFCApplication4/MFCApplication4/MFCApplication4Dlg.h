
// MFCApplication4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCApplication4Dlg �Ի���
class CMFCApplication4Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

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
