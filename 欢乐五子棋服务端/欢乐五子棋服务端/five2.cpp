// ������_�γ����_�����.cpp : Defines the entry point for the console application.
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ͷ�ļ�++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>		//��ͷ�ļ������˴󲿷�win32����ϵͳ���API
#include <conio.h>			//����̨����/��ͷ�ļ�����C���Ա�׼ͷ�ļ�
#include <winsock2.h>		
#include<stdio.h>
#include <Mmsystem.h>//��������
#include <time.h>

#pragma comment(lib, "WSOCK32.LIB")
#pragma comment(lib, "winmm.lib")//��������-----------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Ԥ���峣��Ⱥ++++++++++++++++++++++++++++++++++++++++++++++++++
#define ENTER	13    //�س�
#define ESC		27	  //�˳�
#define	UP		72		//��������ƶ�
#define DOWN	80		//��������ƶ�
#define LEFT	75		//��������ƶ�
#define RIGHT	77		//��������ƶ�
#define E       69    //�˳�
#define R       82    //�����
#define C		67   //��C����������
#define PORT 9002    //��ͻ���Э�̣�ʹ��9001�Ŷ˿�
# define EMPTY 0
# define PLAYER 1
# define COMPUTER -1 /* ��λ����Ϊ0 ������µ�λ����Ϊ1 �������µ�λ����Ϊ-1 */
#define SIZE 400
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++ȫ�ֱ���Ⱥ+++++++++++++++++++++++++++++++++++++++++++++++++++++++
int step[21][21]={0};//��Ԫ�ص�ֵΪ1ʱ��ʾ���ӡ���Ԫ�ص�ֵΪ0ʱ��ʾ����,�����ս����
int curX = 21, curY = 10;    //�ֱ��ʾ���λ�õ�x��y����ʼֵĬ������������
int player;   //�������У���0��1��ʾ��ҿɷ�����
int k;//���ڽ��շ��صļ�ֵ
int tot;//��¼���Ӳ���
int rebegin();//���¿�ʼ��Ϸ
int recorde_host=0;//��Ҽ�¼����
int recorde_completor=0;//��ս�߼�¼����
clock_t start, finish;//��ʼ������ʱ��
double duration;//����Ϊ��λ��ʱ
//����
struct queue
{
	int x[SIZE];
	int y[SIZE];
	char ch[SIZE][4];
	int front,rear;
};
struct gaolian
{
	int X;//������
	int Y;//������
}gl[5];//������ӡ�
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++�Զ��庯������Ⱥ++++++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x, int y);//��궨λ
void Drawingboard();//��ӡ����
int check(int x,int y);//�жϺ�����Ӯ
int getInputKey();//�����������ĸ���
int pingju();//ƽ���ж�
void help2();//������Ϣ
void show_menu();//��ʾѡ��˵�
//void help1();//��ʾ�˵�������Ϣ
void help3();//��ʾ˫�˶�ս�İ�����Ϣ
int Int_game();//�����ս
int doub_game();//˫�˶�ս
int man_com();//�˻���ս
void regongzinen(int *a,int *b);//�˹������㷨
int value_s(int a,int b);//����Ȩֵ
int Qixing_s(int n,int a,int b);//��������
void Yi_wei(int n,int *I,int *J);//������λ
int check1(int x,int y);//�жϰ�����Ӯ
//�ж϶����Ƿ�����
bool queueFull(queue *q);
//�ж϶����Ƿ��ѿ�
bool queueEmpty(queue *q);
//�������
void queueOut(queue *q);
//��ʼ������ָ��
inline void queueInit(queue *q);
//model:��ʾ1-�˻���2-���ˡ�3-����ģʽ��who:���˻�������ģʽ�£�who=1����ӣ�who=0����ӣ�_curX,_curY�����̵�����ʾ�ϵ�x,y����
//void play_chess(int model,int who,int _curX,int _curY,queue *q1);
//void show_chess(int model,int who,queue *q1);//���̵Ĳ���
void gaolianInit();//��ʼ���ṹ������gl
void show_gl();//����������һ��ʱ����ӡ�����
//void xiazi_music();//��������
//void ManWin_music();//����ʤ������
//void FemaleWin_music();//���ʤ������
void Initrecorde();//��ʼ�����м�¼����
void show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
void playsound();
void cmain();
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++������++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main(int argc, char* argv[])
{
	cmain();
	return 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++��������Ⱥ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//��ӡ�˵�
void show_menu()
{
	printf("\t                                                              \n");
	printf("\t��������������������������������������������������������������\n");
	printf("\t��                                                          ��\n");
	printf("\t��                   ����������                             ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  1���˻���ս                             ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  2�����˱�����ս                         ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  3������������ս                         ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  4���������ֲ���                         ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  5���˳�����                             ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��������������������������������������������������������������\n");
	printf("\n");
}
//��ӡ�˵�������Ϣ
void help1()
{
	printf("\n\t�裪������������������������������������������������������\n");
	printf("\t��                       ��Ϸ����                       ��\n");
	printf("\t��                                                      ��\n");
	printf("\t��   ��������ƹ�꣬�������λ��    �س���ȷ������     ��\n");
	printf("\t��                                                      ��\n");
	printf("\t��                 ��                                   ��\n");
	printf("\t��               ��  ��                    ��           ��\n");
	printf("\t��                 ��                 <������           ��\n");
	printf("\t��                                                      ��\n");
	printf("\t��     Shift+C ������                                   ��\n");
	printf("\t��                                                      ��\n");
	printf("\t��                            ����   ��   ��     ��     ��\n");
	printf("\t��     Shift+R ������                ��     ��  ��      ��\n");
	printf("\t��                               ������   ��        ��\n");
	printf("\t��                                   ��      �� ��      ��\n");
	printf("\t��     Shift+E ���˳�                ��     ��    ��    ��\n");
	printf("\t��                             ����һ�߾�ʤ��!!!        ��\n");
	printf("\t�裪������������������������������������������������������\n\n\n");
}
//�����ս
int Int_game()
{
	player=1;
	int cX=41,cY=23;//����λ�ö�λ
	tot=0;//������0
	//��ʼ������
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//��ʼ�����м�¼����
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++�������׼������++++++++++++++++++++++++++++++++++++++++++++++++++++++
	char buff[100];    //���ڷ���/�������ݵĻ�����
	WSADATA wsa;
	SOCKET sliten;     //�����׽��֣�ֻ�������Ҫ
	SOCKET sConnection;   //�����׽��֣���������֮���ͨ��˫��
	struct sockaddr_in serverAdd;     //������������˵ĵ�ַ
	struct sockaddr_in clientAdd;     //���������ͻ��˵ĵ�ַ
	int clientAddSize;      //���ڱ���ͻ���ַ��ռ�õ��ֽ���
	//�����ʼ�����ж��Ƿ�ɹ�
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("��ʼ��ʧ�ܣ�");
		exit(-1);      //�������˳�
	}
	sliten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sliten == INVALID_SOCKET)
	{
		printf("�׽��ִ���ʧ�ܣ�");
		exit(-1);
	}
	//׼�������ַ
	serverAdd.sin_family = AF_INET;
	serverAdd.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAdd.sin_port = htons(PORT);     //����Ϊͳһ�˿�
	memset(serverAdd.sin_zero, 0x00, 8);
	if (bind(sliten, (struct sockaddr*)(&serverAdd), sizeof(serverAdd)) != 0)
	{
		printf("���׽���ʧ�ܣ�");
		exit(-1);
	}
	if (listen(sliten, 1) != 0)
	{
		printf("�׽��ּ���ʧ�ܣ�");
		exit(-1);
	}
	printf("����ƥ�������...\n");
	clientAddSize = sizeof(clientAdd);	
	sConnection = accept(sliten, (struct sockaddr*)(&clientAdd), &clientAddSize);
	if (sConnection == INVALID_SOCKET)
	{
		printf("��ͻ�������ʧ�ܣ�");
		exit(-1);
	}
	printf("�Ѿ�����һ���ƥ��ɹ�����Ϸ�����С���\n");
	//++++++++++++++++++++++++++++++++++++++++++++������ɣ�������ɡ���ʼ��Ϸ++++++++++++++++++++++++++++++++++++++++++++++++	
    system("PAUSE");
    system("cls"); //����
    system("color 9f");//9��ɫ���� f����ɫǰ��
    Drawingboard();//��������
	help2();//�����Աߵİ�����Ϣ
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++��Ϸ��++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	start = clock();//��ʱ��ʼ
	while (1)
	{
	    gotoxy(1,21);  //����Ƶ������·�           
		printf("����������...\n");		
		gotoxy(curX, curY);//����Ƶ���������        
		k=getInputKey();//��������
		switch(k)
		{
			//=================================�ж����������ִ�ж�Ӧ����=============================================
		case UP:{//����
			        if(curY>1)
					{
					    curY--;//���������
					}
			        else curY = 20 ;
				}
			break;
		case DOWN:{//����
			        if(curY<20)
					{
					    curY++;//���������
					}
					else curY = 1 ;
				  }
			break;
		case LEFT:{//����
			        if(curX>1)
					{
					  curX=curX-2;//���������
					}
					else curX = 39 ;
				  }
			break;
		case RIGHT:{//����
			        if(curX<39)
					{
					  curX=curX+2;//���������
					}
					else curX = 1;
				   }
			break;
		case ENTER://�س�
			 if(step[curY-1][(curX+1)/2-1]==0)//�����λ��û�����ӣ����������
			 {
				printf("��");
				step[curY-1][(curX+1)/2-1]=1;//��¼����λ��
				//����������Ϣ
				buff[0]='N';
				buff[1]=curX;
				buff[2]=curY;
				buff[3]='\0';
				send(sConnection,buff,4,0);//������߶Է������λ��
				//xiazi_music();//������������
				recorde_host++;//�����岽����1;
//				play_chess(3,1,curX,curY,q);//���̵�¼��
				player=0;
				if((check(curY-1,(curX+1)/2-1))==1)//�ж���Ӯ
				{
					finish = clock();//��ʱ����
					recorde_host=recorde_completor+1;//����
					show_gl();//����������һ��ʱ����ӡ�����
					gotoxy(1,21);
					printf("��ϲ��Ӯ�ˣ�\n");
					//FemaleWin_music();//�������ʤ������
					show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//					show_chess(3,1,q);//���̵Ĳ���
					gotoxy(1,24);
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//�������¿�ʼ��Ϸ����
				}
				if(pingju()==1)//�����ƽ��
				{
					finish = clock();//��ʱ����
					recorde_host=recorde_completor+1;//����
					show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//					show_chess(3,-1,q);//���̵Ĳ���
					gotoxy(1,21);
					printf("\tƽ��\n");
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//�������¿�ʼ��Ϸ����
				}
			 }
				 break;
		case R://����
			buff[0]='R';
			buff[1]='\0';
			send(sConnection,buff,4,0);//���߶Է�������
			finish = clock();//��ʱ����
			recorde_host=recorde_completor;//����
			gotoxy(1,21);
			printf("�������䣡��������\n");
			show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//			show_chess(3,-1,q);//���̵Ĳ���
			closesocket(sConnection);    
			closesocket(sliten);         
			WSACleanup();
			return rebegin();//�������¿�ʼ��Ϸ����
			break;
		case C://����
			gotoxy(cX,cY);
			printf("��:");
			gotoxy(cX+3,cY++);
			scanf_s("%s",buff);
			send(sConnection,buff,sizeof(buff),0);//����������Ϣ
			player=1;
			break;
		case ESC://�˳�
			buff[0]='E';
			buff[1]='\0';
			send(sConnection,buff,sizeof(buff),0);//���߶Է����˳�
			gotoxy(1,21);
			printf("���Ѿ��˳���Ϸ��\n");
			finish = clock();//��ʱ����
			recorde_host=recorde_completor;//����
			show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//			show_chess(3,-1,q);//���̵Ĳ���
			closesocket(sConnection);    
			closesocket(sliten);         
			WSACleanup();
			gotoxy(1,21);
			printf("���Ѿ��˳���Ϸ��\n");
			return rebegin();//�������¿�ʼ��Ϸ����
		}
		//======================================================����״̬======================================================
		while(player==0)
		{
			gotoxy(1,21);        
		    printf("��ȴ�...\n");
			recv(sConnection,buff,100,0);//��ʱ���ڽ���״̬��=0
			switch(buff[0])
			{
			case 'N'://�����������Ϣ
				curX=buff[1];
				curY=buff[2];
				gotoxy(curX,curY);
				printf("��");
				//xiazi_music();//������������
				recorde_completor++;
				step[curY-1][(curX+1)/2-1]=-1;//��¼���������λ��
//				play_chess(3,0,curX,curY,q);//���̵�¼��
				player=1;//�ֵ�������
				if((check1(curY-1,(curX+1)/2-1))==1)//�ж���Ӯ
				{
					finish = clock();//��ʱ����
					recorde_host=recorde_completor;//����
					show_gl();//����������һ��ʱ����ӡ�����
					gotoxy(1,21);
					printf("�����ˣ�\n");
					//ManWin_music();//�������ʤ������
					show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//					show_chess(3,0,q);//���̵Ĳ���
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					gotoxy(1,24);
					return rebegin();//�������¿�ʼ��Ϸ����
				}
				if(pingju()==1)//�����ƽ��
				{
					finish = clock();//��ʱ����
					recorde_host=recorde_completor;//����
					gotoxy(1,21);
					printf("\tƽ��\n");
					show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//					show_chess(3,-1,q);//���̵Ĳ���
					closesocket(sConnection);    
					closesocket(sliten);         
					WSACleanup();
					return rebegin();//�������¿�ʼ��Ϸ����
				}
				break;
			case 'E'://�����˳�
				finish = clock();//��ʱ����
				recorde_host=recorde_completor+1;//����
				gotoxy(1,21);
				printf("���������ߣ�\n");
				show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//				show_chess(3,-1,q);//���̵Ĳ���
				closesocket(sConnection);    
				closesocket(sliten);         
				WSACleanup();
				system("PAUSE");
				gotoxy(1,24);
				return rebegin();//�������¿�ʼ��Ϸ����
				break;
			case 'R'://��������
				finish = clock();//��ʱ����
				recorde_host=recorde_completor+1;//����
				gotoxy(1,21);
				printf("��̫�����ˣ����������ˣ�\n");
				show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//				show_chess(3,-1,q);//���̵Ĳ���
				closesocket(sConnection);    
				closesocket(sliten);         
				WSACleanup();
				return rebegin();//�������¿�ʼ��Ϸ����
				break;
			default:
						//�����������
				gotoxy(cX,cY);
				printf("����:");
				gotoxy(cX+5,cY++);
				printf("%s",buff);
			
			}
		}
	}
	getchar();
	system("PAUSE");
	//=====================================================����====================================================
	closesocket(sConnection);    
	closesocket(sliten);         
	WSACleanup();
}//Int_game

void Drawingboard()//��ӡ����
{
	int i;
	for (i=1;i<=20;i++)    
	{
		if(i==1)
		{
			printf("���өөөөөөөөөөөөөөөөөө�\n");//�� �� �� �� �� �̩� �� ��
		} 
		if(2<=i&&i<=19)
		{
			printf("�ĩ�������������������\n");
		}
		if(i==20)
		{
			printf("���۩۩۩۩۩۩۩۩۩۩۩۩۩۩۩۩۩۩�\n");
		}
	}
}

void help2()  //�����ұߵİ�����Ϣ
{
	gotoxy(43,2);
	printf("�裪��������ʾ����Ϣ����������");
	gotoxy(43,3);
	printf("��        ���� ��           ��\n");
	gotoxy(43,4);
	printf("��    ��������ƹ��        ��\n");
	gotoxy(43,5);
	printf("��                          ��\n");
	gotoxy(43,6);
	printf("�� �س���ȷ�����ӻ�����Ϣ ��\n");
	gotoxy(43,7);
	printf("��                          ��\n");
	gotoxy(43,8);
	printf("��    ��                    ��\n");
	gotoxy(43,9);
	printf("��  ��  ��                  ��\n");
	gotoxy(43,10);
	printf("��    ��        <����       ��\n");
	gotoxy(43,11);
	printf("��                          ��\n");
	gotoxy(43,12);
	printf("��                          ��\n");
	gotoxy(43,13);
	printf("��                          ��\n");
	gotoxy(43,14);
	printf("��                          ��\n");
	gotoxy(43,15);
	printf("��   Shift+R ������         ��\n");
	gotoxy(43,16);
	printf("��                          ��\n");
	gotoxy(43,17);
	printf("��                          ��\n");
	gotoxy(43,18);
	printf("��   Esc ���˳�             ��\n");
	gotoxy(43,19);
	printf("��                          ��\n");
	gotoxy(43,20);
	printf("�裪��������������������������\n\n\n");
	gotoxy(39,22);
	
}

void gotoxy(int x, int y)//��궨λ
{
	COORD loc;
	loc.X = x - 1;
	loc.Y = y - 1;
	HANDLE stdH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(stdH, loc);
}

int getInputKey()//��������
{
	int key;     
	while (1)
	{
		//�����û��Ӽ�������
		key = _getch();
		//�жϼ�������ĸ���
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
		default:           //�����һ������������ʲô���������ȴ��´�����
			continue;
		}
	}
}

int pingju()//ƽ��
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
//˫�˶�ս
int doub_game()
{
	//��ʼ��
	int i,j;//ѭ������
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			step[i][j]=0;
	curX = 21, curY = 10;    //�ֱ��ʾ���λ�õ�x��y����ʼֵĬ������������
	player=1;   //��ʾ���ӿ�������
	tot=0;//������0
	//��ʼ������
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//��ʼ�����м�¼����

	system("cls"); //����
    system("color 9f");//9��ɫ���� f����ɫǰ��
	Drawingboard();//��������
	help3();//�����Աߵİ�����Ϣ

	start = clock();//��ʱ��ʼ
	while (1)
	{
	    gotoxy(1,21);  //����Ƶ������·�
		if(player==1)//����1��Ϊ�������壬�����������
			printf("�á�������...\n");	
		else
			printf("�á�������...\n");
		gotoxy(curX, curY);//����Ƶ���������        
		k=getInputKey();//��������
		switch(k)
		{
			//=================================�ж����������ִ�ж�Ӧ����=============================================
		case UP://����
			 if(curY>1)
				 curY--;//���������
			 else 
				 curY = 20 ;
			 break;	
		case DOWN://����
			if(curY<20)
				curY++;//���������
			else 
				curY = 1 ;
			break;	
		case LEFT://����
			if(curX>1)
				curX=curX-2;//���������
			else 
				curX = 39 ;
			break;	
		case RIGHT://����
			if(curX<39)
				curX=curX+2;//���������
			else 
				curX = 1;
			break;
		case ENTER://�س�
			 if(step[curY-1][(curX+1)/2-1]==0)//�����λ��û�����ӣ����������
			 {
				if(player==1)
				{
					printf("��");
					recorde_host++;//�����岽����1;
					//xiazi_music();//������������
				    step[curY-1][(curX+1)/2-1]=1;//��¼����λ��
//					play_chess(2,1,curX,curY,q);//���̵�¼��
					if(check(curY-1,(curX+1)/2-1)==1)//�ж���Ӯ
					{
						finish = clock();//��ʱ����
						show_gl();//����������һ��ʱ����ӡ�����
						recorde_host=recorde_completor+1;//������ֵ
						gotoxy(1,21);
						printf("��ϲ����Ӯ�ˣ�\n");
						//FemaleWin_music();//�������ʤ������
						show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
						system("PAUSE");
//						show_chess(2,1,q);//���̵Ĳ���	
						gotoxy(1,24);
						return rebegin();//�������¿�ʼ��Ϸ����
					}
					player=0;
				}
				else
				{
					printf("��");
					recorde_completor++;//������ֵ
					//xiazi_music();//������������
				    step[curY-1][(curX+1)/2-1]=-1;//��¼����λ��
//					play_chess(1,0,curX,curY,q);//���̵�¼��
					if(check1(curY-1,(curX+1)/2-1)==1)//�ж���Ӯ
					{
						finish = clock();//��ʱ����
						show_gl();//����������һ��ʱ����ӡ�����
						recorde_host=recorde_completor;//������ֵ
						gotoxy(1,21);
						printf("��ϲ����Ӯ�ˣ�\n");
						//ManWin_music();//�������ʤ������
						show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
						system("PAUSE");
					//-----------------------------------------------------------------------------���̵�¼���벥��--------------
//						show_chess(2,1,q);//���̵Ĳ���
					//-----------------------------------------------------------------------------���̵�¼���벥��--------------
						gotoxy(1,24);
						return rebegin();//�������¿�ʼ��Ϸ����
					}
					player=1;
				}
				if(pingju()==1)//�����ƽ��
				{
					finish = clock();//��ʱ����
					gotoxy(1,21);
					printf("\tƽ��\n");
					recorde_host=recorde_completor;//������ֵ
					show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//					//show_chess(2,-1,q);//���̵Ĳ���
					gotoxy(1,24);
					return rebegin();//�������¿�ʼ��Ϸ����
				}
			 }
			break;
		case ESC://�˳�
			finish = clock();//��ʱ����
			gotoxy(1,21);
			printf("�����˳���Ϸ��\n");
			return rebegin();//�������¿�ʼ��Ϸ����
		}
	}
	gotoxy(1,21);
}//doub_game

void help3()//˫�˶�ս������Ϣ
{
	gotoxy(43,2);
	printf("�裪��������ʾ����Ϣ����������");
	gotoxy(43,3);
	printf("��                          ��\n");
	gotoxy(43,4);
	printf("��    ��������ƹ��        ��\n");
	gotoxy(43,5);
	printf("��                          ��\n");
	gotoxy(43,6);
	printf("�� �س���ȷ������           ��\n");
	gotoxy(43,7);
	printf("��                          ��\n");
	gotoxy(43,8);
	printf("��    ��                    ��\n");
	gotoxy(43,9);
	printf("��  ��  ��                  ��\n");
	gotoxy(43,10);
	printf("��    ��        <����       ��\n");
	gotoxy(43,11);
	printf("��                          ��\n");
	gotoxy(43,12);
	printf("��                          ��\n");
	gotoxy(43,13);
	printf("��    Esc ���˳�            ��\n");
	gotoxy(43,14);
	printf("��                          ��\n");
	gotoxy(43,15);
	printf("��                          ��\n");
	gotoxy(43,16);
	printf("�裪��������������������������\n\n\n");
	gotoxy(39,22);
}
//�˻���ս
int man_com()
{
	//��ʼ��
	int i,j;//ѭ������
	for(i=0;i<21;i++)
		for(j=0;j<21;j++)
			step[i][j]=0;
	curX = 21, curY = 10;    //�ֱ��ʾ���λ�õ�x��y����ʼֵĬ������������
	player=1;   //��ʾ��ҿ������壬player==0,��ʾ��������
	tot=0;//������0
	//��ʼ������
	queue oq,*q;
	q=&oq;
	queueInit(q);
	Initrecorde();//��ʼ�����м�¼����
//--------------------------------------------------------------------------------------------
	system("cls"); //����
    system("color 9f");//9��ɫ���� f����ɫǰ��
	Drawingboard();//��������
	help3();//�����Աߵİ�����Ϣ
	start = clock();//��ʱ��ʼ
	while (1)
	{
		while(player==1)//����1��Ϊ������壬�����������
		{
			gotoxy(1,21);  //����Ƶ������·�
			printf("����������...\n");
			gotoxy(curX, curY);//����Ƶ���������        
			k=getInputKey();//��������
			switch(k)
			{
				//=================================�ж����������ִ�ж�Ӧ����=============================================
			case UP://����
				if(curY>1)
					curY--;//���������
				else 
					curY = 20 ;
				break;	
			case DOWN://����
				if(curY<20)
					curY++;//���������
				else 
					curY = 1 ;
				break;	
			case LEFT://����
				if(curX>1)
					curX=curX-2;//���������
				else 
					curX = 39 ;
				break;	
			case RIGHT://����
				if(curX<39)
					curX=curX+2;//���������
				else 
					curX = 1;
				break;
			case ENTER://�س�
				if(step[curY-1][((curX+1)/2)-1]==0)//�����λ��û�����ӣ����������
				{
					printf("��");
					//xiazi_music();//������������
					recorde_host++;//�����岽����1;
//					play_chess(1,1,curX,curY,q);//���̵�¼��
				    step[curY-1][((curX+1)/2)-1]=1;//��¼����λ��
					if((check(curY-1,((curX+1)/2)-1))==1)//�ж���Ӯ
					{
						finish = clock();//��ʱ����
						recorde_host=recorde_completor+1;//������ֵ
						show_gl();//����������һ��ʱ����ӡ�����
						gotoxy(1,21);
						if(player==1)
						{
							printf("��ϲ��Ӯ�ˣ�\n");
							//FemaleWin_music();//�������ʤ������
						}
						show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
						system("PAUSE");
						//-----------------------------------------------------------------------------���̵�¼���벥��--------------
//						show_chess(1,1,q);//���̵Ĳ���
						//-----------------------------------------------------------------------------���̵�¼���벥��--------------
						gotoxy(1,24);
						return rebegin();//�������¿�ʼ��Ϸ����
					}
					if(pingju()==1)//�����ƽ��
					{
						finish = clock();//��ʱ����
						gotoxy(1,21);
						printf("\tƽ��\n");
						show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
//						show_chess(1,-1,q);//���̵Ĳ���
						gotoxy(1,24);
						return rebegin();//�������¿�ʼ��Ϸ����
					}
					player=0;	
				}
				break;
			case ESC://�˳�
				finish = clock();//��ʱ����
				show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
				gotoxy(1,21);
				return rebegin();//�������¿�ʼ��Ϸ����
			}//switch
		}//�������
		while(player==0)
		{
			regongzinen(&curX,&curY);//���ú�����ȷ����������λ��
			gotoxy(curX,curY);//�����������λ��
			printf("��");
			recorde_completor++;//�������岽����1
			//xiazi_music();//������������
//			play_chess(1,0,curX,curY,q);//���̵�¼��
			step[curY-1][((curX+1)/2)-1]=-1;//��¼����λ��
			if((check1(curY-1,((curX+1)/2)-1))==1)//�ж���Ӯ
			{
				show_gl();//����������һ��ʱ����ӡ�����
				finish = clock();//��ʱ����
				recorde_host=recorde_completor;//������ֵ
				gotoxy(1,21);
				printf("�����ˣ���������\n");
				//ManWin_music();//����ʤ������
				show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
				system("PAUSE");
				//-----------------------------------------------------------------------------���̵�¼���벥��--------------
//				show_chess(1,0,q);//���̵Ĳ���
				//-----------------------------------------------------------------------------���̵�¼���벥��--------------
				gotoxy(1,24);
				return rebegin();//�������¿�ʼ��Ϸ����
			}
			if(pingju()==1)//�����ƽ��
			{
				finish = clock();//��ʱ����
				gotoxy(1,21);
				printf("\tƽ��\n");
				show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
				system("PAUSE");
				//-----------------------------------------------------------------------------���̵�¼���벥��--------------
//				show_chess(1,-1,q);//���̵Ĳ���
				//-----------------------------------------------------------------------------���̵�¼���벥��--------------
				gotoxy(1,24);
				return rebegin();//�������¿�ʼ��Ϸ����
			}
			player=1;
		}//��������

	}//while
}

void regongzinen(int *a,int *b) /* �������� *a *b������������ */
{
	int i,j,k,MAX=0,I,J; /* I JΪ�µ����� */
	for(j=0;j<20;j++)
		for(i=0;i<20;i++)
			if(step[j][i]==EMPTY)
			{ /* �������̣������յ�������ֵ��ȡ����ֵ�����ӡ� */
				k=value_s(i,j);
				if(k>=MAX) 
				{ 
					I=i; J=j; MAX=k; 
				}
			}
	*a=((I+1)*2)-1; *b=J+1;//ת������Ļ����
}



int value_s(int p,int q) /* ����յ�p q�ļ�ֵ ��k���� */ 
{
	int n=1,k=0,k1,k2,K1,K2,X1,Y1,Z1,X2,Y2,Z2,temp; 
	int type[2][4][4]={40,400,3000,10000,6,10,600,10000,20,120,200,0,6,10,500,0,30,300,2500,5000,2,8,300,8000,26,160,0,0,4,20,300,0};
	/* ����type�д��漺���ͶԷ���32�����͵�ֵ ����0�Է�1 ��0��1�ջ�2�ճ�3 ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */
	while(n!=5)
	{
		k1=Qixing_s(n,p,q); n+=4; /* k1,k2Ϊ2������������ͱ�� */
		k2=Qixing_s(n,p,q); n-=3;
		if(k1>k2) 
		{ 
			temp=k1; k1=k2; k2=temp; 
		} /* ʹ���С��Ϊk1,���Ϊk2 */
		K1=k1; K2=k2; /* K1 K2����k1 k2�ı�� */
		Z1=k1%10; Z2=k2%10; k1/=10; k2/=10; Y1=k1%10; Y2=k2%10; k1/=10; k2/=10; X1=k1%10; X2=k2%10;
		/* X Y Z�ֱ��ʾ ����0�Է�1 ��0��1�ջ�2�ճ�3 ����0-3��0��ʾ1���ӣ�3��ʾ4���ӣ� */
		if(K1==-1) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]+5; continue; }; /* ������and���� */
		if(K1==-2) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]/2; continue; }; /* �߽������and���� */ 
		if(K1==-3) { if(K2<0) { k+=0; continue; } else k+=type[X2][Y2][Z2]/3; continue; }; /* �߽�ճ�����and���� */ 
		if(((K1>-1&&K1<4)&&((K2>-1&&K2<4)||(K2>9&&K2<14)))||((K1>99&&K1<104)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{
/* ����� ����� �Ի�Ի� �Ի�Գ� �����͸�ֵ*/
			if(Z1+Z2>=2) { k+=type[X2][Y2][3]; continue; }
			else { k+=type[X2][Y2][Z1+Z2+1]; continue; }
		}
		if(((K1>9&&K1<14)&&(K2>9&&K2<14))||((K1>109&&K1<114)&&(K2>109&&K2<114)))
		{
/* ���强�� �Գ�Գ� �����͸�ֵ*/
			if(Z1+Z2>=2) { k+=10000; continue; }
			else { k+=0; continue; }
		}
		if(((K1>-1&&K1<4)&&((K2>99&&K2<104)||(K2>109&&K2<114)))||((K1>9&&K1<14)&&((K2>99&&K2<104)||(K2>109&&K2<114))))
		{
/* ����Ի� ����Գ� ����Ի� ����Գ� �����͸�ֵ*/
			if(Z1==3||Z2==3) { k+=10000; continue; }
			else { k+=type[X2][Y2][Z2]+type[X1][Y1][Z1]/4; continue; } 
		}
		else { k+=type[X1][Y1][Z1]+type[X2][Y2][Z2]; continue; } /* �������͵ĸ�ֵ */
	}//while
	return k;
}


int Qixing_s(int n,int p,int q) /* ���ؿյ�p q��n�����ϵ����ͺ� nΪ1-8���� ����˳ʱ�뿪ʼ�� */ 
{
	int k,m=0; /* ���ͺ�ע��: ����000-003 ����010-013 �Ի�100-103 �Գ�110-113 ���ջ�020-023 ���ճ�030-033 �Կջ�120-123 �Կճ�130-133 ��-1 �߽��-2 �߽�ճ�-3*/
	Yi_wei(n,&p,&q);
	if(p<0||p>14||q<0||q>14) k=-2; /* �߽������ */
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
			if(step[q][p]==EMPTY) k=m-1; /* ���������� */
			else k=m+9; /* ���������� */
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
			if(step[q][p]==EMPTY) k=m+99; /* �Է������� */
			else k=m+109; /* �Է������� */
		}break;
	case EMPTY:
		{
			Yi_wei(n,&p,&q);
			if(p<0||p>14||q<0||q>14) { k=-3; return k; } /* �߽�ճ����� */
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

					if(step[q][p]==EMPTY) k=m+19; /* �����ջ����� */
					else k=m+29; /* �����ճ����� */
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
					if(step[q][p]==EMPTY) k=m+119; /* �Է��ջ����� */
					else k=m+129; /* �Է��ճ����� */ 
				}break;
			case EMPTY: 
				k=-1; break; /* ������ */
			}
		}break;//case spa
	}//swith1
	return k;
}

void Yi_wei(int n,int *x,int *y) /* ��n�����϶����� x y ��λ nΪ1-8���� ����˳ʱ�뿪ʼ�� */
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

int check(int x,int y)//һ���ӣ���������
{	//�ж��Ƿ���������
	int i,j,zi=-1,I;
	zi=-1;gaolianInit();I=0;//����
	for(i=x,j=y;i>=0&&step[i][j]==1;i--)
	{
		zi++;//����
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
	zi=-1;gaolianInit();I=0;//����
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
	zi=-1;gaolianInit();I=0;//'\'б��
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
	zi=-1;gaolianInit();I=0;//'/'б��
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

int check1(int x,int y)//һ���ӣ���������
{	//�ж��Ƿ���������
	int i,j,zi=-1,I;
	zi=-1;gaolianInit();I=0;//����
	for(i=x,j=y;i>=0&&step[i][j]==-1;i--)
	{
		zi++;//����
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
	zi=-1;gaolianInit();I=0;//����
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
	zi=-1;gaolianInit();I=0;//'\'б��
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
	zi=-1;gaolianInit();I=0;//'/'б��
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
//�ж϶����Ƿ�����
bool queueFull(queue *q)
{
	if(q->rear==SIZE)
		return true;
	else
		return false;
}
//�ж϶����Ƿ��ѿ�
bool queueEmpty(queue *q)
{
	if(q->front==SIZE)
		return true;
	else
		return false;
}
//�������
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
//��ʼ������ָ��
inline void queueInit(queue *q)
{
	q->front=q->rear=NULL;
}

//��ʼ������
void gaolianInit()
{
	int i;
	for(i=0;i<=4;i++)
	{
		gl[i].X=-1;
		gl[i].Y=-1;
	}
}

void show_gl()//����������һ��ʱ����ӡ�����
{
	int i;
	for(i=0;i<5;i++)
	{
		if(gl[i].X==-1)
			return;
		gotoxy(gl[i].X,gl[i].Y);//gl[i].x,gl[i].y��Ӧ��Ļ�ϵ�x,y
		printf("��");
	}
}



//���¿�ʼ��Ϸ
int rebegin()
{
	int c;
	printf("�Ƿ����¿�ʼ��Ϸ����1���ǣ�/0���񣩣�\n");
	scanf_s("%d",&c);
	return c;
}
//���̵�¼��
void play_chess(int model,int who,int _curX,int _curY,queue *q1)
{
	char *c;
	if(who==1)//����
		c="��";
	else//����
		c="��";
	if(!queueFull(q1))
	{
		q1->x[q1->rear]=_curX;
		q1->y[q1->rear]=_curY;
		strcpy_s(q1->ch[q1->rear],c);
		q1->rear++;
		tot++;
	}
}
//���̵Ĳ���
void show_chess(int model,int who,queue *q1)
{
	int i;
	printf("�Ƿ񲥷�������̣���Y���ǣ�/N���񣩣�\n");
	char ch;
	scanf_s("%s",&ch);
	if(ch=='Y')
	{
		system("cls"); //����
		system("color 9f");//9��ɫ���� f����ɫǰ��
		Drawingboard();//��������
		if(model==3)
			help2();
		else
			help3();//�����Աߵİ�����Ϣ
		gotoxy(1,21);
		printf("������������С���\n");
		system("PAUSE");
		for(i=0;i<tot;i++)
		{
			queueOut(q1);
			//xiazi_music();//������������
			gotoxy(1,21);
			printf("������������С���\n");
			system("PAUSE");
		}
		if(who==-1)
			return;
		show_gl();//����������һ��ʱ����ӡ�����
		
	}
}

void Initrecorde()//��ʼ�����м�¼����
{
	recorde_host=0;//��Ҳ�����0
	recorde_completor=0;//���ֲ�����0
	start=0;//��ʼʱ���0
	finish=0;//����ʱ���0
}

void show_recorde()//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
{
	int t=0;
	duration = (double)(finish - start) / CLOCKS_PER_SEC;//�����
	t=duration;
	int h,m,s;//Сʱ���֡���
    h=t/3600;
    m=t%3600/60;
    s=t%3600%60;
	gotoxy(42,27);
	printf("-----------------���ͳ��-------------");
	gotoxy(50,28);
	printf("������Ĳ�����%d\n",recorde_host);
	gotoxy(50,29);
	printf("��������Ĳ�����%d\n",recorde_completor);
	gotoxy(50,30);
	printf("������ʱ�䣺%dʱ%d��%d��\n",h,m,s);
	gotoxy(1,22);
}
void playsound()
{
	printf("\t                                                              \n");
	printf("\t��������������������������������������������������������������\n");
	printf("\t��                                                          ��\n");
	printf("\t��                   ѡ�񱳾�����                           ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  1��                                     ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  2��                                     ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  3��                                     ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  4��                                     ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��                  5��������һ���˵�                       ��\n");
	printf("\t��                                                          ��\n");
	printf("\t��������������������������������������������������������������\n");
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
	int choose = -1;//�˵�ѡ�����
	while (choose != 0)
	{
		if (c != 1)
			system("PAUSE");
		c = 2;
		system("cls"); //����
		show_menu();//��ӡ�˵�
		printf("��ѡ�񣨰���Ӧ���ּ�����ѡ�񣩣�");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1://�˻���ս
		{
				   choose = man_com();//�����˻���ս����
				   break;
		}//1
		case 2://˫�˶�ս
		{
				   choose = doub_game();
				   break;
		}//2
		case 3://�����ս
		{
				   choose = Int_game();//�����ս
				   break;
		}//3
		case 4://��������
		{
				   // help1();//��ӡ�˵�������Ϣ
				   playsound();
				   break;
		}//4
		case 5://�˳���Ϸ
		{
				   printf("�˳���Ϸ��\n");
				   choose = 0;
				   break;
		}//5
		}
	}
}