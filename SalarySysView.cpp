
// SalarySysView.cpp : CSalarySysView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SalarySys.h"
#endif

#include "SalarySysDoc.h"
#include "SalarySysView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSalarySysView

IMPLEMENT_DYNCREATE(CSalarySysView, CView)

BEGIN_MESSAGE_MAP(CSalarySysView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSalarySysView ����/����

CSalarySysView::CSalarySysView()
{
	// TODO: �ڴ˴���ӹ������

}

CSalarySysView::~CSalarySysView()
{
}

BOOL CSalarySysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSalarySysView ����

void CSalarySysView::OnDraw(CDC* /*pDC*/)
{
	CSalarySysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);

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

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSalarySysView ��ӡ

BOOL CSalarySysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSalarySysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSalarySysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSalarySysView ���

#ifdef _DEBUG
void CSalarySysView::AssertValid() const
{
	CView::AssertValid();
}

void CSalarySysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSalarySysDoc* CSalarySysView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSalarySysDoc)));
	return (CSalarySysDoc*)m_pDocument;
}
#endif //_DEBUG


// CSalarySysView ��Ϣ�������
