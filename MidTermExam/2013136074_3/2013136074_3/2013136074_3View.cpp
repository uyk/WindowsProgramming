
// 2013136074_3View.cpp : CMy2013136074_3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy2013136074_3View 생성/소멸

CMy2013136074_3View::CMy2013136074_3View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_3View 그리기

void CMy2013136074_3View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
}


// CMy2013136074_3View 인쇄


void CMy2013136074_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136074_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2013136074_3View 진단

#ifdef _DEBUG
void CMy2013136074_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_3Doc* CMy2013136074_3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_3Doc)));
	return (CMy2013136074_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_3View 메시지 처리기


void CMy2013136074_3View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	dc.Ellipse(SP.x, SP.y, EP.x, EP.y);
	dc.Rectangle(400,400,600,600);
	//CClientDC dc(this);
	CString str;
	str = "오른쪽(1), 왼쪽(2), 아래(3), 위(4)";

	dc.DrawText(CString(str),CRect(200,50,600,150),0);
}


void CMy2013136074_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	case '3' :// 위
		SP.y += 10;
		EP.y += 10;
		break;
	case '4' :// 아래
		SP.y -= 10;
		EP.y -= 10;
		break;
	}

	//원의 중심좌표
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
