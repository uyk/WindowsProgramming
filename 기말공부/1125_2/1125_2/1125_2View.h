
// 1125_2View.h : CMy1125_2View 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMy1125_2View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy1125_2View();
	DECLARE_DYNCREATE(CMy1125_2View)

public:
	enum{ IDD = IDD_MY1125_2_FORM };

// 특성입니다.
public:
	CMy1125_2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMy1125_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CButton m_checkBox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};

#ifndef _DEBUG  // 1125_2View.cpp의 디버그 버전
inline CMy1125_2Doc* CMy1125_2View::GetDocument() const
   { return reinterpret_cast<CMy1125_2Doc*>(m_pDocument); }
#endif

