// BrightnessContrastDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "BrightnessContrastDlg.h"
#include "afxdialogex.h"


// CBrightnessContrastDlg 대화 상자입니다.

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


// CBrightnessContrastDlg 메시지 처리기입니다.


BOOL CBrightnessContrastDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// 밝기 조절 슬라이더 컨트롤 초기화
	m_SliderBrightness.SetRange(-255, 255);
	m_SliderBrightness.SetTicFreq(32);
	m_SliderBrightness.SetPageSize(32);

	// 명암비 조절 슬라이더 컨트롤 초기화
	m_sliderContrast.SetRange(-100, 100);
	m_sliderContrast.SetTicFreq(20);
	m_sliderContrast.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBrightnessContrastDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 밝기 조절 슬라이드바에서 발생한 WM_HSCROLL 메시지 처리
	if (m_SliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_Brightness = m_SliderBrightness.GetPos();
		UpdateData(FALSE);
	}
	// 명암비 조절 슬라이드바에서 발생한 WM_HSCROLL 메시지 처리
	else if (m_sliderContrast.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_nContrast = m_sliderContrast.GetPos();
		UpdateData(FALSE);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CBrightnessContrastDlg::OnEnChangeBrightnessEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	UpdateData(TRUE);
	m_SliderBrightness.SetPos(m_Brightness);
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CBrightnessContrastDlg::OnEnChangeContastEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.
	UpdateData(TRUE);
	m_sliderContrast.SetPos(m_nContrast);
	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


//void CBrightnessContrastDlg::OnBrightnessContrast()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//}
