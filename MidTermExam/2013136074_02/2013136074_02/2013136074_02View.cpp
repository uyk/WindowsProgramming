
// 2013136074_02View.cpp : CMy2013136074_02View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136074_02.h"
#endif

#include "2013136074_02Doc.h"
#include "2013136074_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136074_02View

IMPLEMENT_DYNCREATE(CMy2013136074_02View, CView)

BEGIN_MESSAGE_MAP(CMy2013136074_02View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074_02View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2013136074_02View ����/�Ҹ�

CMy2013136074_02View::CMy2013136074_02View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	Shape = 0;
}

CMy2013136074_02View::~CMy2013136074_02View()
{
}

BOOL CMy2013136074_02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_02View �׸���

void CMy2013136074_02View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074_02Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(0,0,500,100);

	dc.MoveTo(100,0);
	dc.LineTo(100,100);
	dc.MoveTo(200,0);
	dc.LineTo(200,100);
	dc.MoveTo(300,0);
	dc.LineTo(300,100);
	dc.MoveTo(400,0);
	dc.LineTo(400,100);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136074_02View �μ�


void CMy2013136074_02View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136074_02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136074_02View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136074_02View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136074_02View ����

#ifdef _DEBUG
void CMy2013136074_02View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_02Doc* CMy2013136074_02View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_02Doc)));
	return (CMy2013136074_02Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_02View �޽��� ó����


BOOL CMy2013136074_02View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nHitTest == HTCLIENT) {
		CPoint point;
		::GetCursorPos(&point);  //  Ŀ���� ����Ʈ �� ������
		ScreenToClient(&point); // Ŭ���̾�Ʈ�� ��ȯ
		CRgn rgn;
		rgn.CreateRectRgn(0,0,400,100);

		switch(Shape) {
		case 1:
			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() ->LoadCursor(IDC_CURSOR1));
			break;
		case 2:
			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() -> LoadCursor(IDC_CURSOR2));
			break;
		case 3:
			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() -> LoadCursor(IDC_CURSOR3));
			break;
		case 4:
			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() -> LoadCursor(IDC_CURSOR4));
			break;
		case 5:
			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() -> LoadCursor(IDC_CURSOR5));
			break;

		if(rgn.PtInRegion(point))
			::SetCursor(AfxGetApp() ->LoadCursor(IDC_CURSOR1));
		else
			::SetCursor(AfxGetApp() ->LoadStandardCursor(IDC_CROSS));
		}

		return true;
	}
	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void CMy2013136074_02View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(point.y <= 100) {
		if(point.x <= 100) Shape = 1;
		else if (point.x <= 200) Shape = 2;
		else if (point.x <= 300) Shape = 3;
		else if (point.x <= 400) Shape = 4;
		else if (point.x <= 500) Shape = 5;
	}
	CView::OnMouseMove(nFlags, point);
}
