
// 1111View.h : CMy1111View Ŭ������ �������̽�
//

#pragma once


class CMy1111View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1111View();
	DECLARE_DYNCREATE(CMy1111View)

// Ư���Դϴ�.
public:
	CMy1111Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMy1111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1111View.cpp�� ����� ����
inline CMy1111Doc* CMy1111View::GetDocument() const
   { return reinterpret_cast<CMy1111Doc*>(m_pDocument); }
#endif

