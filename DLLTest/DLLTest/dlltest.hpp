#if defined(EXPORTBUILD)
#define _DLLExport __declspec(dllexport)
#else
#define _DLLExport __declspec(dllimport);
#endif
#include <opencv2/opencv.hpp>
using namespace cv;

extern "C" int _DLLExport read();

