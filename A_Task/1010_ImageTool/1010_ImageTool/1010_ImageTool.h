
// 1010_ImageTool.h : 1010_ImageTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1010_ImageToolApp:
// �� Ŭ������ ������ ���ؼ��� 1010_ImageTool.cpp�� �����Ͻʽÿ�.
//
class IppDib;
class CMy1010_ImageToolApp : public CWinAppEx
{
public:
	CMy1010_ImageToolApp();
public :
	IppDib* m_pNewDib;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1010_ImageToolApp theApp;
void AfxNewBitmap(IppDib& dib);