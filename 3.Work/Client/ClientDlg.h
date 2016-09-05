// ClientDlg.h : header file
//

#if !defined(AFX_CLIENTDLG_H__9181B6DF_84B1_4049_AEF2_BE40B09CDC33__INCLUDED_)
#define AFX_CLIENTDLG_H__9181B6DF_84B1_4049_AEF2_BE40B09CDC33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

//Socket��
#include "../AddIn/MySocket.h"

//ͨ��Э����
#include "../AddIn/SocketDeal.h"

class CClientDlg : public CDialog
{
// Construction
public:
	
	CClientDlg(CWnd* pParent = NULL);	// standard constructor

    //Socket
    CMySocket m_Sock;

    //���ڼ��������Ƿ�����
    BOOL  bIsServerConnect;

    //���ڷ��͵�������Ϣ
    CDataInfo  m_ClientInfo;


    //���ӷ�����
    BOOL ConnectServer();

    //��ȡEdit����Ϣ
    BOOL GetEditInfo();

    //��ʼ����ع���
	BOOL InitSomething();
    
    //��ʼ�����е�CString
    BOOL InitCStr();
    
// Dialog Data
	//{{AFX_DATA(CClientDlg)
	enum { IDD = IDD_CLIENT_DIALOG };
	CListCtrl	m_ListCTL;
	CString	m_strSname;
	CString	m_strSid;
	CString	m_strSgender;
	CString	m_strCouID;
	CString	m_strCouName;
	CString	m_strCname;
	CString	m_strCid;
	CString	m_strTips;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    
    CMenu m_FunMenu;
	// Generated message map functions
	//{{AFX_MSG(CClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnInsert();
	afx_msg void OnBtnDel();
	afx_msg void OnBtnQuery();
	afx_msg void OnBtnAlter();
	afx_msg void OnRclickListResult(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTDLG_H__9181B6DF_84B1_4049_AEF2_BE40B09CDC33__INCLUDED_)
