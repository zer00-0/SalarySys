// StaffDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SalarySys.h"
#include "StaffDlg.h"


// CStaffDlg

IMPLEMENT_DYNCREATE(CStaffDlg, CFormView)

CStaffDlg::CStaffDlg()
	: CFormView(IDD_DIALOG_STAFF)
	, s_TotalStaff(_T(""))
	, s_TotalSalary(_T(""))
	, s_TotalTax(_T(""))
	, Add_account(_T(""))
	, Add_name(_T(""))
	, Add_pwd(_T(""))
	, Add_position(_T(""))
	, Add_workyear(_T(""))
	, Add_salary(_T(""))
	, ListLine(0)
{

}

CStaffDlg::~CStaffDlg()
{
}

void CStaffDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	/*DDX_Text(pDX, IDC_LIST1, m_list);*/
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_PEOPLE, s_TotalStaff);
	DDX_Text(pDX, IDC_SUM, s_TotalSalary);
	DDX_Text(pDX, IDC_SHUI, s_TotalTax);
	DDX_Text(pDX, IDC_EDIT1, Add_account);
	DDX_Text(pDX, IDC_EDIT4, Add_name);
	DDX_Text(pDX, IDC_EDIT2, Add_pwd);
	DDX_Text(pDX, IDC_EDIT6, Add_position);
	DDX_Text(pDX, IDC_EDIT5, Add_workyear);
	DDX_Text(pDX, IDC_EDIT3, Add_salary);
}

BEGIN_MESSAGE_MAP(CStaffDlg, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CStaffDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CStaffDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CStaffDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CStaffDlg::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_GETMESSAGE, &CStaffDlg::OnBnClickedButtonGetmessage)
END_MESSAGE_MAP()


// CStaffDlg 诊断

#ifdef _DEBUG
void CStaffDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CStaffDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CStaffDlg 消息处理程序


void CStaffDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CStaffDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	// 设置扩展风格
	//LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString field[] = { _T("账号"), _T("姓名"), _T("职称"), _T("工龄"), _T("工资"), _T("税金")};
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	//需要包含#include "InfoFile.h"
	CInfofile file;
	file.ReadDocline(); //读取商品信息

						//添加数据
	int i = 0;
	CString str;
	int TotalSalary = 0;
	double TotalTax = 0;
	for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++)
	{
		str.Format(_T("%s"), it->m_Account);
		m_list.InsertItem(i, str);
		int column = 1;
		m_list.SetItemText(i, column++, it->m_Name);
		str.Format(_T("%s"), it->m_Psition);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%s"), it->m_WorkYear);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%s"), it->m_Salary);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%s"), it->m_Tax);
		m_list.SetItemText(i, column++, str);
		TotalTax += _ttoi(_T(it->m_Tax));
		TotalSalary += _ttoi(_T(it->m_Salary));
		i++;
	}
	s_TotalStaff.Format( _T("%d"),file.MessVec.size());
	s_TotalSalary.Format(_T("%d"), TotalSalary);
	s_TotalTax.Format(_T("%f"), TotalTax);
	UpdateData(FALSE);
}





void CStaffDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfofile file;
	file.ReadDocline(); //读取员工信息
	for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
		if (it->m_Account == Add_account) {
			AfxMessageBox(_T("账号重复！"));
			return;
		}
	}
	message mes;
	mes.m_Account = Add_account;
	mes.m_Name = Add_name;
	mes.m_Psition = Add_position;
	mes.m_PWD = Add_pwd;
	mes.m_Salary = Add_salary;
	mes.m_WorkYear = Add_workyear;
	if (Add_account == "" || Add_name == "" || Add_position == "" || Add_pwd == "" || Add_salary == "" || Add_workyear == "") {
		AfxMessageBox(_T("数据不全！"));
	}
	else {
		int len = file.MessVec.size()+1;
		file.MessVec.push_back(mes);
		CString str;
		//m_list.ModifyStyle(0, LVS_REPORT);
		m_list.ModifyStyleEx(0, LVS_EX_FULLROWSELECT);
		str.Format(_T("%s"), mes.m_Account);
		m_list.InsertItem(len, str);
		str.Format(_T("%s"), mes.m_Name);
		m_list.SetItemText(len, 1,str);
		str.Format(_T("%s"), mes.m_Psition);
		m_list.SetItemText(len, 2,str);
		str.Format(_T("%s"), mes.m_WorkYear);
		m_list.SetItemText(len, 3, str);
		str.Format(_T("%s"), mes.m_Salary);
		m_list.SetItemText(len, 4, str);
		AfxMessageBox(_T("添加成功！"));
		file.WirteDocline();

	}
	Add_account.Empty();
	Add_name.Empty();
	Add_position.Empty();
	Add_pwd.Empty();
	Add_salary.Empty();
	Add_workyear.Empty();
	UpdateData(FALSE);
}


void CStaffDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CInfofile file;
	file.ReadDocline(); //读取员工信息
	POSITION p1 = m_list.GetFirstSelectedItemPosition();    //获取所选中行位置
	int i = m_list.GetNextSelectedItem(p1);
	file.MessVec.erase(file.MessVec.begin() + i);
	file.WirteDocline();
	POSITION p = m_list.GetFirstSelectedItemPosition();    //获取所选中行位置
	while (p)
	{
		int  nSelected = m_list.GetNextSelectedItem(p); //获取选中行的索引
		m_list.DeleteItem(nSelected); //根据索引删除
		p = m_list.GetFirstSelectedItemPosition();
	}

	AfxMessageBox(_T("删除成功！"));
	file.WirteDocline();
	Add_account.Empty();
	Add_name.Empty();
	Add_position.Empty();
	Add_pwd.Empty();
	Add_salary.Empty();
	Add_workyear.Empty();
	UpdateData(FALSE);

}



void CStaffDlg::OnBnClickedButtonChange()
{
	
	// TODO: 在此添加控件通知处理程序代码
	CInfofile file;
	file.ReadDocline(); //读取员工信息

	if (Add_account == "" || Add_name == "" || Add_position == "" || Add_pwd == "" || Add_salary == "" || Add_workyear == "") {
		AfxMessageBox(_T("数据不全！"));
	}
	else {
		UpdateData(TRUE);
		file.MessVec[ListLine ].m_Account = Add_account;
		file.MessVec[ListLine].m_Name = Add_name;
		file.MessVec[ListLine].m_Psition = Add_position;
		file.MessVec[ListLine].m_WorkYear = Add_workyear;
		file.MessVec[ListLine].m_Salary = Add_salary;
		file.MessVec[ListLine].m_PWD = Add_pwd;
		AfxMessageBox(_T("修改信息成功！"));
	}
	file.WirteDocline();
	Add_account.Empty();
	Add_name.Empty();
	Add_position.Empty();
	Add_pwd.Empty();
	Add_salary.Empty();
	Add_workyear.Empty();
	UpdateData(FALSE);
}


void CStaffDlg::OnBnClickedButtonGetmessage()
{
	Add_account.Empty();
	Add_name.Empty();
	Add_position.Empty();
	Add_pwd.Empty();
	Add_salary.Empty();
	Add_workyear.Empty();
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
	POSITION p = m_list.GetFirstSelectedItemPosition();    //获取所选中行位置
	ListLine = m_list.GetNextSelectedItem(p);
	if (ListLine < 0) {
		AfxMessageBox(_T("未选中列表行！"));
		return;
	}
	CInfofile file;
	file.ReadDocline(); //读取员工信息

						//((CEdit*)GetDlgItem(IDC_EDIT1))->SetDlgItemText(IDC_EDIT1, file.MessVec[i - 1].m_Account);

	Add_account = file.MessVec[ListLine].m_Account;
	Add_name = file.MessVec[ListLine].m_Name;
	Add_position = file.MessVec[ListLine].m_Psition;
	Add_workyear = file.MessVec[ListLine].m_WorkYear;
	Add_pwd = file.MessVec[ListLine].m_PWD;
	Add_salary = file.MessVec[ListLine].m_Salary;
	UpdateData(FALSE);
}


//void CStaffDlg::OnPrint(CDC* pDC, CPrintInfo* pInfo)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	CFormView::OnPrint(pDC, pInfo);
//}


void CStaffDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类

	//加载位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP5);

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
