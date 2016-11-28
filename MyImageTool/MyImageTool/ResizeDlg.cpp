// ResizeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyImageTool.h"
#include "ResizeDlg.h"
#include "afxdialogex.h"


// CResizeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CResizeDlg, CDialogEx)

CResizeDlg::CResizeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CResizeDlg::IDD, pParent)
	, m_nOldWidth(0)
	, m_nOldHieght(0)
	, m_nNewWidth(0)
	, m_nNewHieght(0)
	, m_bAspectRatio(FALSE)
	, m_nInterpolation(0)
{

}

CResizeDlg::~CResizeDlg()
{
}

void CResizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_OLD_WIDTH, m_nOldWidth);
	DDX_Text(pDX, IDC_OLD_HEIGHT, m_nOldHieght);
	DDX_Text(pDX, IDC_NEW_WIDTH, m_nNewWidth);
	DDV_MinMaxInt(pDX, m_nNewWidth, 1, 4096);
	DDX_Text(pDX, IDC_NEW_HEIGHT, m_nNewHieght);
	DDV_MinMaxInt(pDX, m_nNewHieght, 1, 4096);
	DDX_Check(pDX, IDC_ASPECT_RATIO, m_bAspectRatio);
	DDX_CBIndex(pDX, IDC_INTERPOLATION, m_nInterpolation);
}


BEGIN_MESSAGE_MAP(CResizeDlg, CDialogEx)
	ON_EN_CHANGE(IDC_NEW_WIDTH, &CResizeDlg::OnEnChangeNewWidth)
	ON_EN_CHANGE(IDC_NEW_HEIGHT, &CResizeDlg::OnEnChangeNewHeight)
	ON_BN_CLICKED(IDC_ASPECT_RATIO, &CResizeDlg::OnBnClickedAspectRatio)
END_MESSAGE_MAP()


// CResizeDlg �޽��� ó�����Դϴ�.


BOOL CResizeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_WIDTH))->SetRange(1, 4096);
	((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_HEIGHT))->SetRange(1, 4096);

	m_nNewWidth = m_nOldWidth;
	m_nNewHieght = m_nOldHieght;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CResizeDlg::OnEnChangeNewWidth()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (GetDlgItem(IDC_INTERPOLATION) == NULL)
		return;

	if (m_bAspectRatio)
	{
		UpdateData(TRUE);
		m_nNewHieght = m_nNewWidth * m_nOldHieght / m_nOldWidth;
		UpdateData(FALSE);
	}
}


void CResizeDlg::OnEnChangeNewHeight()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (GetDlgItem(IDC_INTERPOLATION) == NULL)
		return;

	if (m_bAspectRatio)
	{
		UpdateData(TRUE);
		m_nNewWidth = m_nNewHieght * m_nOldWidth / m_nOldHieght;
		UpdateData(FALSE);
	}
}


void CResizeDlg::OnBnClickedAspectRatio()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);

	if (m_bAspectRatio)
	{
		m_nNewHieght = m_nNewWidth * m_nOldHieght / m_nOldWidth;
		UpdateData(FALSE);
	}
}
