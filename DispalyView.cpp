// DispalyView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalarySys.h"
#include "DispalyView.h"


// CDispalyView

IMPLEMENT_DYNCREATE(CDispalyView, CFormView)

CDispalyView::CDispalyView()
	: CFormView(IDD_DISPALYVIEW)
{

}

CDispalyView::~CDispalyView()
{
}

void CDispalyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDispalyView, CFormView)
END_MESSAGE_MAP()


// CDispalyView ���

#ifdef _DEBUG
void CDispalyView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDispalyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDispalyView ��Ϣ�������
