#if !defined(SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_)
#define SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//������Ϣ��
enum PACKET_FLAG
{
    NONE,

    //client -> server 
    CLIENT_LOGIN,               //��½����
    CLIENT_MSG_ADD,             //�����������������Ϣ
    CLIENT_MSG_SEARCH,          //����������Ͳ�����Ϣ
    CLIENT_MSG_DEL,             //�����������ɾ����Ϣ
    CLIENT_MSG_ALTER,           //������������޸���Ϣ
    
    //server -> client
    SERVER_LOGINREPLY,          //��������½�ظ�
    SERVER_REPLY_ADD,           //����������������Ϣ�ظ�
    SERVER_REPLY_SEARCH,        //���������ղ�����Ϣ�ظ�
    SERVER_REPLY_DEL,           //����������ɾ����Ϣ�ظ�
    SERVER_REPLY_ALTER,         //�����������޸���Ϣ�ظ�

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

//�ͻ���������Ϣ
typedef struct _TagClientDataLength
{
    CHAR    cSidLen;        //���ȣ�ѧ��ID
    CHAR    cSNameLen;      //���ȣ�ѧ����
    CHAR    cSgenderLen;    //���ȣ�ѧ���Ա�
    CHAR    cCouIDLen;      //���ȣ��γ�ID
    CHAR    cCouNameLen;    //���ȣ��γ���
    CHAR    cCidLen;        //���ȣ��༶ID
    CHAR    cCnameLen;      //���ȣ��༶��

    PTCHAR  pszData;        //���ݼ���
}CDataInfo, *PCDataInfo;


//���͵�Э��
typedef struct  _TagClientMidDeal
{
    PACKET_FLAG flag;       //������Ϣ��
    DWORD       dwSize;     //���ݳ���
    PTCHAR      pszBuf;     //����
}CMDeal, *PCMDeal;

//���͵�Э��
typedef struct  _TagServerMidDeal
{
    PACKET_FLAG flag;       //������Ϣ��
    DWORD       dwSize;     //���ݳ���
    PTCHAR      pszBuf;     //����
}SMDeal, *PSMDeal;




#pragma pack(pop)




#endif // !defined(SOCKET_DEAL_H__D9605F44_2F0B_4976_9B11_CD65507EA11E__INCLUDED_)