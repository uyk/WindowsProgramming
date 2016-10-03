
// MFCApplication1View.cpp : CMFCApplication1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1View ����/�Ҹ�

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View �׸���

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	int i, dan = 7;
	CString str;

	for (i = 1; i <= 9; i++)
	{
		str.Format(_T("%d x %d = %d"), dan, i, dan*i);
		pDC->TextOut(20, 20 * i, str);
	}

}


// CMFCApplication1View �μ�


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View ����

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View �޽��� ó����


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//CView::OnLButtonDown(nFlags, point);
	//-------------------------------------------------------------------------
	// lenna.bmp ���Ϸκ��� DIB ������ �о���δ�.
	//-------------------------------------------------------------------------

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
	if (c == 24)
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER);
	else
		lpvBits = (BYTE*)pDib + sizeof(BITMAPINFOHEADER)
		+ sizeof(RGBQUAD)*(1 << c);

	// DC�� ���´�.
	CClientDC dc(this);

	::SetDIBitsToDevice(dc.m_hDC, point.x, point.y, w, h, 0, 0, 0, h,
		lpvBits, (BITMAPINFO*)pDib, DIB_RGB_COLORS);

	// ���� �Ҵ��� �޸𸮸� �����Ѵ�.
	delete[] pDib;

	CView::OnLButtonDown(nFlags, point);
}
