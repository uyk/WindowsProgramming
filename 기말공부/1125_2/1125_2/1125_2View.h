
// 1125_2View.h : CMy1125_2View Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CMy1125_2View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMy1125_2View();
	DECLARE_DYNCREATE(CMy1125_2View)

public:
	enum{ IDD = IDD_MY1125_2_FORM };

// Ư���Դϴ�.
public:
	CMy1125_2Doc* GetDocument() const;

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
	virtual ~CMy1125_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // 1125_2View.cpp�� ����� ����
inline CMy1125_2Doc* CMy1125_2View::GetDocument() const
   { return reinterpret_cast<CMy1125_2Doc*>(m_pDocument); }
#endif

