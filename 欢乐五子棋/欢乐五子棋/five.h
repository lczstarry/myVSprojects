// ������_�γ����_�ͻ���.cpp : Defines the entry point for the console application.
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
#pragma comment(lib, "winmm.lib")//��������
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
#define SERVER_IP "127.0.0.1"//�ڱ������з��񡢿ͻ���ʱ���ͻ��˵ĵ�ַ
# define EMPTY 0
# define PLAYER 1
# define COMPUTER -1 /* ��λ����Ϊ0 ������µ�λ����Ϊ1 �������µ�λ����Ϊ-1 */
#define SIZE 400



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++�Զ��庯������Ⱥ++++++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x, int y);//��궨λ
void Drawingboard();//��ӡ����
int check(int x, int y);//�жϺ�����Ӯ
int getInputKey();//�����������ĸ���
int pingju();//ƽ���ж�
void help2();//������Ϣ
void show_menu();//��ʾѡ��˵�
//void help1();//��ʾ�˵�������Ϣ
int Int_game();//�����ս
void help3();//��ʾ˫�˶�ս�İ�����Ϣ
int doub_game();//˫�˶�ս
int man_com();//�˻���ս
void regongzinen(int *p, int *q);//�˹������㷨
int value_s(int p, int q);//����Ȩֵ
int Qixing_s(int n, int p, int q);//����
void Yi_wei(int n, int *i, int *j);//��λ
int check1(int x, int y);//�жϰ�����Ӯ
//�ж϶����Ƿ�����
//model:��ʾ1-�˻���2-���ˡ�3-����ģʽ��who:���˻�������ģʽ�£�who=1����ӣ�who=0����ӣ�_curX,_curY�����̵�����ʾ�ϵ�x,y����
//void play_chess(int model, int who, int _curX, int _curY, queue *q1);
//void show_chess(int model, int who, queue *q1);//���̵Ĳ���
void gaolianInit();//��ʼ���ṹ������gl
void show_gl();//����������һ��ʱ����ӡ�����
//void xiazi_music();//��������
//void ManWin_music();//����ʤ������
//void FemaleWin_music();//���ʤ������
int rebegin();//���¿�ʼ��Ϸ
void Initrecorde();//��ʼ�����м�¼����
void show_recorde();//������ʱ��Ϊ��λת����ʱ���֣���ĸ�ʽ����ӡ��¼���
void playsound();//��������
void cmain();