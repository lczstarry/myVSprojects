#ifndef EXAMPLE_MARKERLESS_AR_PATTERN_HPP
#define EXAMPLE_MARKERLESS_AR_PATTERN_HPP
#include <opencv2/opencv.hpp>

/**
* �洢Ŀ��ģʽ��ͼ�����ݺͼ���������
*/
struct Pattern
{
	cv::Size                  size;
	cv::Mat                   frame;
	cv::Mat                   grayImg;

	std::vector<cv::KeyPoint> keypoints;
	cv::Mat                   descriptors;

	std::vector<cv::Point2f>  points2d;
	std::vector<cv::Point3f>  points3d;
};
/**
* �м�ģʽ������Ϣ�ṹ
*/
struct PatternTrackingInfo
{
	cv::Mat                   homography;
	std::vector<cv::Point2f>  points2d;
	//Transformation            pose3d;

	void draw2dContour(cv::Mat& image, cv::Scalar color) const;

	/**
	* Compute pattern pose using PnP algorithm
	*/
	//void computePose(const Pattern& pattern, const CameraCalibration& calibration);
};

#endif