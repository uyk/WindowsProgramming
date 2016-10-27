
// DrawMouseMoveView.h : CDrawMouseMoveView Ŭ������ �������̽�
//

#pragma once


class CDrawMouseMoveView : public CView
{
protected: // serialization������ ��������ϴ�.
	CDrawMouseMoveView();
	DECLARE_DYNCREATE(CDrawMouseMoveView)

// Ư���Դϴ�.
public:
	CDrawMouseMoveDoc* GetDocument() const;

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
	virtual ~CDrawMouseMoveView();
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
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool isDrawMove;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint SP;
	CPoint EP;
	bool isLeft;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawMouseMoveView.cpp�� ����� ����
inline CDrawMouseMoveDoc* CDrawMouseMoveView::GetDocument() const
   { return reinterpret_cast<CDrawMouseMoveDoc*>(m_pDocument); }
#endif

