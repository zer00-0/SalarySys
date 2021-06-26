// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SalarySys.h"
#include "UserDlg.h"
#include "Infofile.h"
#include "GlobalVal.h"
// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(IDD_DIALOG_USER)
	, Account(_T(""))
	, Position(_T(""))
	, Pwd1(_T(""))
	, Pwd2(_T(""))
	, Workyear(_T(""))
	, Salary(_T(""))
	, Tax(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_POSITION, Account);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, Position);
	DDX_Text(pDX, IDC_EDIT_NEWPWD1, Pwd1);
	DDX_Text(pDX, IDC_EDIT_NEWPWD2, Pwd2);
	DDX_Text(pDX, IDC_EDIT_WORKYEAR, Workyear);
	DDX_Text(pDX, IDC_EDIT_SALARY, Salary);
	DDX_Text(pDX, IDC_EDIT_TAX, Tax);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CUserDlg::OnBnClickedButtonEnter)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CUserDlg::OnBnClickedButtonCancel)
	ON_EN_CHANGE(IDC_EDIT_POSITION, &CUserDlg::OnEnChangeEditPosition)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnBnClickedButtonEnter()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); //拿到最新值


	if (Pwd1.IsEmpty() || Pwd2.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空！"));
		return;
	}

	//新密码和确定密码要一致
	if (Pwd1 != Pwd2)
	{
		MessageBox(TEXT("新密码与确定密码要一致！"));
		return;
	}
	if (Pwd1 == old_Pwd) {
		MessageBox(TEXT("新密码与旧密码不能一致！"));
		return;
	}
	CInfofile file;
	file.ReadDocline();
	for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
		if (it->m_Account == now_account) {
			it->m_PWD = Pwd1;
		}
	}
	file.WirteDocline();
	AfxMessageBox(_T("修改密码成功！"));

	Pwd1.Empty();
	Pwd2.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButtonCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	Pwd1.Empty();
	Pwd2.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	CInfofile file;
	file.ReadDocline();
	for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
		if (it->m_Account == now_account) {
			Position = it->m_Psition;
			Account = it->m_Account;
			Workyear = it->m_WorkYear;
			Salary = it->m_Salary;
			old_Pwd = it->m_PWD;
			Tax = it->m_Tax;
		}
	}

	// TODO: 在此添加专用代码和/或调用基类
	UpdateData(FALSE);
}




void CUserDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	//加载位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP6);

	//选入DC
	CClientDC cdc(this);
	CDC comdc;
	comdc.CreateCompatibleDC(&cdc);
	comdc.SelectObject(&bitmap);

	//生成BITMAP
	BITMAP bit;
	bitmap.GetBitmap(&bit);

	//客户区域
	CRect rect;
	GetClientRect(rect);

	cdc.SetStretchBltMode(HALFTONE);   //解决图形失真问题
									   //用客户区的DC绘制所生成的BITMAP，并适应为窗口大小
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &comdc, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);

}


void CUserDlg::OnEnChangeEditPosition()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
