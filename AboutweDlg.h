#pragma once



// CAboutweDlg ������ͼ

class CAboutweDlg : public CFormView
{
	DECLARE_DYNCREATE(CAboutweDlg)

protected:
	CAboutweDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAboutweDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PERSON };
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
public:
	virtual void OnInitialUpdate();
	afx_msg void OnEnChangeEditAboutwe();
	virtual void OnDraw(CDC* /*pDC*/);
};


