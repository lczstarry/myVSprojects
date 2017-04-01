
// calculaterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculater.h"
#include "calculaterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcalculaterDlg 对话框



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


// CcalculaterDlg 消息处理程序

BOOL CcalculaterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculaterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculaterDlg::Onb1()
{
	AddDigit('1');

	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb0()
{
	AddDigit('0');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb2()
{
	AddDigit('2');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb3()
{
	AddDigit('3');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb4()
{
	AddDigit('4');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb5()
{
	AddDigit('5');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb9()
{
	AddDigit('9');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb8()
{
	AddDigit('8');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb7()
{
	AddDigit('7');
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Onb6()
{
	AddDigit('6');
	// TODO:  在此添加控件通知处理程序代码
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
			MessageBox("除数不能为零，你在逗我是吗？！请点击AC重新计算！","警告");
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
	// TODO:  在此添加控件通知处理程序代码
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
	// TODO:  在此添加控件通知处理程序代码
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
	// TODO:  在此添加控件通知处理程序代码
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
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::Ondian()
{
	AddDigit('.');
	// TODO:  在此添加控件通知处理程序代码
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
	
	// TODO:  在此添加控件通知处理程序代码
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
				MessageBox("除数不能为零，你在逗我是吗？！请点击AC重新计算！", "警告");
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
	// TODO:  在此添加控件通知处理程序代码
}


void CcalculaterDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
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
