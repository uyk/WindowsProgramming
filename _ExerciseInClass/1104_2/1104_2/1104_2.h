
// 1104_2.h : 1104_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1104_2App:
// �� Ŭ������ ������ ���ؼ��� 1104_2.cpp�� �����Ͻʽÿ�.
//

class CMy1104_2App : public CWinApp
{
public:
	CMy1104_2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1104_2App theApp;
