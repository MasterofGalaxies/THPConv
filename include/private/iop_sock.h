/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */

/*---------------------------------------------------------------------------*
 * 
 * definitions and structures used between socket lib and network stack
 * 
 *---------------------------------------------------------------------------*/

#ifndef __IOP_SOCK_H__
#define __IOP_SOCK_H__

#define NET_RM_SOCK             "/dev/net/ip/top"

#define NET_SO_ACCEPT           0x01
#define NET_SO_BIND             0x02
#define NET_SO_CLOSE            0x03
#define NET_SO_CONNECT          0x04
#define NET_SO_FCNTL            0x05
#define NET_SO_GETPEERNAME      0x06
#define NET_SO_GETSOCKNAME      0x07
#define NET_SO_GETSOCKOPT       0x08
#define NET_SO_SETSOCKOPT       0x09
#define NET_SO_LISTEN           0x0A
#define NET_SO_POLL             0x0B
#define NET_SO_RECVFROM         0x0C
#define NET_SO_SENDTO           0x0D
#define NET_SO_SHUTDOWN         0x0E
#define NET_SO_SOCKET           0x0F
#define NET_SO_GETHOSTID        0x10
#define NET_SO_GETHOSTBYNAME    0x11
#define NET_SO_GETHOSTBYADDR    0x12
#define NET_SO_GETNAMEINFO      0x13
#define NET_SO_GETLASTERROR     0x14
#define NET_SO_InetAtoN         0x15
#define NET_SO_InetPtoN         0x16
#define NET_SO_InetNtoP         0x17
#define NET_SO_GETADDRINFO      0x18
#define NET_SO_SOCKATMARK       0x19
#define NET_SO_STARTUP          0x1A
#define NET_SO_CLEANUP          0x1B
#define NET_SO_GETINTOPT        0x1C
#define NET_SO_SETINTOPT        0x1D
#define NET_SO_SETINTERFACE     0x1E
#define NET_SO_INIT             0x1F

#define NET_ICMP_SOCKET         0x30
#define NET_ICMP_PING           0x31
#define NET_ICMP_CANCEL         0x32
#define NET_ICMP_CLOSE          0x33

typedef struct NETSoSocket
{
    int         af;
    int         type;
    int         protocol;
} NETSoSocket;

typedef struct NETSoAddr
{
    u8          addrBuf[sizeof(SOSockAddrIn6)];
} NETSoAddr;

typedef struct NETSoMap
{
    int         sock;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    u8          addrBuf[sizeof(SOSockAddrIn6)];
} NETSoMap;

typedef struct NETSoRecv
{
    int         sock;
    int         flags;
} NETSoRecv;

typedef struct NETSoSend
{
    int         sock;
    int         flags;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    u8          addrBuf[sizeof(SOSockAddrIn6)];
} NETSoSend;

#define MAX_SET_OPTVAL_LEN      20          // sizeof(SOIPv6Mreq)
#define MAX_GET_OPTVAL_LEN      8           // sizeof(SOLinger)

typedef struct NETSoGetOpt
{
    int         sock;
    int         level;
    int         optname;
    int         optlen;
    u8          optval[MAX_GET_OPTVAL_LEN];
} NETSoGetOpt;

typedef struct NETSoSetOpt
{
    int         sock;
    int         level;
    int         optname;
    int         optlen;
    u8          optval[MAX_SET_OPTVAL_LEN];
} NETSoSetOpt;

typedef struct NETSoListen
{
    int         sock;
    int         backlog;
} NETSoListen;

typedef struct NETSoShutdown
{
    int         sock;
    int         how;
} NETSoShutdown;

typedef struct NETSoFcntl
{
    int         sock;
    int         cmd;
    int         flag;
} NETSoFcntl;

typedef struct NETSoGetHostByAddr
{
    int         len;
    int         type;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    u8          addrBuf[sizeof(SOSockAddrIn6)];
} NETSoGetHostByAddr;

typedef struct NETSoInetPtoN
{
    int         af;
    u8          addrBuf[sizeof(SOIn6Addr)];
} NETSoInetPtoN;

typedef struct NETSoInetNtoP
{
    int         af;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    u8          addrBuf[sizeof(SOIn6Addr)];
} NETSoInetNtoP;

typedef struct NETSoNameInfo
{
    int         flags;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    u8          addrBuf[sizeof(SOSockAddrIn6)];
} NETSoNameInfo;

typedef struct NETSoIntOpt
{
    int         level;
    int         optname;
} NETSoIntOpt;

typedef struct NETIcmpPing
{
    s32         fd;
    int         validAddr;      /* 1: an IP address is stored at addrBuf */
    OSTime      timeout;
    u8          addrBuf[sizeof(SOSockAddrIn6)];
    
    u8          padding[4];
    
} NETIcmpPing;

#endif // __IOP_SOCK_H__
