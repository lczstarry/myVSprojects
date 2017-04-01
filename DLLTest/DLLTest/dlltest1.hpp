if defined(EXPORTBUILD)
#define _DLLExport __declspec(dllexport)
#else
#define _DLLExport __declspec(dllimport);
#endif
#include <opencv2/opencv.hpp>

extern "C" int _DLLExport Mymax(int x, int y);
