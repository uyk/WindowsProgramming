
// Assignment_2.h : Assignment_2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CAssignment_2App:
// �� Ŭ������ ������ ���ؼ��� Assignment_2.cpp�� �����Ͻʽÿ�.
//
class IppDib;
class CAssignment_2App : public CWinAppEx
{
public :
	IppDib* m_pNewDib;
public:
	CAssignment_2App();


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

extern CAssignment_2App theApp;

//�����Լ�����
void AfxNewBitmap(IppDib& dib);