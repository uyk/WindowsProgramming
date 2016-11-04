
// 2013136074_4View.cpp : CMy2013136074_4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CMy2013136074_4View 생성/소멸

CMy2013136074_4View::CMy2013136074_4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	isDraw = FALSE;
	Shape = 0;
}

CMy2013136074_4View::~CMy2013136074_4View()
{
}

BOOL CMy2013136074_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_4View 그리기

void CMy2013136074_4View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(0,0,5000,5000);
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy2013136074_4View 인쇄


void CMy2013136074_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136074_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2013136074_4View 진단

#ifdef _DEBUG
void CMy2013136074_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_4Doc* CMy2013136074_4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_4Doc)));
	return (CMy2013136074_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_4View 메시지 처리기


void CMy2013136074_4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	isDraw = TRUE;

	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMy2013136074_4View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(isDraw == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//도형에서 면을 어떤색으로 지정할지. NULL_BRUSH를 넣으면 속이 투명색인 도형을 그린다.
		dc.SetROP2(R2_NOT);					//겹치는 부분을 어떻게 처리할지 정하는 함수(R2_NOT:겹치는 부분 색을 반전함->검은색이었으면 흰색으로);
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	isDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2013136074_4View::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Shape = 1;
}


void CMy2013136074_4View::OnEli()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Shape = 2;
}


void CMy2013136074_4View::OnRec()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Shape = 3;
}


void CMy2013136074_4View::OnDel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CClientDC dc(this);
	dc.Rectangle(0,0,5000,5000);
}
