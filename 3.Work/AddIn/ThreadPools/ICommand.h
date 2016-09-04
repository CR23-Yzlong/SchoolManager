// ICommand.h: interface for the ICommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICOMMAND_H__0B80671E_0318_47FB_AD85_CDC52F1DCFA0__INCLUDED_)
#define AFX_ICOMMAND_H__0B80671E_0318_47FB_AD85_CDC52F1DCFA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WINDOWS.H>

class ICommand  
{
public:
	ICommand();
	virtual ~ICommand();
    
    //Ö´ÐÐCmd
    virtual BOOL CmdExecute() = 0;

};

#endif // !defined(AFX_ICOMMAND_H__0B80671E_0318_47FB_AD85_CDC52F1DCFA0__INCLUDED_)
