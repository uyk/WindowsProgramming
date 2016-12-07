#pragma once


// CAddNoiseDlg 대화 상자입니다.

#pragma once

class CAddNoiseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddNoiseDlg)

public:
	CAddNoiseDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddNoiseDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ADD_NOISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nNoiseType;
	int m_nAmount;
	virtual BOOL OnInitDialog();
};
