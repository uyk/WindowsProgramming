
// 0923View.cpp : CMy0923View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "0923.h"
#endif

#include "0923Doc.h"
#include "0923View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0923View

IMPLEMENT_DYNCREATE(CMy0923View, CView)

BEGIN_MESSAGE_MAP(CMy0923View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0923View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0923View ����/�Ҹ�

CMy0923View::CMy0923View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	count = 0;
}

CMy0923View::~CMy0923View()
{
}

BOOL CMy0923View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy0923View �׸���

void CMy0923View::OnDraw(CDC* /*pDC*/)
{
	CMy0923Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy0923View �μ�


void CMy0923View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0923View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy0923View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy0923View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy0923View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0923View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0923View ����

#ifdef _DEBUG
void CMy0923View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0923View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0923Doc* CMy0923View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0923Doc)));
	return (CMy0923Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0923View �޽��� ó����


void CMy0923View::OnPaint()
{
	CString str1;
	str1 = "���� : ";
	count = 0;
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.

	dc.DrawText(CString(str1), CRect(10, 20, 500, 40), 0);
}


void CMy0923View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	count++;
	CString str;
	str.Format(_T("%d"), count);

	CString str2;
	str2 = "23";
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.DrawText(CString(str), CRect(70, 20, 500, 40), 0);
	CView::OnLButtonDown(nFlags, point);
}
