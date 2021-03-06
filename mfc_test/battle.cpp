#define _CRT_SECURE_NO_WARNINGS

#include  <conio.h>
#include "stdafx.h"
#include <Windows.h>  
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <string>
#include "resource.h"
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
int isBaojuReady();
int baoju[4];
int Window_X, Window_Y;//为窗口左上角的坐标
POINT skill[10];//记录9个技能位置
POINT personPos[5];//记录使用从者技能或者礼装技能时，选择的人的位置
POINT cardPos[6];//五张卡的位置
POINT baojuPos[4];//三张宝具的位置

POINT attackPos;//attack 位置
COLORREF attackColor;//attack 颜色
POINT battleEndPos;//战斗结束下一步位置
POINT ClosePos;//左上角，关闭按键位置
COLORREF CloseColor;//左上角颜色值

POINT startBattlePos;//开始战斗按钮位置
POINT helpPos;//第一个助战位置

POINT Masterskillpos[5];//御主技能位置，0为御主技能位置，1 2 3 为3个技能分别的位置
POINT cardDect[6][3];//对于每张卡，选取两个像素点进行判断卡的属性

POINT goldApplePos;//金苹果位置
POINT sliverApplePos;//银苹果
POINT bronzeApplePos;//铜苹果
POINT stoneApplePos;//圣晶石位置
POINT yesPos;//吃苹果是确定键位置
POINT startPos;//打的本的位置，这个会变,根据要打哪个本而定
POINT friendPos;//关卡结束出现好友添加按钮的否定位置
POINT skillCancelPos;
HWND hq;
HDC hdc;
int clinetWindow_X, clinetWindow_Y;
struct CARD
{
	int id;
	int isRed, isBule, isGreen;//记录卡的颜色，用三个变量是为了方便对卡排序
	int isWeak;//是否克制,克制为1，普通为0 ，被克制为-1
}card[6];
struct ColorRGB
{
	int R, G, B;
};


void windowCorrect(int x, int y)
{
	if (x == -1 || y == -1)
		return;
	else
	{
		//clinetWindow_X = Window_X + 2;
		//clinetWindow_Y= Window_Y+36;

		clinetWindow_X = Window_X + x;
		clinetWindow_Y = Window_Y + y;
		Window_X = clinetWindow_X - 2;
		Window_Y = clinetWindow_Y - 36;
	}

}

void init(int x,int y, CString windowName = _T("夜神模拟器"))//初始化
{
	CString tmp;
	if (windowName[0] == '\0')
		tmp = _T("夜神模拟器");
	else tmp = windowName;
	
	CStringA tmpA(tmp);
	LPCSTR newWindowName = tmpA;

	LPCWSTR a;
	hq = FindWindowA(NULL, newWindowName);//获得窗口句柄
	hdc = ::GetDC(NULL);
	RECT rect, clientRect;
	GetWindowRect(hq, &rect);
	Window_X = rect.left;
	Window_Y = rect.top;
	//clinetWindow_X = Window_X + 2;
	//clinetWindow_Y= Window_Y+36;
	
	cout << "not correct window" << endl;
	std::cout << Window_X << " " << Window_Y << std::endl;
	windowCorrect(x, y);
	cout << "correctwindow" << endl;
	cout << Window_X << " " << Window_Y << endl;

	skill[1].x = 57;  skill[1].y = 471;
	skill[2].x = 126;  skill[2].y = 471;
	skill[3].x = 193;  skill[3].y = 471;
	skill[4].x = 297;  skill[4].y = 471;
	skill[5].x = 363;  skill[5].y = 471;
	skill[6].x = 433;  skill[6].y = 471;
	skill[7].x = 531;  skill[7].y = 471;
	skill[8].x = 600;  skill[8].y = 471;
	skill[9].x = 673;  skill[9].y = 471;

	personPos[1].x = 253; personPos[1].y = 357;
	personPos[2].x = 480; personPos[2].y = 357;
	personPos[3].x = 731; personPos[3].y = 357;

	cardPos[1].x = 96; cardPos[1].y = 414;
	cardPos[2].x = 291; cardPos[2].y = 414;
	cardPos[3].x = 485; cardPos[3].y = 414;
	cardPos[4].x = 674; cardPos[4].y = 414;
	cardPos[5].x = 878; cardPos[5].y = 414;

	baojuPos[1].x = 291; baojuPos[1].y = 201;
	baojuPos[2].x = 485; baojuPos[2].y = 201;
	baojuPos[3].x = 674; baojuPos[3].y = 201;

	attackPos.x = 852; attackPos.y = 425;
	attackColor = RGB(2, 233, 249);//attack的颜色赋值

	cardDect[1][0].x = 747; cardDect[1][0].y = 468;
	cardDect[1][1].x = 724; cardDect[1][1].y = 398;
	cardDect[1][2].x = 734; cardDect[1][2].y = 402;//

	cardDect[2][0].x = 768; cardDect[2][0].y = 422;
	cardDect[2][1].x = 773; cardDect[2][1].y = 349;
	cardDect[2][2].x = 780; cardDect[2][2].y = 357;

	cardDect[3][0].x = 800; cardDect[3][0].y = 395;
	cardDect[3][1].x = 833; cardDect[3][1].y = 329;
	cardDect[3][2].x = 836; cardDect[3][2].y = 340;//

	cardDect[4][0].x = 842; cardDect[4][0].y = 379;
	cardDect[4][1].x = 902; cardDect[4][1].y = 336;
	cardDect[4][2].x = 900; cardDect[4][2].y = 348;//

	cardDect[5][0].x = 892; cardDect[5][0].y = 387;
	cardDect[5][1].x = 960; cardDect[5][1].y = 365;
	cardDect[5][2].x = 956; cardDect[5][2].y = 375;//

	Masterskillpos[0].x = 897; Masterskillpos[0].y = 274;
	Masterskillpos[1].x = 679; Masterskillpos[1].y = 274;
	Masterskillpos[2].x = 746; Masterskillpos[2].y = 274;
	Masterskillpos[3].x = 813; Masterskillpos[3].y = 274;

	battleEndPos.x = 829; battleEndPos.y = 546;
	ClosePos.x = 37; ClosePos.y = 51;
	COLORREF CloseColor = RGB(242, 242, 242);

	helpPos.x = 400; helpPos.y = 217;
	startBattlePos.x = 889; startBattlePos.y = 541;

	goldApplePos.x = 500; goldApplePos.y = 268;
	sliverApplePos.x = 475; sliverApplePos.y = 376;
	bronzeApplePos.x = 475; bronzeApplePos.y = 461;
	stoneApplePos.x = 502; stoneApplePos.y = 186;
	yesPos.x = 635; yesPos.y = 455;

	skillCancelPos.x = 263; skillCancelPos.y = 356;

	friendPos.x = 196; friendPos.y = 497;
}
ColorRGB getRGB(COLORREF color)//得到rgb表示的颜色值
{
	ColorRGB tmp;
	BYTE Red = GetRValue(color); //得到红颜色
	BYTE Green = GetGValue(color); //得到绿颜色
	BYTE Blue = GetBValue(color); //得到蓝颜色
	char chR[4];
	_itoa_s(Red, chR, 10);

	char chG[4];
	_itoa_s(Green, chG, 10);

	char chB[4];
	_itoa_s(Blue, chB, 10);

	tmp.R = atoi(chR);
	tmp.G = atoi(chG);
	tmp.B = atoi(chB);
	return tmp;
}
COLORREF getColor(int x, int y)//x，y为相对坐标
{
	COLORREF clr = ::GetPixel(hdc, x + Window_X, y + Window_Y);
	return clr;
}
COLORREF getColor(POINT p)//p为相对位置
{

	COLORREF clr = ::GetPixel(hdc, p.x + Window_X, p.y + Window_Y);
	return clr;
}
void leftclick()//此函数模拟鼠标点击
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
void moveto(int x, int y)//移动鼠标，x,y为相对位置
{
	SetCursorPos(x + Window_X, y + Window_Y);
}
void moveto(POINT p)//移动鼠标，POINT为相对位置
{
	SetCursorPos(p.x + Window_X, p.y + Window_Y);
}
void leftdown()//按住鼠标向上移动三个狗粮的垂直距离
{
	int x = 490;
	int y = 481;
	moveto(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(500);
	for (; y >= 17; y -= 7)
	{
		moveto(x, y);
		Sleep(20);
	}
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
bool ifSkillReady()
{
	POINT tag;
	tag.x = 584;
	tag.y = 357;
	ColorRGB tmp = getRGB(getColor(tag));
	if (abs(tmp.R - 108) <= 2 && abs(tmp.G - 108) <= 2 && abs(tmp.B - 108) <= 2)
		return false;
	return true;
}
void useSkill(int k)//使用第k个技能
{
	moveto(skill[k]);
	leftclick();
	Sleep(1000);
	/* 如果技能cd没好*/
	ColorRGB tmp = getRGB(getColor(skillCancelPos));
	if (!ifSkillReady())
	{
		printf("技能cd未好");
		moveto(skillCancelPos);
		leftclick();
		Sleep(1000);
		return;
	}

	Sleep(4000);
}
void useSkill(int k, int i)//使用第k个技能对第i个人
{
	moveto(skill[k]);
	leftclick();
	Sleep(1000);
	/*如果技能cd没好*/
	ColorRGB tmp = getRGB(getColor(skillCancelPos));
	if (!ifSkillReady())
	{
		printf("技能cd未好");
		moveto(skillCancelPos);
		leftclick();
		Sleep(1000);
		return;
	}
	moveto(personPos[i]);
	leftclick();
	Sleep(4000);
}
void useMasterSkill(int k)//使用第k个御主技能
{
	moveto(Masterskillpos[0]);
	leftclick();
	Sleep(1000);
	moveto(Masterskillpos[k]);
	leftclick();
	Sleep(5000);
}
void useMasterSkill(int k, int i)//使用第k个御主技能对第i个人，当i>10时，视为换人礼装 14即1 4对调
{
	if (i > 10)//换人礼装
	{
		int tmp1 = i / 10;
		int tmp2 = i % 10;

		POINT changePos[7];
		changePos[1].x =99 ; changePos[1].y = 297;
		changePos[2].x = 271; changePos[2].y = 297;
		changePos[3].x = 433; changePos[3].y = 297;
		changePos[4].x = 575; changePos[4].y = 297;
		changePos[5].x = 725; changePos[5].y = 297;
		changePos[6].x = 874; changePos[6].y = 297;
		moveto(Masterskillpos[0]);
		leftclick();
		Sleep(1000);
		moveto(Masterskillpos[k]);
		leftclick();
		Sleep(500);
		moveto(changePos[tmp1]);
		leftclick();
		Sleep(200);
		moveto(changePos[tmp2]);
		leftclick();
		Sleep(200);
		moveto(485, 505);
		leftclick();

		Sleep(10000);
	}
	else
	{
		moveto(Masterskillpos[0]);
		leftclick();
		Sleep(1000);
		moveto(Masterskillpos[k]);
		leftclick();
		Sleep(200);
		moveto(personPos[i]);
		leftclick();
		Sleep(6000);
	}
}
void getCardinfo()//获得每张卡的类型
{
	for (int i = 1; i <= 5; i++)
	{
		card[i].id = i;
		card[i].isWeak = 0;
		for (int j = 0; j <= 2; j++)
		{
			if (j == 0)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				if (cl.R >= 100 && cl.G <= 80 && cl.B <= 80)//是红卡
				{
					card[i].isRed = 1;
					card[i].isGreen = 0;
					card[i].isBule = 0;
					cout << "第" << i << "张卡是" << "红" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else if (cl.G >= 100 && cl.R <= 80 && cl.B <= 80)//绿卡
				{
					card[i].isRed = 0;
					card[i].isGreen = 1;
					card[i].isBule = 0;
					cout << "第" << i << "张卡是" << "绿" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else if (cl.B >= 100 && cl.R <= 80 && cl.G <= 80)//蓝卡
				{
					card[i].isRed = 0;
					card[i].isGreen = 0;
					card[i].isBule = 1;
					cout << "第" << i << "张卡是" << "蓝" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else//区分不出的看作绿卡
				{
					card[i].isRed = 0;
					card[i].isGreen = 1;
					card[i].isBule = 0;
					cout << "第" << i << "张卡是" << "不确定" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
			}
			else if (j == 1)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;
				if (cl.R >= 100 && cl.G <= 50 && cl.B <= 50)//克制
				{
					card[i].isWeak = 1;
					cout << "第" << i << "张卡是" << "克制" << endl;

				}
			}
			else if (j == 2 && card[i].isWeak != 1)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;
				if (cl.B >= 100 && cl.R <= 60 && cl.G <= 60 )//被克制
				{
					card[i].isWeak = -1;
					cout << "第" << i << "张卡是" << "被克制" << endl;
				}
			}
		}
	}

}
bool cmp(CARD a, CARD b)//对卡的优先级进行排序
{
	if (a.isWeak != b.isWeak)
		return a.isWeak > b.isWeak;
	else if (a.isRed != b.isRed)
		return a.isRed > b.isRed;
	else if (a.isBule != b.isBule)
		return a.isBule > b.isBule;
	else return a.isGreen > b.isGreen;
}
void delayBaojuTime()//隔开宝具时间
{
	POINT dectNode;//特定颜色值的一点
	dectNode.x = 730;
	dectNode.y = 47;
	Sleep(5500);//隔开反应时间
	//COLORREF cl = RGB(118, 219, 220);
	while (1)
	{
		ColorRGB cl = getRGB(getColor(dectNode));
		cout << cl.R << " " << cl.G << " " << cl.B << endl;
		ColorRGB bronze, silver, gold;
		bronze.R =141 ; bronze.G = 100; bronze.B=59;
		silver.R = 116; silver.G = 150; silver.B =167;
		gold.R = 229; gold.G = 181; gold.B = 148;
		cout << "跳过宝具" << endl;
		if (abs(cl.R - gold.R) <= 5 && abs(cl.G -gold.G) <= 5 && abs(cl.B - gold.B) <= 5)
			break;
		else if (abs(cl.R - silver.R) <= 5 && abs(cl.G -silver.G) <= 5 && abs(cl.B - silver.B) <= 5)
			break;
		else if (abs(cl.R - bronze.R) <= 5 && abs(cl.G - bronze.G) <= 5 && abs(cl.B - bronze.B) <= 5)
			break;
		Sleep(200);
	}
}
int attack()//进行常规选取三张卡进行一次攻击
{
	getCardinfo();
	sort(card + 1, card + 6, cmp);
	moveto(attackPos);
	Sleep(1000);
	leftclick();
	Sleep(2000);
	for (int i = 1; i <= 3; i++)
	{
		moveto(cardPos[card[i].id]);
		leftclick();
		Sleep(1000);
	}
	return 0;
}
int attack(int k)//选取第i个宝具进行一次攻击
{
	if(k>10)
	{
		int k1 = k / 10;
		int k2 = k % 10;
		isBaojuReady();
		if (baoju[k1] != 1)//宝具未准备
		{
			printf("宝具未准备");
			attack(k2);
			return 0;
		}
		if (baoju[k2] != 1)//宝具未准备
		{
			printf("宝具未准备");
			attack(k1);
			return 0;
		}
		getCardinfo();
		sort(card + 1, card + 6, cmp);
		moveto(attackPos);
		Sleep(1000);
		leftclick();
		Sleep(2000);
		moveto(baojuPos[k1]);
		leftclick();
		Sleep(1000);
		moveto(baojuPos[k2]);
		leftclick();
		Sleep(1000);
		for (int i = 1; i < 2; i++)
		{
			moveto(cardPos[card[i].id]);
			leftclick();
			Sleep(1000);
		}
		delayBaojuTime();
		printf("宝具1结束");
		Sleep(2000);//待修改
		delayBaojuTime();
		printf("宝具2结束");
		return 0;
	}
	else
	{
		isBaojuReady();
		if (baoju[k] != 1)//宝具未准备
		{
			attack();
			return 0;
		}
		getCardinfo();
		sort(card + 1, card + 6, cmp);
		moveto(attackPos);
		Sleep(1000);
		leftclick();
		Sleep(2000);
		moveto(baojuPos[k]);
		leftclick();
		Sleep(1000);
		for (int i = 1; i <= 2; i++)
		{
			moveto(cardPos[card[i].id]);
			leftclick();
			Sleep(1000);
		}
		delayBaojuTime();
		return 0;
	}
}
bool isNewBattle()//通过黑屏判断是否已经打完这关.
{
	POINT tmp;
	//tmp.x = 65; tmp.y = 176;
	//tmp.x = 730; tmp.y = 47;
	tmp.x = 680; tmp.y = 108;
	ColorRGB color = getRGB(getColor(tmp));
	cout << "newBettle判断" << endl;
	cout << color.R << " " << color.G << " " << color.B << endl;
	if (color.R == 0 && color.G == 0 && color.B == 0)
	{
		cout << "newBettle判断==true" << endl;
		return true;
	}
	cout << "newBettle判断==false" << endl;
	return false;
}
bool isAllBattleEnd()//通过黑屏判断是否已经打完
{
	POINT tmp;
//	tmp.x = 729; tmp.y = 51;
	tmp.x = 49; tmp.y = 530;
	ColorRGB color = getRGB(getColor(tmp));
	cout << "newBettle判断" << endl;
	cout << color.R << " " << color.G << " " << color.B << endl;
	if (color.R == 0 && color.G == 0 && color.B == 0)
	{
		cout << "newBettle判断==true" << endl;
		return true;
	}
	cout << "newBettle判断==false" << endl;
	return false;
}
bool isEnd()//判断是否出现了战斗结束
{
	POINT tmp;
	//tmp.x = 575; tmp.y = 67;
	tmp.x = 65; tmp.y = 176;
	ColorRGB k = getRGB(getColor(tmp));
	cout << k.R << " " << k.G << " " << k.B << endl;
	ColorRGB tmpcl;
	tmpcl.R = 234; tmpcl.G = 192; tmpcl.B = 36;
	if (abs(k.R - tmpcl.R) <= 1 && abs(k.G - tmpcl.G) <= 1 && abs(k.B - tmpcl.B) <= 1)
		return true;
	return false;
}
bool isAttackButton()//判断attack按钮是否出现
{
	attackPos.x = 869 - 5;
	attackPos.y = 454 - 9;
	ColorRGB tmp = getRGB(getColor(attackPos));
	cout << tmp.R << " " << tmp.G << " " << tmp.B << endl;
	/*
	//对应初始化的点的位置
	if (abs(tmp.R - 253) <= 1 && abs(tmp.G - 253) <= 1 && abs(tmp.B - 253) <= 1)
		return true;
		*/
	if (abs(tmp.R - 0) <= 1 && abs(tmp.G - 237) <= 1 && abs(tmp.B - 253) <= 1)
		return true;
	return false;
}
void waitForAttack()//延迟时间到attack出现
{
	while (!isAttackButton())
		Sleep(500);
}
int isBaojuReady()//判断宝具是否准备，没有则返回0，有则返回最后一个准备好的宝具
{
	POINT dect[4][2];
	dect[1][0].x = 181; dect[1][0].y = 536;//219 219 219
	dect[1][1].x = 125; dect[1][1].y = 545;//226 153 11
	dect[2][0].x = 419; dect[2][0].y = 536;//236 236 236
	dect[2][1].x = 362; dect[2][1].y = 545;//226 153 11
	dect[3][0].x = 659; dect[3][0].y = 536;//236 236 236
	dect[3][1].x = 602; dect[3][1].y = 545;//226 153 11
	ColorRGB cl[4][2];
	int res = 0;
	for (int i = 1; i <= 3; i++) baoju[i] = 0;
	for (int i = 1; i <= 3; i++)
	{
		cl[i][0] = getRGB(getColor(dect[i][0]));
		cl[i][1] = getRGB(getColor(dect[i][1]));
		/*cout << cl[i][0].R << " " << cl[i][0].G << " " << cl[i][0].B << endl;
		cout << cl[i][1].R << " " << cl[i][1].G << " " << cl[i][1].B << endl << endl;*/
		if ((abs(cl[i][0].R - 219) <= 20 && abs(cl[i][0].G - 219) <= 20 && abs(cl[i][0].B - 219) <= 20) ||
			(abs(cl[i][1].R - 226) <= 20 && abs(cl[i][1].G - 153) <= 20 && abs(cl[i][1].B - 11) <= 20)||
			(abs(cl[i][1].R - 246) <= 20 && abs(cl[i][1].G - 231) <= 20 && abs(cl[i][1].B - 125) <= 20)
			)
		{
			if (res == 0)
				res = i;
			cout << "第" << i << "个宝具准备" << endl;
			baoju[i] = 1;
		}
	}
	return res;
}
bool isSkillReady(int x)//判断第X个技能cd是否冷却
{
	POINT skillDect[10];//用来判断技能cd
	skillDect[1].x = 40; skillDect[1].y = 487;//237
	skillDect[2].x = 110; skillDect[2].y = 487;//247
	skillDect[3].x = 182; skillDect[3].y = 487;//250
	skillDect[4].x = 278; skillDect[4].y = 487;//238
	skillDect[5].x = 348; skillDect[5].y = 487;//247
	skillDect[6].x = 420; skillDect[6].y = 487;//251
	skillDect[7].x = 517; skillDect[7].y = 487;//245
	skillDect[8].x = 588; skillDect[8].y = 487;//248
	skillDect[9].x = 660; skillDect[9].y = 487;//232
	int key[10] = { 0, 237, 247, 250, 238, 247, 251, 245, 248, 232 };
	ColorRGB tmp = getRGB(getColor(skillDect[x]));
	int Gray = tmp.R * 0.299 + tmp.G * 0.587 + tmp.B * 0.114;
	cout << "第" << x << "技能" << " " << tmp.R << " " << tmp.G << " " << tmp.B << endl;
	if (tmp.R == tmp.G&&tmp.G == tmp.B&&tmp.R == key[x])
	{

		return false;
	}
	cout << "第" << x << "技能" << "准备" << endl;
	return true;
}
void battleEnd()//出现了战斗结束之后应该做的
{

	while (!isAllBattleEnd())
	{
		moveto(battleEndPos);
		ColorRGB tmp = getRGB(getColor(ClosePos));
		ColorRGB tmp2 = getRGB(getColor(friendPos));
		if (abs(tmp2.R - 213) < 3 && abs(tmp2.G - 213) < 3 && abs(tmp2.B - 213) < 3)//判断是否添加好友
		{
			cout << "取消添加好友" << endl;
			moveto(friendPos);
			leftclick();
			Sleep(1000);
		}
		if (abs(tmp.R-242)<5&&abs(tmp.G-242)<5&&abs(tmp.B-242)<5)//判断是否掉落礼装
		{
			cout << "礼装掉落" << endl;
			PlaySound(LPWSTR(IDR_WAVE3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC );
			moveto(ClosePos);
			leftclick();
			Sleep(1000);
		}
		cout << "战斗结束" << endl;
		leftclick();
		Sleep(500);
	}
	Sleep(3000);
	while (isAllBattleEnd())//一直等到黑屏结束
		Sleep(1000);
	Sleep(2000);
}
void eatApple(int appFlag)
{
	printf("appFlag=%d\n", appFlag);
	if (appFlag == 2)
	{
		moveto(bronzeApplePos);

	}
	else if (appFlag == 1)
	{
		moveto(sliverApplePos);
	}
	else if (appFlag == 0)
	{
		moveto(goldApplePos);
	}
	else if (appFlag == 3)
	{
		moveto(stoneApplePos);
	}
	leftclick();
	moveto(yesPos);
	Sleep(3000);
	leftclick();
	Sleep(3000);
	/*
	moveto(startPos);
	leftclick();
	Sleep(2000);
	*/
}
void refreshFriendAndSelect()//刷新好友并且选择
{
	POINT fPos, yesAndClosePos;//刷新位置,确定按钮，关闭按钮位置（同一个）
	fPos.x = 629;
	fPos.y = 137;
	yesAndClosePos.x = 544;
	yesAndClosePos.y = 458;
	POINT tmp;//检测有没有符合设定条件的好友
	tmp.x = 349; tmp.y = 373;
	ColorRGB cl;
	do {
		moveto(fPos);
		leftclick();
		Sleep(1000);
		moveto(yesAndClosePos);
		leftclick();
		Sleep(4000);
		cl = getRGB(getColor(tmp));
	} while ((abs(cl.R - 255) <= 1 && abs(cl.G - 255) <= 1 && abs(cl.B - 255) <= 1));
	moveto(helpPos);
	leftclick();
	Sleep(2000);

}
void startBattle(int appFlag)//开始战斗
{
	startPos.x = 728;
	startPos.y = 175;
	moveto(startPos);
	leftclick();
	Sleep(4000);
	/*判断是否吃苹果*/
	POINT tmp;
	tmp.x = 803; tmp.y = 209;
	ColorRGB cl = getRGB(getColor(tmp));
	if (abs(cl.R - 62) <= 5 && abs(cl.G - 116) <= 5 && abs(cl.B - 163) <= 5)
	{
		printf("eat apple\n");
		eatApple(appFlag);
	}
	/*-------*/
	refreshFriendAndSelect();
	moveto(startBattlePos);
	leftclick();
	Sleep(2000);
}

void Event(int flag)//如果有活动，-1不执行操作，0，不选择模具，1 2 3 4 选择第几个
{
	POINT bt1, bt2, bt3, btNotUse;
	bt1.x = 484; bt1.y = 190;
	bt2.x = 484; bt2.y = 285;
	bt3.x = 484; bt3.y = 406;
	btNotUse.x = 684; btNotUse.y = 527;
	if (flag == -1) return;
	if (flag == 0)
	{
		moveto(btNotUse);
		leftclick();
		Sleep(2000);
	}
	else if (flag == 1)
	{
		moveto(bt1);
	}
	else if (flag == 2)
	{
		moveto(bt2);
	}
	else if (flag == 3)
	{
		moveto(bt3);
	}
	else if (flag == 4)
	{
		leftdown();
		Sleep(500);
		moveto(bt3);
	}
	
	leftclick(); 
	Sleep(4000);
	ColorRGB tmp = getRGB(getColor(btNotUse));
	if (abs(tmp.R - 215) < 5 && abs(tmp.G - 215) < 5 && abs(tmp.B - 216) < 5)//如果没有模具
	{
		moveto(btNotUse);
		leftclick();
	}
}
void selectEnemy(int i)
{
	POINT first, second, third;
	first.x = 35; first.y = 71;
	second.x = 220; second.y = 71;
	third.x = 401; third.y = 71;
	if (i == 0||i==-1) return;
	else if (i == 1)
	{
		moveto(first);
	}
	else if (i == 2)
	{
		moveto(second);
	}
	else if (i == 3)
	{
		moveto(third);
	}
	leftclick();
	Sleep(1000);
}


void onBattle(int info[4][20],int eventFlag,int turns,int appFlag,int x,int y)//处理整个副本的流程
{
	
	int flag1 = 0, flag2 = 0, flag3 = 0;
	startBattle(appFlag);
	/**/
	Event(eventFlag);
	/*---第一关------*/

	if (turns == 2 || turns == 3)
	{
		waitForAttack();
		/*使用技能，放宝具*/
		selectEnemy(info[1][14]);//选择敌人位置

		//使用技能，双重循环
		for (int count = 0; count < 2; count++)
		{
			for (int i = 1; i < 10; i++)//9个技能循环
			{
				if (info[1][i] < 10)//只循环一次
				{
					if (count == 1) continue;//第二轮循环跳过
					if (info[1][i] == 0)
						useSkill(i);
					else if (info[1][i] > 0)
						useSkill(i, info[1][i]);
				}
				else
				{
					int round[5], cnt = 0, tmpInfo = info[1][i];
					while (tmpInfo)//字符分割
					{
						round[cnt++] = tmpInfo % 10;
						tmpInfo /= 10;
					}
					if (round[1 - count] == 0)
					{
						useSkill(i);
					}
					else if (round[1 - count] > 0)
					{
						if (round[1 - count] >= 4)
							continue;
						useSkill(i, round[1 - count]);
					}
				}

			}
			if (count == 1) break;
			for (int i = 11; i <= 13; i++)//御主技能循环
			{
				if (info[1][i] == 0)
					useMasterSkill(i - 10);
				else if (info[1][i] > 0)
					useMasterSkill(i - 10, info[1][i]);
			}
		}
		if (info[1][10] > 0)
			attack(info[1][10]);
		else attack();
		/*使用技能,放宝具*/

		while (!isNewBattle())//判断有没有打完,是否需要平砍
		{
			cout << "第一关等待" << endl;
			Sleep(200);
			if (isAttackButton())
			{
				flag1 = 1;
				break;
			}
		}
		if (flag1)
		{
			while (isAttackButton())
			{
				cout << "第一关平砍" << endl;
				attack();
				while (!isNewBattle() && !isAttackButton())//判断有没有打完
					Sleep(200);
			}
		}
		cout << "第一关结束" << endl;
		/*--------------------------------------------------------------------------------*/
	}
	/*---第二关------*/
	if (turns == 3)
	{
		waitForAttack();
		/*使用技能，放宝具*/
		selectEnemy(info[2][14]);//选择敌人位置

		//使用技能，双重循环
		for (int count = 0; count < 2; count++)
		{
			for (int i = 1; i < 10; i++)//9个技能循环
			{
				if (info[2][i] < 10)//只循环一次
				{
					if (count == 1) continue;//第二轮循环跳过
					if (info[2][i] == 0)
						useSkill(i);
					else if (info[2][i] > 0)
						useSkill(i, info[2][i]);
				}
				else
				{
					int round[5], cnt = 0, tmpInfo = info[2][i];
					while (tmpInfo)
					{
						round[cnt++] = tmpInfo % 10;
						tmpInfo /= 10;
					}
					if (round[1 - count] == 0)
					{
						useSkill(i);
					}
					else if (round[1 - count] > 0)
					{
						if (round[1 - count] >= 4)
							continue;
						useSkill(i, round[1 - count]);
					}
				}

			}
			if (count == 1) break;
			for (int i = 11; i <= 13; i++)//御主技能循环
			{
				if (info[2][i] == 0)
					useMasterSkill(i - 10);
				else if (info[2][i] > 0)
					useMasterSkill(i - 10, info[2][i]);
			}
		}


		if (info[2][10] > 0)
			attack(info[2][10]);
		else attack();
		/*使用技能,放宝具*/

		while (!isNewBattle())//判断有没有打完,是否需要平砍
		{
			cout << "第二关等待" << endl;
			Sleep(200);
			if (isAttackButton())
			{
				flag2 = 1;
				break;
			}
		}
		if (flag2)
		{
			while (isAttackButton())
			{
				cout << "第二关平砍" << endl;
				attack();
				while (!isNewBattle() && !isAttackButton())//判断有没有打完
					Sleep(200);
			}
		}
		cout << "第二关结束" << endl;
	}
	/*--------------------------------------------------------------------------------*/
	/*---第三关------*/
	waitForAttack();
	/*使用技能，放宝具*/
	selectEnemy(info[3][14]);//选择敌人位置

	//使用技能，双重循环
	for (int count = 0; count < 2; count++)
	{
		for (int i = 1; i < 10; i++)//9个技能循环
		{
			if (info[3][i] < 10)//只循环一次
			{
				if (count == 1) continue;//第二轮循环跳过
				if (info[3][i] == 0)
					useSkill(i);
				else if (info[3][i] > 0)
					useSkill(i, info[3][i]);
			}
			else
			{
				int round[5], cnt = 0, tmpInfo = info[3][i];
				while (tmpInfo)
				{
					round[cnt++] = tmpInfo % 10;
					tmpInfo /= 10;
				}
				if (round[1 - count] == 0)
				{
					useSkill(i);
				}
				else if (round[1 - count] > 0)
				{
					if (round[1 - count] >= 4)
						continue;
					useSkill(i, round[1 - count]);
				}
			}

		}
		if (count == 1) break;
		for (int i = 11; i <= 13; i++)//御主技能循环
		{
			if (info[3][i] == 0)
				useMasterSkill(i - 10);
			else if (info[3][i] > 0)
				useMasterSkill(i - 10, info[3][i]);
		}
	}


	if (info[3][10] > 0)
		attack(info[3][10]);
	else attack();
	/*使用技能,放宝具*/

	while (!isEnd())//判断有没有打完,是否需要平砍
	{
		cout << "第三关等待" << endl;
		Sleep(200);
		if (isAttackButton())
		{
			flag3 = 1;
			break;
		}
	}
	if (flag3)
	{
		while (isAttackButton())
		{
			
			/*自动使用技能*/
			/*
			Sleep(1000);
			for (int k = 2; k <= 3; k++)
			{
				if (isSkillReady(k))
					useSkill(k);
			}
			*/
			cout << "第三关平砍" << endl;
			int tmppos = isBaojuReady();
			if (tmppos == 0)
				attack();
			else attack(tmppos);
			while (!isEnd() && !isAttackButton())//判断有没有打完
				Sleep(200);
		}
	}
	/*-----------------------------------------------------------------------*/
	cout << "第三关结束" << endl;
	battleEnd();
}
void selectFire(int num)//有bug，
{
	int row_tmp = num % 15 == 0 ? num / 15 : num / 15 + 1;
	int left_num = num - (num / 15) * 15;
	for (int k = 1; k <= row_tmp; k++)
	{
		if (k == row_tmp && left_num != 0)
		{
			int row = left_num % 5 == 0 ? left_num / 5 : left_num / 5 + 1;
			int col = left_num % 5 == 0 ? 5 : left_num % 5;

			for (int i = 0; i < row; i++)
			{
				int x = 130, y = 252;
				if (i == row - 1)
				{
					for (int j = 0; j < col; j++)
					{
						moveto(x + j * 144, y + i * 144);
						leftclick();
						Sleep(100);
					}
				}
				else
				{
					for (int j = 0; j < 5; j++)
					{
						moveto(x + j * 144, y + i * 144);
						leftclick();
						Sleep(100);
					}
				}
			}
		}
		else
		{
			//选15个
			for (int i = 0; i < 3; i++)
			{
				int x = 130, y = 252 ;
				for (int j = 0; j < 5; j++)
				{
					moveto(x + j * 144, y + i * 144);
					leftclick();
					Sleep(100);
				}
			}
			Sleep(200);
			leftdown();
			Sleep(500);
		}
	}
}
void FriendlyPool(int num)
{
	
	while (num--)
	{
		moveto(619, 457);
		leftclick();
		Sleep(500);
		leftclick();
		moveto(566, 539);
		Sleep(8000);
		leftclick();
		Sleep(1500);
		leftclick();
		Sleep(1000);
	}
}

void check()//用来检测特定点颜色值
{
	printf("check\n");
	
	isEnd();
}