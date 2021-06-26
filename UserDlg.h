#pragma once
#include "Infofile.h"


// CUserDlg ������ͼ

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_USER };
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
	CString Account;
	CString Position;
	CString Pwd1;
	CString Pwd2;
public:
	afx_msg void OnBnClickedButtonEnter();
	afx_msg void OnBnClickedButtonCancel();
	virtual void OnInitialUpdate();
private:
	CString Workyear;
	CString Salary;
	CString Tax;
	CString old_Pwd;
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg void OnEnChangeEditPosition();
};


