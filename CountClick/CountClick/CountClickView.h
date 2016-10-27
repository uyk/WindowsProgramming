
// CountClickView.h : CCountClickView Ŭ������ �������̽�
//

#pragma once


class CCountClickView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCountClickView();
	DECLARE_DYNCREATE(CCountClickView)

// Ư���Դϴ�.
public:
	CCountClickDoc* GetDocument() const;

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
	virtual ~CCountClickView();
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
	int count;
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // CountClickView.cpp�� ����� ����
inline CCountClickDoc* CCountClickView::GetDocument() const
   { return reinterpret_cast<CCountClickDoc*>(m_pDocument); }
#endif
