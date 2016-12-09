// RotateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyImageTool.h"
#include "RotateDlg.h"
#include "afxdialogex.h"


// CRotateDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRotateDlg, CDialogEx)

CRotateDlg::CRotateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRotateDlg::IDD, pParent)
	, m_nRotate(0)
	, m_fAngle(0)
{

}

CRotateDlg::~CRotateDlg()
{
}

void CRotateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_ROTATE1, m_nRotate);
	DDX_Text(pDX, IDC_ANGLE, m_fAngle);
	DDV_MinMaxFloat(pDX, m_fAngle, 0, 360);
}


BEGIN_MESSAGE_MAP(CRotateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ROTATE4, &CRotateDlg::OnBnClickedRotate4)
	ON_EN_SETFOCUS(IDC_ANGLE, &CRotateDlg::OnEnSetfocusAngle)
END_MESSAGE_MAP()


// CRotateDlg �޽��� ó�����Դϴ�.


void CRotateDlg::OnBnClickedRotate4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�..
	m_nRotate = 3;
	UpdateData(FALSE);
}


void CRotateDlg::OnEnSetfocusAngle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_ANGLE);
	pEdit->SetSel(0, -1);
	pEdit->SetFocus();
}