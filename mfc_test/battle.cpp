#define _CRT_SECURE_NO_WARNINGS

#include  <conio.h>
#include "stdafx.h"
#include <Windows.h>  
#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include<string>
#include<algorithm>

using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 


int Window_X, Window_Y;//Ϊ�������Ͻǵ�����
POINT skill[10];//��¼9������λ��
POINT personPos[5];//��¼ʹ�ô��߼��ܻ�����װ����ʱ��ѡ����˵�λ��
POINT cardPos[6];//���ſ���λ��
POINT baojuPos[4];//���ű��ߵ�λ��

POINT attackPos;//attack λ��
COLORREF attackColor;//attack ��ɫ
POINT battleEndPos;//ս��������һ��λ��
POINT ClosePos;//���Ͻǣ��رհ���λ��
COLORREF CloseColor;//���Ͻ���ɫֵ

POINT startBattlePos;//��ʼս����ťλ��
POINT helpPos;//��һ����սλ��

POINT Masterskillpos[5];//��������λ�ã�0Ϊ��������λ�ã�1 2 3 Ϊ3�����ֱܷ��λ��
POINT cardDect[6][3];//����ÿ�ſ���ѡȡ�������ص�����жϿ�������

POINT goldApplePos;//��ƻ��λ��
POINT sliverApplePos;//��ƻ��
POINT bronzeApplePos;//ͭƻ��
POINT yesPos;//��ƻ����ȷ����λ��
POINT startPos;//��ı���λ�ã�������,����Ҫ���ĸ�������

POINT skillCancelPos;
HWND hq;
HDC hdc;
struct CARD
{
	int id;
	int isRed, isBule, isGreen;//��¼������ɫ��������������Ϊ�˷���Կ�����
	int isWeak;//�Ƿ����,����Ϊ1����ͨΪ0 ��������Ϊ-1
}card[6];
struct ColorRGB
{
	int R, G, B;
};
void init()//��ʼ��
{
	LPCWSTR a;
	hq = FindWindowA(NULL,"ҹ��ģ����");//��ô��ھ��
	hdc = ::GetDC(NULL);
	RECT rect;
	GetWindowRect(hq, &rect);
	Window_X = rect.left;
	Window_Y = rect.top;
	std::cout << Window_X << " " << Window_Y << std::endl;
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
	attackColor = RGB(2, 233, 249);//attack����ɫ��ֵ

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
	yesPos.x = 635; yesPos.y = 455;

	skillCancelPos.x = 263; skillCancelPos.y = 356;
}
ColorRGB getRGB(COLORREF color)//�õ�rgb��ʾ����ɫֵ
{
	ColorRGB tmp;
	BYTE Red = GetRValue(color); //�õ�����ɫ
	BYTE Green = GetGValue(color); //�õ�����ɫ
	BYTE Blue = GetBValue(color); //�õ�����ɫ
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
COLORREF getColor(int x, int y)//x��yΪ�������
{
	COLORREF clr = ::GetPixel(hdc, x + Window_X, y + Window_Y);
	return clr;
}
COLORREF getColor(POINT p)//pΪ���λ��
{

	COLORREF clr = ::GetPixel(hdc, p.x + Window_X, p.y + Window_Y);
	return clr;
}
void leftclick()//�˺���ģ�������
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void moveto(int x, int y)//�ƶ���꣬x,yΪ���λ��
{
	SetCursorPos(x + Window_X, y + Window_Y);
}
void moveto(POINT p)//�ƶ���꣬POINTΪ���λ��
{
	SetCursorPos(p.x + Window_X, p.y + Window_Y);
}
void leftdown()//��ס��������ƶ����������Ĵ�ֱ����
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
void useSkill(int k)//ʹ�õ�k������
{
	moveto(skill[k]);
	leftclick();
	Sleep(1000);
	/* �������cdû��*/
	ColorRGB tmp = getRGB(getColor(skillCancelPos));
	if (abs(tmp.R - 215) <= 5 && abs(tmp.G - 215) <= 5 && abs(tmp.B - 215) <= 5)
	{
		moveto(skillCancelPos);
		leftclick();
		Sleep(1000);
		return;
	}

	Sleep(3000);
}
void useSkill(int k, int i)//ʹ�õ�k�����ܶԵ�i����
{
	moveto(skill[k]);
	leftclick();
	Sleep(1000);
	/*�������cdû��*/
	ColorRGB tmp = getRGB(getColor(skillCancelPos));
	if (abs(tmp.R - 215) <= 5 && abs(tmp.G - 215) <= 5 && abs(tmp.B - 215) <= 5)
	{
		moveto(skillCancelPos);
		leftclick();
		Sleep(1000);
		return;
	}
	moveto(personPos[i]);
	leftclick();
	Sleep(4000);
}
void useMasterSkill(int k)//ʹ�õ�k����������
{
	moveto(Masterskillpos[0]);
	leftclick();
	Sleep(1000);
	moveto(Masterskillpos[k]);
	leftclick();
	Sleep(4000);
}
void useMasterSkill(int k, int i)//ʹ�õ�k���������ܶԵ�i����
{
	moveto(Masterskillpos[0]);
	leftclick();
	Sleep(1000);
	moveto(Masterskillpos[k]);
	leftclick();
	Sleep(200);
	moveto(personPos[i]);
	leftclick();
	Sleep(4000);
}
void getCardinfo()//���ÿ�ſ�������
{
	for (int i = 1; i <= 5; i++)
	{
		card[i].id = i;
		for (int j = 0; j <= 2; j++)
		{
			if (j == 0)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				if (cl.R >= 100 && cl.G <= 80 && cl.B <= 80)//�Ǻ쿨
				{
					card[i].isRed = 1;
					card[i].isGreen = 0;
					card[i].isBule = 0;
					cout << "��" << i << "�ſ���" << "��" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else if (cl.G >= 100 && cl.R <= 80 && cl.B <= 80)//�̿�
				{
					card[i].isRed = 0;
					card[i].isGreen = 1;
					card[i].isBule = 0;
					cout << "��" << i << "�ſ���" << "��" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else if (cl.B >= 100 && cl.R <= 80 && cl.G <= 80)//����
				{
					card[i].isRed = 0;
					card[i].isGreen = 0;
					card[i].isBule = 1;
					cout << "��" << i << "�ſ���" << "��" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
				else//���ֲ����Ŀ����̿�
				{
					card[i].isRed = 0;
					card[i].isGreen = 1;
					card[i].isBule = 0;
					cout << "��" << i << "�ſ���" << "��ȷ��" << endl;
					cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;

				}
			}
			else if (j == 1)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;
				if (cl.R >= 100 && cl.G <= 50 && cl.B <= 50)//����
				{
					card[i].isWeak = 1;
					cout << "��" << i << "�ſ���" << "����" << endl;

				}
			}
			else if (j == 2 && card[i].isWeak != 1)
			{
				COLORREF tmp = getColor(cardDect[i][j]);
				ColorRGB cl = getRGB(tmp);
				cout << "R=" << cl.R << " " << "G=" << cl.G << " B=" << cl.B << endl;
				if (cl.B >= 100 && cl.R <= 60 && cl.G <= 60 )//������
				{
					card[i].isWeak = -1;
					cout << "��" << i << "�ſ���" << "������" << endl;
				}
			}
		}
	}

}
bool cmp(CARD a, CARD b)//�Կ������ȼ���������
{
	if (a.isWeak != b.isWeak)
		return a.isWeak > b.isWeak;
	else if (a.isRed != b.isRed)
		return a.isRed > b.isRed;
	else if (a.isBule != b.isBule)
		return a.isBule > b.isBule;
	else return a.isGreen > b.isGreen;
}
void delayBaojuTime()//��������ʱ��
{
	POINT dectNode;//�ض���ɫֵ��һ��
	dectNode.x = 730;
	dectNode.y = 47;
	Sleep(5500);//������Ӧʱ��
	//COLORREF cl = RGB(118, 219, 220);
	while (1)
	{
		ColorRGB cl = getRGB(getColor(dectNode));
		cout << cl.R << " " << cl.G << " " << cl.B << endl;
		cout << "��������" << endl;
		if (abs(cl.R - 133) <= 5 && abs(cl.G - 99) <= 5 && abs(cl.B - 62) <= 5)
			break;
		else if (abs(cl.R - 123) <= 5 && abs(cl.G - 151) <= 5 && abs(cl.B - 172) <= 5)
			break;
		else if (abs(cl.R - 229) <= 5 && abs(cl.G - 150) <= 5 && abs(cl.B - 133) <= 5)
			break;
		Sleep(200);
	}
}
int attack()//���г���ѡȡ���ſ�����һ�ι���
{
	getCardinfo();
	sort(card + 1, card + 6, cmp);
	moveto(attackPos);
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
int attack(int k)//ѡȡ��i�����߽���һ�ι���,����һ��ѡ��������������
{
	getCardinfo();
	sort(card + 1, card + 6, cmp);
	moveto(attackPos);
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
bool isNewBattle()//ͨ�������ж��Ƿ��Ѿ��������.�ж�λ����
{
	POINT tmp;
	tmp.x = 730;
	tmp.y = 47;
	if (getColor(tmp) == 0)
		return true;
	return false;
}
bool isEnd()//�ж��Ƿ������ս������
{
	POINT tmp;
	tmp.x = 544; tmp.y = 93;
	ColorRGB k = getRGB(getColor(tmp));
	cout << k.R << " " << k.G << " " << k.B << endl;
	COLORREF cl = RGB(246, 247, 255);
	if (abs(k.R - 248) <= 1 && abs(k.G - 251) <= 1 && abs(k.B - 251) <= 1)
		return true;
	return false;
}
bool isAttackButton()//�ж�attack��ť�Ƿ����
{
	ColorRGB tmp = getRGB(getColor(attackPos));
	cout << tmp.R << " " << tmp.G << " " << tmp.B << endl;
	if (abs(tmp.R - 253) <= 1 && abs(tmp.G - 253) <= 1 && abs(tmp.B - 253) <= 1)
		return true;
	return false;
}
void waitForAttack()//�ӳ�ʱ�䵽attack����
{
	while (!isAttackButton())
		Sleep(500);
}

int isBaojuReady()//�жϱ����Ƿ�׼����û���򷵻�0�����򷵻����һ��׼���õı���
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
	for (int i = 1; i <= 3; i++)
	{
		cl[i][0] = getRGB(getColor(dect[i][0]));
		cl[i][1] = getRGB(getColor(dect[i][1]));
		/*cout << cl[i][0].R << " " << cl[i][0].G << " " << cl[i][0].B << endl;
		cout << cl[i][1].R << " " << cl[i][1].G << " " << cl[i][1].B << endl << endl;*/
		if ((abs(cl[i][0].R - 219) <= 20 && abs(cl[i][0].G - 219) <= 20 && abs(cl[i][0].B - 219) <= 20) ||
			(abs(cl[i][1].R - 226) <= 20 && abs(cl[i][1].G - 153) <= 20 && abs(cl[i][1].B - 11) <= 20))
		{
			if (res == 0)
				res = i;
			cout << "��" << i << "������׼��" << endl;
		}
	}
	return res;
}

bool isSkillReady(int x)//�жϵ�X������cd�Ƿ���ȴ
{
	POINT skillDect[10];//�����жϼ���cd
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
	cout << "��" << x << "����" << " " << tmp.R << " " << tmp.G << " " << tmp.B << endl;
	if (tmp.R == tmp.G&&tmp.G == tmp.B&&tmp.R == key[x])
	{

		return false;
	}
	cout << "��" << x << "����" << "׼��" << endl;
	return true;
}

void battleEnd()//������ս������֮��Ӧ������
{

	while (!isNewBattle())
	{
		moveto(battleEndPos);
		ColorRGB tmp = getRGB(getColor(ClosePos));
		if (abs(tmp.R-242)<5&&abs(tmp.G-242)<5&&abs(tmp.B-242)<5)//�ж��Ƿ������װ
		{
			cout << "��װ����" << endl;
			moveto(ClosePos);
			leftclick();
			Sleep(1000);
		}
		leftclick();
		Sleep(500);
	}
	while (isNewBattle())//һֱ�ȵ���������
		Sleep(200);
}
void eatApple(int appFlag)
{
	if (appFlag == 2)
	{
		moveto(bronzeApplePos);
	}
	else if (appFlag == 1)
	{
		moveto(sliverApplePos);
	}
	else 
		moveto(goldApplePos);
	leftclick();
	Sleep(2000);
	moveto(yesPos);
	leftclick();
	Sleep(2000);
	/*
	moveto(startPos);
	leftclick();
	Sleep(2000);
	*/
}
void startBattle(int appFlag)//��ʼս��
{
	startPos.x = 728;
	startPos.y = 151;
	moveto(startPos);
	leftclick();
	Sleep(2000);
	/*�ж��Ƿ��ƻ��*/
	POINT tmp;
	tmp.x = 803; tmp.y = 209;
	ColorRGB cl = getRGB(getColor(tmp));
	if (abs(cl.R - 43) <= 5 && abs(cl.G - 63) <= 5 && abs(cl.B - 98) <= 5)
		eatApple(appFlag);
	/*-------*/
	POINT fPos;//ˢ��λ��
	fPos.x = 629;
	fPos.y = 137;
	moveto(fPos);
	leftclick();
	Sleep(800);
	moveto(yesPos);
	leftclick();
	Sleep(1500);

	moveto(helpPos);
	leftclick();
	Sleep(2000);
	moveto(startBattlePos);
	leftclick();
	Sleep(2000);
}
void Event(int flag)//����л��-1��ִ�в�����0����ѡ��ģ�ߣ�1 2 3 4 ѡ��ڼ���
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
	if (abs(tmp.R - 215) < 5 && abs(tmp.G - 215) < 5 && abs(tmp.B - 216) < 5)//���û��ģ��
	{
		moveto(btNotUse);
		leftclick();
	}
}
void onBattle(int info[4][20],int eventFlag,int turns,int appFlag)//������������������
{
	cout << Window_X << " " << Window_Y << endl;
	int flag1 = 0, flag2 = 0, flag3 = 0;
	startBattle(appFlag);
	/**/
	Event(eventFlag);
	/*---��һ��------*/
	waitForAttack();
	/*ʹ�ü��ܣ��ű���*/
	for (int i = 1; i < 10; i++)
	{
		if (info[1][i] == 0)
			useSkill(i);
		else if (info[1][i]>0)
			useSkill(i, info[1][i]);
	}
	for (int i = 11; i <= 13; i++)
	{
		if (info[1][i] == 0)
			useMasterSkill(i - 10);
		else if (info[1][i] > 0)
			useMasterSkill(i - 10, info[1][i]);
	}

	if (info[1][10] > 0)
		attack(info[1][10]);
	else attack();
	/*ʹ�ü���,�ű���*/

	while (!isNewBattle())//�ж���û�д���,�Ƿ���Ҫƽ��
	{
		cout << "��һ�صȴ�" << endl;
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
			cout << "��һ��ƽ��" << endl;
			attack();
			while (!isNewBattle() && !isAttackButton())//�ж���û�д���
				Sleep(200);
		}
	}
	cout << "��һ�ؽ���" << endl;
	/*--------------------------------------------------------------------------------*/

	/*---�ڶ���------*/
	if (turns == 3)
	{
		waitForAttack();
		/*ʹ�ü��ܣ��ű���*/
		for (int i = 1; i < 10; i++)
		{
			if (info[2][i] == 0)
				useSkill(i);
			else if (info[2][i] > 0)
				useSkill(i, info[2][i]);
		}

		for (int i = 11; i <= 13; i++)
		{
			if (info[2][i] == 0)
				useMasterSkill(i - 10);
			else if (info[2][i] > 0)
				useMasterSkill(i - 10, info[2][i]);
		}


		if (info[2][10] > 0)
			attack(info[2][10]);
		else attack();
		/*ʹ�ü���,�ű���*/

		while (!isNewBattle())//�ж���û�д���,�Ƿ���Ҫƽ��
		{
			cout << "�ڶ��صȴ�" << endl;
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
				cout << "�ڶ���ƽ��" << endl;
				attack();
				while (!isNewBattle() && !isAttackButton())//�ж���û�д���
					Sleep(200);
			}
		}
		cout << "�ڶ��ؽ���" << endl;
	}
	/*--------------------------------------------------------------------------------*/
	/*---������------*/
	waitForAttack();
	/*ʹ�ü��ܣ��ű���*/
	for (int i = 1; i < 10; i++)
	{
		if (info[3][i] == 0)
			useSkill(i);
		else if (info[3][i]>0)
			useSkill(i, info[3][i]);
	}

	for (int i = 11; i <= 13; i++)
	{
		if (info[3][i] == 0)
			useMasterSkill(i - 10);
		else if (info[3][i] > 0)
			useMasterSkill(i - 10, info[3][i]);
	}


	if (info[3][10] > 0)
		attack(info[3][10]);
	else attack();
	/*ʹ�ü���,�ű���*/

	while (!isEnd())//�ж���û�д���,�Ƿ���Ҫƽ��
	{
		cout << "�����صȴ�" << endl;
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
			
			/*�Զ�ʹ�ü���*/
			/*
			Sleep(1000);
			for (int k = 2; k <= 3; k++)
			{
				if (isSkillReady(k))
					useSkill(k);
			}
			*/
			cout << "������ƽ��" << endl;
			int tmppos = isBaojuReady();
			if (tmppos == 0)
				attack();
			else attack(tmppos);
			while (!isEnd() && !isAttackButton())//�ж���û�д���
				Sleep(200);
		}
	}
	/*-----------------------------------------------------------------------*/
	cout << "�����ؽ���" << endl;
	battleEnd();
}
void selectFire(int num)
{
	init();
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
			//ѡ15��
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
	init();
	while (num--)
	{
		moveto(619, 457);
		leftclick();
		Sleep(500);
		leftclick();
		moveto(566, 539);
		Sleep(5000);
		leftclick();
		Sleep(1500);
		leftclick();
		Sleep(1000);
	}
}