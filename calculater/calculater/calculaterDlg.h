
// calculaterDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CcalculaterDlg �Ի���
class CcalculaterDlg : public CDialogEx
{
// ����
public:
	CcalculaterDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void CcalculaterDlg::AddDigit(char numKey);
	void CcalculaterDlg::Equal2();

// �Ի�������
	enum { IDD = IDD_CALCULATER_DIALOG };

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
	afx_msg void Onb1();
	afx_msg void Onb0();
	afx_msg void Onb2();
	afx_msg void Onb3();
	afx_msg void Onb4();
	afx_msg void Onb5();
	afx_msg void Onb9();
	afx_msg void Onb8();
	afx_msg void Onb7();
	afx_msg void Onb6();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	afx_msg void OnMul();
	afx_msg void OnDiv();
	afx_msg void Ondian();
	afx_msg void OnAC();
	afx_msg void OnEqual();

	afx_msg void OnEnChangeEdit1();
	CButton Cin1;
//	CEdit EditText;
//	CString EditText;
	CEdit m_control_e;
	double m_num;
	bool st1;
	bool st2;
	double op1;
	double op2;
	int m_operation;
	double m_result;
	bool pflag;
};
