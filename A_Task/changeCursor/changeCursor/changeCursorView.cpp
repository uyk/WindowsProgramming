
// changeCursorView.cpp : CchangeCursorView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "changeCursor.h"
#endif

#include "changeCursorDoc.h"
#include "changeCursorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchangeCursorView

IMPLEMENT_DYNCREATE(CchangeCursorView, CView)

BEGIN_MESSAGE_MAP(CchangeCursorView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CchangeCursorView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CchangeCursorView::OnLine)
	ON_COMMAND(ID_REC, &CchangeCursorView::OnRec)
	ON_COMMAND(ID_ELI, &CchangeCursorView::OnEli)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CchangeCursorView ����/�Ҹ�

CchangeCursorView::CchangeCursorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	Shape = 0;
}

CchangeCursorView::~CchangeCursorView()
{
}

BOOL CchangeCursorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CchangeCursorView �׸���

void CchangeCursorView::OnDraw(CDC* /*pDC*/)
{
	CchangeCursorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CchangeCursorView �μ�


void CchangeCursorView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CchangeCursorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CchangeCursorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CchangeCursorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CchangeCursorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CchangeCursorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CchangeCursorView ����

#ifdef _DEBUG
void CchangeCursorView::AssertValid() const
{
	CView::AssertValid();
}

void CchangeCursorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CchangeCursorDoc* CchangeCursorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CchangeCursorDoc)));
	return (CchangeCursorDoc*)m_pDocument;
}
#endif //_DEBUG


// CchangeCursorView �޽��� ó����


void CchangeCursorView::OnLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 1;
}


void CchangeCursorView::OnRec()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 2;
}


void CchangeCursorView::OnEli()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Shape = 3;
}

BOOL CchangeCursorView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
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

			if(rgn.PtInRegion(point))
				::SetCursor(AfxGetApp() ->LoadCursor(IDC_CURSOR1));
			else
				::SetCursor(AfxGetApp() ->LoadStandardCursor(IDC_CROSS));
		}

		return true;
	}
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
