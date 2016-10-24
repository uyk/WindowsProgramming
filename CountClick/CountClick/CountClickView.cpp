
// CountClickView.cpp : CCountClickView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCountClickView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCountClickView 생성/소멸

CCountClickView::CCountClickView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	count = 0;
}

CCountClickView::~CCountClickView()
{
}

BOOL CCountClickView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCountClickView 그리기

void CCountClickView::OnDraw(CDC* pDC)
{
	CCountClickDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(10,10,100,100);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCountClickView 인쇄


void CCountClickView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCountClickView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCountClickView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCountClickView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CCountClickView 진단

#ifdef _DEBUG
void CCountClickView::AssertValid() const
{
	CView::AssertValid();
}

void CCountClickView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCountClickDoc* CCountClickView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCountClickDoc)));
	return (CCountClickDoc*)m_pDocument;
}
#endif //_DEBUG


// CCountClickView 메시지 처리기


void CCountClickView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	CString str;
	str = "갯수 : ";

	dc.DrawText(CString(str),CRect(10,20,500,40),0);
}
