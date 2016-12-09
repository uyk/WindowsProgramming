
// 1125View.cpp : CMy1125View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1125.h"
#endif

#include "1125Doc.h"
#include "1125View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1125View

IMPLEMENT_DYNCREATE(CMy1125View, CView)

BEGIN_MESSAGE_MAP(CMy1125View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1125View ����/�Ҹ�

CMy1125View::CMy1125View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1125View::~CMy1125View()
{
}

BOOL CMy1125View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1125View �׸���

void CMy1125View::OnDraw(CDC* /*pDC*/)
{
	CMy1125Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1125View �μ�

BOOL CMy1125View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1125View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1125View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1125View ����

#ifdef _DEBUG
void CMy1125View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1125View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1125Doc* CMy1125View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1125Doc)));
	return (CMy1125Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1125View �޽��� ó����
