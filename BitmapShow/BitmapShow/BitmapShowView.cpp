
// BitmapShowView.cpp : CBitmapShowView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BitmapShow.h"
#endif

#include "BitmapShowDoc.h"
#include "BitmapShowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitmapShowView

IMPLEMENT_DYNCREATE(CBitmapShowView, CView)

BEGIN_MESSAGE_MAP(CBitmapShowView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBitmapShowView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CBitmapShowView 생성/소멸

CBitmapShowView::CBitmapShowView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBitmapShowView::~CBitmapShowView()
{
}

BOOL CBitmapShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBitmapShowView 그리기

void CBitmapShowView::OnDraw(CDC* /*pDC*/)
{
	CBitmapShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBitmapShowView 인쇄


void CBitmapShowView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBitmapShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBitmapShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBitmapShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CBitmapShowView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBitmapShowView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBitmapShowView 진단

#ifdef _DEBUG
void CBitmapShowView::AssertValid() const
{
	CView::AssertValid();
}

void CBitmapShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitmapShowDoc* CBitmapShowView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapShowDoc)));
	return (CBitmapShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CBitmapShowView 메시지 처리기


void CBitmapShowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CFile file;
	BITMAPFILEHEADER bmfh;
	DWORD dwFileSize, dwDibSize;
	BYTE* pDib;

	file.Open(_T("lenna.bmp"), CFile::modeRead | CFile::shareDenyWrite, NULL);

	dwFileSize = (DWORD)file.GetLength();
	dwDibSize = dwFileSize - sizeof(BITMAPFILEHEADER);

	pDib = new BYTE[dwDibSize];

	file.Read(&bmfh, sizeof(BITMAPFILEHEADER));
	file.Read(pDib, dwDibSize);

	file.Close();

	//-------------------------------------------------------------------------
	// 읽어들인 DIB를 화면에 출력한다.
	//-------------------------------------------------------------------------

	BITMAPINFOHEADER* lpbmih;
	BYTE* lpvBits;
	int w, h, c;

	lpbmih = (BITMAPINFOHEADER*)pDib;
	w = lpbmih->biWidth;
	h = lpbmih->biHeight;
	c = lpbmih->biBitCount;

	// 비트맵 정보 시작 위치를 계산한다.
	if( c == 24 )
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER);
	else
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER) 
		+ sizeof(RGBQUAD)*(1<<c);

	// DC를 얻어온다.
	CClientDC dc(this);

	::SetDIBitsToDevice(dc.m_hDC, point.x, point.y, w, h, 0, 0, 0, h,
		lpvBits, (BITMAPINFO*)pDib, DIB_RGB_COLORS);

	// 동적 할당한 메모리를 해제한다.
	delete [] pDib;


	CView::OnLButtonDown(nFlags, point);
}
