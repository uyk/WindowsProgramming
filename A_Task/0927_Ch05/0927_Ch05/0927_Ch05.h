
// 0927_Ch05.h : 0927_Ch05 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy0927_Ch05App:
// �� Ŭ������ ������ ���ؼ��� 0927_Ch05.cpp�� �����Ͻʽÿ�.
//

class CMy0927_Ch05App : public CWinAppEx
{
public:
	CMy0927_Ch05App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0927_Ch05App theApp;
