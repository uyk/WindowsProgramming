
// 1111.h : 1111 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1111App:
// �� Ŭ������ ������ ���ؼ��� 1111.cpp�� �����Ͻʽÿ�.
//

class CMy1111App : public CWinApp
{
public:
	CMy1111App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1111App theApp;
