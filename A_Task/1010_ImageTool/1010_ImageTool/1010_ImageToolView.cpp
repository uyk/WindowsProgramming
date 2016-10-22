
// 1010_ImageToolView.cpp : CMy1010_ImageToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1010_ImageTool.h"
#endif

#include "1010_ImageToolDoc.h"
#include "1010_ImageToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1010_ImageToolView

IMPLEMENT_DYNCREATE(CMy1010_ImageToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMy1010_ImageToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy1010_ImageToolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_WM_ICONERASEBKGND()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy1010_ImageToolView ����/�Ҹ�

CMy1010_ImageToolView::CMy1010_ImageToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1010_ImageToolView::~CMy1010_ImageToolView()
{
}

BOOL CMy1010_ImageToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMy1010_ImageToolView �׸���

void CMy1010_ImageToolView::OnDraw(CDC* pDC)
{
	CMy1010_ImageToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if(pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);
}

void CMy1010_ImageToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.

	CMy1010_ImageToolDoc* pDoc = GetDocument();
	if(pDoc->m_Dib.IsValid()) {
		sizeTotal.cx = pDoc->m_Dib.GetWidth();
		sizeTotal.cy = pDoc->m_Dib.GetHeight();
	}
	else {
		sizeTotal.cx = sizeTotal.cy = 100;
	}
	//sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	ResizeParentToFit(TRUE);
}


// CMy1010_ImageToolView �μ�


void CMy1010_ImageToolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy1010_ImageToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1010_ImageToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1010_ImageToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy1010_ImageToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy1010_ImageToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy1010_ImageToolView ����

#ifdef _DEBUG
void CMy1010_ImageToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy1010_ImageToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy1010_ImageToolDoc* CMy1010_ImageToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1010_ImageToolDoc)));
	return (CMy1010_ImageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy1010_ImageToolView �޽��� ó����


//void CMy1010_ImageToolView::OnIconEraseBkgnd(CDC* pDC)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	CBrush br;
//	br.CreateHatchBrush(HS_DIAGCROSS,RGB(200,200,200));
//	FillOutsideRect(pDC, &br);
//
//	CScrollView::OnIconEraseBkgnd(pDC);
//}


BOOL CMy1010_ImageToolView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200,200,200));
	FillOutsideRect(pDC, &br);

	//return CScrollView::OnEraseBkgnd(pDC);
	return TRUE;
}
