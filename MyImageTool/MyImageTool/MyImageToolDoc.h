
// MyImageToolDoc.h : CMyImageToolDoc 클래스의 인터페이스
//


#pragma once
#include "./IppImage/IppDib.h"

class CMyImageToolDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMyImageToolDoc();
	DECLARE_DYNCREATE(CMyImageToolDoc)

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
	virtual ~CMyImageToolDoc();
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
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	afx_msg void OnWindowDuplicate();
	afx_msg void OnImageInverse();
	afx_msg void OnBrightnessContrast();
	afx_msg void OnViewHistogram();
	afx_msg void OnHistoStretching();
	afx_msg void OnHistoEqualization();
	afx_msg void OnArithmeticLogical();
	afx_msg void OnAddNoise();
	afx_msg void OnImageTranslate();
	afx_msg void OnImageResize();
	afx_msg void OnImageRotate();
	afx_msg void OnImageMirror();
	afx_msg void OnImageFlip();
	afx_msg void OnColorSplitRgb();
	afx_msg void OnColorSplitHsi();
	afx_msg void OnColorSplitYuv();
	afx_msg void OnUpdateColorSplitRgb(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorSplitHsi(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorSplitYuv(CCmdUI *pCmdUI);
	afx_msg void OnColorCombineRgb();
	afx_msg void OnColorCombineHsi();
	afx_msg void OnColorCombineYuv();
	afx_msg void OnColorEdge();
	afx_msg void OnUpdateColorEdge(CCmdUI *pCmdUI);
};
