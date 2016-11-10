
// Assignment_2Doc.h : CAssignment_2Doc 클래스의 인터페이스
//


#pragma once

#include "./IppImage/IppDib.h"


class CAssignment_2Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CAssignment_2Doc();
	DECLARE_DYNCREATE(CAssignment_2Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CAssignment_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	IppDib m_Dib;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);		//lpaszPathName : 선택된 파일의 전체 경로 문자열
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	afx_msg void OnImageInverse();
	afx_msg void OnBrightnessContrast();
	afx_msg void OnViewHistogram();
	afx_msg void OnHistoStretching();
	afx_msg void OnHistoEqualization();
};
