#pragma once


// CHistogram 대화 상자입니다.

class CHistogram : public CDialogEx
{
	DECLARE_DYNAMIC(CHistogram)

public:
	CHistogram(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHistogram();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HISTOGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_Histogram[256];
public :
	void SetImage(IppDib* pDib);
};
