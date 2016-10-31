// Histogram.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "Histogram.h"
#include "afxdialogex.h"

#include "IppImage\IppDib.h"
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "IppImage\IppEnhance.h"
// CHistogram 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHistogram, CDialogEx)

CHistogram::CHistogram(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHistogram::IDD, pParent)
{
	memset(m_Histogram, 0, sizeof(int) * 256);
}

CHistogram::~CHistogram()
{
}

void CHistogram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHistogram, CDialogEx)
END_MESSAGE_MAP()


// CHistogram 메시지 처리기입니다.

void CHistogram::SetImage(IppDib* pDib)
{
	if (pDib != NULL && pDib->GetBitCount() == 8)
	{
		IppByteImage img;
		IppDibToImage(*pDib, img);

		// 정규화된 히스토그램을 구한다.
		float histo[256] = { 0.f, };
		IppHistogram(img, histo);

		// 정규화된 히스토그램에서 최대값을 구한다.
		float max_histo = histo[0];
		for (int i = 1; i < 256; i++)
			if (histo[i] > max_histo) max_histo = histo[i];

		// m_Histogram 배열의 최대값이 100이 되도록 전체 배열의 값을 조절한다.
		for (int i = 0; i < 256; i++)
		{
			m_Histogram[i] = static_cast<int>(histo[i] * 100 / max_histo);
		}
	}
	else
	{
		memset(m_Histogram, 0, sizeof(int) * 256);
	}
}