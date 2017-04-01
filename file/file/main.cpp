#include <fstream> // c++ ÎÄ¼þIOÍ·
using namespace std;

int main()
{
	int array[2][8] = { { 2, 4, 5, 77, 99, 6, 55, 3 },
	{ 21, 3, 54, 6, 7, 88, 55, 2 }
	};
	ofstream myfile("E:\\1.txt", ios::ate | ios::out); 

	if (myfile)
	{
		for (int i = 0; i<2; ++i)
		{
			for (int j = 0; j<8; ++j)
				myfile << array[i][j] << " ";
			myfile << endl;
		}

	}
	myfile.close();
		
	return 0;
	
}