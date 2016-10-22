
// 1010_ImageToolDoc.cpp : CMy1010_ImageToolDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1010_ImageTool.h"
#endif

#include "1010_ImageToolDoc.h"

#include <propkey.h>

#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "IppImage\IppEnhance.h"
#include "BriDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy1010_ImageToolDoc

IMPLEMENT_DYNCREATE(CMy1010_ImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy1010_ImageToolDoc, CDocument)
	ON_COMMAND(ID_BRI_CONT, &CMy1010_ImageToolDoc::OnBriCont)
END_MESSAGE_MAP()


// CMy1010_ImageToolDoc ����/�Ҹ�

CMy1010_ImageToolDoc::CMy1010_ImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy1010_ImageToolDoc::~CMy1010_ImageToolDoc()
{
}

BOOL CMy1010_ImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy1010_ImageToolDoc serialization

void CMy1010_ImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy1010_ImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMy1010_ImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy1010_ImageToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy1010_ImageToolDoc ����

#ifdef _DEBUG
void CMy1010_ImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1010_ImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy1010_ImageToolDoc ���


BOOL CMy1010_ImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return m_Dib.Load(CT2A(lpszPathName));
}


BOOL CMy1010_ImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return m_Dib.Save(CT2A(lpszPathName));
}


void CMy1010_ImageToolDoc::OnBriCont()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBriDlg dlg;
	IppByteImage img;
	IppDib dib;

	if(dlg.DoModal() == IDOK) {
		IppDibToImage(m_Dib, img);
		IppBrightness(img, dlg.m_nBrightness);
		IppContrast(img, dlg.m_nContrast);
		IppImageToDib(img, dib);
	}
	AfxNewBitmap(dib);
}

