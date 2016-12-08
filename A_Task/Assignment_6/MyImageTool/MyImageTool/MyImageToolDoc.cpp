
// MyImageToolDoc.cpp : CMyImageToolDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MyImageTool.h"
#endif

#include "MyImageToolDoc.h"
#include "FileNewDlg.h"

#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "IppImage\IppEnhance.h"
#include "IppImage\IppFilter.h"
#include "IppImage\IppColor.h"
#include "IppImage\IppGeometry.h"

#include "BrightnessContrastDlg.h"
#include "HistogramDlg.h"
#include "ArithmeticLogicalDlg.h"
#include "AddNoiseDlg.h"
#include "TranslateDlg.h"
#include "ResizeDlg.h"
#include "RotateDlg.h"
#include "ColorCombineDlg.h"

#include <propkey.h>

#define CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img) \
	IppByteImage img; \
	IppDibToImage(m_Dib, img);

#define CONVERT_IMAGE_TO_DIB(img, dib) \
	IppDib dib; \
	IppImageToDib(img, dib);

#define CONVERT_DIB_TO_RGBIMAGE(m_Dib, img) \
	IppRgbImage img; \
	IppDibToImage(m_Dib, img);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyImageToolDoc

IMPLEMENT_DYNCREATE(CMyImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CMyImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_IMAGE_INVERSE, &CMyImageToolDoc::OnImageInverse)
	ON_COMMAND(ID_BRIGHTNESS_CONTRAST, &CMyImageToolDoc::OnBrightnessContrast)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CMyImageToolDoc::OnViewHistogram)
	ON_COMMAND(ID_HISTO_STRETCHING, &CMyImageToolDoc::OnHistoStretching)
	ON_COMMAND(ID_HISTO_EQUALIZATION, &CMyImageToolDoc::OnHistoEqualization)
	ON_COMMAND(ID_ARITHMETIC_LOGICAL, &CMyImageToolDoc::OnArithmeticLogical)
	ON_COMMAND(ID_ADD_NOISE, &CMyImageToolDoc::OnAddNoise)
	ON_COMMAND(ID_IMAGE_TRANSLATE, &CMyImageToolDoc::OnImageTranslate)
	ON_COMMAND(ID_IMAGE_RESIZE, &CMyImageToolDoc::OnImageResize)
	ON_COMMAND(ID_IMAGE_ROTATE, &CMyImageToolDoc::OnImageRotate)
	ON_COMMAND(ID_IMAGE_MIRROR, &CMyImageToolDoc::OnImageMirror)
	ON_COMMAND(ID_IMAGE_FLIP, &CMyImageToolDoc::OnImageFlip)
	ON_COMMAND(ID_COLOR_SPLIT_RGB, &CMyImageToolDoc::OnColorSplitRgb)
	ON_COMMAND(ID_COLOR_SPLIT_HSI, &CMyImageToolDoc::OnColorSplitHsi)
	ON_COMMAND(ID_COLOR_SPLIT_YUV, &CMyImageToolDoc::OnColorSplitYuv)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_RGB, &CMyImageToolDoc::OnUpdateColorSplitRgb)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_HSI, &CMyImageToolDoc::OnUpdateColorSplitHsi)
	ON_UPDATE_COMMAND_UI(ID_COLOR_SPLIT_YUV, &CMyImageToolDoc::OnUpdateColorSplitYuv)
	ON_COMMAND(ID_COLOR_COMBINE_RGB, &CMyImageToolDoc::OnColorCombineRgb)
	ON_COMMAND(ID_COLOR_COMBINE_HSI, &CMyImageToolDoc::OnColorCombineHsi)
	ON_COMMAND(ID_COLOR_COMBINE_YUV, &CMyImageToolDoc::OnColorCombineYuv)
	ON_COMMAND(ID_COLOR_EDGE, &CMyImageToolDoc::OnColorEdge)
	ON_UPDATE_COMMAND_UI(ID_COLOR_EDGE, &CMyImageToolDoc::OnUpdateColorEdge)
END_MESSAGE_MAP()


// CMyImageToolDoc ����/�Ҹ�

CMyImageToolDoc::CMyImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMyImageToolDoc::~CMyImageToolDoc()
{
}

BOOL CMyImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL ret = TRUE;

	if (theApp.m_pNewDib == NULL)
	{
		CFileNewDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			if (dlg.m_nType == 0) // �׷��̽����� ��Ʈ��
				ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
			else // Ʈ���÷� ��Ʈ��
				ret = m_Dib.CreateRgbBitmap(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		m_Dib = *(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return ret;
}




// CMyImageToolDoc serialization

void CMyImageToolDoc::Serialize(CArchive& ar)
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
void CMyImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMyImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMyImageToolDoc::SetSearchContent(const CString& value)
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

// CMyImageToolDoc ����

#ifdef _DEBUG
void CMyImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyImageToolDoc ���


BOOL CMyImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return m_Dib.Load(CT2A(lpszPathName));
}


BOOL CMyImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return m_Dib.Save(CT2A(lpszPathName));
}


void CMyImageToolDoc::OnWindowDuplicate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	AfxNewBitmap(m_Dib);
}


void CMyImageToolDoc::OnImageInverse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
	IppInverse(img);
	CONVERT_IMAGE_TO_DIB(img, dib)

	AfxNewBitmap(dib);
}


void CMyImageToolDoc::OnBrightnessContrast()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBrightnessContrastDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppBrightness(img, dlg.m_nBrightness);
		IppContrast(img, dlg.m_nContrast);
		CONVERT_IMAGE_TO_DIB(img, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnViewHistogram()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CHistogramDlg dlg;
	dlg.SetImage(&m_Dib);
	dlg.DoModal();
}


void CMyImageToolDoc::OnHistoStretching()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
	IppHistogramStretching(img);
	CONVERT_IMAGE_TO_DIB(img, dib)

	AfxNewBitmap(dib);
}


void CMyImageToolDoc::OnHistoEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (m_Dib.GetBitCount() == 8)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppHistogramEqualization(img);
		CONVERT_IMAGE_TO_DIB(img, dib)

		AfxNewBitmap(dib);
	}
	else if (m_Dib.GetBitCount() == 24)
	{
		CONVERT_DIB_TO_RGBIMAGE(m_Dib, img)
		IppByteImage imgY, imgU, imgV;
		IppColorSplitYUV(img, imgY, imgU, imgV);
		IppHistogramEqualization(imgY);

		IppRgbImage imgRes;
		IppColorCombineYUV(imgY, imgU, imgV, imgRes);
		CONVERT_IMAGE_TO_DIB(imgRes, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnArithmeticLogical()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CArithmeticLogicalDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CMyImageToolDoc* pDoc1 = (CMyImageToolDoc*)dlg.m_pDoc1;
		CMyImageToolDoc* pDoc2 = (CMyImageToolDoc*)dlg.m_pDoc2;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2)
		IppByteImage img3;

		bool ret = false;

		switch (dlg.m_nFunction)
		{
		case 0: ret = IppAdd(img1, img2, img3);  break;
		case 1: ret = IppSub(img1, img2, img3);  break;
		case 2: ret = IppAve(img1, img2, img3);  break;
		case 3: ret = IppDiff(img1, img2, img3); break;
		case 4: ret = IppAND(img1, img2, img3);  break;
		case 5: ret = IppOR(img1, img2, img3);   break;
		}

		if (ret)
		{
			CONVERT_IMAGE_TO_DIB(img3, dib)

			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
	}
}


void CMyImageToolDoc::OnAddNoise()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CAddNoiseDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;

		if( dlg.m_nNoiseType == 0 )
			IppNoiseGaussian(imgSrc, imgDst, dlg.m_nAmount);
		else
			IppNoiseSaltNPepper(imgSrc, imgDst, dlg.m_nAmount);

		CONVERT_IMAGE_TO_DIB(imgDst, dib)

		TCHAR* noise[] = { _T("����þ�"), _T("�ұ�&����") };
		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnImageTranslate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTranslateDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
		IppTranslate(imgSrc, imgDst, dlg.m_nNewSX, dlg.m_nNewSY);
		CONVERT_IMAGE_TO_DIB(imgDst, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnImageResize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CResizeDlg dlg;
	dlg.m_nOldWidth = m_Dib.GetWidth();
	dlg.m_nOldHieght = m_Dib.GetHeight();
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
		switch (dlg.m_nInterpolation)
		{
		case 0: IppResizeNearest(imgSrc, imgDst, dlg.m_nNewWidth, dlg.m_nNewHieght); break;
		case 1: IppResizeBilinear(imgSrc, imgDst, dlg.m_nNewWidth, dlg.m_nNewHieght); break;
		case 2: IppResizeCubic(imgSrc, imgDst, dlg.m_nNewWidth, dlg.m_nNewHieght); break;
		}

		CONVERT_IMAGE_TO_DIB(imgDst, dib)
		
		TCHAR* interpolation[] = { _T("�ֱٹ� �̿� ������"), _T("�缱�� ������"), _T("3�� ȸ�� ������") };
		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnImageRotate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CRotateDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
		switch (dlg.m_nRotate)
		{
		case 0: IppRotate90(imgSrc, imgDst); break;
		case 1: IppRotate180(imgSrc, imgDst); break;
		case 2: IppRotate270(imgSrc, imgDst); break;
		case 3: IppRotate(imgSrc, imgDst, (double)dlg.m_fAngle); break;
		}

		CONVERT_IMAGE_TO_DIB(imgDst, dib)

		TCHAR* rotate[] = { _T("90��"), _T("180��"), _T("270��") };
		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnImageMirror()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
	IppByteImage imgDst;
	IppMirror(imgSrc, imgDst);
	CONVERT_IMAGE_TO_DIB(imgDst, dib)

	AfxNewBitmap(dib);
}


void CMyImageToolDoc::OnImageFlip()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
	IppByteImage imgDst;
	IppFlip(imgSrc, imgDst);
	CONVERT_IMAGE_TO_DIB(imgDst, dib)

	AfxNewBitmap(dib);
}


void CMyImageToolDoc::OnColorSplitRgb()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_RGBIMAGE(m_Dib, imgColor)
	IppByteImage imgR, imgG, imgB;
	IppColorSplitRGB(imgColor, imgR, imgG, imgB);
	CONVERT_IMAGE_TO_DIB(imgR, dibR)
	CONVERT_IMAGE_TO_DIB(imgG, dibG)
	CONVERT_IMAGE_TO_DIB(imgB, dibB)

	AfxNewBitmap(dibR);
	AfxNewBitmap(dibG);
	AfxNewBitmap(dibB);
}


void CMyImageToolDoc::OnColorSplitHsi()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_RGBIMAGE(m_Dib, imgColor)
	IppByteImage imgH, imgS, imgI;
	IppColorSplitHSI(imgColor, imgH, imgS, imgI);
	CONVERT_IMAGE_TO_DIB(imgH, dibH)
	CONVERT_IMAGE_TO_DIB(imgS, dibS)
	CONVERT_IMAGE_TO_DIB(imgI, dibI)

	AfxNewBitmap(dibH);
	AfxNewBitmap(dibS);
	AfxNewBitmap(dibI);
}


void CMyImageToolDoc::OnColorSplitYuv()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_RGBIMAGE(m_Dib, imgColor)
	IppByteImage imgY, imgU, imgV;
	IppColorSplitYUV(imgColor, imgY, imgU, imgV);
	CONVERT_IMAGE_TO_DIB(imgY, dibY)
	CONVERT_IMAGE_TO_DIB(imgU, dibU)
	CONVERT_IMAGE_TO_DIB(imgV, dibV)

	AfxNewBitmap(dibY);
	AfxNewBitmap(dibU);
	AfxNewBitmap(dibV);
}


void CMyImageToolDoc::OnUpdateColorSplitRgb(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CMyImageToolDoc::OnUpdateColorSplitHsi(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CMyImageToolDoc::OnUpdateColorSplitYuv(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}


void CMyImageToolDoc::OnColorCombineRgb()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("RGB ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CMyImageToolDoc* pDoc1 = (CMyImageToolDoc*)dlg.m_pDoc1;
		CMyImageToolDoc* pDoc2 = (CMyImageToolDoc*)dlg.m_pDoc2;
		CMyImageToolDoc* pDoc3 = (CMyImageToolDoc*)dlg.m_pDoc3;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, imgR)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, imgG)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc3->m_Dib, imgB)

		IppRgbImage imgColor;
		if (IppColorCombineRGB(imgR, imgG, imgB, imgColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		CONVERT_IMAGE_TO_DIB(imgColor, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnColorCombineHsi()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("HSI ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CMyImageToolDoc* pDoc1 = (CMyImageToolDoc*)dlg.m_pDoc1;
		CMyImageToolDoc* pDoc2 = (CMyImageToolDoc*)dlg.m_pDoc2;
		CMyImageToolDoc* pDoc3 = (CMyImageToolDoc*)dlg.m_pDoc3;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, imgH)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, imgS)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc3->m_Dib, imgI)

		IppRgbImage imgColor;
		if (IppColorCombineHSI(imgH, imgS, imgI, imgColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		CONVERT_IMAGE_TO_DIB(imgColor, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnColorCombineYuv()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorCombineDlg dlg;
	dlg.m_strColorSpace = _T("YUV ���� ��� ��ġ��");
	if (dlg.DoModal() == IDOK)
	{
		CMyImageToolDoc* pDoc1 = (CMyImageToolDoc*)dlg.m_pDoc1;
		CMyImageToolDoc* pDoc2 = (CMyImageToolDoc*)dlg.m_pDoc2;
		CMyImageToolDoc* pDoc3 = (CMyImageToolDoc*)dlg.m_pDoc3;

		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, imgY)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, imgU)
		CONVERT_DIB_TO_BYTEIMAGE(pDoc3->m_Dib, imgV)

		IppRgbImage imgColor;
		if (IppColorCombineYUV(imgY, imgU, imgV, imgColor) == false)
		{
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
			return;
		}

		CONVERT_IMAGE_TO_DIB(imgColor, dib)

		AfxNewBitmap(dib);
	}
}


void CMyImageToolDoc::OnColorEdge()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_RGBIMAGE(m_Dib, img)
	IppByteImage imgEdge;
	IppColorEdge(img, imgEdge);
	CONVERT_IMAGE_TO_DIB(imgEdge, dib)

	
	AfxNewBitmap(dib);
}


void CMyImageToolDoc::OnUpdateColorEdge(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 24);
}
