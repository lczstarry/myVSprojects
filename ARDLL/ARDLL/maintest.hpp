#if defined(EXPORTBUILD)
#define _DLLExport __declspec(dllexport)
#else
#define _DLLExport __declspec(dllimport);
#endif
using namespace cv;
#include "ARPipeline.hpp"
#include <opencv2/opencv.hpp>
#include <fstream> 
//extern "C" void  _DLLExport ARPipeline_ARPipeline();
//extern "C" bool  _DLLExport ARPipeline_processFrame();
extern "C" bool _DLLExport  ARPipeline_getPatternLocation();

