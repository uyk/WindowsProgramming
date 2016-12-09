
// 1125View.h : CMy1125View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMy1125View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMy1125View();
	DECLARE_DYNCREATE(CMy1125View)

public:
	enum{ IDD = IDD_MY1125_FORM };

// Ư���Դϴ�.
public:
	CMy1125Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMy1125View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};

#ifndef _DEBUG  // 1125View.cpp�� ����� ����
inline CMy1125Doc* CMy1125View::GetDocument() const
   { return reinterpret_cast<CMy1125Doc*>(m_pDocument); }
#endif

