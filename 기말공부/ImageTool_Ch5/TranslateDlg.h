#pragma once


// TranslateDlg ��ȭ �����Դϴ�.

class TranslateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TranslateDlg)

public:
	TranslateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~TranslateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TRANSLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nNewSX;
	int m_nNewSY;
};
