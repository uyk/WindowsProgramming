// ImageToolDoc.cpp : CImageToolDoc Ŭ������ ����
//

#include "stdafx.h"
#include "ImageTool.h"

#include "ImageToolDoc.h"

#include "Dib.h"
#include "DibEnhancement.h"
#include "DibFilter.h"
#include "DibGeometry.h"
#include "DibColor.h"

#include "FileNewDlg.h"
#include "BrightnessContrastDlg.h"
#include "HistogramDlg.h"
#include "ArithmeticDlg.h"
#include "GaussianDlg.h"
#include "AddNoiseDlg.h"
#include "TranslateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_BRIGHTNESS_CONTRAST, &CImageToolDoc::OnBrightnessContrast)
	ON_COMMAND(ID_IMAGE_INVERSE, &CImageToolDoc::OnImageInverse)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_COMMAND(ID_HISTO_STRETCHING, &CImageToolDoc::OnHistoStretching)
	ON_COMMAND(ID_HISTO_EQUALIZATION, &CImageToolDoc::OnHistoEqualization)
	//ON_BN_CLICKED(IDOK, &CImageToolDoc::OnBnClickedOk)
	ON_COMMAND(ID_ARITHMETIC, &CImageToolDoc::OnArithmetic)
	ON_COMMAND(ID_FILTER_GAUSSIAN, &CImageToolDoc::OnFilterGaussian)
	ON_COMMAND(ID_ADD_NOISE, &CImageToolDoc::OnAddNoise)
	ON_COMMAND(ID_TRANSLATE, &CImageToolDoc::OnTranslate)
	ON_COMMAND(ID_COLOR_SPLIT_RGB, &CImageToolDoc::OnColorSplitRgb)
	ON_COMMAND(ID_COLOR_SPLIT_HSI, &CImageToolDoc::OnColorSplitHsi)
	ON_COMMAND(ID_COLOR_SPLIT_YUV, &CImageToolDoc::OnColorSplitYuv)
END_MESSAGE_MAP()


// CImageToolDoc ����/�Ҹ�

CImageToolDoc::CImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL bSuccess = TRUE;

	if( theApp.m_pNewDib == NULL )
	{
		CFileNewDlg dlg;
		if( dlg.DoModal() == IDOK )
		{
			if( dlg.m_nType == 0 ) // �׷��̽����� �̹���
				bSuccess = m_Dib.CreateGrayImage(dlg.m_nWidth, dlg.m_nHeight);
			else // Ʈ��Į�� �̹���
				bSuccess = m_Dib.CreateRGBImage(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			bSuccess = FALSE;
		}
	}
	else
	{
		m_Dib.Copy(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return bSuccess;
}

// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
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


// CImageToolDoc ����

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc ���


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	return  m_Dib.Load(lpszPathName);
}

BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return  m_Dib.Save(lpszPathName);
}

void CImageToolDoc::OnEditCopy()
{
	if( m_Dib.IsValid() )
		m_Dib.CopyToClipboard();
}

void CImageToolDoc::OnWindowDuplicate()
{
	AfxNewImage(m_Dib);
}



void CImageToolDoc::OnBrightnessContrast()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CBrightnessContrastDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibBrightness(dib, dlg.m_nBrightness);
		DibContrast(dib, dlg.m_nContrast);
		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnImageInverse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibInverse(dib);
	AfxNewImage(dib);

}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CHistogramDlg dlg;
	dlg.SetImage(m_Dib);
	dlg.DoModal();
}


void CImageToolDoc::OnHistoStretching()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CImageToolDoc::OnHistoEqualization()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	DibHistEqual(dib);
	AfxNewImage(dib);
}


//void CImageToolDoc::OnBnClickedOk()
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//}


void CImageToolDoc::OnArithmetic()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CArithmeticDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;

		CDib dib;
		BOOL ret = FALSE;

		switch( dlg.m_nFunction )
		{
		case 0: ret = DibAdd(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 1: ret = DibSub(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 2: ret = DibAve(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 3: ret = DibDif(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 4: ret = DibAND(pDoc1->m_Dib, pDoc2->m_Dib, dib); break;
		case 5: ret = DibOR(pDoc1->m_Dib, pDoc2->m_Dib, dib);  break;
		}

		if( ret )
			AfxNewImage(dib);
		else
			AfxMessageBox(_T("������ ũ�Ⱑ �ٸ��ϴ�!"));
	}
}


void CImageToolDoc::OnFilterGaussian()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CGaussianDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibFilterGaussian(dib, dlg.m_fSigma);
		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnAddNoise()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CAddNoiseDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;

		if( dlg.m_nNoiseType == 0 )
			DibNoiseGaussian(dib, dlg.m_nAmount);
		else
			DibNoiseSaltNPepper(dib, dlg.m_nAmount);

		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnTranslate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	TranslateDlg dlg;
	if( dlg.DoModal() == IDOK )
	{
		CDib dib = m_Dib;
		DibTranslate(dib, dlg.m_nNewSX, dlg.m_nNewSY);
		AfxNewImage(dib);
	}
}


void CImageToolDoc::OnColorSplitRgb()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDib dib = m_Dib;
	CDib dibR, dibG, dibB;

	DibColorSplitRGB(dib,dibR,dibG,dibB);
	//AfxNewImage(dibR);
	//AfxNewImage(dibG);
	//AfxNewImage(dibB);
}


void CImageToolDoc::OnColorSplitHsi()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}


void CImageToolDoc::OnColorSplitYuv()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
}
