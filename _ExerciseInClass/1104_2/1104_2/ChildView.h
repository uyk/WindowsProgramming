
// ChildView.h : CChildView Ŭ������ �������̽�
//

#include "stdafx.h"
#pragma once


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	COLORREF m_color;
	CArray<TCHAR, TCHAR>m_str;
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

