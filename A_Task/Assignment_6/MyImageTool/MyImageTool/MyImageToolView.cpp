
// MyImageToolView.cpp : CMyImageToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MyImageTool.h"
#endif

#include "MyImageToolDoc.h"
#include "MyImageToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyImageToolView

IMPLEMENT_DYNCREATE(CMyImageToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMyImageToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyImageToolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMyImageToolView ����/�Ҹ�

CMyImageToolView::CMyImageToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMyImageToolView::~CMyImageToolView()
{
}

BOOL CMyImageToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMyImageToolView �׸���

void CMyImageToolView::OnDraw(CDC* pDC)
{
	CMyImageToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CMyImageToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	//sizeTotal.cx = sizeTotal.cy = 100;
	CMyImageToolDoc* pDoc = GetDocument();
	if(pDoc->m_Dib.IsValid()) {
		sizeTotal.cx = pDoc->m_Dib.GetWidth();
		sizeTotal.cy = pDoc->m_Dib.GetHeight();
	}
	else {
		sizeTotal.cx = sizeTotal.cy = 100;
	}

	SetScrollSizes(MM_TEXT, sizeTotal);

	ResizeParentToFit(TRUE);
}


// CMyImageToolView �μ�


void CMyImageToolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyImageToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMyImageToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMyImageToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMyImageToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMyImageToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyImageToolView ����

#ifdef _DEBUG
void CMyImageToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMyImageToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMyImageToolDoc* CMyImageToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyImageToolDoc)));
	return (CMyImageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyImageToolView �޽��� ó����


BOOL CMyImageToolView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200, 200, 200));
	FillOutsideRect(pDC, &br);

	return TRUE;
}
