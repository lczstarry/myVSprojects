#include<iostream>
using namespace std;
int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	char(*q)[32] = new char[N][32];
	char(*p)[32] = new char[M][32];
	for (int i = 0; i<N; i++)
	{
		cin >> q[i];
	}
	for (int i = 0; i<N; i++)
	{
		cin >> p[i];
	}


	return 0;
}



