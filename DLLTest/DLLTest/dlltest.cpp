#define EXPORTBUILD
#include "dlltest.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;




int read(){
	
	cv::Mat testImage = cv::imread("F:\\unity project\\ARDemo2\\patern.jpg");
	if (testImage.empty())
	{
		return -1;
	}
	else{
		return 1;
	}


}
