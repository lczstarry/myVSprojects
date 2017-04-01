// 五子棋_课程设计_客户端.cpp : Defines the entry point for the console application.
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
#pragma comment(lib, "winmm.lib")//播放音乐
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
#define SERVER_IP "127.0.0.1"//在本机运行服务、客户端时，客户端的地址
# define EMPTY 0
# define PLAYER 1
# define COMPUTER -1 /* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为-1 */
#define SIZE 400



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++自定义函数声明群++++++++++++++++++++++++++++++++++++++++++++++++
void gotoxy(int x, int y);//光标定位
void Drawingboard();//打印棋盘
int check(int x, int y);//判断黑子输赢
int getInputKey();//获得输入的是哪个键
int pingju();//平局判定
void help2();//帮助信息
void show_menu();//显示选择菜单
//void help1();//显示菜单帮助信息
int Int_game();//网络对战
void help3();//显示双人对战的帮助信息
int doub_game();//双人对战
int man_com();//人机对战
void regongzinen(int *p, int *q);//人工智能算法
int value_s(int p, int q);//分析权值
int Qixing_s(int n, int p, int q);//棋型
void Yi_wei(int n, int *i, int *j);//移位
int check1(int x, int y);//判断白子输赢
//判断队列是否已满
//model:表示1-人机、2-人人、3-网络模式；who:在人机和人人模式下，who=1表黑子；who=0表白子；_curX,_curY表棋盘电脑显示上的x,y坐标
//void play_chess(int model, int who, int _curX, int _curY, queue *q1);
//void show_chess(int model, int who, queue *q1);//棋盘的播放
void gaolianInit();//初始化结构体数组gl
void show_gl();//当五子连成一线时，打印五个星
//void xiazi_music();//下子音乐
//void ManWin_music();//对手胜利音乐
//void FemaleWin_music();//玩家胜利音乐
int rebegin();//重新开始游戏
void Initrecorde();//初始化所有记录数据
void show_recorde();//将以秒时间为单位转换成时，分，秒的格式并打印记录结果
void playsound();//播放音乐
void cmain();