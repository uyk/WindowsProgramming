
// 0927_Ch05_ImageToolView.h : CMy0927_Ch05_ImageToolView Ŭ������ �������̽�
//

#pragma once


class CMy0927_Ch05_ImageToolView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy0927_Ch05_ImageToolView();
	DECLARE_DYNCREATE(CMy0927_Ch05_ImageToolView)

// Ư���Դϴ�.
public:
	CMy0927_Ch05_ImageToolDoc* GetDocument() const;

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
	virtual ~CMy0927_Ch05_ImageToolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawClipboard();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};

#ifndef _DEBUG  // 0927_Ch05_ImageToolView.cpp�� ����� ����
inline CMy0927_Ch05_ImageToolDoc* CMy0927_Ch05_ImageToolView::GetDocument() const
   { return reinterpret_cast<CMy0927_Ch05_ImageToolDoc*>(m_pDocument); }
#endif

