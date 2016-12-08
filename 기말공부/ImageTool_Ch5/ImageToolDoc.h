// ImageToolDoc.h : CImageToolDoc Ŭ������ �������̽�
//


#pragma once

#include "dib.h"

class CImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

public:
	// �̹��� ��ü
	CDib m_Dib;

	// ���� �ҷ����� & �����ϱ�
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
