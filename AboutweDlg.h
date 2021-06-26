#pragma once



// CAboutweDlg 窗体视图

class CAboutweDlg : public CFormView
{
	DECLARE_DYNCREATE(CAboutweDlg)

protected:
	CAboutweDlg();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnEnChangeEditAboutwe();
	virtual void OnDraw(CDC* /*pDC*/);
};


