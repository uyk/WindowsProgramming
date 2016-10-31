// Histogram.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "Histogram.h"
#include "afxdialogex.h"

#include "IppImage\IppDib.h"
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "IppImage\IppEnhance.h"
// CHistogram ��ȭ �����Դϴ�.

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


// CHistogram �޽��� ó�����Դϴ�.

void CHistogram::SetImage(IppDib* pDib)
{
	if (pDib != NULL && pDib->GetBitCount() == 8)
	{
		IppByteImage img;
		IppDibToImage(*pDib, img);

		// ����ȭ�� ������׷��� ���Ѵ�.
		float histo[256] = { 0.f, };
		IppHistogram(img, histo);

		// ����ȭ�� ������׷����� �ִ밪�� ���Ѵ�.
		float max_histo = histo[0];
		for (int i = 1; i < 256; i++)
			if (histo[i] > max_histo) max_histo = histo[i];

		// m_Histogram �迭�� �ִ밪�� 100�� �ǵ��� ��ü �迭�� ���� �����Ѵ�.
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