
// 1104View.h : CMy1104View 클래스의 인터페이스
//

#pragma once


class CMy1104View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1104View();
	DECLARE_DYNCREATE(CMy1104View)

// 특성입니다.
public:
	CMy1104Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMy1104View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1104View.cpp의 디버그 버전
inline CMy1104Doc* CMy1104View::GetDocument() const
   { return reinterpret_cast<CMy1104Doc*>(m_pDocument); }
#endif

