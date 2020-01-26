
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
#include<iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int F2Status = 0;//没有用
int bIsRunning = 1;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
UINT MfcThreadProc(LPVOID lpParam);
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
ON_EN_CHANGE(IDC_EDIT48, &Cmfc_testDlg::OnEnChangeEdit48)
ON_BN_CLICKED(IDOK6, &Cmfc_testDlg::OnBnClickedOk6)
ON_BN_CLICKED(IDOK7, &Cmfc_testDlg::OnBnClickedOk7)
ON_EN_CHANGE(IDC_EDIT52, &Cmfc_testDlg::OnEnChangeEdit52)
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
	if (s.GetLength() > 1)//如果长度大于1
	{
		if (s[0] == '0')//第一位是0，变成10X
		{
			CString tmp("1");
			s = tmp + s;
		}
	}
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
		if (s.GetLength() == 3)
		{
			s = s.Mid(1);
		}
		return s;
	}
}
void Cmfc_testDlg::getInfo(int Info[4][20], int &eventFlag, int &turns, int &appFlag,int &times,int &x,int &y)
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

	GetDlgItem(IDC_EDIT48)->GetWindowText(tmp);
	Info[1][14] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT49)->GetWindowText(tmp);
	Info[2][14] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT50)->GetWindowText(tmp);
	Info[3][14] = __ttoi(tmp);

	GetDlgItem(IDC_EDIT31)->GetWindowText(tmp);
	times = _ttoi(tmp);


	GetDlgItem(IDC_EDIT41)->GetWindowText(tmp);
	eventFlag = __ttoi(tmp);


	GetDlgItem(IDC_EDIT42)->GetWindowText(tmp);
	turns = __ttoi(tmp);

	GetDlgItem(IDC_EDIT43)->GetWindowText(tmp);
	appFlag = __ttoi(tmp);

	GetDlgItem(IDC_EDIT52)->GetWindowText(tmp);
	x= __ttoi(tmp);
	GetDlgItem(IDC_EDIT51)->GetWindowText(tmp);
	y = __ttoi(tmp);
}

void Cmfc_testDlg::OnBnClickedOk()
{
	CString windowName;
	GetDlgItem(IDC_EDIT53)->GetWindowText(windowName);
	

	// TODO:  在此添加控件通知处理程序代码
	int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
	int times;//次数
	int eventFlag;//活动需要在进入副本时选择加成药品时确定
	int turns;//回合数
	int appFlag;//苹果flag
	int x, y;//窗口差值
	getInfo(Info, eventFlag, turns, appFlag,times,x,y);
	init(windowName);
	//PlaySound(LPWSTR(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	while (times--)
	{
		SetDlgItemText(IDC_EDIT31, IntToCstring(times));
		Sleep(500);
		onBattle(Info,eventFlag,turns,appFlag,x,y);
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
		string tmp_windowName;//窗口名称
		int x, y;
		getInfo(Info, eventFlag, turns, appFlag, times,x,y);

		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 14; j++)
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
		in >> x; in.get();
		in >> y; in.get();
		in >> tmp_windowName; in.get();
		in.close();

		CA2T szr((tmp_windowName).c_str());
		CString windowName = (LPCTSTR)szr;
		

		

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
		
		SetDlgItemText(IDC_EDIT52, IntToCstring(x));
		SetDlgItemText(IDC_EDIT51, IntToCstring(y));
		SetDlgItemText(IDC_EDIT53, windowName);

		SetDlgItemText(IDC_EDIT48, IntToCstring(Info[1][14]));
		SetDlgItemText(IDC_EDIT49, IntToCstring(Info[2][14]));
		SetDlgItemText(IDC_EDIT50, IntToCstring(Info[3][14]));
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

		CString windowName;//窗口名称
		GetDlgItem(IDC_EDIT53)->GetWindowText(windowName);
		string tmp_windowName = CT2A(windowName);

		int  Info[4][20];//1-9为9个技能，10为宝具，11-13为御主技能
		int times;//次数
		int eventFlag;//活动需要在进入副本时选择加成药品时确定
		int turns;//回合数
		int appFlag;//苹果flag
		int x, y;
		getInfo(Info, eventFlag, turns, appFlag, times,x,y);
		
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 14; j++)
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
		out << x << endl;
		out << y << endl;
		out << tmp_windowName << endl;
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


	GetDlgItem(IDC_EDIT53)->GetWindowText(tmp);
	
	FriendlyPool(num, tmp);
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


void Cmfc_testDlg::OnEnChangeEdit48()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


UINT MfcThreadProc(LPVOID lpParam)
{
	POINT tar, reStart, tmpOk, dec;
	tar.x = 295; tar.y = 376;
	reStart.x = 852; reStart.y = 220;
	tmpOk.x = 637; tmpOk.y = 448;
	dec.x = 158;
	dec.y = 353;
	while (1)
	{
		ColorRGB cl = getRGB(getColor(dec));
		cout << cl.R <<" "<< cl.G <<" "<< cl.B << endl;

		if (abs(cl.R - 10) <= 1 && abs(cl.G - 79) <= 1 && abs(cl.B - 112) <= 1)
		{
			cout <<"get "<< cl.R << " " << cl.G << " " << cl.B << endl;
			moveto(reStart);
			Sleep(1000);
			leftclick();
			moveto(tmpOk);
			Sleep(1000);
			leftclick();
			moveto(478, 461);
			Sleep(2000);
			leftclick();
			continue;
		}
		moveto(tar);
		leftclick();
		Sleep(500);

		if (bIsRunning == 0)
			return 0;
	}

	return 0;
}

void Cmfc_testDlg::OnBnClickedOk6()//抽花瓣
{
	// TODO: 在此添加控件通知处理程序代码

	CString tmp;
	GetDlgItem(IDC_EDIT53)->GetWindowText(tmp);

	init(tmp);

	CWinThread* MyThread=AfxBeginThread(MfcThreadProc,0);
	bIsRunning = 1;
	while (1)
	{
		if (bIsRunning==1)
		{
			if (KEY_DOWN('Q'))
			{
				bIsRunning = 0;
				break;
			}
		}
	}
}


void Cmfc_testDlg::OnBnClickedOk7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmp;
	GetDlgItem(IDC_EDIT53)->GetWindowText(tmp);
	init(tmp);
	check();
}


void Cmfc_testDlg::OnEnChangeEdit52()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
