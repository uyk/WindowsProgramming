
// 1010_ImageToolView.h : CMy1010_ImageToolView Ŭ������ �������̽�
//

#pragma once


class CMy1010_ImageToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy1010_ImageToolView();
	DECLARE_DYNCREATE(CMy1010_ImageToolView)

// Ư���Դϴ�.
public:
	CMy1010_ImageToolDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy1010_ImageToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnIconEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 1010_ImageToolView.cpp�� ����� ����
inline CMy1010_ImageToolDoc* CMy1010_ImageToolView::GetDocument() const
   { return reinterpret_cast<CMy1010_ImageToolDoc*>(m_pDocument); }
#endif

