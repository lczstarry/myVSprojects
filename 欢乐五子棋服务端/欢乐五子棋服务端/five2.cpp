// 五子棋_课程设计_服务端.cpp : Defines the entry point for the console application.
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++头文件++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>		//此头文件包含了大部分win32操作系统相关API
#include <conio.h>			//控制台输入/出头文件，非C语言标准头文件
#include <winsock2.h>		
#include<stdio.h>
#include <Mmsystem.h>//播放音乐
#include <time.h>

#pragma comment(lib, "WSOCK32.LIB")
#pragma comment(lib, "winmm.lib")//播放音乐-----------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++预定义常数群++++++++++++++++++++++++++++++++++++++++++++++++++
#define ENTER	13    //回车
#define ESC		27	  //退出
#define	UP		72		//光标向上移动
#define DOWN	80		//光标向下移动
#define LEFT	75		//光标向左移动
#define RIGHT	77		//光标向右移动
#define E       69    //退出
#define R       82    //认输键
#define C		67   //按C键进行聊天
#define PORT 9002    //与客户端协商，使用9001号端口
# define EMPTY 0
# define PLAYER 1
# define COMPUTER -1 /* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为-1 */
#define SIZE 400
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++全局变量群+++++++++++++++++++++++++++++++++++++++++++++++++++++++
int step[21][21]={0};//当元素的值为1时表示黑子、当元素的值为0时表示白子,网络对战数组
int curX = 21, curY = 10;    //分别表示光标位置的x和y，初始值默认在棋盘中心
int player;   //在网络中，用0和1表示玩家可否下子
int k;//用于接收返回的键值
int tot;//记录棋子步数
int rebegin();//重新开始游戏
int recorde_host=0;//玩家记录步数
int recorde_completor=0;//挑战者记录步数
clock_t start, finish;//开始，结束时间
double duration;//以秒为单位计时
//队列
struct queue
{
	int x[SIZE];
	int y[SIZE];
	char ch[SIZE][4];
	int front,rear;
};
struct gaolian
{
	int X;//横坐标
	int Y;//纵坐标
}gl[5];//五个棋子☆
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++自定义函数声明群++++++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x, int y);//光标定位
void Drawingboard();//打印棋盘
int check(int x,int y);//判断黑子输赢
int getInputKey();//获得输入的是哪个键
int pingju();//平局判定
void help2();//帮助信息
void show_menu();//显示选择菜单
//void help1();//显示菜单帮助信息
void help3();//显示双人对战的帮助信息
int Int_game();//网络对战
int doub_game();//双人对战
int man_com();//人机对战
void regongzinen(int *a,int *b);//人工智能算法
int value_s(int a,int b);//分析权值
int Qixing_s(int n,int a,int b);//分析棋型
void Yi_wei(int n,int *I,int *J);//分析移位
int check1(int x,int y);//判断白子输赢
//判断队列是否已满
bool queueFull(queue *q);
//判断队列是否已空
bool queueEmpty(queue *q);
//输出队列
void queueOut(queue *q);
//初始化队列指针
inline void queueInit(queue *q);
//model:表示1-人机、2-人人、3-网络模式；who:在人机和人人模式下，who=1表黑子；who=0表白子；_curX,_curY表棋盘电脑显示上的x,y坐标
//void play_chess(int model,int who,int _curX,int _curY,queue *q1);
//void show_chess(int model,int who,queue *q1);//棋盘的播放
void gaolianInit();//初始化结构体数组gl
void show_gl();//当五子连成一线时，打印五个星
//void xiazi_music();//下子音乐
//void ManWin_music();//对手胜利音乐
//void FemaleWin_music();//玩家胜利音乐
void Initrecorde();//初始化所有记录数据
void show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
void playsound();
void cmain();
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++主函数++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(int argc, char* argv[])
{
	cmain();
	return 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++函数定义群++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//打印菜单
void show_menu()
{
	printf("\t                                                              \n");
	printf("\t┏┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅┓\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                   欢乐五子棋                             ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  1、人机对战                             ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  2、人人本机对战                         ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  3、人人联机对战                         ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  4、背景音乐播放                         ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  5、退出界面                             ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┗┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅┛\n");
	printf("\n");
}
//打印菜单帮助信息
void help1()
{
	printf("\n\t¤＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊¤\n");
	printf("\t＃                       游戏方法                       ＃\n");
	printf("\t＃                                                      ＃\n");
	printf("\t＃   方向键控制光标，获得下子位置    回车键确认落子     ＃\n");
	printf("\t＃                                                      ＃\n");
	printf("\t＃                 ↑                                   ＃\n");
	printf("\t＃               ←  →                    ┃           ＃\n");
	printf("\t＃                 ↓                 <━━┛           ＃\n");
	printf("\t＃                                                      ＃\n");
	printf("\t＃     Shift+C ：聊天                                   ＃\n");
	printf("\t＃                                                      ＃\n");
	printf("\t＃                            您是   ●   ●     ●     ＃\n");
	printf("\t＃     Shift+R ：认输                ●     ●  ●      ＃\n");
	printf("\t＃                               ●●●●●   ●        ＃\n");
	printf("\t＃                                   ●      ● ●      ＃\n");
	printf("\t＃     Shift+E ：退出                ●     ●    ●    ＃\n");
	printf("\t＃                             连成一线就胜利!!!        ＃\n");
	printf("\t¤＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊¤\n\n\n");
}
//网络对战
int Int_game()
{
	player=1;
	int cX=41,cY=23;//聊天位置定位
	tot=0;//重新置0
	//初始化队列
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//初始化所有记录数据
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++网络变量准备区域++++++++++++++++++++++++++++++++++++++++++++++++++++++
	char buff[100];    //用于发送/接收数据的缓冲区
	WSADATA wsa;
	SOCKET sliten;     //监听套接字，只服务端需要
	SOCKET sConnection;   //连接套接字，建立连接之后的通话双方
	struct sockaddr_in serverAdd;     //用于描述服务端的地址
	struct sockaddr_in clientAdd;     //用于描述客户端的地址
	int clientAddSize;      //用于保存客户地址所占用的字节数
	//网络初始化，判断是否成功
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("初始化失败！");
		exit(-1);      //非正常退出
	}
	sliten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sliten == INVALID_SOCKET)
	{
		printf("套接字创建失败！");
		exit(-1);
	}
	//准备网络地址
	serverAdd.sin_family = AF_INET;
	serverAdd.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAdd.sin_port = htons(PORT);     //设置为统一端口
	memset(serverAdd.sin_zero, 0x00, 8);
	if (bind(sliten, (struct sockaddr*)(&serverAdd), sizeof(serverAdd)) != 0)
	{
		printf("绑定套接字失败！");
		exit(-1);
	}
	if (listen(sliten, 1) != 0)
	{
		printf("套接字监听失败！");
		exit(-1);
	}
	printf("正在匹配玩家中...\n");
	clientAddSize = sizeof(clientAdd);	
	sConnection = accept(sliten, (struct sockaddr*)(&clientAdd), &clientAddSize);
	if (sConnection == INVALID_SOCKET)
	{
		printf("与客户端连接失败！");
		exit(-1);
	}
	printf("已经与另一玩家匹配成功，游戏载入中……\n");
	//++++++++++++++++++++++++++++++++++++++++++++网络完成，连接完成、开始游戏++++++++++++++++++++++++++++++++++++++++++++++++	
    system("PAUSE");
    system("cls"); //清屏
    system("color 9f");//9蓝色背景 f亮白色前景
    Drawingboard();//绘制棋盘
	help2();//棋盘旁边的帮助信息
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++游戏中++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	start = clock();//计时开始
	while (1)
	{
	    gotoxy(1,21);  //光标移到棋盘下方           
		printf("该您走棋了...\n");		
		gotoxy(curX, curY);//光标移到棋盘中心        
		k=getInputKey();//获得输入键
		switch(k)
		{
			//=================================判断输入键，并执行对应操作=============================================
		case UP:{//向上
			        if(curY>1)
					{
					    curY--;//光标向上移
					}
			        else curY = 20 ;
				}
			break;
		case DOWN:{//向下
			        if(curY<20)
					{
					    curY++;//光标向下移
					}
					else curY = 1 ;
				  }
			break;
		case LEFT:{//向左
			        if(curX>1)
					{
					  curX=curX-2;//光标向左移
					}
					else curX = 39 ;
				  }
			break;
		case RIGHT:{//向右
			        if(curX<39)
					{
					  curX=curX+2;//光标向右移
					}
					else curX = 1;
				   }
			break;
		case ENTER://回车
			 if(step[curY-1][(curX+1)/2-1]==0)//如果该位置没有棋子，则可以下棋
			 {
				printf("●");
				step[curY-1][(curX+1)/2-1]=1;//记录棋子位置
				//发送下棋信息
				buff[0]='N';
				buff[1]=curX;
				buff[2]=curY;
				buff[3]='\0';
				send(sConnection,buff,4,0);//否则告诉对方下棋的位置
				//xiazi_music();//调用下子音乐
				recorde_host++;//我下棋步数加1;
//				play_chess(3,1,curX,curY,q);//棋盘的录制
				player=0;
				if((check(curY-1,(curX+1)/2-1))==1)//判断输赢
				{
					finish = clock();//计时结束
					recorde_host=recorde_completor+1;//步数
					show_gl();//当五子连成一线时，打印五个星
					gotoxy(1,21);
					printf("恭喜您赢了！\n");
					//FemaleWin_music();//播放玩家胜利音乐
					show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//					show_chess(3,1,q);//棋盘的播放
					gotoxy(1,24);
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//调用重新开始游戏函数
				}
				if(pingju()==1)//如果是平局
				{
					finish = clock();//计时结束
					recorde_host=recorde_completor+1;//步数
					show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//					show_chess(3,-1,q);//棋盘的播放
					gotoxy(1,21);
					printf("\t平局\n");
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//调用重新开始游戏函数
				}
			 }
				 break;
		case R://认输
			buff[0]='R';
			buff[1]='\0';
			send(sConnection,buff,4,0);//告诉对方我认输
			finish = clock();//计时结束
			recorde_host=recorde_completor;//步数
			gotoxy(1,21);
			printf("您已认输！！！！！\n");
			show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//			show_chess(3,-1,q);//棋盘的播放
			closesocket(sConnection);    
			closesocket(sliten);         
			WSACleanup();
			return rebegin();//调用重新开始游戏函数
			break;
		case C://聊天
			gotoxy(cX,cY);
			printf("我:");
			gotoxy(cX+3,cY++);
			scanf_s("%s",buff);
			send(sConnection,buff,sizeof(buff),0);//发送聊天信息
			player=1;
			break;
		case ESC://退出
			buff[0]='E';
			buff[1]='\0';
			send(sConnection,buff,sizeof(buff),0);//告诉对方我退出
			gotoxy(1,21);
			printf("您已经退出游戏！\n");
			finish = clock();//计时结束
			recorde_host=recorde_completor;//步数
			show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//			show_chess(3,-1,q);//棋盘的播放
			closesocket(sConnection);    
			closesocket(sliten);         
			WSACleanup();
			gotoxy(1,21);
			printf("您已经退出游戏！\n");
			return rebegin();//调用重新开始游戏函数
		}
		//======================================================接收状态======================================================
		while(player==0)
		{
			gotoxy(1,21);        
		    printf("请等待...\n");
			recv(sConnection,buff,100,0);//此时处于接收状态，=0
			switch(buff[0])
			{
			case 'N'://对手下棋的信息
				curX=buff[1];
				curY=buff[2];
				gotoxy(curX,curY);
				printf("○");
				//xiazi_music();//调用下子音乐
				recorde_completor++;
				step[curY-1][(curX+1)/2-1]=-1;//记录对手下棋的位置
//				play_chess(3,0,curX,curY,q);//棋盘的录制
				player=1;//轮到我下棋
				if((check1(curY-1,(curX+1)/2-1))==1)//判断输赢
				{
					finish = clock();//计时结束
					recorde_host=recorde_completor;//步数
					show_gl();//当五子连成一线时，打印五个星
					gotoxy(1,21);
					printf("您输了！\n");
					//ManWin_music();//播放玩家胜利音乐
					show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//					show_chess(3,0,q);//棋盘的播放
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					gotoxy(1,24);
					return rebegin();//调用重新开始游戏函数
				}
				if(pingju()==1)//如果是平局
				{
					finish = clock();//计时结束
					recorde_host=recorde_completor;//步数
					gotoxy(1,21);
					printf("\t平局\n");
					show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//					show_chess(3,-1,q);//棋盘的播放
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//调用重新开始游戏函数
				}
				break;
			case 'E'://对手退出
				finish = clock();//计时结束
				recorde_host=recorde_completor+1;//步数
				gotoxy(1,21);
				printf("对手已逃走！\n");
				show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//				show_chess(3,-1,q);//棋盘的播放
				closesocket(sConnection);    
				closesocket(sliten);         
				WSACleanup();
				system("PAUSE");
				gotoxy(1,24);
				return rebegin();//调用重新开始游戏函数
				break;
			case 'R'://对手认输
				finish = clock();//计时结束
				recorde_host=recorde_completor+1;//步数
				gotoxy(1,21);
				printf("您太厉害了，对手认输了！\n");
				show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//				show_chess(3,-1,q);//棋盘的播放
				closesocket(sConnection);    
				closesocket(sliten);         
				WSACleanup();
				return rebegin();//调用重新开始游戏函数
				break;
			default:
						//输出聊天内容
				gotoxy(cX,cY);
				printf("对手:");
				gotoxy(cX+5,cY++);
				printf("%s",buff);
			
			}
		}
	}
	getchar();
	system("PAUSE");
	//=====================================================下线====================================================
	closesocket(sConnection);    
	closesocket(sliten);         
	WSACleanup();
}//Int_game

void Drawingboard()//打印棋盘
{
	int i;
	for (i=1;i<=20;i++)    
	{
		if(i==1)
		{
			printf("┏┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┓\n");//┏ ┯ ┓ ┠ ┼ ┨┗ ┷ ┛
		} 
		if(2<=i&&i<=19)
		{
			printf("┠┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┨\n");
		}
		if(i==20)
		{
			printf("┗┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┛\n");
		}
	}
}

void help2()  //棋盘右边的帮助信息
{
	gotoxy(43,2);
	printf("¤＊＊＊＊提示┅信息＊＊＊＊¤");
	gotoxy(43,3);
	printf("＃        您是 ●           ＃\n");
	gotoxy(43,4);
	printf("＃    方向键控制光标        ＃\n");
	gotoxy(43,5);
	printf("＃                          ＃\n");
	gotoxy(43,6);
	printf("＃ 回车键确认落子或发送信息 ＃\n");
	gotoxy(43,7);
	printf("＃                          ＃\n");
	gotoxy(43,8);
	printf("＃    ↑                    ＃\n");
	gotoxy(43,9);
	printf("＃  ←  →                  ＃\n");
	gotoxy(43,10);
	printf("＃    ↓        <━┛       ＃\n");
	gotoxy(43,11);
	printf("＃                          ＃\n");
	gotoxy(43,12);
	printf("＃                          ＃\n");
	gotoxy(43,13);
	printf("＃                          ＃\n");
	gotoxy(43,14);
	printf("＃                          ＃\n");
	gotoxy(43,15);
	printf("＃   Shift+R ：认输         ＃\n");
	gotoxy(43,16);
	printf("＃                          ＃\n");
	gotoxy(43,17);
	printf("＃                          ＃\n");
	gotoxy(43,18);
	printf("＃   Esc ：退出             ＃\n");
	gotoxy(43,19);
	printf("＃                          ＃\n");
	gotoxy(43,20);
	printf("¤＊＊＊＊＊＊＊＊＊＊＊＊＊¤\n\n\n");
	gotoxy(39,22);
	
}

void gotoxy(int x, int y)//光标定位
{
	COORD loc;
	loc.X = x - 1;
	loc.Y = y - 1;
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(stdH, loc);
}

int getInputKey()//获得输入键
{
	int key;     
	while (1)
	{
		//接收用户从键盘输入
		key = _getch();
		//判断键入的是哪个键
		switch (key)
		{
		case 13:
			return ENTER;
		case 27:
			return ESC;
		case 72:
			return UP;
		case 80:
			return DOWN;
		case 75:
			return LEFT;
		case 77:
			return RIGHT;
		case 69:
			return E;
		case 82:
			return R;
		case 67:
			return C;
		default:           //如果是一切其它键，则什么都不做，等待下次输入
			continue;
		}
	}
}

int pingju()//平局
{
	int i,j;
	for(i=1;i<21;i++)
	{
		for(j=1;j<21;j++)
		{
		if(step[i][j]==0)return 0;
		}
	}
	return 1;
}

//--------------------------------------------------------------------------------------------------------------
//双人对战
int doub_game()
{
	//初始化
	int i,j;//循环变量
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			step[i][j]=0;
	curX = 21, curY = 10;    //分别表示光标位置的x和y，初始值默认在棋盘中心
	player=1;   //表示黑子可以下棋
	tot=0;//重新置0
	//初始化队列
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//初始化所有记录数据

	system("cls"); //清屏
    system("color 9f");//9蓝色背景 f亮白色前景
	Drawingboard();//绘制棋盘
	help3();//棋盘旁边的帮助信息

	start = clock();//计时开始
	while (1)
	{
	    gotoxy(1,21);  //光标移到棋盘下方
		if(player==1)//等于1，为黑子下棋，否则白子下棋
			printf("该●走棋了...\n");	
		else
			printf("该○走棋了...\n");
		gotoxy(curX, curY);//光标移到棋盘中心        
		k=getInputKey();//获得输入键
		switch(k)
		{
			//=================================判断输入键，并执行对应操作=============================================
		case UP://向上
			 if(curY>1)
				 curY--;//光标向上移
			 else 
				 curY = 20 ;
			 break;	
		case DOWN://向下
			if(curY<20)
				curY++;//光标向下移
			else 
				curY = 1 ;
			break;	
		case LEFT://向左
			if(curX>1)
				curX=curX-2;//光标向左移
			else 
				curX = 39 ;
			break;	
		case RIGHT://向右
			if(curX<39)
				curX=curX+2;//光标向右移
			else 
				curX = 1;
			break;
		case ENTER://回车
			 if(step[curY-1][(curX+1)/2-1]==0)//如果该位置没有棋子，则可以下棋
			 {
				if(player==1)
				{
					printf("●");
					recorde_host++;//我下棋步数加1;
					//xiazi_music();//调用下子音乐
				    step[curY-1][(curX+1)/2-1]=1;//记录棋子位置
//					play_chess(2,1,curX,curY,q);//棋盘的录制
					if(check(curY-1,(curX+1)/2-1)==1)//判断输赢
					{
						finish = clock();//计时结束
						show_gl();//当五子连成一线时，打印五个星
						recorde_host=recorde_completor+1;//步数赋值
						gotoxy(1,21);
						printf("恭喜您●赢了！\n");
						//FemaleWin_music();//播放玩家胜利音乐
						show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
						system("PAUSE");
//						show_chess(2,1,q);//棋盘的播放	
						gotoxy(1,24);
						return rebegin();//调用重新开始游戏函数
					}
					player=0;
				}
				else
				{
					printf("○");
					recorde_completor++;//步数赋值
					//xiazi_music();//调用下子音乐
				    step[curY-1][(curX+1)/2-1]=-1;//记录棋子位置
//					play_chess(1,0,curX,curY,q);//棋盘的录制
					if(check1(curY-1,(curX+1)/2-1)==1)//判断输赢
					{
						finish = clock();//计时结束
						show_gl();//当五子连成一线时，打印五个星
						recorde_host=recorde_completor;//步数赋值
						gotoxy(1,21);
						printf("恭喜您○赢了！\n");
						//ManWin_music();//播放玩家胜利音乐
						show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
						system("PAUSE");
					//-----------------------------------------------------------------------------棋盘的录制与播放--------------
//						show_chess(2,1,q);//棋盘的播放
					//-----------------------------------------------------------------------------棋盘的录制与播放--------------
						gotoxy(1,24);
						return rebegin();//调用重新开始游戏函数
					}
					player=1;
				}
				if(pingju()==1)//如果是平局
				{
					finish = clock();//计时结束
					gotoxy(1,21);
					printf("\t平局\n");
					recorde_host=recorde_completor;//步数赋值
					show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//					//show_chess(2,-1,q);//棋盘的播放
					gotoxy(1,24);
					return rebegin();//调用重新开始游戏函数
				}
			 }
			break;
		case ESC://退出
			finish = clock();//计时结束
			gotoxy(1,21);
			printf("您已退出游戏！\n");
			return rebegin();//调用重新开始游戏函数
		}
	}
	gotoxy(1,21);
}//doub_game

void help3()//双人对战帮助信息
{
	gotoxy(43,2);
	printf("¤＊＊＊＊提示┅信息＊＊＊＊¤");
	gotoxy(43,3);
	printf("＃                          ＃\n");
	gotoxy(43,4);
	printf("＃    方向键控制光标        ＃\n");
	gotoxy(43,5);
	printf("＃                          ＃\n");
	gotoxy(43,6);
	printf("＃ 回车键确认落子           ＃\n");
	gotoxy(43,7);
	printf("＃                          ＃\n");
	gotoxy(43,8);
	printf("＃    ↑                    ＃\n");
	gotoxy(43,9);
	printf("＃  ←  →                  ＃\n");
	gotoxy(43,10);
	printf("＃    ↓        <━┛       ＃\n");
	gotoxy(43,11);
	printf("＃                          ＃\n");
	gotoxy(43,12);
	printf("＃                          ＃\n");
	gotoxy(43,13);
	printf("＃    Esc ：退出            ＃\n");
	gotoxy(43,14);
	printf("＃                          ＃\n");
	gotoxy(43,15);
	printf("＃                          ＃\n");
	gotoxy(43,16);
	printf("¤＊＊＊＊＊＊＊＊＊＊＊＊＊¤\n\n\n");
	gotoxy(39,22);
}
//人机对战
int man_com()
{
	//初始化
	int i,j;//循环变量
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			step[i][j]=0;
	curX = 21, curY = 10;    //分别表示光标位置的x和y，初始值默认在棋盘中心
	player=1;   //表示玩家可以下棋，player==0,表示电脑下子
	tot=0;//重新置0
	//初始化队列
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//初始化所有记录数据
//--------------------------------------------------------------------------------------------
	system("cls"); //清屏
    system("color 9f");//9蓝色背景 f亮白色前景
	Drawingboard();//绘制棋盘
	help3();//棋盘旁边的帮助信息
	start = clock();//计时开始
	while (1)
	{
		while(player==1)//等于1，为玩家下棋，否则电脑下棋
		{
			gotoxy(1,21);  //光标移到棋盘下方
			printf("该您走棋了...\n");
			gotoxy(curX, curY);//光标移到棋盘中心        
			k=getInputKey();//获得输入键
			switch(k)
			{
				//=================================判断输入键，并执行对应操作=============================================
			case UP://向上
				if(curY>1)
					curY--;//光标向上移
				else 
					curY = 20 ;
				break;	
			case DOWN://向下
				if(curY<20)
					curY++;//光标向下移
				else 
					curY = 1 ;
				break;	
			case LEFT://向左
				if(curX>1)
					curX=curX-2;//光标向左移
				else 
					curX = 39 ;
				break;	
			case RIGHT://向右
				if(curX<39)
					curX=curX+2;//光标向右移
				else 
					curX = 1;
				break;
			case ENTER://回车
				if(step[curY-1][((curX+1)/2)-1]==0)//如果该位置没有棋子，则可以下棋
				{
					printf("●");
					//xiazi_music();//调用下子音乐
					recorde_host++;//我下棋步数加1;
//					play_chess(1,1,curX,curY,q);//棋盘的录制
				    step[curY-1][((curX+1)/2)-1]=1;//记录棋子位置
					if((check(curY-1,((curX+1)/2)-1))==1)//判断输赢
					{
						finish = clock();//计时结束
						recorde_host=recorde_completor+1;//步数赋值
						show_gl();//当五子连成一线时，打印五个星
						gotoxy(1,21);
						if(player==1)
						{
							printf("恭喜您赢了！\n");
							//FemaleWin_music();//播放玩家胜利音乐
						}
						show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
						system("PAUSE");
						//-----------------------------------------------------------------------------棋盘的录制与播放--------------
//						show_chess(1,1,q);//棋盘的播放
						//-----------------------------------------------------------------------------棋盘的录制与播放--------------
						gotoxy(1,24);
						return rebegin();//调用重新开始游戏函数
					}
					if(pingju()==1)//如果是平局
					{
						finish = clock();//计时结束
						gotoxy(1,21);
						printf("\t平局\n");
						show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
//						show_chess(1,-1,q);//棋盘的播放
						gotoxy(1,24);
						return rebegin();//调用重新开始游戏函数
					}
					player=0;	
				}
				break;
			case ESC://退出
				finish = clock();//计时结束
				show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
				gotoxy(1,21);
				return rebegin();//调用重新开始游戏函数
			}//switch
		}//玩家下棋
		while(player==0)
		{
			regongzinen(&curX,&curY);//调用函数，确定电脑下棋位置
			gotoxy(curX,curY);//光标跳到下棋位置
			printf("○");
			recorde_completor++;//电脑下棋步数加1
			//xiazi_music();//调用下子音乐
//			play_chess(1,0,curX,curY,q);//棋盘的录制
			step[curY-1][((curX+1)/2)-1]=-1;//记录棋子位置
			if((check1(curY-1,((curX+1)/2)-1))==1)//判断输赢
			{
				show_gl();//当五子连成一线时，打印五个星
				finish = clock();//计时结束
				recorde_host=recorde_completor;//步数赋值
				gotoxy(1,21);
				printf("您输了！继续加油\n");
				//ManWin_music();//对手胜利音乐
				show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
				system("PAUSE");
				//-----------------------------------------------------------------------------棋盘的录制与播放--------------
//				show_chess(1,0,q);//棋盘的播放
				//-----------------------------------------------------------------------------棋盘的录制与播放--------------
				gotoxy(1,24);
				return rebegin();//调用重新开始游戏函数
			}
			if(pingju()==1)//如果是平局
			{
				finish = clock();//计时结束
				gotoxy(1,21);
				printf("\t平局\n");
				show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
				system("PAUSE");
				//-----------------------------------------------------------------------------棋盘的录制与播放--------------
//				show_chess(1,-1,q);//棋盘的播放
				//-----------------------------------------------------------------------------棋盘的录制与播放--------------
				gotoxy(1,24);
				return rebegin();//调用重新开始游戏函数
			}
			player=1;
		}//电脑下棋

	}//while
}

void regongzinen(int *a,int *b) /* 电脑下子 *a *b返回下子坐标 */
{
	int i,j,k,MAX=0,I,J; /* I J为下点坐标 */
	for(j=0;j<20;j++)
		for(i=0;i<20;i++)
			if(step[j][i]==EMPTY)
			{ /* 历遍棋盘，遇到空点则计算价值，取最大价值点下子。 */
				k=value_s(i,j);
				if(k>=MAX) 
				{ 
					I=i; J=j; MAX=k; 
				}
			}
	*a=((I+1)*2)-1; *b=J+1;//转化成屏幕坐标
}



int value_s(int p,int q) /* 计算空点p q的价值 以k返回 */ 
{
	int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp; 
	int type[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0};
	/* 数组type中储存己方和对方共32种棋型的值 己方0对方1 活0冲1空活2空冲3 子数0-3（0表示1个子，3表示4个子） */
	while(n!=5)
	{
		k1=Qixing_s(n,p,q); n+=4; /* k1,k2为2个反方向的棋型编号 */
		k2=Qixing_s(n,p,q); n-=3;
		if(k1>k2) 
		{ 
			temp=k1; k1=k2; k2=temp; 
		} /* 使编号小的为k1,大的为k2 */
		K1=k1; K2=k2; /* K1 K2储存k1 k2的编号 */
		Z1=k1%10; Z2=k2%10; k1/=10; k2/=10; Y1=k1%10; Y2=k2%10; k1/=10; k2/=10; X1=k1%10; X2=k2%10;
		/* X Y Z分别表示 己方0对方1 活0冲1空活2空冲3 子数0-3（0表示1个子，3表示4个子） */
		if(K1==-1) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]+5; continue; }; /* 空棋型and其他 */
		if(K1==-2) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]/2; continue; }; /* 边界冲棋型and其他 */ 
		if(K1==-3) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]/3; continue; }; /* 边界空冲棋型and其他 */ 
		if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{
/* 己活己活 己活己冲 对活对活 对活对冲 的棋型赋值*/
			if(Z1+Z2>=2) { k+=type[X2][Y2][3]; continue; }
			else { k+=type[X2][Y2][Z1+Z2+1]; continue; }
		}
		if(((K1>9&&K1<14)&&(K2>9&&K2<14))||((K1>109&&K1<114)&&(K2>109&&K2<114)))
		{
/* 己冲己冲 对冲对冲 的棋型赋值*/
			if(Z1+Z2>=2) { k+=10000; continue; }
			else { k+=0; continue; }
		}
		if(((K1>-1&&K1<4)&&((K2>99&&K2<104)||(K2>109&&K2<114)))||((K1>9&&K1<14)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{
/* 己活对活 己活对冲 己冲对活 己冲对冲 的棋型赋值*/
			if(Z1==3||Z2==3) { k+=10000; continue; }
			else { k+=type[X2][Y2][Z2]+type[X1][Y1][Z1]/4; continue; } 
		}
		else { k+=type[X1][Y1][Z1]+type[X2][Y2][Z2]; continue; } /* 其他棋型的赋值 */
	}//while
	return k;
}


int Qixing_s(int n,int p,int q) /* 返回空点p q在n方向上的棋型号 n为1-8方向 从右顺时针开始数 */ 
{
	int k,m=0; /* 棋型号注解: 己活000-003 己冲010-013 对活100-103 对冲110-113 己空活020-023 己空冲030-033 对空活120-123 对空冲130-133 空-1 边界冲-2 边界空冲-3*/
	Yi_wei(n,&p,&q);
	if(p<0||p>14||q<0||q>14) k=-2; /* 边界冲棋型 */
	switch(step[q][p])
	{
	case COMPUTER:
		{
			m++; Yi_wei(n,&p,&q);
			if(p<0||p>14||q<0||q>14) { k=m+9; return k; }
			while(step[q][p]==COMPUTER) 
			{ 
				m++; 
				Yi_wei(n,&p,&q);
				if(p<0||p>14||q<0||q>14)
				{ 
					k=m+9; 
					return k; 
				} 
			}
			if(step[q][p]==EMPTY) k=m-1; /* 己方活棋型 */
			else k=m+9; /* 己方冲棋型 */
		}break;
	case PLAYER:
		{
			m++; Yi_wei(n,&p,&q);
			if(p<0||p>14||q<0||q>14) { k=m+109; return k; }
			while(step[q][p]==PLAYER) 
			{ 
				m++; 
				Yi_wei(n,&p,&q); 
				if(p<0||p>14||q<0||q>14) 
				{ 
					k=m+109; 
					return k; 
				} 
			}
			if(step[q][p]==EMPTY) k=m+99; /* 对方活棋型 */
			else k=m+109; /* 对方冲棋型 */
		}break;
	case EMPTY:
		{
			Yi_wei(n,&p,&q);
			if(p<0||p>14||q<0||q>14) { k=-3; return k; } /* 边界空冲棋型 */
			switch(step[q][p])
			{
			case COMPUTER:
				{
					m++; Yi_wei(n,&p,&q);
					if(p<0||p>14||q<0||q>14)
					{
						k=m+29; return k; 
					}
					while(step[q][p]==COMPUTER) 
					{ 
						m++; Yi_wei(n,&p,&q); 
						if(p<0||p>14||q<0||q>14) 
						{ k=m+29; return k; } 
					}

					if(step[q][p]==EMPTY) k=m+19; /* 己方空活棋型 */
					else k=m+29; /* 己方空冲棋型 */
				}break;
			case PLAYER:
				{
					m++; Yi_wei(n,&p,&q);
					if(p<0||p>14||q<0||q>14) { k=m+129; return k; }
					while(step[q][p]==PLAYER)
					{ 
						m++; Yi_wei(n,&p,&q); 
						if(p<0||p>14||q<0||q>14) 
						{ 
							k=m+129; return k; 
						} 
					} 
					if(step[q][p]==EMPTY) k=m+119; /* 对方空活棋型 */
					else k=m+129; /* 对方空冲棋型 */ 
				}break;
			case EMPTY: 
				k=-1; break; /* 空棋型 */
			}
		}break;//case spa
	}//swith1
	return k;
}

void Yi_wei(int n,int *x,int *y) /* 在n方向上对坐标 x y 移位 n为1-8方向 从右顺时针开始数 */
{
	switch(n)
	{
	case 1: 
		*x+=1; 
		break;
	case 2: 
		*x+=1; *y+=1; 
		break;
	case 3: 
		*y+=1; 
		break;
	case 4: 
		*x-=1; *y+=1; 
		break;
	case 5: 
		*x-=1; 
		break;
	case 6: 
		*x-=1; *y-=1; 
		break;
	case 7: 
		*y-=1; 
		break;
	case 8: 
		*x+=1; *y-=1;
		break;
	}
}

int check(int x,int y)//一落子，传入坐标
{	//判断是否有五连子
	int i,j,zi=-1,I;
	zi=-1;gaolianInit();I=0;//竖向
	for(i=x,j=y;i>=0&&step[i][j]==1;i--)
	{
		zi++;//向上
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&step[i][j]==1;i++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//横向
	for(i=x,j=y;j>=0&&step[i][j]==1;j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;j<21&&step[i][j]==1;j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//'\'斜向
	for(i=x,j=y;i>=0&&j>=0&&step[i][j]==1;i--,j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&j<21&&step[i][j]==1;i++,j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//'/'斜向
	for(i=x,j=y;i>=0&&j<21&&step[i][j]==1;i--,j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&j>=0&&step[i][j]==1;i++,j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	gaolianInit();
	return 0;
}

int check1(int x,int y)//一落子，传入坐标
{	//判断是否有五连子
	int i,j,zi=-1,I;
	zi=-1;gaolianInit();I=0;//竖向
	for(i=x,j=y;i>=0&&step[i][j]==-1;i--)
	{
		zi++;//向上
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&step[i][j]==-1;i++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//横向
	for(i=x,j=y;j>=0&&step[i][j]==-1;j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;j<21&&step[i][j]==-1;j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//'\'斜向
	for(i=x,j=y;i>=0&&j>=0&&step[i][j]==-1;i--,j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&j<21&&step[i][j]==-1;i++,j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	zi=-1;gaolianInit();I=0;//'/'斜向
	for(i=x,j=y;i>=0&&j<21&&step[i][j]==-1;i--,j++)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	for(i=x,j=y;i<21&&j>=0&&step[i][j]==-1;i++,j--)
	{
		zi++;
		gl[I].X=(j+1)*2-1;
		gl[I].Y=i+1;
		I++;
	}
	if(zi>=5)return 1;
	gaolianInit();
	return 0;
}
//判断队列是否已满
bool queueFull(queue *q)
{
	if(q->rear==SIZE)
		return true;
	else
		return false;
}
//判断队列是否已空
bool queueEmpty(queue *q)
{
	if(q->front==SIZE)
		return true;
	else
		return false;
}
//输出队列
void queueOut(queue *q)
{
	if(!queueEmpty(q))
	//if(q->front<=SIZE)

	{
		//cout<<q->x[q->front]<<" "<<q->y[q->front]<<" "<<q->ch[q->front]<<endl;
		gotoxy(q->x[q->front],q->y[q->front]);
		printf("%s",q->ch[q->front]);
		q->front++;
	}
}
//初始化队列指针
inline void queueInit(queue *q)
{
	q->front=q->rear=NULL;
}

//初始化数组
void gaolianInit()
{
	int i;
	for(i=0;i<=4;i++)
	{
		gl[i].X=-1;
		gl[i].Y=-1;
	}
}

void show_gl()//当五子连成一线时，打印五个星
{
	int i;
	for(i=0;i<5;i++)
	{
		if(gl[i].X==-1)
			return;
		gotoxy(gl[i].X,gl[i].Y);//gl[i].x,gl[i].y对应屏幕上的x,y
		printf("☆");
	}
}



//重新开始游戏
int rebegin()
{
	int c;
	printf("是否重新开始游戏？（1（是）/0（否））\n");
	scanf_s("%d",&c);
	return c;
}
//棋盘的录制
void play_chess(int model,int who,int _curX,int _curY,queue *q1)
{
	char *c;
	if(who==1)//黑子
		c="●";
	else//白子
		c="○";
	if(!queueFull(q1))
	{
		q1->x[q1->rear]=_curX;
		q1->y[q1->rear]=_curY;
		strcpy_s(q1->ch[q1->rear],c);
		q1->rear++;
		tot++;
	}
}
//棋盘的播放
void show_chess(int model,int who,queue *q1)
{
	int i;
	printf("是否播放下棋过程？（Y（是）/N（否））\n");
	char ch;
	scanf_s("%s",&ch);
	if(ch=='Y')
	{
		system("cls"); //清屏
		system("color 9f");//9蓝色背景 f亮白色前景
		Drawingboard();//绘制棋盘
		if(model==3)
			help2();
		else
			help3();//棋盘旁边的帮助信息
		gotoxy(1,21);
		printf("播放下棋过程中……\n");
		system("PAUSE");
		for(i=0;i<tot;i++)
		{
			queueOut(q1);
			//xiazi_music();//播放下棋声音
			gotoxy(1,21);
			printf("播放下棋过程中……\n");
			system("PAUSE");
		}
		if(who==-1)
			return;
		show_gl();//当五子连成一线时，打印五个星
		
	}
}

void Initrecorde()//初始化所有记录数据
{
	recorde_host=0;//玩家步数归0
	recorde_completor=0;//对手步数归0
	start=0;//开始时间归0
	finish=0;//结束时间归0
}

void show_recorde()//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
{
	int t=0;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;//算出秒
	t=duration;
	int h,m,s;//小时、分、秒
    h=t/3600;
    m=t%3600/60;
    s=t%3600%60;
	gotoxy(42,27);
	printf("-----------------结果统计-------------");
	gotoxy(50,28);
	printf("我走棋的步数：%d\n",recorde_host);
	gotoxy(50,29);
	printf("对手走棋的步数：%d\n",recorde_completor);
	gotoxy(50,30);
	printf("所用总时间：%d时%d分%d秒\n",h,m,s);
	gotoxy(1,22);
}
void playsound()
{
	printf("\t                                                              \n");
	printf("\t┏┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅┓\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                   选择背景音乐                           ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  1、                                     ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  2、                                     ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  3、                                     ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  4、                                     ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┃                  5、返回上一级菜单                       ┃\n");
	printf("\t┇                                                          ┇\n");
	printf("\t┗┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅━┅┛\n");
	printf("\n");
	int choose = -1;

	scanf_s("%d", &choose);
	switch (choose)
	{
	case 1:
	{
			  PlaySound(TEXT("1.wav"), 0, SND_FILENAME);

			  break;
	}//1
	case 2:
	{
			  PlaySound(TEXT("1.wav"), 0, SND_FILENAME);

			  break;
	}//2
	case 3:
	{
			  PlaySound(TEXT("1.wav"), 0, SND_FILENAME);
			  break;
	}//3
	case 4:
	{
			  PlaySound(TEXT("1.wav"), 0, SND_FILENAME);

			  break;
	}//4
	case 5:
	{


			  break;
	}//5

	}
	cmain();

}
void cmain()
{
	int c = 1;
	int choose = -1;//菜单选择变量
	while (choose != 0)
	{
		if (c != 1)
			system("PAUSE");
		c = 2;
		system("cls"); //清屏
		show_menu();//打印菜单
		printf("请选择（按相应数字键进行选择）：");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1://人机对战
		{
				   choose = man_com();//调用人机对战函数
				   break;
		}//1
		case 2://双人对战
		{
				   choose = doub_game();
				   break;
		}//2
		case 3://网络对战
		{
				   choose = Int_game();//网络对战
				   break;
		}//3
		case 4://播放音乐
		{
				   // help1();//打印菜单帮助信息
				   playsound();
				   break;
		}//4
		case 5://退出游戏
		{
				   printf("退出游戏！\n");
				   choose = 0;
				   break;
		}//5
		}
	}
}