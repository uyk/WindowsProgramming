
// 1104View.h : CMy1104View Ŭ������ �������̽�
//

#pragma once


class CMy1104View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1104View();
	DECLARE_DYNCREATE(CMy1104View)

// Ư���Դϴ�.
public:
	CMy1104Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMy1104View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 1104View.cpp�� ����� ����
inline CMy1104Doc* CMy1104View::GetDocument() const
   { return reinterpret_cast<CMy1104Doc*>(m_pDocument); }
#endif

