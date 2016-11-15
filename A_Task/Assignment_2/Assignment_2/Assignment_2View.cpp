
// Assignment_2View.cpp : CAssignment_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Assignment_2.h"
#endif

#include "Assignment_2Doc.h"
#include "Assignment_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAssignment_2View

IMPLEMENT_DYNCREATE(CAssignment_2View, CScrollView)

BEGIN_MESSAGE_MAP(CAssignment_2View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAssignment_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CAssignment_2View 생성/소멸

CAssignment_2View::CAssignment_2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAssignment_2View::~CAssignment_2View()
{
}

BOOL CAssignment_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CAssignment_2View 그리기

void CAssignment_2View::OnDraw(CDC* pDC)
{
	CAssignment_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CAssignment_2View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	//sizeTotal.cx = sizeTotal.cy = 100;
	CAssignment_2Doc* pDoc = GetDocument();
	if(pDoc->m_Dib.IsValid()) {
		sizeTotal.cx = pDoc->m_Dib.GetWidth();
		sizeTotal.cy = pDoc->m_Dib.GetHeight();
	}
	else {
		sizeTotal.cx = sizeTotal.cy = 100;
	}

	SetScrollSizes(MM_TEXT, sizeTotal);

	ResizeParentToFit(TRUE);
}


// CAssignment_2View 인쇄


void CAssignment_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAssignment_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAssignment_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAssignment_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CAssignment_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAssignment_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAssignment_2View 진단

#ifdef _DEBUG
void CAssignment_2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAssignment_2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CAssignment_2Doc* CAssignment_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAssignment_2Doc)));
	return (CAssignment_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CAssignment_2View 메시지 처리기


BOOL CAssignment_2View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CBrush br;
	br.CreateHatchBrush(HS_DIAGCROSS, RGB(200, 200, 200));
	FillOutsideRect(pDC, &br);

	return TRUE;
}
