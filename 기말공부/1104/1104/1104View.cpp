
// 1104View.cpp : CMy1104View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1104.h"
#endif

#include "1104Doc.h"
#include "1104View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1104View

IMPLEMENT_DYNCREATE(CMy1104View, CView)

BEGIN_MESSAGE_MAP(CMy1104View, CView)
END_MESSAGE_MAP()

// CMy1104View ����/�Ҹ�

CMy1104View::CMy1104View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1104View::~CMy1104View()
{
}

BOOL CMy1104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1104View �׸���

void CMy1104View::OnDraw(CDC* /*pDC*/)
{
	CMy1104Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1104View ����

#ifdef _DEBUG
void CMy1104View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1104View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1104Doc* CMy1104View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1104Doc)));
	return (CMy1104Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1104View �޽��� ó����
