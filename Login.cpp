// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "SalarySys.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, Account);
	DDX_Text(pDX, IDC_EDIT_PWD, Pwd);
	DDX_Control(pDX, IDC_BUTTON_ENTER, Enter);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, Cancel);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_ACCOUNT, &CLoginDlg::OnEnChangeEditAccount)
	ON_EN_CHANGE(IDC_EDIT_PWD, &CLoginDlg::OnEnChangeEditPwd)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CLoginDlg::OnBnClickedButtonEnter)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CLoginDlg::OnBnClickedButtonCancel)
	ON_WM_CLOSE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLogin 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->SetWindowText(_T("登录系统"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void CLoginDlg::OnEnChangeEditAccount()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString Account;

}


void CLoginDlg::OnEnChangeEditPwd()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLoginDlg::OnBnClickedButtonEnter()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); //更新控件的数据到对应的变量

	CInfofile file; //创建操作文件类对象，需要头文件#include "InfoFile.h" 
	file.ReadDocline();
	if (file.ReadLoginAccount(Account))//用户名相等
	{
		if (!file.ReadLoginPwd(Pwd))
		{
			MessageBox(_T("密码错误"));
			Pwd.Empty();			//清空密码
		}
		else
		{
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("用户名不存在"));
		Account.Empty();		//清空账号
		Pwd.Empty();		//清空密码
	}
}


void CLoginDlg::OnBnClickedButtonCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);	//结束整个程序
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);		//结束整个程序
	CDialogEx::OnClose();
}

//编辑区回车键关闭对话框问题解决
void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	//加载位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP2);

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
