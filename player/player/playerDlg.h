
// playerDlg.h : ͷ�ļ�
//

#pragma once
#include "ocx1.h"


// CplayerDlg �Ի���
class CplayerDlg : public CDialogEx
{
// ����
public:
	CplayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PLAYER_DIALOG };

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
	COcx1 m_player;
	afx_msg void OnBnClickedButton1();
};
