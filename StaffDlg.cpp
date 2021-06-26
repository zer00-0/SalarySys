// StaffDlg.cpp : ʵ���ļ�
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


// CStaffDlg ���

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


// CStaffDlg ��Ϣ�������


void CStaffDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CStaffDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	// ������չ���
	//LVS_EX_FULLROWSELECTѡ�����У�LVS_EX_GRIDLINES����
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// ��ʼ����ͷ
	CString field[] = { _T("�˺�"), _T("����"), _T("ְ��"), _T("����"), _T("����"), _T("˰��")};
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	//��Ҫ����#include "InfoFile.h"
	CInfofile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ

						//�������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CInfofile file;
	file.ReadDocline(); //��ȡԱ����Ϣ
	for (vector<message>::iterator it = file.MessVec.begin(); it != file.MessVec.end(); it++) {
		if (it->m_Account == Add_account) {
			AfxMessageBox(_T("�˺��ظ���"));
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
		AfxMessageBox(_T("���ݲ�ȫ��"));
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
		AfxMessageBox(_T("��ӳɹ���"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInfofile file;
	file.ReadDocline(); //��ȡԱ����Ϣ
	POSITION p1 = m_list.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��
	int i = m_list.GetNextSelectedItem(p1);
	file.MessVec.erase(file.MessVec.begin() + i);
	file.WirteDocline();
	POSITION p = m_list.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��
	while (p)
	{
		int  nSelected = m_list.GetNextSelectedItem(p); //��ȡѡ���е�����
		m_list.DeleteItem(nSelected); //��������ɾ��
		p = m_list.GetFirstSelectedItemPosition();
	}

	AfxMessageBox(_T("ɾ���ɹ���"));
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
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInfofile file;
	file.ReadDocline(); //��ȡԱ����Ϣ

	if (Add_account == "" || Add_name == "" || Add_position == "" || Add_pwd == "" || Add_salary == "" || Add_workyear == "") {
		AfxMessageBox(_T("���ݲ�ȫ��"));
	}
	else {
		UpdateData(TRUE);
		file.MessVec[ListLine ].m_Account = Add_account;
		file.MessVec[ListLine].m_Name = Add_name;
		file.MessVec[ListLine].m_Psition = Add_position;
		file.MessVec[ListLine].m_WorkYear = Add_workyear;
		file.MessVec[ListLine].m_Salary = Add_salary;
		file.MessVec[ListLine].m_PWD = Add_pwd;
		AfxMessageBox(_T("�޸���Ϣ�ɹ���"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION p = m_list.GetFirstSelectedItemPosition();    //��ȡ��ѡ����λ��
	ListLine = m_list.GetNextSelectedItem(p);
	if (ListLine < 0) {
		AfxMessageBox(_T("δѡ���б��У�"));
		return;
	}
	CInfofile file;
	file.ReadDocline(); //��ȡԱ����Ϣ

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
//	// TODO: �ڴ����ר�ô����/����û���
//
//	CFormView::OnPrint(pDC, pInfo);
//}


void CStaffDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���

	//����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP5);

	//ѡ��DC
	CClientDC cdc(this);
	CDC comdc;
	comdc.CreateCompatibleDC(&cdc);
	comdc.SelectObject(&bitmap);

	//����BITMAP
	BITMAP bit;
	bitmap.GetBitmap(&bit);

	//�ͻ�����
	CRect rect;
	GetClientRect(rect);

	cdc.SetStretchBltMode(HALFTONE);   //���ͼ��ʧ������
									   //�ÿͻ�����DC���������ɵ�BITMAP������ӦΪ���ڴ�С
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &comdc, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);

}
