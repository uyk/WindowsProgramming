
// IppCreateView.h : CIppCreateView Ŭ������ �������̽�
//

#pragma once


class CIppCreateView : public CView
{
protected: // serialization������ ��������ϴ�.
	CIppCreateView();
	DECLARE_DYNCREATE(CIppCreateView)

// Ư���Դϴ�.
public:
	CIppCreateDoc* GetDocument() const;

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
	virtual ~CIppCreateView();
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

#ifndef _DEBUG  // IppCreateView.cpp�� ����� ����
inline CIppCreateDoc* CIppCreateView::GetDocument() const
   { return reinterpret_cast<CIppCreateDoc*>(m_pDocument); }
#endif

