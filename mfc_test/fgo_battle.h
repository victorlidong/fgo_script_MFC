void onBattle(int info[4][20],int eventFlag,int turns,int appFlag,int x,int y);
void init(CString windowName = _T("ҹ��ģ����"));
void moveto(int x, int y);
void leftdown();
void leftclick();
bool isEnd();
void selectFire(int num);
void FriendlyPool(int num, CString windowName = _T("ҹ��ģ����"));
struct ColorRGB
{
	int R, G, B;
};
ColorRGB getRGB(COLORREF color);
COLORREF getColor(POINT p);
void moveto(POINT p);
void useMasterSkill(int k, int i);
void check();


