
// 0927_Ch05_ImageTool_02Doc.h : CMy0927_Ch05_ImageTool_02Doc Ŭ������ �������̽�
//


#pragma once
#include "Dib.h"


class CMy0927_Ch05_ImageTool_02Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMy0927_Ch05_ImageTool_02Doc();
	DECLARE_DYNCREATE(CMy0927_Ch05_ImageTool_02Doc)

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
	virtual ~CMy0927_Ch05_ImageTool_02Doc();
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
	// �̹��� ��ü
	CDib m_Dib;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
};
