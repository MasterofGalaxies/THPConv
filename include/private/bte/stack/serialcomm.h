/*******************************************************************************
**  Name:       serialcomm.h
**
**  Description:
**  This file contains the definitions necessary to interface to the
**  serial ports on a Windows platform.
**
**  Copyright (c) 2001, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Software. Proprietary and confidential.
*******************************************************************************/
#define BTRPC_COMM_PORT_BUFSIZE 4096

/* Callback for incoming data */
typedef void (*tSERIALCOMM_CBACK)(BYTE port_id);

class USerialComm
{
public:
    USerialComm();
    ~USerialComm();

    int         Send (void *p_data, int size);

    CRITICAL_SECTION m_cs;
    BOOL        OpenPort();
    BOOL        IsOpen();

    void        ClosePort();
    void        Abort (UINT8 err_code, char *p_fmt, ...);

    int         m_instance;

    UINT8       m_active_tid;             // Only for Tester, since there are 2 script tasks
    BYTE        m_port_num;
    HANDLE      m_hComm;
    UINT        m_baud;
    BOOL        m_flow;
    CString     m_szName;
    HANDLE      m_hReadThread;
    DCB         m_dcb;
    OVERLAPPED  m_olRead;
    OVERLAPPED  m_olWrite;
    BOOL        m_bWaitTxComplete;
    UINT        m_maxOutQueue;
    UINT        m_maxInQueue;

    BOOL        m_bWaitingForFetch;

    tSERIALCOMM_CBACK   m_pSerialCommCback;


    BOOL   m_aborting;
};

void transdll_serial_init (UINT32 port_num, UINT32 baud, BOOLEAN flow);
int transdll_serial_send(UINT8 *buf, UINT32 bufsize);
void transdll_serial_close(void);


