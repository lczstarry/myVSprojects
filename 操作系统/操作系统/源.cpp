#include<iostream>
#include<fstream>
using namespace std;
class jinchengkuai
{
public:
	int num;
	int needTime;
	int comeTime;
	int doTime;
	int doneTime;
};
int main()
{
	int i = 0, num, cometime, needtime;
	float zhou = 0;
	float daiquan = 0;
	jinchengkuai kuai[16];
	ifstream file("C:\\Users\\DELL\\Desktop\\test.txt");
	while (!file.eof())
	{
		file >> num >> cometime >> needtime;
		kuai[i].num = num; kuai[i].comeTime = cometime; kuai[i].needTime = needtime;
		i++;
	}
	kuai[0].doTime = 0; kuai[0].doneTime = kuai[0].needTime;
	for (i = 1; i<16; i++)
	{
		kuai[i].doTime = kuai[i - 1].doneTime;
		kuai[i].doneTime = kuai[i].doTime + kuai[i].needTime;
	}
	ofstream fi("C:\\Users\\DELL\\Desktop\\test1.txt");
	for (i = 0; i<16; i++)
	{
		fi << "第" << i << "个进程的开始执行时间是" << kuai[i].doTime << ",结束时间是" << kuai[i].doneTime << ",";
		fi << "周转时间是" << kuai[i].doneTime - kuai[i].comeTime << "," << "带权周转时间是" << (kuai[i].doneTime - kuai[i].comeTime)*1.0 / kuai[i].needTime << endl;
		zhou += kuai[i].doneTime - kuai[i].comeTime;
		daiquan += (kuai[i].doneTime - kuai[i].comeTime)*1.0 / kuai[i].needTime;
	}
	fi << "平均周转时间是" << zhou / 16 << endl;
	fi << "平均带权周转时间是" << daiquan / 16 << endl;
	return 0;

}