
// changeCursorView.h : CchangeCursorView Ŭ������ �������̽�
//

#pragma once


class CchangeCursorView : public CView
{
protected: // serialization������ ��������ϴ�.
	CchangeCursorView();
	DECLARE_DYNCREATE(CchangeCursorView)

// Ư���Դϴ�.
public:
	CchangeCursorDoc* GetDocument() const;

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
	virtual ~CchangeCursorView();
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
	afx_msg void OnLine();
	int Shape;
	afx_msg void OnRec();
	afx_msg void OnEli();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // changeCursorView.cpp�� ����� ����
inline CchangeCursorDoc* CchangeCursorView::GetDocument() const
   { return reinterpret_cast<CchangeCursorDoc*>(m_pDocument); }
#endif

