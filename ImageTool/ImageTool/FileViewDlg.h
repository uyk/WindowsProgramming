#pragma once


// CFileViewDlg ��ȭ �����Դϴ�.

class CFileViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileViewDlg)

public:
	CFileViewDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileViewDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILE_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nWidth;
	int m_nHeight;
	int m_nType;
};
