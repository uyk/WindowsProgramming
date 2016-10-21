
// 1010_ImageToolView.h : CMy1010_ImageToolView 클래스의 인터페이스
//

#pragma once


class CMy1010_ImageToolView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMy1010_ImageToolView();
	DECLARE_DYNCREATE(CMy1010_ImageToolView)

// 특성입니다.
public:
	CMy1010_ImageToolDoc* GetDocument() const;

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
	virtual ~CMy1010_ImageToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 1010_ImageToolView.cpp의 디버그 버전
inline CMy1010_ImageToolDoc* CMy1010_ImageToolView::GetDocument() const
   { return reinterpret_cast<CMy1010_ImageToolDoc*>(m_pDocument); }
#endif

