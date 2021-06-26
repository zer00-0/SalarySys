// UserDlg.cpp : ʵ���ļ�
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������


void CUserDlg::OnBnClickedButtonEnter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE); //�õ�����ֵ


	if (Pwd1.IsEmpty() || Pwd2.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ�գ�"));
		return;
	}

	//�������ȷ������Ҫһ��
	if (Pwd1 != Pwd2)
	{
		MessageBox(TEXT("��������ȷ������Ҫһ�£�"));
		return;
	}
	if (Pwd1 == old_Pwd) {
		MessageBox(TEXT("������������벻��һ�£�"));
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
	AfxMessageBox(_T("�޸�����ɹ���"));

	Pwd1.Empty();
	Pwd2.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnBnClickedButtonCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Pwd1.Empty();
	Pwd2.Empty();
	UpdateData(FALSE);
}


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
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

	// TODO: �ڴ����ר�ô����/����û���
	UpdateData(FALSE);
}




void CUserDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	//����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP6);

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


void CUserDlg::OnEnChangeEditPosition()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
