
// MyImageTool.h : MyImageTool ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMyImageToolApp:
// �� Ŭ������ ������ ���ؼ��� MyImageTool.cpp�� �����Ͻʽÿ�.
//
class IppDib;
class CMyImageToolApp : public CWinAppEx
{
public:
	CMyImageToolApp();

public:
	IppDib* m_pNewDib;
	CMultiDocTemplate* m_pImageDocTemplate;

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

extern CMyImageToolApp theApp;
void AfxNewBitmap(IppDib& dib);