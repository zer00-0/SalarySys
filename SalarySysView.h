
// SalarySysView.h : CSalarySysView ��Ľӿ�
//

#pragma once


class CSalarySysView : public CView
{
protected: // �������л�����
	CSalarySysView();
	DECLARE_DYNCREATE(CSalarySysView)

// ����
public:
	CSalarySysDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSalarySysView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SalarySysView.cpp �еĵ��԰汾
inline CSalarySysDoc* CSalarySysView::GetDocument() const
   { return reinterpret_cast<CSalarySysDoc*>(m_pDocument); }
#endif

