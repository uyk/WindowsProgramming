// TranslateDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyImageTool.h"
#include "TranslateDlg.h"
#include "afxdialogex.h"


// CTranslateDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTranslateDlg, CDialogEx)

CTranslateDlg::CTranslateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTranslateDlg::IDD, pParent)
	, m_nNewSX(0)
	, m_nNewSY(0)
{

}

CTranslateDlg::~CTranslateDlg()
{
}

void CTranslateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEW_SX, m_nNewSX);
	DDX_Text(pDX, IDC_NEW_SY, m_nNewSY);
}


BEGIN_MESSAGE_MAP(CTranslateDlg, CDialogEx)
	ON_EN_CHANGE(IDC_NEW_SX, &CTranslateDlg::OnEnChangeNewSx)
END_MESSAGE_MAP()


// CTranslateDlg 메시지 처리기입니다.


void CTranslateDlg::OnEnChangeNewSx()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
