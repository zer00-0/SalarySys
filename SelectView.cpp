// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SalarySys.h"
#include "SelectView.h"
#include "MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView ���

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//ͼ����Դ�ļ��� CWinApp::LoadIcon
	//IDI_ICON_REΪͼ����ԴID
	HICON icon = AfxGetApp()->LoadIcon(IDI_ICON_RE);

	//ͼƬ�б�Ĵ��� CImageList::Create
	//30, 30��ָ��ͼ��Ŀ�Ⱥ͸߶�
	//ILC_COLOR32��ͼ���ʽ
	//1, 1���ж���ͼ���д����
	m_imageList.Create(30, 30, ILC_COLOR32, 1, 1);
	//ͼƬ�б�׷��ͼ�� CImageList::Add
	m_imageList.Add(icon);

	//��ȡ����ͼ�е����ؼ� CTreeView::GetTreeCtrl
	m_treeCtrl = &GetTreeCtrl();

	//���ؼ�����ͼƬ�б� CTreeCtrl::SetImageList
	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

	//���ؼ����ýڵ� CTreeCtrl::InsertItem
	m_treeCtrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("Ա����Ϣ����"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("��Ϣ��ѯ"), 0, 0, NULL);
	m_treeCtrl->InsertItem(TEXT("��������"), 0, 0, NULL);
	//m_treeCtrl->InsertItem(TEXT("���ɾ��"), 0, 0, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	// ��ȡ��ǰ�ڵ�ѡ����Ŀ CTreeCtrl::GetSelectedItem
		HTREEITEM item = m_treeCtrl->GetSelectedItem();

	//��ȡѡ������ı����� CTreeCtrl::GetItemText
	CString str = m_treeCtrl->GetItemText(item);
	//MessageBox(str);

	if (str == TEXT("������Ϣ"))
	{
		//��Ҫ���������ͷ�ļ�#include "MainFrm.h" 
		//CWnd::PostMessage ��һ����Ϣ���봰�ڵ���Ϣ����
		//AfxGetMainWnd()����ܴ��ڶ����ָ��
		//AfxGetMainWnd()->GetSafeHwnd()����ȡ���ش��ڵľ����CWnd::GetSafeHwnd
		//NM_A�������Զ�����Ϣ
		//(WPARAM)NM_A��ָ���˸��ӵ���Ϣ��Ϣ
		//(LPARAM)0��ָ���˸��ӵ���Ϣ��Ϣ���˲�������û������
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}
	else if (str == TEXT("Ա����Ϣ����"))
	{
		if (now_account == "Admin")
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
		else
			AfxMessageBox(_T("�޷���Ȩ�ޣ�"));
	}
	else if (str == TEXT("��������"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
	}
	else if (str == TEXT("��Ϣ��ѯ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
		if (now_account == "Admin")
			::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
		else
			AfxMessageBox(_T("�޷���Ȩ�ޣ�"));
	}
	/*else if (str == TEXT("���ɾ��"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
	}*/
}
