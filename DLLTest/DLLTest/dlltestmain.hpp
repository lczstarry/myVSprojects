#if defined(EXPORTBUILD)
#define _DLLExport __declspec(dllexport)
#else
#define _DLLExport __declspec(dllimport);
#endif
extern "C"int _DLLExport open_openadd(int x, int y);