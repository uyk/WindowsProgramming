
// 0927_Ch05_ImageToolView.h : CMy0927_Ch05_ImageToolView 클래스의 인터페이스
//

#pragma once


class CMy0927_Ch05_ImageToolView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMy0927_Ch05_ImageToolView();
	DECLARE_DYNCREATE(CMy0927_Ch05_ImageToolView)

// 특성입니다.
public:
	CMy0927_Ch05_ImageToolDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy0927_Ch05_ImageToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawClipboard();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};

#ifndef _DEBUG  // 0927_Ch05_ImageToolView.cpp의 디버그 버전
inline CMy0927_Ch05_ImageToolDoc* CMy0927_Ch05_ImageToolView::GetDocument() const
   { return reinterpret_cast<CMy0927_Ch05_ImageToolDoc*>(m_pDocument); }
#endif

