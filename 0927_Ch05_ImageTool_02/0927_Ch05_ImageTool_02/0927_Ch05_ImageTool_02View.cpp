
// 0927_Ch05_ImageTool_02View.cpp : CMy0927_Ch05_ImageTool_02View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "0927_Ch05_ImageTool_02.h"
#endif

#include "0927_Ch05_ImageTool_02Doc.h"
#include "0927_Ch05_ImageTool_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0927_Ch05_ImageTool_02View

IMPLEMENT_DYNCREATE(CMy0927_Ch05_ImageTool_02View, CScrollView)

BEGIN_MESSAGE_MAP(CMy0927_Ch05_ImageTool_02View, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0927_Ch05_ImageTool_02View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy0927_Ch05_ImageTool_02View ����/�Ҹ�

CMy0927_Ch05_ImageTool_02View::CMy0927_Ch05_ImageTool_02View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy0927_Ch05_ImageTool_02View::~CMy0927_Ch05_ImageTool_02View()
{
}

BOOL CMy0927_Ch05_ImageTool_02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMy0927_Ch05_ImageTool_02View �׸���

void CMy0927_Ch05_ImageTool_02View::OnDraw(CDC* pDC)
{
	CMy0927_Ch05_ImageTool_02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if (pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);
}

void CMy0927_Ch05_ImageTool_02View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	CMy0927_Ch05_ImageTool_02Doc *pDoc = GetDocument();
	if (pDoc->m_Dib.IsValid())
	{
		sizeTotal.cx = pDoc->m_Dib.GetWidth();
		sizeTotal.cy = pDoc->m_Dib.GetHeight();
	}
	else
	{
		sizeTotal.cx = sizeTotal.cy = 100;
	}

	SetScrollSizes(MM_TEXT, sizeTotal);
	ResizeParentToFit(TRUE);
}


// CMy0927_Ch05_ImageTool_02View �μ�


void CMy0927_Ch05_ImageTool_02View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0927_Ch05_ImageTool_02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy0927_Ch05_ImageTool_02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy0927_Ch05_ImageTool_02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy0927_Ch05_ImageTool_02View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0927_Ch05_ImageTool_02View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0927_Ch05_ImageTool_02View ����

#ifdef _DEBUG
void CMy0927_Ch05_ImageTool_02View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy0927_Ch05_ImageTool_02View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy0927_Ch05_ImageTool_02Doc* CMy0927_Ch05_ImageTool_02View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0927_Ch05_ImageTool_02Doc)));
	return (CMy0927_Ch05_ImageTool_02Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0927_Ch05_ImageTool_02View �޽��� ó����


BOOL CMy0927_Ch05_ImageTool_02View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200, 200, 200));
	FillOutsideRect(pDC, &br);
	//return CScrollView::OnEraseBkgnd(pDC);
	return TRUE;
}
