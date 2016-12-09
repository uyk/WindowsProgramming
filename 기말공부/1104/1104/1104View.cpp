
// 1104View.cpp : CMy1104View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1104.h"
#endif

#include "1104Doc.h"
#include "1104View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1104View

IMPLEMENT_DYNCREATE(CMy1104View, CView)

BEGIN_MESSAGE_MAP(CMy1104View, CView)
END_MESSAGE_MAP()

// CMy1104View 생성/소멸

CMy1104View::CMy1104View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1104View::~CMy1104View()
{
}

BOOL CMy1104View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1104View 그리기

void CMy1104View::OnDraw(CDC* /*pDC*/)
{
	CMy1104Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy1104View 진단

#ifdef _DEBUG
void CMy1104View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1104View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1104Doc* CMy1104View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1104Doc)));
	return (CMy1104Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1104View 메시지 처리기
