
// 1118View.cpp : CMy1118View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1118.h"
#endif

#include "1118Doc.h"
#include "1118View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1118View

IMPLEMENT_DYNCREATE(CMy1118View, CView)

BEGIN_MESSAGE_MAP(CMy1118View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_BN_CLICKED(101,onButtonClicked)
	ON_BN_CLICKED(107,onPush2Clicked)
	ON_BN_CLICKED(108,onPush3Clicked)

END_MESSAGE_MAP()

// CMy1118View ����/�Ҹ�

CMy1118View::CMy1118View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1118View::~CMy1118View()
{
}

BOOL CMy1118View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1118View �׸���

void CMy1118View::OnDraw(CDC* /*pDC*/)
{
	CMy1118Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1118View �μ�

BOOL CMy1118View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1118View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1118View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1118View ����

#ifdef _DEBUG
void CMy1118View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1118View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1118Doc* CMy1118View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1118Doc)));
	return (CMy1118Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1118View �޽��� ó����


int CMy1118View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_pushButton1.Create(_T("Ǫ�ù�ư1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20,20,160,50), this, 101);
	m_checkBox.Create(_T("üũ�ڽ�"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX , CRect(20,60,160,90), this, 102);
	m_3state.Create(_T("3���� üũ�ڽ�"), WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, CRect(20,100,160,130), this, 103);
	m_radio1.Create(_T("���� ��ư1"), WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(20,170,160,200), this, 104);
	m_radio2.Create(_T("���� ��ư2"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(20,210,160,240), this, 105);
	m_groupBox.Create(_T("�׷�ڽ�"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 140, 170, 250), this, 106);
	m_pushButton2.Create(_T("Ǫ�ù�ư2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20,250,160,300), this, 107);
	m_pushButton3.Create(_T("Ǫ�ù�ư3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20,310,160,360), this, 108);

	m_checkBox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);

	return 0;
}

void CMy1118View::onButtonClicked(void)
{
	int state_checkbox = m_checkBox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;

	str.Format(_T("��ư���� : %d, %d, %d, %d"), 
		state_checkbox, state_3state, state_radio1, state_radio1);

	MessageBox(str, _T("Button ����"), MB_ICONINFORMATION);
}

void CMy1118View::onPush2Clicked(void)
{
	CString push2;
	push2.Format(_T("Ǫ�ù�ư 2 �̺�Ʈ"));
	
	MessageBox(push2, _T("Button ����"), MB_ICONINFORMATION);
}


void CMy1118View::onPush3Clicked(void)
{
	
	CString push3;
	push3.Format(_T("Ǫ�ù�ư 3 �̺�Ʈ"));
	
	MessageBox(push3, _T("Button ����"), MB_ICONINFORMATION);
}