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
		fi << "��" << i << "�����̵Ŀ�ʼִ��ʱ����" << kuai[i].doTime << ",����ʱ����" << kuai[i].doneTime << ",";
		fi << "��תʱ����" << kuai[i].doneTime - kuai[i].comeTime << "," << "��Ȩ��תʱ����" << (kuai[i].doneTime - kuai[i].comeTime)*1.0 / kuai[i].needTime << endl;
		zhou += kuai[i].doneTime - kuai[i].comeTime;
		daiquan += (kuai[i].doneTime - kuai[i].comeTime)*1.0 / kuai[i].needTime;
	}
	fi << "ƽ����תʱ����" << zhou / 16 << endl;
	fi << "ƽ����Ȩ��תʱ����" << daiquan / 16 << endl;
	return 0;

}