
// 1111View.cpp : CMy1111View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1111.h"
#endif

#include "1111Doc.h"
#include "1111View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1111View

IMPLEMENT_DYNCREATE(CMy1111View, CView)

BEGIN_MESSAGE_MAP(CMy1111View, CView)
END_MESSAGE_MAP()

// CMy1111View ����/�Ҹ�

CMy1111View::CMy1111View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1111View::~CMy1111View()
{
}

BOOL CMy1111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1111View �׸���

void CMy1111View::OnDraw(CDC* /*pDC*/)
{
	CMy1111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1111View ����

#ifdef _DEBUG
void CMy1111View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1111Doc* CMy1111View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1111Doc)));
	return (CMy1111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1111View �޽��� ó����
