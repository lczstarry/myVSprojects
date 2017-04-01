
// calculaterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculater.h"
#include "calculaterDlg.h"
#include "afxdialogex.h"

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


// CcalculaterDlg �Ի���



CcalculaterDlg::CcalculaterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculaterDlg::IDD, pParent)
	
	, m_num(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	op1 = 0.0;
	op2 = 0.0;
	m_operation = 0;
	m_result = 0.0;
}

void CcalculaterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Cin1);
	//  DDX_Control(pDX, IDC_EDIT1, EditText);
	//  DDX_Text(pDX, IDC_EDIT1, EditText);
	DDX_Control(pDX, IDC_EDIT1, m_control_e);
	DDX_Text(pDX, IDC_EDIT1, m_num);
}

BEGIN_MESSAGE_MAP(CcalculaterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculaterDlg::Onb1)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculaterDlg::Onb0)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculaterDlg::Onb2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculaterDlg::Onb3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculaterDlg::Onb4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculaterDlg::Onb5)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculaterDlg::Onb9)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculaterDlg::Onb8)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculaterDlg::Onb7)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculaterDlg::Onb6)
	ON_BN_CLICKED(IDC_BUTTON11, &CcalculaterDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON12, &CcalculaterDlg::OnSub)
	ON_BN_CLICKED(IDC_BUTTON13, &CcalculaterDlg::OnMul)
	ON_BN_CLICKED(IDC_BUTTON14, &CcalculaterDlg::OnDiv)
	ON_BN_CLICKED(IDC_BUTTON15, &CcalculaterDlg::Ondian)
	ON_BN_CLICKED(IDC_BUTTON16, &CcalculaterDlg::OnAC)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculaterDlg::OnEqual)
	ON_EN_CHANGE(IDC_EDIT1, &CcalculaterDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CcalculaterDlg ��Ϣ�������

BOOL CcalculaterDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculaterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculaterDlg::OnPaint()
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
HCURSOR CcalculaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculaterDlg::Onb1()
{
	AddDigit('1');

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb0()
{
	AddDigit('0');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb2()
{
	AddDigit('2');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb3()
{
	AddDigit('3');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb4()
{
	AddDigit('4');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb5()
{
	AddDigit('5');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb9()
{
	AddDigit('9');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb8()
{
	AddDigit('8');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb7()
{
	AddDigit('7');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Onb6()
{
	AddDigit('6');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void CcalculaterDlg::Equal2()
{
	UpdateData(TRUE);
	op2 = m_num;

	switch (m_operation)
	{
	case 1:
		m_result = op1 + op2;
		break;
	case 2:
		m_result = op1 - op2;
		break;
	case 3:
		if (op2 == 0)
		{
			MessageBox("��������Ϊ�㣬���ڶ������𣿣�����AC���¼��㣡","����");
		}
		else
		{
			m_result = op1 / op2;
			break;
		}
	case 4:
		m_result = op1*op2;
		break;
	}

	m_num = m_result;
	st1 = 0;
	op1 = m_result;
	UpdateData(FALSE);
}

void CcalculaterDlg::OnAdd()
{
	// TODO: Add your control notification handler code here
	if (st2 == 0)
	{
		UpdateData(TRUE);
		op1 = m_num;
		m_operation = 1;
		
		st1 = 0;
		st2 = 1;
		// m_control_e.SetSel(0,-1);
	}
	else
	{
			Equal2();
		UpdateData(TRUE);
		m_operation = 1;
	
		
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnSub()
{
	if (st2 == 0)
	{
		UpdateData(TRUE);
		op1 = m_num;
		m_operation = 2;
		
		st1  = 0;
		st2 = 1;
		// m_control_e.SetSel(0,-1);
	}
	else
	{
		Equal2();
		UpdateData(TRUE);
		m_operation = 2;
		st1 = 0;
		
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnMul()
{
	if (st2 == 0)
	{
		UpdateData(TRUE);
		op1 = m_num;
		m_operation = 4;
		
		st1  = 0;
		st2 = 1;
		// m_control_e.SetSel(0,-1);
	}
	else
	{
		Equal2();
		UpdateData(TRUE);
		m_operation = 4;
	
		st1  = 0;
		
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnDiv()
{
	if (st2 == 0)
	{
		UpdateData(TRUE);
		op1 = m_num;
		m_operation = 3;
		
		st1  = 0;
		st2 = 1;
		// m_control_e.SetSel(0,-1);
	}
	else
	{
		Equal2();
		UpdateData(TRUE);
		m_operation = 3;
		
		st1  = 0;
		
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::Ondian()
{
	AddDigit('.');
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnAC()
{
	op1 = 0.0;
	op2 = 0.0;
	m_result = 0.0;
	m_operation = 0;

	m_num = 0.0;
	UpdateData(FALSE);
	
	st1 = st2 = 0;
	
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnEqual()
{
	if (st2 == 0)
	{
		UpdateData(TRUE);

		op1 = m_num;
	}
	else
	{
		UpdateData(TRUE);
		op2 = m_num;

		switch (m_operation)
		{
		case 1:
			m_result = op1 + op2;
			break;
		case 2:
			m_result = op1 - op2;
			break;
		case 3:
			if (op2 == 0)
			{
				MessageBox("��������Ϊ�㣬���ڶ������𣿣�����AC���¼��㣡", "����");
			}
			else
			{
				m_result = op1 / op2;
				break;
			}
		case 4:
			m_result = op1*op2;
			break;
		}

		m_num = m_result;
		st1 = 0;
		op1 = m_result;
		st2 = 0;
	
		// m_control_e.SetSel(0,-1);
		UpdateData(FALSE);
	}
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalculaterDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void CcalculaterDlg::AddDigit(char numKey)
{
	// TODO: Add your control notification handler code here
	CString str, tmp;

	tmp=numKey;
	m_control_e.GetWindowText(str);
	if (str == '0' || st1 == 0)
		str = tmp;
	else
		str += tmp;
	st1 = 1;
	m_control_e.SetWindowText(str);
}
