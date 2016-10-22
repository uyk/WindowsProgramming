
// BitmapShowView.h : CBitmapShowView Ŭ������ �������̽�
//

#pragma once


class CBitmapShowView : public CView
{
protected: // serialization������ ��������ϴ�.
	CBitmapShowView();
	DECLARE_DYNCREATE(CBitmapShowView)

// Ư���Դϴ�.
public:
	CBitmapShowDoc* GetDocument() const;

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
	virtual ~CBitmapShowView();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // BitmapShowView.cpp�� ����� ����
inline CBitmapShowDoc* CBitmapShowView::GetDocument() const
   { return reinterpret_cast<CBitmapShowDoc*>(m_pDocument); }
#endif

