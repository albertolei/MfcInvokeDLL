
// MfcInvokeDLL.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMfcInvokeDLLApp: 
// �йش����ʵ�֣������ MfcInvokeDLL.cpp
//

class CMfcInvokeDLLApp : public CWinApp
{
public:
	CMfcInvokeDLLApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMfcInvokeDLLApp theApp;