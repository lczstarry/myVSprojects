#ifndef EXAMPLE_MARKERLESS_AR_PATTERNDETECTOR_HPP
#define EXAMPLE_MARKERLESS_AR_PATTERNDETECTOR_HPP
#include"Pattern.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>
class PatternDetector
{
public:
	/**
	* Initialize a pattern detector with specified feature detector, descriptor extraction and matching algorithm
	*/
	PatternDetector
		(
		cv::Ptr<cv::FeatureDetector>     detector = new cv::ORB(1000),  // 创建orb特征点检测 
		cv::Ptr<cv::DescriptorExtractor> extractor = new cv::FREAK(false, false),  // 用Freak特征来描述特征点 
		cv::Ptr<cv::DescriptorMatcher>   matcher = new cv::BFMatcher(cv::NORM_HAMMING, true),//特征匹配器
		bool enableRatioTest = false
		);

	/**
	*train类用来为训练描述子建立索引树，加快匹配速度
	*/
	void train(const Pattern& pattern);

	/**
	* Initialize Pattern structure from the input image.
	* This function finds the feature points and extract descriptors for them.
	*/
	void buildPatternFromImage(const cv::Mat& image, Pattern& pattern) const;

	/**
	* Tries to find a @pattern object on given @image.
	* The function returns true if succeeded and store the result (pattern 2d location, homography) in @info.
	*/
	bool findPattern(const cv::Mat& image, PatternTrackingInfo& info);
	/**
	*测试用
	*/
	bool PatternDetector::findPatterntest(const cv::Mat& image, PatternTrackingInfo& info);

	bool enableRatioTest;
	bool enableHomographyRefinement;
	float homographyReprojectionThreshold;

protected:

	bool extractFeatures(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) const;

	void getMatches(const cv::Mat& queryDescriptors, std::vector<cv::DMatch>& matches);

	/**
	* Get the gray image from the input image.
	* Function performs necessary color conversion if necessary
	* Supported input images types - 1 channel (no conversion is done), 3 channels (assuming BGR) and 4 channels (assuming BGRA).
	*/
	static void getGray(const cv::Mat& image, cv::Mat& gray);

	/**
	*提炼单应性
	*/
	static bool refineMatchesWithHomography(
		const std::vector<cv::KeyPoint>& queryKeypoints,
		const std::vector<cv::KeyPoint>& trainKeypoints,
		float reprojectionThreshold,
		std::vector<cv::DMatch>& matches,
		cv::Mat& homography);
	

private:
	std::vector<cv::KeyPoint> m_queryKeypoints;
	cv::Mat                   m_queryDescriptors;//查询描述子
	std::vector<cv::DMatch>   m_matches;//匹配的特征描述子
	std::vector< std::vector<cv::DMatch> > m_knnMatches;//保存knn方法匹配的特征描述子

	cv::Mat                   m_grayImg;//输入的灰度图像
	cv::Mat                   m_warpedImg;//透视变换后的输出图像
	cv::Mat                   m_roughHomography;//粗糙的单应性
	cv::Mat                   m_refinedHomography;//提纯的单应性

	Pattern                          m_pattern;
	cv::Ptr<cv::FeatureDetector>     m_detector;
	cv::Ptr<cv::DescriptorExtractor> m_extractor;
	cv::Ptr<cv::DescriptorMatcher>   m_matcher; 
};


#endif