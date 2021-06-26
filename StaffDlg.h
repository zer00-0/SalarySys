#pragma once
#include "afxcmn.h"
#include "Infofile.h"


// CStaffDlg ������ͼ

class CStaffDlg : public CFormView
{
	DECLARE_DYNCREATE(CStaffDlg)

protected:
	CStaffDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CStaffDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STAFF };
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
private:
	CListCtrl m_list;
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual void OnInitialUpdate();
private:
	CString s_TotalStaff;
	CString s_TotalSalary;
	CString s_TotalTax;
public:
private:
	CString Add_account;
	CString Add_name;
	CString Add_pwd;
	CString Add_position;
	CString Add_workyear;
	CString Add_salary;
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedButtonGetmessage();
	int ListLine;		//��¼�б�����Ϣ
//	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* /*pDC*/);
};


