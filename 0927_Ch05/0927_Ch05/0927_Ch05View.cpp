
// 0927_Ch05View.cpp : CMy0927_Ch05View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "0927_Ch05.h"
#endif

#include "0927_Ch05Doc.h"
#include "0927_Ch05View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0927_Ch05View

IMPLEMENT_DYNCREATE(CMy0927_Ch05View, CScrollView)

BEGIN_MESSAGE_MAP(CMy0927_Ch05View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0927_Ch05View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy0927_Ch05View 생성/소멸

CMy0927_Ch05View::CMy0927_Ch05View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy0927_Ch05View::~CMy0927_Ch05View()
{
}

BOOL CMy0927_Ch05View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CMy0927_Ch05View 그리기

void CMy0927_Ch05View::OnDraw(CDC* /*pDC*/)
{
	CMy0927_Ch05Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMy0927_Ch05View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy0927_Ch05View 인쇄


void CMy0927_Ch05View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0927_Ch05View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy0927_Ch05View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy0927_Ch05View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy0927_Ch05View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0927_Ch05View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0927_Ch05View 진단

#ifdef _DEBUG
void CMy0927_Ch05View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy0927_Ch05View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy0927_Ch05Doc* CMy0927_Ch05View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0927_Ch05Doc)));
	return (CMy0927_Ch05Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0927_Ch05View 메시지 처리기
