
// 2013136074_02View.h : CMy2013136074_02View Ŭ������ �������̽�
//

#pragma once


class CMy2013136074_02View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136074_02View();
	DECLARE_DYNCREATE(CMy2013136074_02View)

// Ư���Դϴ�.
public:
	CMy2013136074_02Doc* GetDocument() const;

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
	virtual ~CMy2013136074_02View();
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
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	int Shape;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2013136074_02View.cpp�� ����� ����
inline CMy2013136074_02Doc* CMy2013136074_02View::GetDocument() const
   { return reinterpret_cast<CMy2013136074_02Doc*>(m_pDocument); }
#endif
