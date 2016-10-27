
// DrawMouseMoveView.cpp : CDrawMouseMoveView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CDrawMouseMoveView 생성/소멸

CDrawMouseMoveView::CDrawMouseMoveView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	isDrawMove = FALSE;

}

CDrawMouseMoveView::~CDrawMouseMoveView()
{
}

BOOL CDrawMouseMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDrawMouseMoveView 그리기

void CDrawMouseMoveView::OnDraw(CDC* /*pDC*/)
{
	CDrawMouseMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDrawMouseMoveView 인쇄


void CDrawMouseMoveView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawMouseMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDrawMouseMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDrawMouseMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CDrawMouseMoveView 진단

#ifdef _DEBUG
void CDrawMouseMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawMouseMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawMouseMoveDoc* CDrawMouseMoveView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawMouseMoveDoc)));
	return (CDrawMouseMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawMouseMoveView 메시지 처리기


void CDrawMouseMoveView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	/* 딱지모양그리기
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//CClientDC dc(this);
	if(isDrawMove == TRUE) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);	//도형에서 면을 어떤색으로 지정할지. NULL_BRUSH를 넣으면 속이 투명색인 도형을 그린다.
		dc.SetROP2(R2_NOT);					//겹치는 부분을 어떻게 처리할지 정하는 함수(R2_NOT:겹치는 부분 색을 반전함->검은색이었으면 흰색으로);
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/* 없어도됨
	CClientDC dc(this);

	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);		//원래의 그림을 덮고 새그림을 그린다

	EP.x = point.x;
	EP.y = point.y;
	dc.Rectangle(SP.x, SP.y, EP.x, EP.y);
	*/
	isDrawMove = FALSE;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawMouseMoveView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	isDrawMove = TRUE;
	isLeft = FALSE;
	SP.x = point.x;
	SP.y = point.y;
	EP.x = point.x;
	EP.y = point.y;


	CView::OnRButtonDown(nFlags, point);
}
