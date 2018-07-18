
// mfc_testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfc_test.h"
#include "mfc_testDlg.h"
#include "afxdialogex.h"
#include "fgo_battle.h"
#include<string>
using namespace std;
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


// Cmfc_testDlg 对话框



Cmfc_testDlg::Cmfc_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmfc_testDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &Cmfc_testDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Cmfc_testDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &Cmfc_testDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// Cmfc_testDlg 消息处理程序

BOOL Cmfc_testDlg::OnInitDialog()
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

void Cmfc_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cmfc_testDlg::OnPaint()
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
HCURSOR Cmfc_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc_testDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}



int __ttoi(CString s)
{
	if (s.IsEmpty())
		return -1;
	return _ttoi(s);
}



void Cmfc_testDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
	CString tmp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(tmp);
	Info[1][1] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT2)->GetWindowText(tmp);
	Info[1][2] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT3)->GetWindowText(tmp);
	Info[1][3] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT4)->GetWindowText(tmp);
	Info[1][4] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT5)->GetWindowText(tmp);
	Info[1][5] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT6)->GetWindowText(tmp);
	Info[1][6] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT7)->GetWindowText(tmp);
	Info[1][7] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT8)->GetWindowText(tmp);
	Info[1][8] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT9)->GetWindowText(tmp);
	Info[1][9] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT10)->GetWindowText(tmp);
	Info[1][10] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT11)->GetWindowText(tmp);
	Info[2][1] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT12)->GetWindowText(tmp);
	Info[2][2] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT13)->GetWindowText(tmp);
	Info[2][3] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT14)->GetWindowText(tmp);
	Info[2][4] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT15)->GetWindowText(tmp);
	Info[2][5] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT16)->GetWindowText(tmp);
	Info[2][6] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT17)->GetWindowText(tmp);
	Info[2][7] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT18)->GetWindowText(tmp);
	Info[2][8] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT19)->GetWindowText(tmp);
	Info[2][9] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT20)->GetWindowText(tmp);
	Info[2][10] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT21)->GetWindowText(tmp);
	Info[3][1] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT22)->GetWindowText(tmp);
	Info[3][2] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT23)->GetWindowText(tmp);
	Info[3][3] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT24)->GetWindowText(tmp);
	Info[3][4] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT25)->GetWindowText(tmp);
	Info[3][5] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT26)->GetWindowText(tmp);
	Info[3][6] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT27)->GetWindowText(tmp);
	Info[3][7] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT28)->GetWindowText(tmp);
	Info[3][8] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT29)->GetWindowText(tmp);
	Info[3][9] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT30)->GetWindowText(tmp);
	Info[3][10] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT32)->GetWindowText(tmp);
	Info[1][11] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT35)->GetWindowText(tmp);
	Info[1][12] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT38)->GetWindowText(tmp);
	Info[1][13] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT33)->GetWindowText(tmp);
	Info[2][11] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT36)->GetWindowText(tmp);
	Info[2][12] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT39)->GetWindowText(tmp);
	Info[2][13] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT34)->GetWindowText(tmp);
	Info[3][11] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT37)->GetWindowText(tmp);
	Info[3][12] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT40)->GetWindowText(tmp);
	Info[3][13] = __ttoi(tmp);
	int times;//次数

	GetDlgItem(IDC_EDIT31)->GetWindowText(tmp);
	times = _ttoi(tmp);
	
	int eventFlag;
	GetDlgItem(IDC_EDIT41)->GetWindowText(tmp);
	eventFlag = __ttoi(tmp);

	int turns;
	GetDlgItem(IDC_EDIT42)->GetWindowText(tmp);
	turns = __ttoi(tmp);
	
	int appFlag;
	GetDlgItem(IDC_EDIT43)->GetWindowText(tmp);
	appFlag= __ttoi(tmp);

	
	init();
	while (times--)
	{
		Sleep(1000);
		onBattle(Info,eventFlag,turns,appFlag);
	}
	

}


void Cmfc_testDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	//选择狗粮按键并且翻页
	
	for (int i = 0; i < 3; i++)
	{
		int x = 126, y = 253;
		for (int j = 0; j < 5; j++)
		{
			moveto(x + j * 144, y + i * 144);
			leftclick();
			Sleep(100);
		}
	}
	Sleep(200);
	leftdown();
	Sleep(200);
	leftdown();
}
