
// 0927_Ch05View.cpp : CMy0927_Ch05View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "0927_Ch05.h"
#endif

#include "0927_Ch05Doc.h"
#include "0927_Ch05View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0927_Ch05View

IMPLEMENT_DYNCREATE(CMy0927_Ch05View, CScrollView)

BEGIN_MESSAGE_MAP(CMy0927_Ch05View, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0927_Ch05View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy0927_Ch05View ����/�Ҹ�

CMy0927_Ch05View::CMy0927_Ch05View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy0927_Ch05View::~CMy0927_Ch05View()
{
}

BOOL CMy0927_Ch05View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMy0927_Ch05View �׸���

void CMy0927_Ch05View::OnDraw(CDC* /*pDC*/)
{
	CMy0927_Ch05Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CMy0927_Ch05View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy0927_Ch05View �μ�


void CMy0927_Ch05View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0927_Ch05View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy0927_Ch05View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy0927_Ch05View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy0927_Ch05View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0927_Ch05View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0927_Ch05View ����

#ifdef _DEBUG
void CMy0927_Ch05View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy0927_Ch05View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy0927_Ch05Doc* CMy0927_Ch05View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0927_Ch05Doc)));
	return (CMy0927_Ch05Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0927_Ch05View �޽��� ó����
