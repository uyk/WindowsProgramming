
// ChildView.h : CChildView 클래스의 인터페이스
//

#include <afxtempl.h>

#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CArray<TCHAR, TCHAR>m_str;
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

