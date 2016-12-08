// ArithmeticDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "ArithmeticDlg.h"
#include "afxdialogex.h"

#include "ImageToolDoc.h"

// CArithmeticDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CArithmeticDlg, CDialogEx)

CArithmeticDlg::CArithmeticDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CArithmeticDlg::IDD, pParent)
	, m_nFunction(0)
	, m_pDoc1(NULL)
	, m_pDoc2(NULL)
{

}

CArithmeticDlg::~CArithmeticDlg()
{
}

void CArithmeticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Radio(pDX, IDC_FUNCTION1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CArithmeticDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CArithmeticDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CArithmeticDlg �޽��� ó�����Դϴ�.


BOOL CArithmeticDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	int nIndex = 0;
	CString strTitle;
	CImageToolApp* pApp = (CImageToolApp*)AfxGetApp();
	CImageToolDoc* pDoc = NULL;
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while( pos != NULL )
	{
		pDoc = (CImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);
		strTitle = pDoc->GetTitle();

		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if( nIndex > 1 ) m_comboImage2.SetCurSel(1);

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CArithmeticDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDoc1 = (CImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());

	//OnOK();
	CDialogEx::OnOK();
}
