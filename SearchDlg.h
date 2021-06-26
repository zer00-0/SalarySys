#pragma once
#include "afxcmn.h"
#include "Infofile.h"


// CSearchDlg ������ͼ

class CSearchDlg : public CFormView
{
	DECLARE_DYNCREATE(CSearchDlg)

protected:
	CSearchDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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


