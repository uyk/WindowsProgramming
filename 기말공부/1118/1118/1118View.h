
// 1118View.h : CMy1118View 클래스의 인터페이스
//

#pragma once


class CMy1118View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1118View();
	DECLARE_DYNCREATE(CMy1118View)

// 특성입니다.
public:
	CMy1118Doc* GetDocument() const;

// 작업입니다.
public:
	CButton m_pushButton1;
	CButton m_pushButton2;
	CButton m_pushButton3;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_checkBox;
	CButton m_groupBox;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy1118View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void onButtonClicked(void);
	void onPush2Clicked(void);
	void onPush3Clicked(void);
};

#ifndef _DEBUG  // 1118View.cpp의 디버그 버전
inline CMy1118Doc* CMy1118View::GetDocument() const
   { return reinterpret_cast<CMy1118Doc*>(m_pDocument); }
#endif

