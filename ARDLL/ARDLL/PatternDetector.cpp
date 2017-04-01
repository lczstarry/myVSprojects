
#include "PatternDetector.hpp"
#include <cmath>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>

PatternDetector::PatternDetector(cv::Ptr<cv::FeatureDetector> detector,
	cv::Ptr<cv::DescriptorExtractor> extractor,
	cv::Ptr<cv::DescriptorMatcher> matcher,
	bool ratioTest)
	: m_detector(detector)
	, m_extractor(extractor)
	, m_matcher(matcher)
	, enableRatioTest(ratioTest)
	, enableHomographyRefinement(true)
	, homographyReprojectionThreshold(3)
{
}

void PatternDetector::getGray(const cv::Mat& image, cv::Mat& gray)
{
	if (image.channels() == 3)
		cv::cvtColor(image, gray, CV_BGR2GRAY);
	else if (image.channels() == 4)
		cv::cvtColor(image, gray, CV_BGRA2GRAY);
	else if (image.channels() == 1)
		gray = image;
}
bool PatternDetector::extractFeatures(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) const
{
	//assert(!image.empty());
	//assert(image.channels() == 1);

	m_detector->detect(image, keypoints); //��������
	if (keypoints.empty())
		return false;

	m_extractor->compute(image, keypoints, descriptors);// ��Freak���������������� ����ȡ������
	if (keypoints.empty())
		return false;

	return true;
}
void PatternDetector::buildPatternFromImage(const cv::Mat& image, Pattern& pattern) const
{
	int numImages = 4;
	float step = sqrtf(2.0f);//��ƽ����

	// Store original image in pattern structure
	pattern.size = cv::Size(image.cols, image.rows);
	pattern.frame = image.clone();
	getGray(image, pattern.grayImg);

	// Build 2d and 3d contours (3d contour lie in XY plane since it's planar)
	pattern.points2d.resize(4); //�ı�vector��Ԫ�ص���ĿΪ4
	pattern.points3d.resize(4);

	// Image dimensions
	const float w = image.cols;
	const float h = image.rows;

	// Normalized dimensions:
	const float maxSize = std::max(w, h);
	const float unitW = w / maxSize;
	const float unitH = h / maxSize;

	pattern.points2d[0] = cv::Point2f(0, 0);
	pattern.points2d[1] = cv::Point2f(w, 0);
	pattern.points2d[2] = cv::Point2f(w, h);
	pattern.points2d[3] = cv::Point2f(0, h);

	pattern.points3d[0] = cv::Point3f(-unitW, -unitH, 0);
	pattern.points3d[1] = cv::Point3f(unitW, -unitH, 0);
	pattern.points3d[2] = cv::Point3f(unitW, unitH, 0);
	pattern.points3d[3] = cv::Point3f(-unitW, unitH, 0);

	extractFeatures(pattern.grayImg, pattern.keypoints, pattern.descriptors);
}
void PatternDetector::train(const Pattern& pattern)
{

	m_pattern = pattern;
	m_matcher->clear(); //����ɵ�ѵ������
	//������������������  
	//ÿһ�������Ӿ�������һ��ͼ��   
	//��ʹ�����ǿ���ִ�ж�ͼ������
	std::vector<cv::Mat> descriptors(1);
	descriptors[0] = pattern.descriptors.clone();
	m_matcher->add(descriptors);
	//����ѵ������֮��ִ��ʵ��ѵ��
	m_matcher->train();

}
void PatternDetector::getMatches(const cv::Mat& queryDescriptors, std::vector<cv::DMatch>& matches)
{
	matches.clear();

	if (enableRatioTest)
	{
		//����ƥ��
		//����õ�ƥ�������0ʱ��Ϊ�˱������NaN������Ϊ0�������ǽ�ʹ�÷�����
		const float minRatio = 1.f / 1.5f;

		//KNNƥ�����ÿһ����ѯ�����ӷ����������ڽ���ƥ��
		m_matcher->knnMatch(queryDescriptors, m_knnMatches, 2);

		for (size_t i = 0; i<m_knnMatches.size(); i++)
		{
			const cv::DMatch& bestMatch = m_knnMatches[i][0];
			const cv::DMatch& betterMatch = m_knnMatches[i][1];

			float distanceRatio = bestMatch.distance / betterMatch.distance;

			//��ͨ�����ڽ�ƥ������������1.5��ƥ�� 
			if (distanceRatio < minRatio)
			{
				matches.push_back(bestMatch);
			}
		}
	}
	else
	{
		// ����ƥ��
		m_matcher->match(queryDescriptors, matches);
	}
}
bool PatternDetector::refineMatchesWithHomography(const std::vector<cv::KeyPoint>& queryKeypoints, const std::vector<cv::KeyPoint>& trainKeypoints, float reprojectionThreshold, std::vector<cv::DMatch>& matches, cv::Mat& homography)
{
	const int minNumberMatchesAllowed = 8;

	if (matches.size() < minNumberMatchesAllowed)
		return false;

	//Ϊcv::findHomograph׼������
	std::vector<cv::Point2f> srcPoints(matches.size());
	std::vector<cv::Point2f> dstPoints(matches.size());

	for (size_t i = 0; i < matches.size(); i++)
	{
		srcPoints[i] = trainKeypoints[matches[i].trainIdx].pt;//trainIdx  ѵ���������������� ��pt ����
		dstPoints[i] = queryKeypoints[matches[i].queryIdx].pt;
	}

	// �ҵ���Ӧ�Ծ����һ�ȡ��Χ������ ��inliers mask��
	std::vector<unsigned char> inliersMask(srcPoints.size());
	homography = cv::findHomography(srcPoints,
		dstPoints,
		CV_FM_RANSAC,
		reprojectionThreshold,
		inliersMask);

	std::vector<cv::DMatch> inliers;
	for (size_t i = 0; i<inliersMask.size(); i++)
	{
		if (inliersMask[i])
			inliers.push_back(matches[i]);
	}

	matches.swap(inliers);//����
	return matches.size() > minNumberMatchesAllowed;
}
bool PatternDetector::findPattern(const cv::Mat& image, PatternTrackingInfo& info)
{
	//ת������ͼ�񵽻Ҷ�  
	getGray(image, m_grayImg);
	//�ӻҶ�ͼ������ȡ������  
	extractFeatures(m_grayImg, m_queryKeypoints,
		m_queryDescriptors);
	//ʹ�õ�ǰģʽ��ȡƥ��  
	getMatches(m_queryDescriptors, m_matches);
	//Ѱ�ҵ�Ӧ�Ա任�ͼ��õ�ƥ��  
	bool homographyFound = refineMatchesWithHomography(
		m_queryKeypoints,
		m_pattern.keypoints,
		homographyReprojectionThreshold,
		m_matches,
		m_roughHomography);
	if (homographyFound)
	{
		//������õ�Ӧ���ᴿ��������ҵ��ĵ�Ӧ�Ա任  

		if (enableHomographyRefinement)
		{
			//ʹ���ҵ��ĵ�Ӧ��ת��ͼ�� ͸�ӱ任���任����ͼ��
			cv::warpPerspective(m_grayImg, m_warpedImg, m_roughHomography, m_pattern.size, cv::WARP_INVERSE_MAP | cv::INTER_CUBIC);
			// Get refined matches��ȡ�ᴿ��ƥ��  
			std::vector<cv::KeyPoint> warpedKeypoints;
			std::vector<cv::DMatch> refinedMatches;
			//��ת�����ͼ���ϼ������  
			extractFeatures(m_warpedImg, warpedKeypoints, m_queryDescriptors);
			// Match with patternʹ��ģʽ����ƥ��  
			getMatches(m_queryDescriptors, refinedMatches);
			// Estimate new refinement homography�����µ��ᴿ��Ӧ��  
			homographyFound = refineMatchesWithHomography(warpedKeypoints, m_pattern.keypoints, homographyReprojectionThreshold, refinedMatches, m_refinedHomography);
			//�õ�һ�������Ӧ����Ϊ�ᴿ�ʹֲڵ�Ӧ�Ծ���˻��Ľ����  
			info.homography = m_roughHomography * m_refinedHomography;
			// Transform contour with precise homographyʹ�þ�ȷ�ĵ�Ӧ��ת���������㣩 ���info.points2d �����任���2d��
			cv::perspectiveTransform(m_pattern.points2d,
				info.points2d, info.homography);
		}
		else
		{
			info.homography = m_roughHomography;
			//ʹ�ô��Եĵ�Ӧ��ת������  ���info.points2d �����任���2d��
			cv::perspectiveTransform(m_pattern.points2d, info.points2d, m_roughHomography);
		}
	}
	//ƥ�����25 ������
	//if (m_matches.size() >25)
	//{
	//	return true;
	//}
	//else{
	//	return false;
	//}

	
	return homographyFound;
}