
// 1010_ImageToolDoc.cpp : CMy1010_ImageToolDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CMy1010_ImageToolDoc 생성/소멸

CMy1010_ImageToolDoc::CMy1010_ImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMy1010_ImageToolDoc::~CMy1010_ImageToolDoc()
{
}

BOOL CMy1010_ImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMy1010_ImageToolDoc serialization

void CMy1010_ImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMy1010_ImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void CMy1010_ImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CMy1010_ImageToolDoc 진단

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


// CMy1010_ImageToolDoc 명령


BOOL CMy1010_ImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return m_Dib.Load(CT2A(lpszPathName));
}


BOOL CMy1010_ImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return m_Dib.Save(CT2A(lpszPathName));
}


void CMy1010_ImageToolDoc::OnBriCont()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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

