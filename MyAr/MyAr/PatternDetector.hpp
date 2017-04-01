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
		cv::Ptr<cv::FeatureDetector>     detector = new cv::ORB(1000),  // ����orb�������� 
		cv::Ptr<cv::DescriptorExtractor> extractor = new cv::FREAK(false, false),  // ��Freak���������������� 
		cv::Ptr<cv::DescriptorMatcher>   matcher = new cv::BFMatcher(cv::NORM_HAMMING, true),//����ƥ����
		bool enableRatioTest = false
		);

	/**
	*train������Ϊѵ�������ӽ������������ӿ�ƥ���ٶ�
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
	*������
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
	*������Ӧ��
	*/
	static bool refineMatchesWithHomography(
		const std::vector<cv::KeyPoint>& queryKeypoints,
		const std::vector<cv::KeyPoint>& trainKeypoints,
		float reprojectionThreshold,
		std::vector<cv::DMatch>& matches,
		cv::Mat& homography);
	

private:
	std::vector<cv::KeyPoint> m_queryKeypoints;
	cv::Mat                   m_queryDescriptors;//��ѯ������
	std::vector<cv::DMatch>   m_matches;//ƥ�������������
	std::vector< std::vector<cv::DMatch> > m_knnMatches;//����knn����ƥ�������������

	cv::Mat                   m_grayImg;//����ĻҶ�ͼ��
	cv::Mat                   m_warpedImg;//͸�ӱ任������ͼ��
	cv::Mat                   m_roughHomography;//�ֲڵĵ�Ӧ��
	cv::Mat                   m_refinedHomography;//�ᴿ�ĵ�Ӧ��

	Pattern                          m_pattern;
	cv::Ptr<cv::FeatureDetector>     m_detector;
	cv::Ptr<cv::DescriptorExtractor> m_extractor;
	cv::Ptr<cv::DescriptorMatcher>   m_matcher; 
};


#endif