
// ChildView.h : CChildView Ŭ������ �������̽�
//

#include <afxtempl.h>

#pragma once


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
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
	void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

