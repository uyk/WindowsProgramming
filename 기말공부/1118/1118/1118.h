
// 1118.h : 1118 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1118App:
// �� Ŭ������ ������ ���ؼ��� 1118.cpp�� �����Ͻʽÿ�.
//

class CMy1118App : public CWinApp
{
public:
	CMy1118App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1118App theApp;
