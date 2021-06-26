
// SalarySysView.cpp : CSalarySysView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSalarySysView 构造/析构

CSalarySysView::CSalarySysView()
{
	// TODO: 在此处添加构造代码

}

CSalarySysView::~CSalarySysView()
{
}

BOOL CSalarySysView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSalarySysView 绘制

void CSalarySysView::OnDraw(CDC* /*pDC*/)
{
	CSalarySysDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//加载位图
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);

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

	// TODO: 在此处为本机数据添加绘制代码
}


// CSalarySysView 打印

BOOL CSalarySysView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSalarySysView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CSalarySysView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CSalarySysView 诊断

#ifdef _DEBUG
void CSalarySysView::AssertValid() const
{
	CView::AssertValid();
}

void CSalarySysView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSalarySysDoc* CSalarySysView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSalarySysDoc)));
	return (CSalarySysDoc*)m_pDocument;
}
#endif //_DEBUG


// CSalarySysView 消息处理程序
