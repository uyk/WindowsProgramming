
// 1104_3.h : 1104_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1104_3App:
// �� Ŭ������ ������ ���ؼ��� 1104_3.cpp�� �����Ͻʽÿ�.
//

class CMy1104_3App : public CWinApp
{
public:
	CMy1104_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1104_3App theApp;
