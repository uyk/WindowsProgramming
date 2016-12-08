// ColorCombineDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyImageTool.h"
#include "ColorCombineDlg.h"
#include "afxdialogex.h"

#include "MyImageToolDoc.h"

// CColorCombineDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CColorCombineDlg, CDialogEx)

CColorCombineDlg::CColorCombineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorCombineDlg::IDD, pParent)
	, m_strColorSpace(_T(""))
{

}

CColorCombineDlg::~CColorCombineDlg()
{
}

void CColorCombineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COLOR_SPACE, m_strColorSpace);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Control(pDX, IDC_COMBO_IMAGE3, m_comboImage3);
}


BEGIN_MESSAGE_MAP(CColorCombineDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CColorCombineDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CColorCombineDlg �޽��� ó�����Դϴ�.


BOOL CColorCombineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	int nIndex = 0;
	CString strTitle;
	CMyImageToolApp* pApp = (CMyImageToolApp*)AfxGetApp();
	CMyImageToolDoc* pDoc = NULL;
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while (pos != NULL)
	{
		pDoc = (CMyImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);
		if (pDoc->m_Dib.GetBitCount() != 8) continue;

		strTitle = pDoc->GetTitle();

		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);
		m_comboImage3.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage3.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	if (nIndex == 0)
	{
		AfxMessageBox(_T("�׷��̽����� ������ �����ϴ�."));
		SendMessage(WM_COMMAND, IDCANCEL, 0);
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	m_comboImage3.SetCurSel(0);
	if (nIndex > 1) m_comboImage2.SetCurSel(1);
	if (nIndex > 2) m_comboImage3.SetCurSel(2);


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CColorCombineDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDoc1 = (CMyImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CMyImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());
	m_pDoc3 = (CMyImageToolDoc*)m_comboImage3.GetItemDataPtr(m_comboImage3.GetCurSel());

	CDialogEx::OnOK();
}
