
// 2013136074_3View.cpp : CMy2013136074_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136074_3.h"
#endif

#include "2013136074_3Doc.h"
#include "2013136074_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136074_3View

IMPLEMENT_DYNCREATE(CMy2013136074_3View, CView)

BEGIN_MESSAGE_MAP(CMy2013136074_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy2013136074_3View ����/�Ҹ�

CMy2013136074_3View::CMy2013136074_3View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	moveCount = 0;
	SP.x = 0;
	SP.y = 0;
	EP.x = 100;
	EP.y = 100;
}

CMy2013136074_3View::~CMy2013136074_3View()
{
}

BOOL CMy2013136074_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_3View �׸���

void CMy2013136074_3View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	
}


// CMy2013136074_3View �μ�


void CMy2013136074_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136074_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136074_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136074_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136074_3View ����

#ifdef _DEBUG
void CMy2013136074_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_3Doc* CMy2013136074_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_3Doc)));
	return (CMy2013136074_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_3View �޽��� ó����


void CMy2013136074_3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	dc.Rectangle(400,400,600,600);
	//CClientDC dc(this);
	CString str;
	str = "������(1), ����(2), �Ʒ�(3), ��(4)";

	dc.DrawText(CString(str),CRect(200,50,600,150),0);
}


void CMy2013136074_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_NOT);
	dc.Ellipse(SP.x,SP.y,EP.x,EP.y);

	switch(nChar) {
	case '1' :// ->
		SP.x += 10;
		EP.x += 10;
		break;
	case '2' :// <-
		SP.x -= 10;
		EP.x -= 10;
		break;
	case '3' :// ��
		SP.y += 10;
		EP.y += 10;
		break;
	case '4' :// �Ʒ�
		SP.y -= 10;
		EP.y -= 10;
		break;
	}

	//���� �߽���ǥ
	center.x = (SP.x + EP.x)/2;
	center.y = (SP.y + EP.y)/2;

	if( (center.x > 400) && (center.x < 600) && (center.y > 400) && (center.y < 600) ) {
		SP.x = 0;
		SP.y = 0;
		EP.x = 100;
		EP.y = 100;
	}

	dc.Ellipse(SP.x,SP.y,EP.x,EP.y);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
