
// MyImageToolDoc.h : CMyImageToolDoc Ŭ������ �������̽�
//


#pragma once
#include "./IppImage/IppDib.h"

class CMyImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMyImageToolDoc();
	DECLARE_DYNCREATE(CMyImageToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMyImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
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
};
