
// 0927_Ch05View.h : CMy0927_Ch05View Ŭ������ �������̽�
//

#pragma once


class CMy0927_Ch05View : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy0927_Ch05View();
	DECLARE_DYNCREATE(CMy0927_Ch05View)

// Ư���Դϴ�.
public:
	CMy0927_Ch05Doc* GetDocument() const;

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
	virtual ~CMy0927_Ch05View();
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
};

#ifndef _DEBUG  // 0927_Ch05View.cpp�� ����� ����
inline CMy0927_Ch05Doc* CMy0927_Ch05View::GetDocument() const
   { return reinterpret_cast<CMy0927_Ch05Doc*>(m_pDocument); }
#endif

