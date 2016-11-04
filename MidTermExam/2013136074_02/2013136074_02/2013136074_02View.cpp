
// 2013136074_02View.cpp : CMy2013136074_02View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy2013136074_02View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2013136074_02View 생성/소멸

CMy2013136074_02View::CMy2013136074_02View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	Shape = 0;
}

CMy2013136074_02View::~CMy2013136074_02View()
{
}

BOOL CMy2013136074_02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074_02View 그리기

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
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy2013136074_02View 인쇄


void CMy2013136074_02View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074_02View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136074_02View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136074_02View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2013136074_02View 진단

#ifdef _DEBUG
void CMy2013136074_02View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074_02View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074_02Doc* CMy2013136074_02View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074_02Doc)));
	return (CMy2013136074_02Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074_02View 메시지 처리기


BOOL CMy2013136074_02View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nHitTest == HTCLIENT) {
		CPoint point;
		::GetCursorPos(&point);  //  커서의 포인트 값 가져옴
		ScreenToClient(&point); // 클라이언트로 변환
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(point.y <= 100) {
		if(point.x <= 100) Shape = 1;
		else if (point.x <= 200) Shape = 2;
		else if (point.x <= 300) Shape = 3;
		else if (point.x <= 400) Shape = 4;
		else if (point.x <= 500) Shape = 5;
	}
	CView::OnMouseMove(nFlags, point);
}
