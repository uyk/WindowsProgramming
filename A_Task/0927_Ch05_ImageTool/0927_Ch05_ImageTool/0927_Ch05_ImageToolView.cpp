
// 0927_Ch05_ImageToolView.cpp : CMy0927_Ch05_ImageToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "0927_Ch05_ImageTool.h"
#endif

#include "0927_Ch05_ImageToolDoc.h"
#include "0927_Ch05_ImageToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0927_Ch05_ImageToolView

IMPLEMENT_DYNCREATE(CMy0927_Ch05_ImageToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMy0927_Ch05_ImageToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_DRAWCLIPBOARD()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()

// CMy0927_Ch05_ImageToolView ����/�Ҹ�

CMy0927_Ch05_ImageToolView::CMy0927_Ch05_ImageToolView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy0927_Ch05_ImageToolView::~CMy0927_Ch05_ImageToolView()
{
}

BOOL CMy0927_Ch05_ImageToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMy0927_Ch05_ImageToolView �׸���

void CMy0927_Ch05_ImageToolView::OnDraw(CDC* pDC)
{
	CMy0927_Ch05_ImageToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if (pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);
}

void CMy0927_Ch05_ImageToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy0927_Ch05_ImageToolView �μ�

BOOL CMy0927_Ch05_ImageToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy0927_Ch05_ImageToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy0927_Ch05_ImageToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy0927_Ch05_ImageToolView ����

#ifdef _DEBUG
void CMy0927_Ch05_ImageToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy0927_Ch05_ImageToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy0927_Ch05_ImageToolDoc* CMy0927_Ch05_ImageToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0927_Ch05_ImageToolDoc)));
	return (CMy0927_Ch05_ImageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0927_Ch05_ImageToolView �޽��� ó����


void CMy0927_Ch05_ImageToolView::OnDrawClipboard()
{
	CScrollView::OnDrawClipboard();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CMy0927_Ch05_ImageToolView::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CScrollView::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
