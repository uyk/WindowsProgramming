
// 1104-2.h : 1104-2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy11042App:
// �� Ŭ������ ������ ���ؼ��� 1104-2.cpp�� �����Ͻʽÿ�.
//

class CMy11042App : public CWinApp
{
public:
	CMy11042App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11042App theApp;
