#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CBriDlg ��ȭ �����Դϴ�.

class CBriDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBriDlg)

public:
	CBriDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBriDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
