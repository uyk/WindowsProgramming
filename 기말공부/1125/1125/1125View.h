
// 1125View.h : CMy1125View Ŭ������ �������̽�
//

#pragma once


class CMy1125View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1125View();
	DECLARE_DYNCREATE(CMy1125View)

// Ư���Դϴ�.
public:
	CMy1125Doc* GetDocument() const;

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
	virtual ~CMy1125View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1125View.cpp�� ����� ����
inline CMy1125Doc* CMy1125View::GetDocument() const
   { return reinterpret_cast<CMy1125Doc*>(m_pDocument); }
#endif

