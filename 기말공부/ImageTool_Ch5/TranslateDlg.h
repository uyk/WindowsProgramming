#pragma once


// TranslateDlg 대화 상자입니다.

class TranslateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TranslateDlg)

public:
	TranslateDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TranslateDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TRANSLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nNewSX;
	int m_nNewSY;
};
