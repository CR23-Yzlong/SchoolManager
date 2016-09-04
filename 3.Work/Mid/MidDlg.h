// MidDlg.h : header file
//

#if !defined(AFX_MIDDLG_H__9D03B1D8_DF67_437B_94CA_C160BFC73385__INCLUDED_)
#define AFX_MIDDLG_H__9D03B1D8_DF67_437B_94CA_C160BFC73385__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMidDlg dialog

#include "../AddIn/MySocket.h"

class CMidDlg : public CDialog
{
// Construction
public:
	CMidDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMidDlg)
	enum { IDD = IDD_MID_DIALOG };
	CStatic	m_ClientCtl;
	CStatic	m_ServerCtl;
	CString	m_strServerInfo;
	CString	m_strClientInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMidDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMidDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIDDLG_H__9D03B1D8_DF67_437B_94CA_C160BFC73385__INCLUDED_)
