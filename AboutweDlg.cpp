// AboutweDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalarySys.h"
#include "AboutweDlg.h"


// CAboutweDlg

IMPLEMENT_DYNCREATE(CAboutweDlg, CFormView)

CAboutweDlg::CAboutweDlg()
	: CFormView(IDD_DIALOG_PERSON)
{

}

CAboutweDlg::~CAboutweDlg()
{
}

void CAboutweDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutweDlg, CFormView)
	ON_EN_CHANGE(IDC_EDIT_ABOUTWE, &CAboutweDlg::OnEnChangeEditAboutwe)
END_MESSAGE_MAP()


// CAboutweDlg ���

#ifdef _DEBUG
void CAboutweDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAboutweDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAboutweDlg ��Ϣ�������


void CAboutweDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CString strLine, strTemp, result;
	int row = 0;
	CString filename("Data/About.txt");
	CStdioFile file(filename, CFile::modeRead);

	while (file.ReadString(strLine))
	{
		//char *str = strLine.GetBufferSetLength(strLine.GetLength());
		char *str = (char *)strLine.GetBufferSetLength(strLine.GetLength());
		//char *p;
		if (strLine != "")
		{
			result += _T("\r\n") + strLine;
			//result += strLine;

			//CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT_ABOUTWE);
			//edit->GetWindowText(result);//Unicode�ַ���
			//edit->GetWindowTextA(result);//���ֽ��ַ���

			GetDlgItem(IDC_EDIT_ABOUTWE)->SetWindowText(result);
			GetDlgItem(IDC_EDIT_ABOUTWE)->UpdateWindow();
			//result = " ";
			row++;
		}
	}
	file.Close();
}


void CAboutweDlg::OnEnChangeEditAboutwe()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAboutweDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	//����λͼ
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP4);

	////ѡ��DC
	//CClientDC cdc(this);
	//CDC comdc;
	//comdc.CreateCompatibleDC(&cdc);
	//comdc.SelectObject(&bitmap);

	////����BITMAP
	//BITMAP bit;
	//bitmap.GetBitmap(&bit);

	////�ͻ�����
	//CRect rect;
	//GetClientRect(rect);

	//cdc.SetStretchBltMode(HALFTONE);   //���ͼ��ʧ������
	//								   //�ÿͻ�����DC���������ɵ�BITMAP������ӦΪ���ڴ�С
	//cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &comdc, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
}
