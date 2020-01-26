
// mfc_testDlg.cpp : ʵ���ļ�
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
int F2Status = 0;//û����
int bIsRunning = 1;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
UINT MfcThreadProc(LPVOID lpParam);
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


// Cmfc_testDlg �Ի���



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


// Cmfc_testDlg ��Ϣ�������

BOOL Cmfc_testDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cmfc_testDlg::OnPaint()
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
HCURSOR Cmfc_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc_testDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}



int __ttoi(CString s)
{
	if (s.IsEmpty())
		return -1;
	if (s.GetLength() > 1)//������ȴ���1
	{
		if (s[0] == '0')//��һλ��0�����10X
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
	

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int  Info[4][20];//1-9Ϊ9�����ܣ�10Ϊ���ߣ�11-13Ϊ��������
	int times;//����
	int eventFlag;//���Ҫ�ڽ��븱��ʱѡ��ӳ�ҩƷʱȷ��
	int turns;//�غ���
	int appFlag;//ƻ��flag
	int x, y;//���ڲ�ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ѡ�����������ҷ�ҳ
	CString tmp;
	GetDlgItem(IDC_EDIT46)->GetWindowText(tmp);
	int num = __ttoi(tmp);//������Ŀ
	selectFire(num);

}



void Cmfc_testDlg::OnBnClickedOk3()//��ȡ�����ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT44, strFilePath);
		fstream in;
		in.open(strFilePath, ios::in);

		int  Info[4][20];//1-9Ϊ9�����ܣ�10Ϊ���ߣ�11-13Ϊ��������
		int times;//����
		int eventFlag;//���Ҫ�ڽ��븱��ʱѡ��ӳ�ҩƷʱȷ��
		int turns;//�غ���
		int appFlag;//ƻ��flag
		string tmp_windowName;//��������
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


void Cmfc_testDlg::OnBnClickedOk4()//���������ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ���ù�����   
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|Word�ļ�(*.doc)|*.doc|�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("fgo�ű�����"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CString strFilePath;

	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT45, strFilePath);
		fstream out;
		out.open(strFilePath, ios::out);

		CString windowName;//��������
		GetDlgItem(IDC_EDIT53)->GetWindowText(windowName);
		string tmp_windowName = CT2A(windowName);

		int  Info[4][20];//1-9Ϊ9�����ܣ�10Ϊ���ߣ�11-13Ϊ��������
		int times;//����
		int eventFlag;//���Ҫ�ڽ��븱��ʱѡ��ӳ�ҩƷʱȷ��
		int turns;//�غ���
		int appFlag;//ƻ��flag
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	F2Status = 0;
	CString tmp;
	GetDlgItem(IDC_EDIT47)->GetWindowText(tmp);
	int num = __ttoi(tmp);


	GetDlgItem(IDC_EDIT53)->GetWindowText(tmp);
	
	FriendlyPool(num, tmp);
}



BOOL Cmfc_testDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���


	if (pMsg->wParam == VK_F2)
	{
		F2Status = 1;
		printf("123");
	}
	return CDialogEx::PreTranslateMessage(pMsg);

}


void Cmfc_testDlg::OnEnChangeEdit48()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

void Cmfc_testDlg::OnBnClickedOk6()//�黨��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tmp;
	GetDlgItem(IDC_EDIT53)->GetWindowText(tmp);
	init(tmp);
	check();
}


void Cmfc_testDlg::OnEnChangeEdit52()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
