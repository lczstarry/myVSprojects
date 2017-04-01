#define EXPORTBUILD
#include "ARPipeline.hpp"
#include"maintest.hpp"
#include <opencv2/opencv.hpp>
#include <fstream> 
using namespace std;

/*void  ARPipeline_ARPipeline()
{
	Mat patternImage = cv::imread("F:\\计算机视觉项目\\Camera Roll\\2.jpg");
	CameraCalibration calibration(1279.2642f, 1286.1035f, 340.7854f, 305.9083f);
	ARPipeline pipeline(patternImage, calibration);
}

bool   ARPipeline_processFrame()
{
	Mat patternImage = cv::imread("F:\\计算机视觉项目\\Camera Roll\\2.jpg");
	Mat VideoCaptureFrame = cv::imread("F:\\unity project\\ARDemo2\\patern.jpg");
	CameraCalibration calibration(1279.2642f, 1286.1035f, 340.7854f, 305.9083f);
	ARPipeline pipeline(patternImage, calibration);
	return pipeline.processFrame(VideoCaptureFrame);
}*/
bool ARPipeline_getPatternLocation()
{
	Mat patternImage = cv::imread("F:\\计算机视觉项目\\Camera Roll\\2.jpg");
	Mat VideoCaptureFrame = cv::imread("F:\\unity project\\ARDemo2\\patern.jpg");
	CameraCalibration calibration(1279.2642f, 1286.1035f, 340.7854f, 305.9083f);
	ARPipeline pipeline(patternImage, calibration);
	bool find = pipeline.processFrame(VideoCaptureFrame);
	Matrix44 m44 = pipeline.getPatternLocation().getMat44();
	
	ofstream myfile("G:\\RT.txt", ios::ate | ios::out);

	if (myfile)
	{
		for (int col = 0; col<4; col++)
		{
			for (int row = 0; row<3; row++)
			{
				
				myfile << m44.mat[col][row] << " ";
			}
			myfile << endl;
			
			
		}
		myfile.close();

	}
	
	return find;

}

