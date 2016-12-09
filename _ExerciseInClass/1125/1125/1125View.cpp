
// 1125View.cpp : CMy1125View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CMy1125View ����/�Ҹ�

CMy1125View::CMy1125View()
	: CFormView(CMy1125View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

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


// CMy1125View ����

#ifdef _DEBUG
void CMy1125View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy1125View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy1125Doc* CMy1125View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1125Doc)));
	return (CMy1125Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1125View �޽��� ó����


void CMy1125View::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	/*
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("��ư ���� : %d, %d, %d, %d"),
		state_checkbox, state_3state, state_radio1, state_radio2);
	//MessageBox(str, _T("Button2 ����"),MB_ICONINFORMATION);
	m_edit.SetWindowTextW(str);
	*/
	//m_edit.GetWindowTextW(str);
	//str += "test";
	//m_edit.SetWindowTextW(str);
	m_edit.SetWindowTextW(_T("1"));
	

}
//����ó��. Ǫ�ù�ư 9�� �����ͼ� 1������ 1���� 

void CMy1125View::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("2"));
}


void CMy1125View::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("3"));
}


void CMy1125View::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("4"));
}


void CMy1125View::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("5"));
}


void CMy1125View::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("6"));
}


void CMy1125View::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("7"));
}


void CMy1125View::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("8"));
}


void CMy1125View::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_edit.SetWindowTextW(_T("9"));
}
