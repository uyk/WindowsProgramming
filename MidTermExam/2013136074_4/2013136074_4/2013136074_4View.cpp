
// 2013136074_4View.cpp : CMy2013136074_4View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136074_4.h"
#endif

#include "2013136074_4Doc.h"
#include "2013136074_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136074_4View

IMPLEMENT_DYNCREATE(CMy2013136074_4View, CView)

BEGIN_MESSAGE_MAP(CMy2013136074_4View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_LINE, &CMy2013136074_4View::OnLine)
	ON_COMMAND(ID_ELI, &CMy2013136074_4View::OnEli)
	ON_COMMAND(ID_REC, &CMy2013136074_4View::OnRec)
	ON_COMMAND(ID_DEL, &CMy2013136074_4View::OnDel)
END_MESSAGE_MAP()

// CMy2013136074_4View ����/�Ҹ�

CMy2013136074_4View::CMy2013136074_4View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	isDraw = FALSE;
	Shape = 0;
}

CMy2013136074_4View::~CMy2013136074_4View()
{
}

BOOL CMy2013136074_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_4View �׸���

void CMy2013136074_4View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(0,0,5000,5000);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136074_4View �μ�


void CMy2013136074_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136074_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136074_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136074_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136074_4View ����

#ifdef _DEBUG
void CMy2013136074_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_4Doc* CMy2013136074_4View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_4Doc)));
	return (CMy2013136074_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_4View �޽��� ó����


void CMy2013136074_4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	isDraw = TRUE;

	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136074_4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(isDraw == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//�������� ���� ������� ��������. NULL_BRUSH�� ������ ���� ������� ������ �׸���.
		dc.SetROP2(R2_NOT);					//��ġ�� �κ��� ��� ó������ ���ϴ� �Լ�(R2_NOT:��ġ�� �κ� ���� ������->�������̾����� �������);
		switch(Shape) {
		case 1:
			dc.MoveTo(SP.x, SP.y);
			dc.LineTo(EP.x, EP.y);
			break;
		case 2:
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
			break;
		case 3:
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
			break;
		}
		
		EP.x = point.x;
		EP.y = point.y;

		switch(Shape) {
		case 1:
			dc.MoveTo(SP.x, SP.y);
			dc.LineTo(EP.x, EP.y);
			break;
		case 2:
			dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
			break;
		case 3:
			dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
			break;
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CMy2013136074_4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	isDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2013136074_4View::OnLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 1;
}


void CMy2013136074_4View::OnEli()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 2;
}


void CMy2013136074_4View::OnRec()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 3;
}


void CMy2013136074_4View::OnDel()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CClientDC dc(this);
	dc.Rectangle(0,0,5000,5000);
}
