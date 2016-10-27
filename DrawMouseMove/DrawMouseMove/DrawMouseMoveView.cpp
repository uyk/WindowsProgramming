
// DrawMouseMoveView.cpp : CDrawMouseMoveView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DrawMouseMove.h"
#endif

#include "DrawMouseMoveDoc.h"
#include "DrawMouseMoveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawMouseMoveView

IMPLEMENT_DYNCREATE(CDrawMouseMoveView, CView)

BEGIN_MESSAGE_MAP(CDrawMouseMoveView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawMouseMoveView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CDrawMouseMoveView ����/�Ҹ�

CDrawMouseMoveView::CDrawMouseMoveView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	isDrawMove = FALSE;

}

CDrawMouseMoveView::~CDrawMouseMoveView()
{
}

BOOL CDrawMouseMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CDrawMouseMoveView �׸���

void CDrawMouseMoveView::OnDraw(CDC* /*pDC*/)
{
	CDrawMouseMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CDrawMouseMoveView �μ�


void CDrawMouseMoveView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawMouseMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CDrawMouseMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CDrawMouseMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CDrawMouseMoveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);

	 OnContextMenu(this, point);
 
	 CClientDC dc(this);
	 dc.SelectStockObject(NULL_BRUSH);
	 dc.SetROP2(R2_COPYPEN);
	 EP.x = point.x;
	 EP.y = point.y;
	 //dc.MoveTo(SP.x,SP.y);
	 //dc.LineTo(EP.x, EP.y);
	 //dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	 isDrawMove = FALSE;

	OnContextMenu(this, point);
}

void CDrawMouseMoveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawMouseMoveView ����

#ifdef _DEBUG
void CDrawMouseMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawMouseMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawMouseMoveDoc* CDrawMouseMoveView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawMouseMoveDoc)));
	return (CDrawMouseMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawMouseMoveView �޽��� ó����


void CDrawMouseMoveView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	/* �������׸���
	dc.MoveTo(50,50);
	dc.LineTo(500,500);
	dc.LineTo(50,500);
	dc.LineTo(50,50);
	dc.LineTo(500,50);
	dc.LineTo(500,500);
	dc.MoveTo(500,50);
	dc.LineTo(50,500);
	*/
}


void CDrawMouseMoveView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//CClientDC dc(this);
	if(isDrawMove == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//�������� ���� ������� ��������. NULL_BRUSH�� ������ ���� ������� ������ �׸���.
		dc.SetROP2(R2_NOT);					//��ġ�� �κ��� ��� ó������ ���ϴ� �Լ�(R2_NOT:��ġ�� �κ� ���� ������->�������̾����� �������);
		if(isLeft) dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
		
		EP.x = point.x;
		EP.y = point.y;

		if(isLeft) dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
		else dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrawMouseMoveView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//CClientDC dc(this);

	isDrawMove = TRUE;
	isLeft = TRUE;

	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawMouseMoveView::OnLButtonUp(UINT nFlags, CPoint point)
{\
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	/* �����
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);		//������ �׸��� ���� ���׸��� �׸���

	EP.x = point.x;
	EP.y = point.y;
	dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
	*/
	isDrawMove = FALSE;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawMouseMoveView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	isDrawMove = TRUE;
	isLeft = FALSE;
	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;


	CView::OnRButtonDown(nFlags, point);
}
