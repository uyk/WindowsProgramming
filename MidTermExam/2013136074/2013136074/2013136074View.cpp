
// 2013136074View.cpp : CMy2013136074View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "2013136074.h"
#endif

#include "2013136074Doc.h"
#include "2013136074View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2013136074View

IMPLEMENT_DYNCREATE(CMy2013136074View, CView)

BEGIN_MESSAGE_MAP(CMy2013136074View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMy2013136074View ����/�Ҹ�

CMy2013136074View::CMy2013136074View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	count = 0;
	isDraw= FALSE;
}

CMy2013136074View::~CMy2013136074View()
{
}

BOOL CMy2013136074View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074View �׸���

void CMy2013136074View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy2013136074View �μ�


void CMy2013136074View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy2013136074View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy2013136074View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy2013136074View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy2013136074View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy2013136074View ����

#ifdef _DEBUG
void CMy2013136074View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074Doc* CMy2013136074View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074Doc)));
	return (CMy2013136074Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074View �޽��� ó����


void CMy2013136074View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	count++;
	CString countStr;
	countStr.Format(_T("%d"),count);


	dc.DrawText(CString(countStr),CRect(100,20,500,40),0);


	isDraw = TRUE;

	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136074View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if(isDraw == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//�������� ���� ������� ��������. NULL_BRUSH�� ������ ���� ������� ������ �׸���.
		dc.SetROP2(R2_NOT);					//��ġ�� �κ��� ��� ó������ ���ϴ� �Լ�(R2_NOT:��ġ�� �κ� ���� ������->�������̾����� �������);
		dc.MoveTo(SP.x, SP.y);
		dc.LineTo(EP.x, EP.y);
		
		EP.x = point.x;
		EP.y = point.y;

		dc.MoveTo(SP.x, SP.y);
		dc.LineTo(EP.x, EP.y);;
	}


	CView::OnMouseMove(nFlags, point);
}


void CMy2013136074View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	isDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2013136074View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CString str;
	str = "���� ���� : ";

	dc.DrawText(CString(str),CRect(10,20,500,40),0);
}
