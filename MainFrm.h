
// MainFrm.h : CMainFrame ��Ľӿ�


#pragma once
//WM_USER ���û��Զ�����Ϣ��һ����ʼֵ
//WM_USER+100��Ϊ������ϵͳ��Ϣ���û���Ϣ�������ͻ
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)
#define NM_E	(WM_USER + 104)

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	//�Զ�����Ϣ������
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CSplitterWnd m_spliter; // �зִ��������
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


