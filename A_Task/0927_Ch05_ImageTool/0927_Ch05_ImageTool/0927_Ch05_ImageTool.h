
// 0927_Ch05_ImageTool.h : 0927_Ch05_ImageTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy0927_Ch05_ImageToolApp:
// �� Ŭ������ ������ ���ؼ��� 0927_Ch05_ImageTool.cpp�� �����Ͻʽÿ�.
//

class CMy0927_Ch05_ImageToolApp : public CWinApp
{
public:
	CMy0927_Ch05_ImageToolApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0927_Ch05_ImageToolApp theApp;
