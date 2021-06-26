#pragma once
#include "afxcmn.h"
#include "Infofile.h"


// CSearchDlg 窗体视图

class CSearchDlg : public CFormView
{
	DECLARE_DYNCREATE(CSearchDlg)

protected:
	CSearchDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CSearchDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCH };
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
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	CString Search_account;
	CString Search_name;
public:
	afx_msg void OnBnClickedButtonSearch();
private:
	CListCtrl m_list;
public:
	virtual void OnInitialUpdate();
	virtual void OnDraw(CDC* /*pDC*/);
};


