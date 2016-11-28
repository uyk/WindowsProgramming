#pragma once


// CResizeDlg ��ȭ �����Դϴ�.

class CResizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResizeDlg)

public:
	CResizeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CResizeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_RESIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nOldWidth;
	int m_nOldHieght;
	int m_nNewWidth;
	int m_nNewHieght;
	BOOL m_bAspectRatio;
	int m_nInterpolation;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeNewWidth();
	afx_msg void OnEnChangeNewHeight();
	afx_msg void OnBnClickedAspectRatio();
};
