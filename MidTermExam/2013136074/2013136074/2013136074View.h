
// 2013136074View.h : CMy2013136074View Ŭ������ �������̽�
//

#pragma once


class CMy2013136074View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136074View();
	DECLARE_DYNCREATE(CMy2013136074View)

// Ư���Դϴ�.
public:
	CMy2013136074Doc* GetDocument() const;

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
	virtual ~CMy2013136074View();
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
	int count;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	CPoint SP;
	CPoint EP;
	bool isDraw;
};

#ifndef _DEBUG  // 2013136074View.cpp�� ����� ����
inline CMy2013136074Doc* CMy2013136074View::GetDocument() const
   { return reinterpret_cast<CMy2013136074Doc*>(m_pDocument); }
#endif

