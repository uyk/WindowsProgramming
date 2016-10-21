// BriDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "1010_ImageTool.h"
#include "BriDlg.h"
#include "afxdialogex.h"


// CBriDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBriDlg, CDialogEx)

CBriDlg::CBriDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBriDlg::IDD, pParent)
	, m_nBrightness(0)
	, m_nContrast(0)
	//, m_nContrast(0)
{

}

CBriDlg::~CBriDlg()
{
}

void CBriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BRI_EDIT, m_BRI_EDIT);
	DDX_Text(pDX, IDC_BRI_EDIT, m_nBrightness);
	DDV_MinMaxInt(pDX, m_nBrightness, -255, 255);
	DDX_Control(pDX, IDC_BRI_SLIDER, m_sliderBrightness);
	//DDX_Text(pDX, IDC_EDIT2, m_nContrast);
	DDV_MinMaxInt(pDX, m_nContrast, -100, 100);
	DDX_Control(pDX, IDC_CONT_SLIDER, m_sliderContrast);
	DDX_Text(pDX, IDC_CONT_EDIT, m_nContrast);
}


BEGIN_MESSAGE_MAP(CBriDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_BRI_EDIT, &CBriDlg::OnEnChangeBriEdit)
	ON_EN_CHANGE(IDC_CONT_EDIT, &CBriDlg::OnEnChangeContEdit)
END_MESSAGE_MAP()


// CBriDlg �޽��� ó�����Դϴ�.


BOOL CBriDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//��� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_sliderBrightness.SetRange(-255,255);
	m_sliderBrightness.SetTicFreq(32);
	m_sliderBrightness.SetPageSize(32);

	//��� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_sliderContrast.SetRange(-100,100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CBriDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(m_sliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd()) {
		m_nBrightness = m_sliderBrightness.GetPos();
		UpdateData(FALSE);
	}
	else if(m_sliderContrast.GetSafeHwnd() == pScrollBar->GetSafeHwnd()) {
		m_nContrast = m_sliderContrast.GetPos();
		UpdateData(FALSE);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CBriDlg::OnEnChangeBriEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);
	m_sliderBrightness.SetPos(m_nBrightness);
}


void CBriDlg::OnEnChangeContEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
}
