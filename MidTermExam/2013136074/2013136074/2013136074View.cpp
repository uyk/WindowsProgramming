
// 2013136074View.cpp : CMy2013136074View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CMy2013136074View 생성/소멸

CMy2013136074View::CMy2013136074View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	count = 0;
	isDraw= FALSE;
}

CMy2013136074View::~CMy2013136074View()
{
}

BOOL CMy2013136074View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy2013136074View 그리기

void CMy2013136074View::OnDraw(CDC* /*pDC*/)
{
	CMy2013136074Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy2013136074View 인쇄


void CMy2013136074View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy2013136074View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy2013136074View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy2013136074View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMy2013136074View 진단

#ifdef _DEBUG
void CMy2013136074View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2013136074View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2013136074Doc* CMy2013136074View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2013136074Doc)));
	return (CMy2013136074Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2013136074View 메시지 처리기


void CMy2013136074View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if(isDraw == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//도형에서 면을 어떤색으로 지정할지. NULL_BRUSH를 넣으면 속이 투명색인 도형을 그린다.
		dc.SetROP2(R2_NOT);					//겹치는 부분을 어떻게 처리할지 정하는 함수(R2_NOT:겹치는 부분 색을 반전함->검은색이었으면 흰색으로);
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	isDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2013136074View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CString str;
	str = "선의 개수 : ";

	dc.DrawText(CString(str),CRect(10,20,500,40),0);
}
