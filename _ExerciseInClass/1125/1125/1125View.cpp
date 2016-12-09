
// 1125View.cpp : CMy1125View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1125.h"
#endif

#include "1125Doc.h"
#include "1125View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1125View

IMPLEMENT_DYNCREATE(CMy1125View, CFormView)

BEGIN_MESSAGE_MAP(CMy1125View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy1125View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy1125View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy1125View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy1125View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy1125View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy1125View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy1125View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy1125View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy1125View::OnBnClickedButton9)
END_MESSAGE_MAP()

// CMy1125View 생성/소멸

CMy1125View::CMy1125View()
	: CFormView(CMy1125View::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1125View::~CMy1125View()
{
}

void CMy1125View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio);
	DDX_Control(pDX, IDC_RADIO3, m_radio2);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL CMy1125View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy1125View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(1);
	m_3state.SetCheck(1);
	m_radio2.SetCheck(1);
	m_edit.SetLimitText(20);
}


// CMy1125View 진단

#ifdef _DEBUG
void CMy1125View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy1125View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy1125Doc* CMy1125View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1125Doc)));
	return (CMy1125Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1125View 메시지 처리기


void CMy1125View::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태 : %d, %d, %d, %d"),
		state_checkbox, state_3state, state_radio1, state_radio2);
	//MessageBox(str, _T("Button2 예제"),MB_ICONINFORMATION);
	m_edit.SetWindowTextW(str);
	*/
	//m_edit.GetWindowTextW(str);
	//str += "test";
	//m_edit.SetWindowTextW(str);
	m_edit.SetWindowTextW(_T("1"));
	

}
//계산기처럼. 푸시버튼 9개 가져와서 1누르면 1들어가는 

void CMy1125View::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("2"));
}


void CMy1125View::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("3"));
}


void CMy1125View::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("4"));
}


void CMy1125View::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("5"));
}


void CMy1125View::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("6"));
}


void CMy1125View::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("7"));
}


void CMy1125View::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("8"));
}


void CMy1125View::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_edit.SetWindowTextW(_T("9"));
}
