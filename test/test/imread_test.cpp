
#pragma comment(lib,"opencv_highgui2410d.lib")
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{

	Mat i = imread("E:\\yuan.jpg"); 
	if (i.empty())
	{
		cout << "qunima" << endl; 
	}

	return 0;
}