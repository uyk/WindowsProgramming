
// 1125_2View.cpp : CMy1125_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1125_2.h"
#endif

#include "1125_2Doc.h"
#include "1125_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1125_2View

IMPLEMENT_DYNCREATE(CMy1125_2View, CFormView)

BEGIN_MESSAGE_MAP(CMy1125_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1125_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy1125_2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy1125_2View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy1125_2View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy1125_2View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy1125_2View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy1125_2View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy1125_2View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy1125_2View::OnBnClickedButton9)
END_MESSAGE_MAP()

// CMy1125_2View 생성/소멸

CMy1125_2View::CMy1125_2View()
	: CFormView(CMy1125_2View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1125_2View::~CMy1125_2View()
{
}

void CMy1125_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_CHECK1, m_checkBox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
}

BOOL CMy1125_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy1125_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkBox.SetCheck(1);
	m_3state.SetCheck(1);
	m_radio2.SetCheck(1);
	m_edit.SetLimitText(20);

}


// CMy1125_2View 진단

#ifdef _DEBUG
void CMy1125_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy1125_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy1125_2Doc* CMy1125_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1125_2Doc)));
	return (CMy1125_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1125_2View 메시지 처리기


void CMy1125_2View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("1"));
}


void CMy1125_2View::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("2"));
}


void CMy1125_2View::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("3"));
}


void CMy1125_2View::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("4"));
}


void CMy1125_2View::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("5"));
}


void CMy1125_2View::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("6"));
}


void CMy1125_2View::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("7"));
}


void CMy1125_2View::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("8"));
}


void CMy1125_2View::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("9"));
}
