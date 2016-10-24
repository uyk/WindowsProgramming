
// CountClickView.cpp : CCountClickView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "CountClick.h"
#endif

#include "CountClickDoc.h"
#include "CountClickView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCountClickView

IMPLEMENT_DYNCREATE(CCountClickView, CView)

BEGIN_MESSAGE_MAP(CCountClickView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCountClickView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCountClickView ����/�Ҹ�

CCountClickView::CCountClickView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	count = 0;
}

CCountClickView::~CCountClickView()
{
}

BOOL CCountClickView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCountClickView �׸���

void CCountClickView::OnDraw(CDC* pDC)
{
	CCountClickDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(10,10,100,100);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCountClickView �μ�


void CCountClickView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCountClickView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCountClickView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCountClickView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CCountClickView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCountClickView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCountClickView ����

#ifdef _DEBUG
void CCountClickView::AssertValid() const
{
	CView::AssertValid();
}

void CCountClickView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCountClickDoc* CCountClickView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCountClickDoc)));
	return (CCountClickDoc*)m_pDocument;
}
#endif //_DEBUG


// CCountClickView �޽��� ó����


void CCountClickView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	count++;
	CString countStr;
	countStr.Format(_T("%d"),count);

	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.DrawText(CString(countStr),CRect(70,20,500,40),0);

	CView::OnLButtonDown(nFlags, point);
}


void CCountClickView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CString str;
	str = "���� : ";

	dc.DrawText(CString(str),CRect(10,20,500,40),0);
}
