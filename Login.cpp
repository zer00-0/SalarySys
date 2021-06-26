// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalarySys.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin �Ի���

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


// CLogin ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	this->SetWindowText(_T("��¼ϵͳ"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void CLoginDlg::OnEnChangeEditAccount()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString Account;

}


void CLoginDlg::OnEnChangeEditPwd()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CLoginDlg::OnBnClickedButtonEnter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE); //���¿ؼ������ݵ���Ӧ�ı���

	CInfofile file; //���������ļ��������Ҫͷ�ļ�#include "InfoFile.h" 
	file.ReadDocline();
	if (file.ReadLoginAccount(Account))//�û������
	{
		if (!file.ReadLoginPwd(Pwd))
		{
			MessageBox(_T("�������"));
			Pwd.Empty();			//�������
		}
		else
		{
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("�û���������"));
		Account.Empty();		//����˺�
		Pwd.Empty();		//�������
	}
}


void CLoginDlg::OnBnClickedButtonCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);	//������������
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(0);		//������������
	CDialogEx::OnClose();
}

//�༭���س����رնԻ���������
void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP2);

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
