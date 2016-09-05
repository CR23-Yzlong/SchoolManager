// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_strSname = _T("");
	m_strSid = _T("");
	m_strSgender = _T("");
	m_strCouID = _T("");
	m_strCouName = _T("");
	m_strCname = _T("");
	m_strCid = _T("");
	m_strTips = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    bIsServerConnect = FALSE;

    memset(&m_ClientInfo, 0, sizeof(m_ClientInfo));

    m_FunMenu.LoadMenu(IDR_MENU_FUN);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_LIST_RESULT, m_ListCTL);
	DDX_Text(pDX, IDC_EDIT_SNAME, m_strSname);
	DDX_Text(pDX, IDC_EDIT_SID, m_strSid);
	DDX_Text(pDX, IDC_EDIT_SGENDER, m_strSgender);
	DDX_Text(pDX, IDC_EDIT_COURSEID, m_strCouID);
	DDX_Text(pDX, IDC_EDIT_COUNAME, m_strCouName);
	DDX_Text(pDX, IDC_EDIT_CLASS_NAME, m_strCname);
	DDX_Text(pDX, IDC_EDIT_CLASS_ID, m_strCid);
	DDX_Text(pDX, IDC_STATIC_TIPS, m_strTips);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INSERT, OnBtnInsert)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	ON_BN_CLICKED(IDC_BTN_QUERY, OnBtnQuery)
	ON_BN_CLICKED(IDC_BTN_ALTER, OnBtnAlter)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_RESULT, OnRclickListResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
    //连接服务端
    if(!ConnectServer())
    {
        AfxMessageBox(TEXT("服务器连接失败，请检查！"));
        exit(0);
    }
    
    
    //初始化
    InitSomething();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::OnBtnInsert() 
{
	// TODO: Add your control notification handler code here
	
}

void CClientDlg::OnBtnDel() 
{
	// TODO: Add your control notification handler code here
	int i = 0;
}

void CClientDlg::OnBtnQuery() 
{
	// TODO: Add your control notification handler code here
	
}

void CClientDlg::OnBtnAlter() 
{
	// TODO: Add your control notification handler code here
	int i = 0;
}

BOOL CClientDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
    //释放菜单资源
    m_FunMenu.DestroyMenu();

	return CDialog::DestroyWindow();
}

BOOL CClientDlg::GetEditInfo()
{
    BOOL bRet = FALSE;
    
    //更新Edit到本地CString
    UpdateData(TRUE);

    if(!m_strSname.IsEmpty())
    {
        m_ClientInfo.cSNameLen = m_strSname.GetLength();
        bRet = TRUE;
    }

    if(!m_strSid.IsEmpty())
    {
        m_ClientInfo.cSidLen = m_strSid.GetLength();
        bRet = TRUE;
    }

    if(!m_strSgender.IsEmpty())
    {
        m_ClientInfo.cSgenderLen = m_strSgender.GetLength();
        bRet = TRUE;
    }

    if(!m_strCouID.IsEmpty())
    {
        m_ClientInfo.cCouIDLen = m_strCouID.GetLength();
        bRet = TRUE;
    }

    if(!m_strCouName.IsEmpty())
    {
        m_ClientInfo.cCouNameLen = m_strCouName.GetLength();
        bRet = TRUE;
    }

    if(!m_strCname.IsEmpty())
    {
        m_ClientInfo.cCnameLen = m_strCname.GetLength();
        bRet = TRUE;
    }

    if(!m_strCid.IsEmpty())
    {
        m_ClientInfo.cCidLen = m_strCid.GetLength();
        bRet = TRUE;
    }

    return bRet;
}

BOOL CClientDlg::InitCStr()
{
    m_strSname      = TEXT("");
    m_strSid        = TEXT("");
    m_strSgender    = TEXT("");
    m_strCouID      = TEXT("");
    m_strCouName    = TEXT("");
    m_strCname      = TEXT("");
    m_strCid        = TEXT("");
	m_strTips       = TEXT("");

    return TRUE;
}


BOOL CClientDlg::ConnectServer()
{
    InitCStr();

    if(!m_Sock.StartClient(8080, TEXT("127.0.0.1")))
    {
        return FALSE; 
    }

    bIsServerConnect = TRUE;


    m_strTips = TEXT("连接服务器成功！");
    UpdateData(TRUE);

    return TRUE;
}

BOOL CClientDlg::InitSomething()
{
    #define RowWidth    9   //标题名的基础值

    LONG lStyle;

	//获取当前窗口style，利用GetWindowLong
    lStyle = ::GetWindowLong(m_ListCTL.GetSafeHwnd(), GWL_STYLE);

    //清除显示方式位
    lStyle &= ~LVS_TYPEMASK; 

    //设置style，与运算
    lStyle |= LVS_REPORT;    

    //设置style  利用SewWindowLong设置View的属性
    SetWindowLong(m_ListCTL.m_hWnd, GWL_STYLE, lStyle);

    DWORD dwStyle = m_ListCTL.GetExtendedStyle();

    //选中某行使整行高亮（只适用与report风格的listctrl）
    dwStyle |= LVS_EX_FULLROWSELECT;

    //网格线（只适用与report风格的listctrl）
    dwStyle |= LVS_EX_GRIDLINES;

    //设置扩展风格
    m_ListCTL.SetExtendedStyle(dwStyle); 


    //初始化ListCtl
    m_ListCTL.InsertColumn(0, TEXT("序号"));

    m_ListCTL.InsertColumn(1, TEXT("学号"));
    m_ListCTL.InsertColumn(2, TEXT("姓名"));
    m_ListCTL.InsertColumn(3, TEXT("性别"));

    m_ListCTL.InsertColumn(4, TEXT("班级ID"));
    m_ListCTL.InsertColumn(5, TEXT("班级名"));

    m_ListCTL.InsertColumn(6, TEXT("课程ID"));
    m_ListCTL.InsertColumn(7, TEXT("课程名"));

    
    m_ListCTL.SetColumnWidth(0, RowWidth * _tcslen(TEXT("序号")));
    m_ListCTL.SetColumnWidth(1, RowWidth * _tcslen(TEXT("学号")));
    m_ListCTL.SetColumnWidth(2, RowWidth * _tcslen(TEXT("姓名")));
    m_ListCTL.SetColumnWidth(3, RowWidth * _tcslen(TEXT("性别")));
    m_ListCTL.SetColumnWidth(4, RowWidth * _tcslen(TEXT("班级ID")));
    m_ListCTL.SetColumnWidth(5, RowWidth * _tcslen(TEXT("班级名")));
    m_ListCTL.SetColumnWidth(6, RowWidth * _tcslen(TEXT("课程ID")));
    m_ListCTL.SetColumnWidth(7, RowWidth * _tcslen(TEXT("课程名")));


    m_ListCTL.InsertItem(0, "1");
    
    m_ListCTL.SetItemText(0, 1, "S001");
    m_ListCTL.SetItemText(0, 2, "张三");
    m_ListCTL.SetItemText(0, 3, "男");
    m_ListCTL.SetItemText(0, 4, "C001");

    return TRUE;
}

void CClientDlg::OnRclickListResult(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);  
    // TODO: 在此添加控件通知处理程序代码  
    POSITION pos = m_ListCTL.GetFirstSelectedItemPosition();//在列表视图控件中获取第一个选择项的位置  
    if (pos!=NULL){  
        POINT pt = {0};  
        GetCursorPos(&pt);//得到鼠标点击位置  
        m_FunMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON,
                                                pt.x,
                                                pt.y,
                                                this); //m_newListCtrl是CListCtrl对象  
    }   
    *pResult = 0;  
}
