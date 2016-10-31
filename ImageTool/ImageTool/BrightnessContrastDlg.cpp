// BrightnessContrastDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "BrightnessContrastDlg.h"
#include "afxdialogex.h"


// CBrightnessContrastDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBrightnessContrastDlg, CDialogEx)

CBrightnessContrastDlg::CBrightnessContrastDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBrightnessContrastDlg::IDD, pParent)
	, m_Brightness(0)
	, m_nContrast(0)
{

}

CBrightnessContrastDlg::~CBrightnessContrastDlg()
{
}

void CBrightnessContrastDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BRIGHTNESS_SLIDER, m_SliderBrightness);
	DDX_Text(pDX, IDC_BRIGHTNESS_EDIT, m_Brightness);
	DDV_MinMaxInt(pDX, m_Brightness, -255, 255);
	DDX_Control(pDX, IDC_CONTRAST_SLIDER, m_sliderContrast);
	DDX_Text(pDX, IDC_CONTAST_EDIT, m_nContrast);
	DDV_MinMaxInt(pDX, m_nContrast, -100, 100);
}


BEGIN_MESSAGE_MAP(CBrightnessContrastDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_BRIGHTNESS_EDIT, &CBrightnessContrastDlg::OnEnChangeBrightnessEdit)
	ON_EN_CHANGE(IDC_CONTAST_EDIT, &CBrightnessContrastDlg::OnEnChangeContastEdit)
	//ON_COMMAND(ID_BRIGHTNESS_CONTRAST, &CBrightnessContrastDlg::OnBrightnessContrast)
END_MESSAGE_MAP()


// CBrightnessContrastDlg �޽��� ó�����Դϴ�.


BOOL CBrightnessContrastDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	// ��� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_SliderBrightness.SetRange(-255, 255);
	m_SliderBrightness.SetTicFreq(32);
	m_SliderBrightness.SetPageSize(32);

	// ��Ϻ� ���� �����̴� ��Ʈ�� �ʱ�ȭ
	m_sliderContrast.SetRange(-100, 100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CBrightnessContrastDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ��� ���� �����̵�ٿ��� �߻��� WM_HSCROLL �޽��� ó��
	if (m_SliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_Brightness = m_SliderBrightness.GetPos();
		UpdateData(FALSE);
	}
	// ��Ϻ� ���� �����̵�ٿ��� �߻��� WM_HSCROLL �޽��� ó��
	else if (m_sliderContrast.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_nContrast = m_sliderContrast.GetPos();
		UpdateData(FALSE);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CBrightnessContrastDlg::OnEnChangeBrightnessEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	m_SliderBrightness.SetPos(m_Brightness);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CBrightnessContrastDlg::OnEnChangeContastEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


//void CBrightnessContrastDlg::OnBrightnessContrast()
//{
//	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
//}
