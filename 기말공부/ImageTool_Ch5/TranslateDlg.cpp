// TranslateDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "TranslateDlg.h"
#include "afxdialogex.h"


// TranslateDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TranslateDlg, CDialogEx)

TranslateDlg::TranslateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(TranslateDlg::IDD, pParent)
	, m_nNewSX(0)
	, m_nNewSY(0)
{

}

TranslateDlg::~TranslateDlg()
{
}

void TranslateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEW_SX, m_nNewSX);
	DDX_Text(pDX, IDC_NEW_SY, m_nNewSY);
}


BEGIN_MESSAGE_MAP(TranslateDlg, CDialogEx)
END_MESSAGE_MAP()


// TranslateDlg �޽��� ó�����Դϴ�.
