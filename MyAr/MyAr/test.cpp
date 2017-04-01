
#include"Pattern.hpp"
#include"PatternDetector.hpp"
#include"DebugHelper.hpp"
#include <opencv2/opencv.hpp>
#include"picMatch.hpp"

int main()
{

	// "E://PyramidPattern.jpg"
	// "E://PyramidPatternTest.bmp"
	//char*patternTe = "F:\\计算机视觉项目\\Camera Roll\\2.jpg";
	//string patternTE = patternTe;
	//char*patternIm = picMatch(patternTe);
	//string patternIM = patternIm;
	//cv::Mat patternImage = cv::imread(patternIM);

	cv::Mat patternImage = cv::imread("F:\\unity project\\ARDemo2\\patern.jpg");
		cv::Mat testImage = cv::imread("F:\\计算机视觉项目\\Camera Roll\\2.jpg");


	if (patternImage.empty())
	{
		std::cout << "Input patternimage cannot be read" << std::endl;
		return -1;
	}


	else  
	{
		
		//cv::Mat testImage = cv::imread(patternTE);
		if (testImage.empty())
		{
			std::cout << "Input testimage cannot be read" << std::endl;
			return -2;
		}
		else 
		{
			bool find = false;
			Pattern pattern;
			Pattern testpattern;
			PatternDetector PD;
			PatternTrackingInfo PI;
			PD.buildPatternFromImage(patternImage, pattern);
			PD.train(pattern);
			find = PD.findPatterntest(testImage, PI);
			if (find)
			{
				std::cout << "find" << std::endl;
			}
			else{
				std::cout << "no_find" << std::endl;
			}


			cv::waitKey();

		}
	}
	

	return 0;
}

