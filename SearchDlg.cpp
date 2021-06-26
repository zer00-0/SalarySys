// SearchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SalarySys.h"
#include "SearchDlg.h"


// CSearchDlg

IMPLEMENT_DYNCREATE(CSearchDlg, CFormView)

CSearchDlg::CSearchDlg()
	: CFormView(IDD_DIALOG_SEARCH)
	, Search_account(_T(""))
	, Search_name(_T(""))
{

}

CSearchDlg::~CSearchDlg()
{
}

void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SNU, Search_account);
	DDX_Text(pDX, IDC_EDIT1, Search_name);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CSearchDlg, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CSearchDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CSearchDlg::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CSearchDlg 诊断

#ifdef _DEBUG
void CSearchDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSearchDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSearchDlg 消息处理程序


void CSearchDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CSearchDlg::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfofile file;
	file.ReadDocline(); //读取员工信息
	if (Search_account == "" && Search_name == "") {
		AfxMessageBox(_T("请输入查询账号或姓名！"));
	}else if (Search_account == "") {
		int i = 0;
		for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
			if (it->m_Name == Search_name) {
				CString str;
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
				i++;
			}
		}
	}else {
		int i = 0;
		for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
			if (it->m_Account == Search_account) {
				CString str;
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
				i++;
			}
		}
	}
	Search_account.Empty();
	Search_name.Empty();
	UpdateData(FALSE);
}


void CSearchDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	// 设置扩展风格
	//LVS_EX_FULLROWSELECT选中整行，LVS_EX_GRIDLINES网格
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 初始化表头
	CString field[] = { _T("账号"), _T("姓名"), _T("职称"), _T("工龄"), _T("工资") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}
	UpdateData(FALSE);
}


void CSearchDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	//加载位图
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP7);

	////选入DC
	//CClientDC cdc(this);
	//CDC comdc;
	//comdc.CreateCompatibleDC(&cdc);
	//comdc.SelectObject(&bitmap);

	////生成BITMAP
	//BITMAP bit;
	//bitmap.GetBitmap(&bit);

	////客户区域
	//CRect rect;
	//GetClientRect(rect);

	//cdc.SetStretchBltMode(HALFTONE);   //解决图形失真问题
	//								   //用客户区的DC绘制所生成的BITMAP，并适应为窗口大小
	//cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &comdc, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
}
