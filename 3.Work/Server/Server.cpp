// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyServer.h"
#include "../AddIn/MySocket.h"

#import "../AddIn/msado15.dll" no_namespace rename("EOF","adoEOF")

//���ڳ�ʼ��COM���õ���
class CComInit
{
public:
    CComInit()
    {
        CoInitialize(NULL);
    }
    ~CComInit()
    {
        CoUninitialize();
    }
}g_Init;

int main(int argc, char* argv[])
{
    CMySocket Server;



	return 0;
}
