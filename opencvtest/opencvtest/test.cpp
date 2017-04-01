//#include <cv.h>
//#include <highgui.h>
#include <opencv2/opencv.hpp>
//using namespace std;
int main()
{
	/*IplImage * test;
	test = cvLoadImage("E:\\无标题.png");//图片路径
	cvNamedWindow("test_demo", 1);
	cvShowImage("test_demo", test);
	cvWaitKey(0);
	cvDestroyWindow("test_demo");
	cvReleaseImage(&test);*/
	const char* imagename = "E://PyramidPattern.jpg";
	cv::Mat Image = cv::imread(imagename);
	if (Image.empty())
	{
		std::cout << "Input image cannot be read" << std::endl;
		// return 2;
	}
	//cv::imshow("image", Image);
	//cv::waitKey();
	return 0 ;
}