; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Client.h"

ClassCount=3
Class1=CClientApp
Class2=CClientDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_CLIENT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU_FUN

[CLS:CClientApp]
Type=0
HeaderFile=Client.h
ImplementationFile=Client.cpp
Filter=N

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D
LastObject=IDC_LIST_RESULT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=24
Control1=IDC_EDIT_SID,edit,1350631425
Control2=IDC_EDIT_SNAME,edit,1350631425
Control3=IDC_EDIT_SGENDER,edit,1350631425
Control4=IDC_EDIT_COURSEID,edit,1350631425
Control5=IDC_EDIT_COUNAME,edit,1350631425
Control6=IDC_EDIT_CLASS_ID,edit,1350631425
Control7=IDC_EDIT_CLASS_NAME,edit,1350631425
Control8=IDC_BTN_INSERT,button,1342242816
Control9=IDC_BTN_DEL,button,1342242816
Control10=IDC_BTN_QUERY,button,1342242816
Control11=IDC_BTN_ALTER,button,1342242816
Control12=IDC_LIST_RESULT,SysListView32,1350631425
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308865
Control16=IDC_STATIC,static,1342308865
Control17=IDC_STATIC,static,1342308865
Control18=IDC_STATIC,static,1342308865
Control19=IDC_STATIC,static,1342308865
Control20=IDC_STATIC,static,1342308865
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC_TIPS,static,1342177793
Control23=IDC_STATIC,button,1342177287
Control24=IDC_STATIC,static,1342308865

[MNU:IDR_MENU_FUN]
Type=1
Class=?
Command1=IDC_BTN_DEL
Command2=IDC_BTN_ALTER
CommandCount=2

