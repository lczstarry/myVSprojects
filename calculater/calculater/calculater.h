
// calculater.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcalculaterApp: 
// �йش����ʵ�֣������ calculater.cpp
//

class CcalculaterApp : public CWinApp
{
public:
	CcalculaterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcalculaterApp theApp;