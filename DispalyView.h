#pragma once



// CDispalyView ������ͼ

class CDispalyView : public CFormView
{
	DECLARE_DYNCREATE(CDispalyView)

protected:
	CDispalyView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDispalyView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISPALYVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


