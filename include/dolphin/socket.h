/*---------------------------------------------------------------------------*
  Project: Dolphin OS Socket API
  File:    socket.h

  Copyright 2002-2006 Nintendo. All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law. They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

    48    4/04/06 15:47 Shiki
    Added SO_CONFIG_MUTE.

    47    06/03/29 16:07 Ueno_kyu
    Removed  SO_CONFIG_DNS_MAX_QUERY and SO_CONFIG_DNS_CLIENT_PORT options.

    46    3/08/06 17:03 Shiki
    Added SO_CONFIG_DNS_MAX_QUERY and SO_CONFIG_DNS_CLIENT_PORT.

    45    06/03/01 14:27 Ueno_kyu
    Added SO_SOCKET_MAX.

    44    2/28/06 8:59 Shiki
    Added more SO_CONFIG_IPV6_*_TABLEs.

    43    2/27/06 15:01 Shiki
    Added SO_CONFIG_DNS_*_NUMBERs.

    42    2/23/06 15:11 Shiki
    Added  SO_CONFIG_DNS_DOMAIN_NAME and SO_CONFIG_DNS_SERVER_TABLE.

    41    2/23/06 13:58 Shiki
    Added SO_CONFIG_IP_ADDR_TABLE.

    40    2/23/06 10:50 Shiki
    Added SOGetInterfaceOpt and SOSetInterfaceOpt.
    Included <dolphin/ip/IPEntry.h>.

    39    2/20/06 18:11 Shiki
    Modified SOResolver to support for SOHostEnt.aliases.

    38    2/15/06 13:25 Shiki
    Added UDPEntry, UDP6Entry, TCPEntry and TCP6Entry.

    37    2/08/06 10:54 Shiki
    Clean up.

    36    2/07/06 17:25 Shiki
    Defined SO_TCP_STDURG.

    35    1/18/06 16:40 Shiki
    Added suffix to SOResolver{}.

    34    12/13/05 18:44 Shiki
    Implemented RFC 3927.

    33    05/10/20 11:50 Ueno_kyu
    Added support for SO_ERROR option.
    Added SOGetLastError() to support errno.

    31    04/11/02 11:25 Ueno_kyu
    Added support for IPv6 Core Protocol.

    37    04/06/25 17:58 Ueno_kyu
    Restored.

    36    04/06/25 16:55 Ueno_kyu
    Changed the type of dial member of SOConfig{}
    from a pointer to an array.
    Added an ispCode member to SOConfig{}.
    Added definitions for Network Setup Screen.

    35    04/06/21 13:47 Ueno_kyu
    Added country code to SOConfig{}.

    34    04/06/17 8:52 Ueno_kyu
    Added modem dial modes.
    Cleanup.

    33    04/06/15 15:03 Ueno_kyu
    Added support for modem.

    32    6/09/04 16:00 Shiki
    IPv6 pilot implementation

    30    1/30/04 9:11 Shiki
    Modified SOSockAddr structures to have a zero padding in WIN32 build.

    29    11/14/03 17:47 Shiki
    Clean up SOResolver{}.

    28    11/14/03 13:10 Shiki
    Added support for SOGetAddrInfo(), SOFreeAddrInfo(), and
    SOGetNameInfo().

    27    11/04/03 14:54 Shiki
    Added new udpSendBuff and udpRecvBuff members to SOConfig{}.

    26    10/24/03 13:41 Shiki
    Added support for client DHCP host name.

    25    10/23/03 20:31 Shiki
    Added support for PPPoE service name.

    24    10/17/03 14:55 Shiki
    Defined SO_SO_SNDLOWAT and SO_SO_RCVLOWAT.

    23    4/18/03 21:57 Shiki
    Added rdhcp member to SOConfig{}.

    22    3/27/03 17:25 Shiki
    Added support for multicast.

    21    3/07/03 10:42 Shiki
    Added SOInit().

    20    1/30/03 18:33 Shiki
    Added SO_MEM_UDP_SENDBUF.

    19    1/22/03 18:08 Shiki
    Added SOPoll() interface.

    18    11/11/02 21:57 Shiki
    Added support for SO_MSG_DONTWAIT.

    17    10/17/02 13:19 Shiki
    Fixed SOGetHostByAddr() function prototype.
    Added SOInetPtoN() and SOInetNtoP().

    16    10/07/02 10:25 Shiki
    Revised SOSetResolver()/SOGetResolver() prototypes.

    15    10/01/02 9:59 Shiki
    Added const keywords to relevant function prototypes.

    14    8/01/02 11:26 Shiki
    Integrated PPPoE. Added SOSetResolver() and SOGetResolver().

    13    7/22/02 13:36 Shiki
    Added SO_SO_SNDBUF and SO_SO_RCVBUF.

    12    7/19/02 16:12 Shiki
    Added support for non-blocking I/O.

    11    7/18/02 15:24 Shiki
    Added SOConfig.r2

    10    7/15/02 13:48 Shiki
    Modified to be SO_EAGAIN == SO_EWOULDBLOCK

    9     02/07/01 15:33 Shiki
    Added mtu and rwin field to SOConfig{}.

    8     4/30/02 14:49 Shiki
    Added SOGetHostID().

    7     4/26/02 15:49 Shiki
    Revised SOConfig{} structure.

    6     4/18/02 17:56 Shiki
    Defined SO_E*.

    5     4/17/02 11:02 Shiki
    Added dns1 and dns2 field to SOResolver{}.

    4     4/17/02 10:01 Shiki
    Added SOResolver{}.

    3     4/15/02 11:42 Shiki
    Disabled SONtoHl() and other macros for WIN32 build.

    2     4/12/02 18:48 Shiki
    Added SO_PF_UNSPEC.

    1     4/08/02 16:35 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DOL_SOCKET_H__
#define __DOL_SOCKET_H__

#include <iostypes.h>

#include <dolphin/iop_os.h>
#include <dolphin/iop_ip.h>
#include <dolphin/iop_ip6.h>
#include <dolphin/iop_ipdns.h>
#include <dolphin/iop_netif.h>

#include <dolphin/ip/IPStat.h>

/*---------------------------------------------------------------------------*
 * 
 * socket.h locates at both IOP and PPC. only the above include files are
 * different. the rest of file is same on IOP and PPC
 * 
 *---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#define SO_VENDOR_NINTENDO  0x0000      // Nintendo TCP/IP stack
#define SO_VERSION          0x0100      // Version 1.0

#define SO_PF_UNSPEC        0           // Unspecified
#define SO_PF_INET          2           // ARPA Internet protocols

#define SO_AF_UNSPEC        SO_PF_UNSPEC// Unspecified
#define SO_AF_INET          SO_PF_INET  // ARPA Internet protocols

#define SO_INET_ADDRSTRLEN  16

#define SO_SOCK_STREAM      1           // stream socket
#define SO_SOCK_DGRAM       2           // datagram socket

#define SO_MSG_OOB          0x01        // send or receive out-of-band data
#define SO_MSG_PEEK         0x02        // take data but leave it
#define SO_MSG_DONTWAIT     0x04        // non-block operation

// IOP_OS: change from 256 to 16
#define SO_SOCKET_MAX       16          // maximum number of open sockets
    
// Socket option levels
#define SO_SOL_SOCKET       0xffff      // options for socket level
#define SO_SOL_IP           0
#define SO_SOL_ICMP         1
#define SO_SOL_TCP          6
#define SO_SOL_UDP          17

#define SO_IPPROTO_ICMP     1
#define SO_IPPROTO_IGMP     2
#define SO_IPPROTO_TCP      6
#define SO_IPPROTO_UDP      17

#define SO_INADDR_ANY               ((u32) 0x00000000)  // 0.0.0.0
#define SO_INADDR_BROADCAST         ((u32) 0xffffffff)  // 255.255.255.255
#define SO_INADDR_LOOPBACK          ((u32) 0x7f000001)  // 127.0.0.1
#define SO_INADDR_UNSPEC_GROUP      ((u32) 0xe0000000)  // 224.0.0.0
#define SO_INADDR_ALLHOSTS_GROUP    ((u32) 0xe0000001)  // 224.0.0.1
#define SO_INADDR_MAX_LOCAL_GROUP   ((u32) 0xe00000ff)  // 224.0.0.255

// SOGetSockOpt() / SOSetSockOpt()
#define SO_IP_TOS               0x00000007  // int
#define SO_IP_TTL               0x00000008  // int
#define SO_IP_MULTICAST_LOOP    0x00000009  // unsigned char
#define SO_IP_MULTICAST_TTL     0x0000000a  // unsigned char
#define SO_IP_ADD_MEMBERSHIP    0x0000000b  // SOIpMreq
#define SO_IP_DROP_MEMBERSHIP   0x0000000c  // SOIpMreq
#define SO_SO_REUSEADDR         0x00000004  // BOOL
#define SO_SO_LINGER            0x00000080  // SOLinger
#define SO_SO_OOBINLINE         0x00000100  // BOOL
#define SO_SO_SNDBUF            0x00001001  // int
#define SO_SO_RCVBUF            0x00001002  // int
#define SO_SO_SNDLOWAT          0x00001003  // int
#define SO_SO_RCVLOWAT          0x00001004  // int
#define SO_SO_TYPE              0x00001008  // int
#define SO_SO_ERROR             0x00001009  // int
#define SO_TCP_NODELAY          0x00002001  // BOOL
#define SO_TCP_MAXSEG           0x00002002  // int
#define SO_TCP_STDURG           0x00002003  // BOOL

// SOShutdown()
#define SO_SHUT_RD          0
#define SO_SHUT_WR          1
#define SO_SHUT_RDWR        2

// SOFcntl()
#define SO_F_GETFL          3
#define SO_F_SETFL          4
#define SO_O_NONBLOCK       0x04

// SOPoll()
#define SO_POLLRDNORM       0x0001  // Normal data read
#define SO_POLLRDBAND       0x0002  // Priority data read
#define SO_POLLPRI          0x0004  // High priority data read
#define SO_POLLWRNORM       0x0008  // Normal data write
#define SO_POLLWRBAND       0x0010  // Priority data write
#define SO_POLLERR          0x0020  // Error (revents only)
#define SO_POLLHUP          0x0040  // Disconnected (revents only)
#define SO_POLLNVAL         0x0080  // Invalid fd (revents only)
#define SO_POLLIN           (SO_POLLRDNORM | SO_POLLRDBAND)
#define SO_POLLOUT          SO_POLLWRNORM

#define SO_INFTIM           -1

#define SO_E2BIG            -1
#define SO_EACCES           -2
#define SO_EADDRINUSE       -3      // Address is already in use
#define SO_EADDRNOTAVAIL    -4
#define SO_EAFNOSUPPORT     -5      // Non-supported address family
#define SO_EAGAIN           -6      // Posix.1
#define SO_EALREADY         -7      // Already in progress
#define SO_EBADF            -8      // Bad socket descriptor
#define SO_EBADMSG          -9
#define SO_EBUSY            -10
#define SO_ECANCELED        -11
#define SO_ECHILD           -12
#define SO_ECONNABORTED     -13     // Connection aborted
#define SO_ECONNREFUSED     -14     // Connection refused
#define SO_ECONNRESET       -15     // Connection reset
#define SO_EDEADLK          -16
#define SO_EDESTADDRREQ     -17     // Not bound to a local address
#define SO_EDOM             -18
#define SO_EDQUOT           -19
#define SO_EEXIST           -20
#define SO_EFAULT           -21
#define SO_EFBIG            -22
#define SO_EHOSTUNREACH     -23
#define SO_EIDRM            -24
#define SO_EILSEQ           -25
#define SO_EINPROGRESS      -26
#define SO_EINTR            -27     // Canceled
#define SO_EINVAL           -28     // Invalid operation
#define SO_EIO              -29     // I/O error
#define SO_EISCONN          -30     // Socket is already connected
#define SO_EISDIR           -31
#define SO_ELOOP            -32
#define SO_EMFILE           -33     // No more socket descriptors
#define SO_EMLINK           -34
#define SO_EMSGSIZE         -35     // Too large to be sent
#define SO_EMULTIHOP        -36
#define SO_ENAMETOOLONG     -37
#define SO_ENETDOWN         -38
#define SO_ENETRESET        -39
#define SO_ENETUNREACH      -40     // Unreachable
#define SO_ENFILE           -41
#define SO_ENOBUFS          -42     // Insufficient resources
#define SO_ENODATA          -43
#define SO_ENODEV           -44
#define SO_ENOENT           -45
#define SO_ENOEXEC          -46
#define SO_ENOLCK           -47
#define SO_ENOLINK          -48
#define SO_ENOMEM           -49     // Insufficient memory
#define SO_ENOMSG           -50
#define SO_ENOPROTOOPT      -51     // Non-supported option
#define SO_ENOSPC           -52
#define SO_ENOSR            -53
#define SO_ENOSTR           -54
#define SO_ENOSYS           -55
#define SO_ENOTCONN         -56     // Not connected
#define SO_ENOTDIR          -57
#define SO_ENOTEMPTY        -58
#define SO_ENOTSOCK         -59     // Not a socket
#define SO_ENOTSUP          -60
#define SO_ENOTTY           -61
#define SO_ENXIO            -62
#define SO_EOPNOTSUPP       -63     // Non-supported operation
#define SO_EOVERFLOW        -64
#define SO_EPERM            -65
#define SO_EPIPE            -66
#define SO_EPROTO           -67
#define SO_EPROTONOSUPPORT  -68     // Non-supported protocol
#define SO_EPROTOTYPE       -69     // Non-supported socket type
#define SO_ERANGE           -70
#define SO_EROFS            -71
#define SO_ESPIPE           -72
#define SO_ESRCH            -73
#define SO_ESTALE           -74
#define SO_ETIME            -75
#define SO_ETIMEDOUT        -76     // Timed out
#define SO_ETXTBSY          -77
#define SO_EWOULDBLOCK      SO_EAGAIN   // Posix.1g
#define SO_EXDEV            -78

#define SO_MAXDNAME         (DNS_NAME_MAX + 1)

#define SO_SIN_LEN          // SOSockAddr{}.len

// Name for SOConfig.alloc() and SOConfig.free()
#define SO_MEM_TCP_INFO         0
#define SO_MEM_TCP_SENDBUF      1
#define SO_MEM_TCP_RECVBUF      2
#define SO_MEM_UDP_INFO         3
#define SO_MEM_UDP_SENDBUF      4
#define SO_MEM_UDP_RECVBUF      5
#define SO_MEM_TIMEWAITBUF      6
#define SO_MEM_REASSEMBLYBUF    7
#define SO_MEM_SOCKADDR         8       // SOGetAddrInfo()
#define SO_MEM_CANONNAME        9       // SOGetAddrInfo()
#define SO_MEM_ADDRINFO         10      // SOGetAddrInfo()

// Flags for SOConfig{}.flag
#define SO_FLAG_DHCP            0x0001  // Use DHCP
#define SO_FLAG_PPPoE           0x0002  // Use PPPoE
#define SO_FLAG_PPP             0x0002  // Use PPP
#define SO_FLAG_IPv6            0x0004  // Use IPv6
#ifndef SO_FLAG_ZEROCONF
#define SO_FLAG_ZEROCONF        0x8000  // Use IPv4 Link-Local Addresses [RFC 3927]
#endif  // SO_FLAG_ZEROCONF

// Modem Dial Mode
#define SO_DIAL_MODE_TONE        0 // Tone
#define SO_DIAL_MODE_PULSE_10    1 // Pulse (10PPS)
#define SO_DIAL_MODE_PULSE_20    2 // Pulse (20PPS)

#define SO_DIAL_NO_MAXLEN       59

// ISP Code
#define SO_ISP_CODE_GENERIC      0
#define SO_ISP_CODE_AOL          1

typedef struct SOSockAddr
{
    u8          len;
    u8          family;
    u8          data[6];
#ifdef WIN32
    u8          zero[8];
#endif
} SOSockAddr;

typedef struct SOInAddr
{
    u32         addr;
} SOInAddr;

typedef struct SOSockAddrIn
{
    u8          len;            // size of socket address structure
    u8          family;         // the address family
    u16         port;           // the port number
    SOInAddr    addr;           // the Internet address
#ifdef WIN32
    u8          zero[8];
#endif
} SOSockAddrIn;

typedef struct SOLinger
{
    int         onoff;          // zero=off, nonzero = on
    int         linger;         // linger time in seconds
} SOLinger;

typedef struct SOIpMreq
{
   SOInAddr     multiaddr;      // IP address of group
   SOInAddr     interface;      // IP address of interface
} SOIpMreq;

typedef struct SOPollFD
{
    int         fd;
    short       events;         // input event flags
    short       revents;        // output event flags
} SOPollFD;

typedef struct SOHostEnt
{
    char*       name;           // official name of host
    char**      aliases;        // alias list (zero-terminated)
    s16         addrType;       // SO_PF_INET or SO_PF_INET6
    s16         length;         // length of address
    u8**        addrList;       // list of addresses
} SOHostEnt;

#ifndef IOP_OS
#if 0
// 35 aliases, 35 addr, 8192 buffer
typedef struct SOResolver
{
    DNSInfo     info;
    SOHostEnt   ent;
    char        name[SO_MAXDNAME];
#ifndef IP_INET6
    u8          addrList[35 * sizeof(SOInAddr)];
#else
    u8          addrList[35 * sizeof(SOIn6Addr)];
#endif  // IP_INET6
    char        buf[8192 - 35 * sizeof(SOInAddr)];
    u8*         ptrList[72];
    char        suffix[SO_MAXDNAME];
} SOResolver;
#endif
#endif // IOP_OS

typedef struct SOConfig
{
    u16         vendor;             // SO_VENDOR_NINTENDO
    u16         version;            // SO_VERSION

    //
    // vendor specific section
    //
    void*    (* alloc )(u32 name, s32 size);
    void     (* free ) (u32 name, void* ptr, s32 size);

    u32         flag;               // ORed SO_FLAG_*
    SOInAddr    addr;
    SOInAddr    netmask;
    SOInAddr    router;
    SOInAddr    dns1;
    SOInAddr    dns2;

    s32         timeWaitBuffer;     // time wait buffer size
    s32         reassemblyBuffer;   // reassembly buffer size
    s32         mtu;                // maximum transmission unit size

    // TCP
    s32         rwin;               // default TCP receive window size (default 2 x MSS)
    OSTime      r2;                 // default TCP total retransmit timeout value (default 100 sec)

    // PPP
    const char* peerid;
    const char* passwd;

    // PPPoE
    const char* serviceName;        // UTF-8 string

    // DHCP
    const char* hostName;           // DHCP host name
    s32         rdhcp;              // TCP total retransmit times (default 4)

    // UDP
    s32         udpSendBuff;        // default UDP send buffer size (default 1472)
    s32         udpRecvBuff;        // defualt UDP receive buffer size (default 4416)

   // Modem
    const char* dial;
    s32         dialMode;
    char*       countryCode;

    u8          ispCode;
} SOConfig;

u32   (SONtoHl)    ( u32 netlong   );
u16   (SONtoHs)    ( u16 netshort  );
u32   (SOHtoNl)    ( u32 hostlong  );
u16   (SOHtoNs)    ( u16 hostshort );

#ifndef WIN32
#define SONtoHl(netlong)        ((u32) (netlong))
#define SONtoHs(netshort)       ((u16) (netshort))
#define SOHtoNl(hostlong)       ((u32) (hostlong))
#define SOHtoNs(hostshort)      ((u16) (hostshort))
#endif

int   SOInetAtoN     ( const char* cp, SOInAddr* inp );
char* SOInetNtoA     ( SOInAddr in );

int   SOInetPtoN     ( int af, const char* src, void* dst );
const
char* SOInetNtoP     ( int af, const void* src, char* dst, unsigned len );

int   SOSocket       ( int af, int type, int protocol );
int   SOClose        ( int s );
int   SOShutdown     ( int s, int how );

int   SOBind         ( int s, const void* sockAddr );
int   SOConnect      ( int s, const void* sockAddr );
int   SOGetPeerName  ( int s, void* sockAddr );
int   SOGetSockName  ( int s, void* sockAddr );

int   SORead         ( int s, void* buf, int len );
int   SORecv         ( int s, void* buf, int len, int flags );
int   SORecvFrom     ( int s, void* buf, int len, int flags,
                       void* sockFrom );

int   SOWrite        ( int s, const void* buf, int len );
int   SOSend         ( int s, const void* buf, int len, int flags );
int   SOSendTo       ( int s, const void* buf, int len, int flags,
                       const void* sockTo );

int   SOAccept       ( int s, void* sockAddr );
int   SOListen       ( int s, int backlog );

int   SOSockAtMark   ( int s );

int   SOGetSockOpt   ( int s, int level, int optname, void* optval, int* optlen );
int   SOSetSockOpt   ( int s, int level, int optname,
                       const void* optval, int optlen );

int   SOFcntl        ( int s, int cmd, ... );

int   SOPoll         ( SOPollFD fds[], unsigned nfds, OSTime timeout );

SOHostEnt*
      SOGetHostByAddr( const void* addr, int len, int type );
SOHostEnt*
      SOGetHostByName( const char* name );

void  SOFreeAddrInfo ( SOAddrInfo* ai );
int   SOGetAddrInfo  ( const char* nodeName, const char* servName,
                       const SOAddrInfo* hints, SOAddrInfo** res );
int   SOGetNameInfo  ( const void* sockAddr,
                       char* node, unsigned nodeLen,
                       char* service, unsigned serviceLen,
                       int flags );

long  SOGetHostID    ( void );
int   SOGetLastError ( void );

void  SOInit         ( void );
int   SOStartup      ( const SOConfig* config );
int   SOCleanup      ( void );

int   SOSetResolver  ( const SOInAddr* dns1, const SOInAddr* dns2 );
int   SOGetResolver  ( SOInAddr* dns1, SOInAddr* dns2 );
int   SOSetSuffix    ( const char* domainSuffix );
int   SOGetSuffix    ( char* domainSuffix );

// level for SOGetInterfaceOpt()/SOSetInterfaceOpt()
#define SO_SOL_CONFIG                               0xfffe

// optname for SOGetInterfaceOpt()/SOSetInterfaceOpt()
#define SO_CONFIG_FILTER_INPUT                      0x1001
#define SO_CONFIG_FILTER_OUTPUT                     0x1002
#define SO_CONFIG_ERROR                             0x1003
#define SO_CONFIG_MAC_ADDRESS                       0x1004
#define SO_CONFIG_LINK_STATE                        0x1005
#define SO_CONFIG_INTERFACE_STATISTICS              0x1006
#define SO_CONFIG_MUTE                              0x1007
#define SO_CONFIG_PPP_MAX_CONFIGURE                 0x2001
#define SO_CONFIG_PPP_MAX_TERMINATE                 0x2002
#define SO_CONFIG_PPP_MAX_FAILURE                   0x2003
#define SO_CONFIG_PPP_RESTART_TIMER                 0x2004
#define SO_CONFIG_PPP_MESSAGE                       0x2005
#define SO_CONFIG_ARP_NUMBER                        0x3001
#define SO_CONFIG_ARP_TABLE                         0x3002
#define SO_CONFIG_ARP_REFRESH                       0x3003
#define SO_CONFIG_ARP_ADD                           0x3004
#define SO_CONFIG_ARP_REMOVE                        0x3005
#define SO_CONFIG_IP_STATISTICS                     0x4001
#define SO_CONFIG_IP_ADDR_NUMBER                    0x4002
#define SO_CONFIG_IP_ADDR_TABLE                     0x4003
#define SO_CONFIG_IP_MTU                            0x4004
#define SO_CONFIG_IP_ROUTING_NUMBER                 0x4005
#define SO_CONFIG_IP_ROUTING_TABLE                  0x4006
#define SO_CONFIG_IP_ADD_ROUTE                      0x4007
#define SO_CONFIG_IP_REMOVE_ROUTE                   0x4008
#define SO_CONFIG_IP_BOOT_ADDRESS                   0x4009
#define SO_CONFIG_ICMP_STATISTICS                   0x5001
#ifdef IP_INET6
#define SO_CONFIG_IPV6_STATISTICS                   0x6001
#define SO_CONFIG_IPV6_MTU                          0x6002
#define SO_CONFIG_IPV6_PREFIX_NUMBER                0x6003
#define SO_CONFIG_IPV6_PREFIX_TABLE                 0x6004
#define SO_CONFIG_IPV6_ADD_ROUTE                    0x6005
#define SO_CONFIG_IPV6_REMOVE_ROUTE                 0x6006
#define SO_CONFIG_IPV6_ADD_ADDRESS                  0x6007
#define SO_CONFIG_IPV6_REMOVE_ADDRESS               0x6008
#define SO_CONFIG_IPV6_DUP_ADDR_DETECT_TRANSMITS    0x6009
#define SO_CONFIG_IPV6_ADDR_PREFIX_NUMBER           0x600a
#define SO_CONFIG_IPV6_ADDR_PREFIX_TABLE            0x600b
#define SO_CONFIG_IPV6_ADDR_NUMBER                  0x600c
#define SO_CONFIG_IPV6_ADDR_TABLE                   0x600d
#define SO_CONFIG_IPV6_ROUTE_NUMBER                 0x600e
#define SO_CONFIG_IPV6_ROUTE_TABLE                  0x600f
#define SO_CONFIG_IPV6_NET_TO_MEDIA_NUMBER          0x6010
#define SO_CONFIG_IPV6_NET_TO_MEDIA_TABLE           0x6011
#define SO_CONFIG_ICMPV6_STATISTICS                 0x7001
#endif // IP_INET6
#define SO_CONFIG_UDP_STATISTICS                    0x8001
#define SO_CONFIG_UDP_NUMBER                        0x8002
#define SO_CONFIG_UDP_TABLE                         0x8003
#define SO_CONFIG_UDP6_NUMBER                       0x8004
#define SO_CONFIG_UDP6_TABLE                        0x8005
#define SO_CONFIG_TCP_STATISTICS                    0x9001
#define SO_CONFIG_TCP_NUMBER                        0x9002
#define SO_CONFIG_TCP_TABLE                         0x9003
#define SO_CONFIG_TCP6_NUMBER                       0x9004
#define SO_CONFIG_TCP6_TABLE                        0x9005
#define SO_CONFIG_TCP_MSL                           0x9006
#define SO_CONFIG_TCP_RTO_MIN                       0x9007
#define SO_CONFIG_TCP_RTO_MAX                       0x9008
#define SO_CONFIG_TCP_RTO_DEFAULT                   0x9009
#define SO_CONFIG_IGMP_MODE                         0xA001
#define SO_CONFIG_DNS_DOMAIN_NAME                   0xB001
#define SO_CONFIG_DNS_SERVER_NUMBER                 0xB002
#define SO_CONFIG_DNS_SERVER_TABLE                  0xB003

#ifndef IOP_OS
int   SOGetInterfaceOpt( IPInterface* interface, int level, int optname,
                         void* optval, int* optlen );
int   SOSetInterfaceOpt( IPInterface* interface, int level, int optname,
                         const void* optval, int optlen );
#endif // IOP_OS

#ifdef __cplusplus
}
#endif

#ifndef IOP_OS
#if 0
#include <dolphin/ip/IPEntry.h>
#endif
#endif // IOP_OS

#ifndef IOP_OS
#include <dolphin/iop_resolver.h>
#include <dolphin/ip/IPEntry.h>
#endif // IOP_OS

#endif // __DOL_SOCKET_H__
