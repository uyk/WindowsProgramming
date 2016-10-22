#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CBriDlg 대화 상자입니다.

class CBriDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBriDlg)

public:
	CBriDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBriDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_BRI_EDIT;
	int m_nBrightness;
	CSliderCtrl m_sliderBrightness;
	int m_nContrast;
	virtual BOOL OnInitDialog();
	CSliderCtrl m_sliderContrast;
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeBriEdit();
	afx_msg void OnEnChangeContEdit();
};
