
// 2013136074_3View.h : CMy2013136074_3View Ŭ������ �������̽�
//

#pragma once


class CMy2013136074_3View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy2013136074_3View();
	DECLARE_DYNCREATE(CMy2013136074_3View)

// Ư���Դϴ�.
public:
	CMy2013136074_3Doc* GetDocument() const;

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
	virtual ~CMy2013136074_3View();
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
	int moveCount;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint SP;
	CPoint EP;
	CPoint center;
};

#ifndef _DEBUG  // 2013136074_3View.cpp�� ����� ����
inline CMy2013136074_3Doc* CMy2013136074_3View::GetDocument() const
   { return reinterpret_cast<CMy2013136074_3Doc*>(m_pDocument); }
#endif

