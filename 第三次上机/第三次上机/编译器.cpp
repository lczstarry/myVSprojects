#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<ctype.h>
#include<iostream>
using namespace std;

typedef struct line
{
	char text[81];
	int num;
	struct line *next;
	struct line *prior;
}txtLine;
txtLine *start;
txtLine *last;

txtLine*find(int linenum)
{
	txtLine *info;
	info = start;
	while (info)
	{
		if (linenum == info->num)
			return (info);
		info = info->next;
	}
	return (NULL);
}

void patchup(int n, int incr)
{
	txtLine *i;
	i = find(n);
	while (i)
	{
		i->num = i->num + incr;
		i = i->next;
	}
}

txtLine *insert_Line(txtLine *i)
{
	txtLine *old, *p;
	if (last == NULL)
	{
		i->next = NULL;
		i->prior = NULL;
		last = i;
		return i;
	}
	p = start;
	old = NULL;
	while (p)
	{
		if (p->num < i->num)
		{
			old = p;
			p = p->next;
		}
		else
		{
			if (p->prior)
			{
				p->prior->next = i;
				i->next = p;
				p->prior = i;
				return start;
			}
			i->next = p;
			i->prior = NULL;
			p->prior = i;
			return i;
		}
	}
	old->next = i;
	i->next = NULL;
	i->prior = old;
	last = i;
	return start;
}

int enter(int linenum)
{
	txtLine *info;
	for (;;)
	{
		info = (txtLine *)malloc(sizeof(txtLine));
		if (!info)
		{
			cout << "�ڴ治��!" << endl;
			return NULL;
		}
		cout << linenum << ":";
		gets_s(info->text);
		info->num = linenum;
		if (*info->text)
		{
			if (find(linenum))
				patchup(linenum, 1);
			if (*info->text)
				start = insert_Line(info);
		}
		else
			break;
		linenum++;
	}
	return linenum;
}

void delete_text()
{
	txtLine *info;
	char s[80];
	int linenum;
	cout << "\t" << "�к�:";
	gets_s(s);
	linenum = atoi(s);
	info = find(linenum);
	if (info)
	{
		if (start == info)
		{
			start = info->next;
			if (start)
				start->prior = NULL;
			else
				last = NULL;
		}
		else
		{
			info->prior->next = info->next;
			if (info != last)
				info->next->prior = info->prior;
			else
				last = info->prior;
		}
		free(info);
		patchup(linenum + 1, -1);
	}
}

void list()
{
	txtLine *info;
	info = start;
	while (info)
	{
		cout << info->text << endl;
		info = info->next;
	}
	cout << endl << endl;
}

void wordnum()
{
	line *p;
	char keyword[80];
	cout << "������Ҫͳ�Ƶĵ���:" << endl;
	gets_s(keyword);
	char *key = keyword, *q, *r;
	int len = strlen(key), i = 0;
	p = start;
	do
	{
		q = p->text;
		q--;
		do
		{
			if (q = strstr(++q, key))
			{
				r = q;
				if (!(((*(r - 1) >= 'a' && *(r - 1) <= 'z') || (*(r - 1) >= 'A'&&*(r - 1)<'Z') && ((*(r + len) >= 'a'&&*(r + len) <= 'z') || (*(r + len) >= 'A'&&*(r + len) <= 'Z')))))
					i++;
			}
		} while (q != NULL);
		p = p->next;
	} while (p);
	cout << "Ҫ���ҵĵ������ı��г��ֵĴ���Ϊ:" << i << endl;
}

void wordfind()
{
	txtLine *p;
	char keyword[80];
	cout << "������Ҫ���ҵĵ���:";
	gets_s(keyword);
	char *key = keyword, *q, *r;
	int len = strlen(key), i;
	p = start;
	do
	{
		q = p->text;
		q--;
		do
		{
			i = 1;
			if (q = strstr(++q, key))
			{
				r = q;
				if (!(((*(r - 1) >= 'a' && *(r - 1) <= 'z') || (*(r - 1) >= 'A'&&*(r - 1)<'Z') && ((*(r + len) >= 'a'&&*(r + len) <= 'z') || (*(r + len) >= 'A'&&*(r + len) <= 'Z')))))
				{
					for (r = p->text; r != q; r++)
					if (!(*r >= 'a' && *r <= 'z' || *r >= 'A' && *r <= 'Z'))
						i++;
					cout << "����ҵĵ����ڵ�" << p->num << "�е�" << i << "��" << endl;
					cout << "������һ����������'y'�س���ֹͣ����:" << endl;
					char s;
					fflush(stdin);
					cin >> s;
					switch (s)
					{
					case 'y':
					case 'Y':
						continue;
					default:
						cout << "������ֹͣ!" << endl;
						return;
					}
				}
			}
		} while (q != NULL);
		p = p->next;
	} while (p);
	cout << "�������!" << endl;
}

void save(char *fname)
{
	txtLine *info;
	char *p;
	FILE *fp;
	if ((fp = fopen("text.txt", "w")) == NULL)
	{
		cout << "\t�ļ��򲻿�!" << endl;
		exit(0);
	}
	cout << "\t���ڴ����ļ�:" << endl;
	info = start;
	while (info)
	{
		p = info->text;
		while (*p)
			putc(*p++, fp);
		putc('\n', fp);
		info = info->next;
	}
	fclose(fp);
}

void load(char *fname)
{
	txtLine *info, *temp = NULL;
	char *p;
	FILE *fp;
	int size, inct;
	if ((fp = fopen("text.txt", "r")) == NULL)
	{
		cout << "\t�ļ��򲻿�!" << endl;
		exit(0);
	}
	while (start)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
	cout << endl << "\t���������ļ�!" << endl;
	size = sizeof(txtLine);
	start = (txtLine *)malloc(size);
	if (!start)
	{
		cout << endl << "\t�ڴ��Ѿ�����!";
		return;
	}
	info = start;
	p = info->text;
	inct = 1;
	while ((*p = getc(fp)) != NULL)
	{
		p++;
		while ((*p = getc(fp)) != '\n')
			p++;
		*p = '\0';
		info->num = inct++;
		info->next = (txtLine *)malloc(size);
		if (!info->next)
		{
			cout << endl << "\t�ڴ��Ѿ�����!";
			return;
		}
		info->prior = temp;
		temp = info;
		info = info->next;
		p = info->text;
	}
	temp->next = NULL;
	last = temp;
	free(fp);
	start->prior = NULL;
	fclose(fp);
}

int menu_select()
{
	char s[80];
	int c;
	cout << "\t\t1.�������ַ�" << endl;
	cout << "\t\t2.ɾ������һ��" << endl;
	cout << "\t\t3.��ʾȫ���ַ�" << endl;
	cout << "\t\t4.����ͳ��" << endl;
	cout << "\t\t5.���Ҷ�λ����" << endl;
	cout << "\t\t6.����λ�ò����ַ�" << endl;
	/*cout << "\t\t7.�ļ�����" << endl;
	cout << "\t\t0.�˳�" << endl;*/
	do
	{
		cout << endl << endl << "\t\t�밴����ѡ��:" << endl;
		gets_s(s);
		c = atoi(s);
	} while (c <= 0 || c > 9);
	return c;
}

void main()
{
	char s[80], choice, fname[80];
	int linenum = 1;
	start = NULL;
	last = NULL;
	do
	{
		choice = menu_select();
		switch (choice)
		{
		case 1:
			cout << "\t�к�:" << endl;
			gets_s(s);
			linenum = atoi(s);
			enter(linenum);
			break;
		case 2:
			delete_text();
			list();
			break;
		case 3:
			list();
			break;
		case 4:
			wordnum();
			cout << "�س��������˵�!" << endl;
			getchar();
			break;
		case 5:
			wordfind();
			cout << "�س��������˵�!" << endl;
			getchar();
			break;
		case 6:
			cout << "\t������к�:";
			gets_s(s);
			linenum = atoi(s);
			enter(linenum);
			list();
			break;
		/*case 7:
			cout << "\t�ļ���:" << endl;
			gets_s(fname);
			save(fname);
			break;
		case 0:exit(0);*/
		}
	} while (1);
}
