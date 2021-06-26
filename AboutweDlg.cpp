// AboutweDlg.cpp : 实现文件
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


// CAboutweDlg 诊断

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


// CAboutweDlg 消息处理程序


void CAboutweDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
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
			//edit->GetWindowText(result);//Unicode字符集
			//edit->GetWindowTextA(result);//多字节字符集

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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAboutweDlg::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	//加载位图
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP4);

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
