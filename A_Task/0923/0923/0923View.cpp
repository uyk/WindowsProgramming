
// 0923View.cpp : CMy0923View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "0923.h"
#endif

#include "0923Doc.h"
#include "0923View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0923View

IMPLEMENT_DYNCREATE(CMy0923View, CView)

BEGIN_MESSAGE_MAP(CMy0923View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy0923View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0923View 생성/소멸

CMy0923View::CMy0923View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	count = 0;
}

CMy0923View::~CMy0923View()
{
}

BOOL CMy0923View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy0923View 그리기

void CMy0923View::OnDraw(CDC* /*pDC*/)
{
	CMy0923Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy0923View 인쇄


void CMy0923View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy0923View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy0923View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy0923View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy0923View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy0923View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy0923View 진단

#ifdef _DEBUG
void CMy0923View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0923View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0923Doc* CMy0923View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0923Doc)));
	return (CMy0923Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0923View 메시지 처리기


void CMy0923View::OnPaint()
{
	CString str1;
	str1 = "갯수 : ";
	count = 0;
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	dc.DrawText(CString(str1), CRect(10, 20, 500, 40), 0);
}


void CMy0923View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	count++;
	CString str;
	str.Format(_T("%d"), count);

	CString str2;
	str2 = "23";
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
	dc.DrawText(CString(str), CRect(70, 20, 500, 40), 0);
	CView::OnLButtonDown(nFlags, point);
}
