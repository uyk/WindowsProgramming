
// 0927_Ch05_ImageToolView.cpp : CMy0927_Ch05_ImageToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "0927_Ch05_ImageTool.h"
#endif

#include "0927_Ch05_ImageToolDoc.h"
#include "0927_Ch05_ImageToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0927_Ch05_ImageToolView

IMPLEMENT_DYNCREATE(CMy0927_Ch05_ImageToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMy0927_Ch05_ImageToolView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_DRAWCLIPBOARD()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()

// CMy0927_Ch05_ImageToolView 생성/소멸

CMy0927_Ch05_ImageToolView::CMy0927_Ch05_ImageToolView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy0927_Ch05_ImageToolView::~CMy0927_Ch05_ImageToolView()
{
}

BOOL CMy0927_Ch05_ImageToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CMy0927_Ch05_ImageToolView 그리기

void CMy0927_Ch05_ImageToolView::OnDraw(CDC* pDC)
{
	CMy0927_Ch05_ImageToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	if (pDoc->m_Dib.IsValid())
		pDoc->m_Dib.Draw(pDC->m_hDC);
}

void CMy0927_Ch05_ImageToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy0927_Ch05_ImageToolView 인쇄

BOOL CMy0927_Ch05_ImageToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy0927_Ch05_ImageToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy0927_Ch05_ImageToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy0927_Ch05_ImageToolView 진단

#ifdef _DEBUG
void CMy0927_Ch05_ImageToolView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy0927_Ch05_ImageToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy0927_Ch05_ImageToolDoc* CMy0927_Ch05_ImageToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0927_Ch05_ImageToolDoc)));
	return (CMy0927_Ch05_ImageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0927_Ch05_ImageToolView 메시지 처리기


void CMy0927_Ch05_ImageToolView::OnDrawClipboard()
{
	CScrollView::OnDrawClipboard();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy0927_Ch05_ImageToolView::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CScrollView::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
