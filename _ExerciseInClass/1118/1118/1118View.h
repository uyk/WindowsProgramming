
// 1118View.h : CMy1118View Ŭ������ �������̽�
//

#pragma once


class CMy1118View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1118View();
	DECLARE_DYNCREATE(CMy1118View)

// Ư���Դϴ�.
public:
	CMy1118Doc* GetDocument() const;
public:
	CButton m_pushButton;
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;
	CButton m_pushButton2;
	CButton m_pushButton3;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy1118View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void onButtonClicked(void);
	void onPush2Clicked(void);
	void onPush3Clicked(void);
};

#ifndef _DEBUG  // 1118View.cpp�� ����� ����
inline CMy1118Doc* CMy1118View::GetDocument() const
   { return reinterpret_cast<CMy1118Doc*>(m_pDocument); }
#endif

