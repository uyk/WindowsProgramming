// TranslateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyImageTool.h"
#include "TranslateDlg.h"
#include "afxdialogex.h"


// CTranslateDlg ��ȭ �����Դϴ�.

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


// CTranslateDlg �޽��� ó�����Դϴ�.


void CTranslateDlg::OnEnChangeNewSx()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
