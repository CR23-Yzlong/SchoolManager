#if !defined(SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_)
#define SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//定义消息码
enum PACKET_FLAG
{
    NONE,

    //client -> server 
    CLIENT_LOGIN,               //登陆请求
    CLIENT_MSG_ADD,             //向服务器发送增加消息
    CLIENT_MSG_SEARCH,          //向服务器发送查找消息
    CLIENT_MSG_DEL,             //向服务器发送删除消息
    CLIENT_MSG_ALTER,           //向服务器发送修改消息
    
    //server -> client
    SERVER_LOGINREPLY,          //服务器登陆回复
    SERVER_REPLY_ADD,           //服务器接收增加信息回复
    SERVER_REPLY_SEARCH,        //服务器接收查找信息回复
    SERVER_REPLY_DEL,           //服务器接收删除信息回复
    SERVER_REPLY_ALTER,         //服务器接收修改信息回复

};

#pragma pack(push)
#pragma pack(1)

/*
m_strSname = _T("");
m_strSid = _T("");
m_strSgender = _T("");
m_strCouID = _T("");
m_strCouName = _T("");
m_strCname = _T("");
m_strCID = _T("");
m_strTips = _T("");
*/

//客户端数据信息
typedef struct _TagClientDataLength
{
    CHAR    cSidLen;        //长度：学生ID
    CHAR    cSNameLen;      //长度：学生名
    CHAR    cSgenderLen;    //长度：学生性别
    CHAR    cCouIDLen;      //长度：课程ID
    CHAR    cCouNameLen;    //长度：课程名
    CHAR    cCidLen;        //长度：班级ID
    CHAR    cCnameLen;      //长度：班级名

    PTCHAR  pszData;        //数据集合
}CDataInfo, *PCDataInfo;


//发送的协议
typedef struct  _TagClientMidDeal
{
    PACKET_FLAG flag;       //定义消息码
    DWORD       dwSize;     //数据长度
    PTCHAR      pszBuf;     //数据
}CMDeal, *PCMDeal;

//发送的协议
typedef struct  _TagServerMidDeal
{
    PACKET_FLAG flag;       //定义消息码
    DWORD       dwSize;     //数据长度
    PTCHAR      pszBuf;     //数据
}SMDeal, *PSMDeal;




#pragma pack(pop)




#endif // !defined(SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_)