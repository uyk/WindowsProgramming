
// 0927_Ch05_ImageTool_02View.h : CMy0927_Ch05_ImageTool_02View Ŭ������ �������̽�
//

#pragma once


class CMy0927_Ch05_ImageTool_02View : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CMy0927_Ch05_ImageTool_02View();
	DECLARE_DYNCREATE(CMy0927_Ch05_ImageTool_02View)

// Ư���Դϴ�.
public:
	CMy0927_Ch05_ImageTool_02Doc* GetDocument() const;

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
	virtual ~CMy0927_Ch05_ImageTool_02View();
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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 0927_Ch05_ImageTool_02View.cpp�� ����� ����
inline CMy0927_Ch05_ImageTool_02Doc* CMy0927_Ch05_ImageTool_02View::GetDocument() const
   { return reinterpret_cast<CMy0927_Ch05_ImageTool_02Doc*>(m_pDocument); }
#endif

