
// mfc_testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mfc_test.h"
#include "mfc_testDlg.h"
#include "afxdialogex.h"
#include "fgo_battle.h"
#include<thread>
#include <fstream>
#include<string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int F2Status = 0;//F1 按键状态
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
	ON_BN_CLICKED(IDOK3, &Cmfc_testDlg::OnBnClickedOk3)
	ON_BN_CLICKED(IDOK4, &Cmfc_testDlg::OnBnClickedOk4)
	ON_BN_CLICKED(IDOK5, &Cmfc_testDlg::OnBnClickedOk5)
//	ON_WM_APPCOMMAND()
//ON_WM_KEYDOWN()
//ON_WM_CHAR()
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

CString IntToCstring(int a)
{
	CString s = NULL;
	if (a == -1)
		return s;
	else
	{
		s.Format(_T("%d"), a);
		return s;
	}
}
void Cmfc_testDlg::getInfo(int Info[4][20], int &eventFlag, int &turns, int &appFlag,int &times)
{
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

	GetDlgItem(IDC_EDIT31)->GetWindowText(tmp);
	times = _ttoi(tmp);


	GetDlgItem(IDC_EDIT41)->GetWindowText(tmp);
	eventFlag = __ttoi(tmp);


	GetDlgItem(IDC_EDIT42)->GetWindowText(tmp);
	turns = __ttoi(tmp);

	GetDlgItem(IDC_EDIT43)->GetWindowText(tmp);
	appFlag = __ttoi(tmp);

}

void Cmfc_testDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
	int times;//次数
	int eventFlag;//活动需要在进入副本时选择加成药品时确定
	int turns;//回合数
	int appFlag;//苹果flag
	getInfo(Info, eventFlag, turns, appFlag,times);
	init();
	while (times--)
	{
		SetDlgItemText(IDC_EDIT31, IntToCstring(times));
		Sleep(500);
		onBattle(Info,eventFlag,turns,appFlag);
	}
	

}


void Cmfc_testDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	//选择狗粮按键并且翻页
	CString tmp;
	GetDlgItem(IDC_EDIT46)->GetWindowText(tmp);
	int num = __ttoi(tmp);//狗粮数目
	selectFire(num);

}



void Cmfc_testDlg::OnBnClickedOk3()//读取配置文件
{
	// TODO: 在此添加控件通知处理程序代码


	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT44, strFilePath);
		fstream in;
		in.open(strFilePath, ios::in);

		int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
		int times;//次数
		int eventFlag;//活动需要在进入副本时选择加成药品时确定
		int turns;//回合数
		int appFlag;//苹果flag
		getInfo(Info, eventFlag, turns, appFlag, times);

		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 13; j++)
			{
				in >> Info[i][j];
				in.get();
			}
			in.get();
		}
		in >> eventFlag; in.get();
		in >> turns; in.get();
		in >> appFlag; in.get();
		in >> times; in.get();
		in.close();

		

		SetDlgItemText(IDC_EDIT1, IntToCstring(Info[1][1]));
		SetDlgItemText(IDC_EDIT2, IntToCstring(Info[1][2]));
		SetDlgItemText(IDC_EDIT3, IntToCstring(Info[1][3]));
		SetDlgItemText(IDC_EDIT4, IntToCstring(Info[1][4]));
		SetDlgItemText(IDC_EDIT5, IntToCstring(Info[1][5]));
		SetDlgItemText(IDC_EDIT6, IntToCstring(Info[1][6]));
		SetDlgItemText(IDC_EDIT7, IntToCstring(Info[1][7]));
		SetDlgItemText(IDC_EDIT8, IntToCstring(Info[1][8]));
		SetDlgItemText(IDC_EDIT9, IntToCstring(Info[1][9]));
		SetDlgItemText(IDC_EDIT10, IntToCstring(Info[1][10]));

		SetDlgItemText(IDC_EDIT11, IntToCstring(Info[2][1]));
		SetDlgItemText(IDC_EDIT12, IntToCstring(Info[2][2]));
		SetDlgItemText(IDC_EDIT13, IntToCstring(Info[2][3]));
		SetDlgItemText(IDC_EDIT14, IntToCstring(Info[2][4]));
		SetDlgItemText(IDC_EDIT15, IntToCstring(Info[2][5]));
		SetDlgItemText(IDC_EDIT16, IntToCstring(Info[2][6]));
		SetDlgItemText(IDC_EDIT17, IntToCstring(Info[2][7]));
		SetDlgItemText(IDC_EDIT18, IntToCstring(Info[2][8]));
		SetDlgItemText(IDC_EDIT19, IntToCstring(Info[2][9]));
		SetDlgItemText(IDC_EDIT20, IntToCstring(Info[2][10]));
		
		SetDlgItemText(IDC_EDIT21, IntToCstring(Info[3][1]));
		SetDlgItemText(IDC_EDIT22, IntToCstring(Info[3][2]));
		SetDlgItemText(IDC_EDIT23, IntToCstring(Info[3][3]));
		SetDlgItemText(IDC_EDIT24, IntToCstring(Info[3][4]));
		SetDlgItemText(IDC_EDIT25, IntToCstring(Info[3][5]));
		SetDlgItemText(IDC_EDIT26, IntToCstring(Info[3][6]));
		SetDlgItemText(IDC_EDIT27, IntToCstring(Info[3][7]));
		SetDlgItemText(IDC_EDIT28, IntToCstring(Info[3][8]));
		SetDlgItemText(IDC_EDIT29, IntToCstring(Info[3][9]));
		SetDlgItemText(IDC_EDIT30, IntToCstring(Info[3][10]));

		SetDlgItemText(IDC_EDIT32, IntToCstring(Info[1][11]));
		SetDlgItemText(IDC_EDIT35, IntToCstring(Info[1][12]));
		SetDlgItemText(IDC_EDIT38, IntToCstring(Info[1][13]));

		SetDlgItemText(IDC_EDIT33, IntToCstring(Info[2][11]));
		SetDlgItemText(IDC_EDIT36, IntToCstring(Info[2][12]));
		SetDlgItemText(IDC_EDIT39, IntToCstring(Info[2][13]));

		SetDlgItemText(IDC_EDIT34, IntToCstring(Info[3][11]));
		SetDlgItemText(IDC_EDIT37, IntToCstring(Info[3][12]));
		SetDlgItemText(IDC_EDIT40, IntToCstring(Info[3][13]));

		SetDlgItemText(IDC_EDIT31, IntToCstring(times));
		SetDlgItemText(IDC_EDIT41, IntToCstring(eventFlag));
		SetDlgItemText(IDC_EDIT42, IntToCstring(turns));
		SetDlgItemText(IDC_EDIT43, IntToCstring(appFlag));


	}
}


void Cmfc_testDlg::OnBnClickedOk4()//保存配置文件
{
	// TODO: 在此添加控件通知处理程序代码

	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("fgo脚本配置"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT45, strFilePath);
		fstream out;
		out.open(strFilePath, ios::out);

		int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
		int times;//次数
		int eventFlag;//活动需要在进入副本时选择加成药品时确定
		int turns;//回合数
		int appFlag;//苹果flag
		getInfo(Info, eventFlag, turns, appFlag, times);
		
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 13; j++)
			{
				out << Info[i][j];
				out << " ";
			}
			out << endl;
		}
		out << eventFlag << endl;
		out << turns << endl;
		out << appFlag << endl;
		out << times << endl;
		out.close();
	}


}

void Cmfc_testDlg::OnBnClickedOk5()
{
	// TODO: 在此添加控件通知处理程序代码
	F2Status = 0;
	CString tmp;
	GetDlgItem(IDC_EDIT47)->GetWindowText(tmp);
	int num = __ttoi(tmp);
	FriendlyPool(num);
}



BOOL Cmfc_testDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类


	if (pMsg->wParam == VK_F2)
	{
		F2Status = 1;
		printf("123");
	}
	return CDialogEx::PreTranslateMessage(pMsg);

}
