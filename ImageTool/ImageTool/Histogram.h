#pragma once


// CHistogram ��ȭ �����Դϴ�.

class CHistogram : public CDialogEx
{
	DECLARE_DYNAMIC(CHistogram)

public:
	CHistogram(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHistogram();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HISTOGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_Histogram[256];
public :
	void SetImage(IppDib* pDib);
};
