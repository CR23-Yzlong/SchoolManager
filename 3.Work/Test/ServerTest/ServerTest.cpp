// ServerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../AddIn/MySocket.h"

#include <IOSTREAM>
#include <STRING>
using namespace std;

int main(int argc, char* argv[])
{
    CMySocket Server;
    Server.StartServer(8080);
    
    cout << "开始监听..." << endl;

    if(!Server.Accept())
        return 0;
    
    
    SOCKET sNew = Server.GetNewSock();
    SOCKADDR_IN addrNew = Server.GetNewAddr();

    cout << "有客户端连接: " 
         << inet_ntoa(addrNew.sin_addr)
         << " : "
         << addrNew.sin_port
         << endl;
    
    string strBuf;

	while(1)
    {
        if(Server.Recv(sNew, strBuf, MAX_RECV_BYTES))
        {
            cout << strBuf << endl;
        }
        else
        {
            cout << "主机退出" << endl;
            CMySocket::OutputErrorMsg(Server.GetErrorMsg());
            break;
        }
    }

    closesocket(sNew);

    system("pause")  ;  
    
    return 0;
}
