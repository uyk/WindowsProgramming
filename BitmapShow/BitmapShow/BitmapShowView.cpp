
// BitmapShowView.cpp : CBitmapShowView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBitmapShowView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CBitmapShowView ����/�Ҹ�

CBitmapShowView::CBitmapShowView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CBitmapShowView::~CBitmapShowView()
{
}

BOOL CBitmapShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CBitmapShowView �׸���

void CBitmapShowView::OnDraw(CDC* /*pDC*/)
{
	CBitmapShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CBitmapShowView �μ�


void CBitmapShowView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBitmapShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CBitmapShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CBitmapShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CBitmapShowView ����

#ifdef _DEBUG
void CBitmapShowView::AssertValid() const
{
	CView::AssertValid();
}

void CBitmapShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitmapShowDoc* CBitmapShowView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapShowDoc)));
	return (CBitmapShowDoc*)m_pDocument;
}
#endif //_DEBUG


// CBitmapShowView �޽��� ó����


void CBitmapShowView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// �о���� DIB�� ȭ�鿡 ����Ѵ�.
	//-------------------------------------------------------------------------

	BITMAPINFOHEADER* lpbmih;
	BYTE* lpvBits;
	int w, h, c;

	lpbmih = (BITMAPINFOHEADER*)pDib;
	w = lpbmih->biWidth;
	h = lpbmih->biHeight;
	c = lpbmih->biBitCount;

	// ��Ʈ�� ���� ���� ��ġ�� ����Ѵ�.
	if( c == 24 )
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER);
	else
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER) 
		+ sizeof(RGBQUAD)*(1<<c);

	// DC�� ���´�.
	CClientDC dc(this);

	::SetDIBitsToDevice(dc.m_hDC, point.x, point.y, w, h, 0, 0, 0, h,
		lpvBits, (BITMAPINFO*)pDib, DIB_RGB_COLORS);

	// ���� �Ҵ��� �޸𸮸� �����Ѵ�.
	delete [] pDib;


	CView::OnLButtonDown(nFlags, point);
}
