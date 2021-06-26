#pragma once
#include "afxwin.h"
#include "Infofile.h"

// CLogin 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString Account;
	CString Pwd;
	CButton Enter;
	CButton Cancel;
public:
	afx_msg void OnEnChangeEditAccount();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEditPwd();
	afx_msg void OnBnClickedButtonEnter();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnClose();
	virtual void OnOK();
	afx_msg void OnPaint();
};
