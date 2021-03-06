// ImageToolDoc.h : CImageToolDoc 클래스의 인터페이스
//


#pragma once

#include "dib.h"

class CImageToolDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 구현입니다.
public:
	virtual ~CImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

public:
	// 이미지 객체
	CDib m_Dib;

	// 파일 불러오기 & 저장하기
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);

public:
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();
	afx_msg void OnBrightnessContrast();
	afx_msg void OnImageInverse();
	afx_msg void OnViewHistogram();
	afx_msg void OnHistoStretching();
	afx_msg void OnHistoEqualization();
//	afx_msg void OnBnClickedOk();
	afx_msg void OnArithmetic();
	afx_msg void OnFilterGaussian();
	afx_msg void OnAddNoise();
	afx_msg void OnTranslate();
	afx_msg void OnColorSplitRgb();
	afx_msg void OnColorSplitHsi();
	afx_msg void OnColorSplitYuv();
};
