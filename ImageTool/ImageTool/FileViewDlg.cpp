// FileViewDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "FileViewDlg.h"
#include "afxdialogex.h"


// CFileViewDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFileViewDlg, CDialogEx)

CFileViewDlg::CFileViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileViewDlg::IDD, pParent)
	, m_nWidth(256)
	, m_nHeight(256)
	, m_nType(0)
{

}

CFileViewDlg::~CFileViewDlg()
{
}

void CFileViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WIDTH, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 1, 4096);
	DDX_Text(pDX, IDC_HEIGHT, m_nHeight);
	DDV_MinMaxInt(pDX, m_nHeight, 1, 4096);
	DDX_CBIndex(pDX, IDC_IMAGE_TYPE, m_nType);
}


BEGIN_MESSAGE_MAP(CFileViewDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileViewDlg 메시지 처리기입니다.
