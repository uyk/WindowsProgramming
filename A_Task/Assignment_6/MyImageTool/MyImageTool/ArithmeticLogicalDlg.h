#pragma once
#include "afxwin.h"


// CArithmeticLogicalDlg 대화 상자입니다.

class CArithmeticLogicalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArithmeticLogicalDlg)

public:
	CArithmeticLogicalDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CArithmeticLogicalDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ARITHMETIC_LOGICAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImage1;
	CComboBox m_comboImage2;
	int m_nFunction;
	virtual BOOL OnInitDialog();
	void* m_pDoc1;
	void* m_pDoc2;
	afx_msg void OnBnClickedOk();
};
