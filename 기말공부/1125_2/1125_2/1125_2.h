
// 1125_2.h : 1125_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1125_2App:
// �� Ŭ������ ������ ���ؼ��� 1125_2.cpp�� �����Ͻʽÿ�.
//

class CMy1125_2App : public CWinApp
{
public:
	CMy1125_2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1125_2App theApp;
