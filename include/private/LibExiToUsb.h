
/*
 * Mr.EXI,ExiToUsb �f�o�C�X���䃉�C�u����
 *
 *
 * (C)2005 HUDSON SOFT
 *
 * $Header: /home/cvsroot/SDK/include/private/LibExiToUsb.h,v 1.3 2006-07-06 08:21:26 mitu Exp $
 *
 * $History: LibExiToUsb.h $
 * 
 * *****************  Version 5  *****************
 * User: Shimop       Date: 06/03/24   Time: 11:45a
 * Updated in $/Product/ExiToUsb/LibExiToUsb
 * USB1.1�Ή�
 * 
 * *****************  Version 4  *****************
 * User: Shimop       Date: 05/12/26   Time: 1:58p
 * Updated in $/Product/ExiToUsb/LibExiToUsb
 * EXITOUSB_DEVICE_INFO�\���̂̃p�X�������o�[��LPCTSTR����TCHAR�̔z��ɕ�
 * �X
 * 
 * *****************  Version 3  *****************
 * User: Shimop       Date: 05/12/13   Time: 5:29p
 * Updated in $/Product/ExiToUsb/LibExiToUsb
 * �V���A���ԍ��Ή�
 * 
 * *****************  Version 2  *****************
 * User: Shimop       Date: 05/12/13   Time: 10:51
 * Updated in $/Product/ExiToUsb/LibExiToUsb
 * 
 * *****************  Version 1  *****************
 * User: Shimop       Date: 05/12/13   Time: 10:39
 * Created in $/Product/ExiToUsb/LibExiToUsb
 * 
 *
 * $NoKeywords: $
 */

#if !defined(__LIBEXITOUSB_H_INCLUDE__)
#define __LIBEXITOUSB_H_INCLUDE__

#ifdef LIBEXITOUSB_USE_NAMESPACE
namespace LibExiToUsb
{
#endif /* LIBEXITOUSB_USE_NAMESPACE */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

	/* Error code */
	typedef enum tagEXITOUSB_RESULT
	{
		EXITOUSB_ERROR_SUCCESS,				/* ����I�� */
		EXITOUSB_ERROR_DEVICE_OPEN,			/* �f�o�C�X���I�[�v���ł��Ȃ����� */
		EXITOUSB_ERROR_INVALID_HANDLE,		/* �s���ȃn���h�� */
		EXITOUSB_ERROR_INVALID_PARAMETER,	/* �s���ȃp�����[�^ */
		EXITOUSB_ERROR_OPERATION,			/* ���삪����Ɋ������Ȃ����� */
		EXITOUSB_ERROR_NOTIMPLEMENT,		/* ��������Ă��Ȃ��@�\(EXI2USB�ɂ͗L�邪�AMr.EXI�ɂ͖����@�\�Ȃ�) */
		EXITOUSB_ERROR_DEVICE_TYPE,			/* OpenEx �Ŏw�肵���f�o�C�X�^�C�v����v���Ȃ� */
	} EXITOUSB_RESULT;

	/* USB Endpoint descriptor */
	typedef struct tagEXITOUSB_ENDPOINT_DESCRIPTOR
	{
	    UCHAR bLength;
	    UCHAR bDescriptorType;
	    UCHAR bEndpointAddress;
	    UCHAR bmAttributes;
	    USHORT wMaxPacketSize;
	    UCHAR bInterval;
	} EXITOUSB_ENDPOINT_DESCRIPTOR,*PEXITOUSB_ENDPOINT_DESCRIPTOR;

	/* Device type */
	typedef enum tagEXITOUSB_DEVICE_TYPE
	{
		EXITOUSB_DEVICE_ALL,				/* ���ׂẴf�o�C�X */
		EXITOUSB_DEVICE_EXI01,				/* EXI to USB (Mr.EXI�̃f�o�C�X) */
		EXITOUSB_DEVICE_EXI2,				/* EXI to USB (�f�o�b�K�p) */
		EXITOUSB_DEVICE_UNKNOWN = 0xffff,	/* �s���ȃf�o�C�X */
		EXITOUSB_DEVICE_MREXI = EXITOUSB_DEVICE_EXI01,		/* Mr.EXI */
		EXITOUSB_DEVICE_EXITOUSB = EXITOUSB_DEVICE_EXI2,	/* EXI to USB */
	} EXITOUSB_DEVICE_TYPE;

	/* Version information */
	typedef struct tagEXITOUSB_VERSION_INFO
	{
		UINT	DriverVersion;		/* �f�o�C�X�h���C�o�[�̃o�[�W���� */
		UINT	FirmwareVersion;	/* �t�@�[���E�G�A�̃o�[�W���� */
		UINT	FpgaVersion;		/* FPGA�̃o�[�W���� */
		EXITOUSB_DEVICE_TYPE Type;	/* �f�o�C�X�̃^�C�v */

	} EXITOUSB_VERSION_INFO,*PEXITOUSB_VERSION_INFO;

	/* FPGA register address */
	typedef enum tagEXITOUSB_REGISTER
	{
		EXITOUSB_REG_CSR		= 0x00000000,	/* Status register */
		EXITOUSB_REG_RXD		= 0x00000004,	/* Rx-Data(�d�l�����Tx-Data) */
		EXITOUSB_REG_TXD		= 0x00000008,	/* Tx-Data(�d�l�����Rx-Data) */
		EXITOUSB_REG_SYS_VER	= 0x0000000C,	/* Version */
		EXITOUSB_REG_USB_FIFO_LEN = 0x00000010,	/* USB FIFO LEN */
		EXITOUSB_REG_RAM		= 0x00010000,	/* RAM start address */
		EXITOUSB_REG_RAM_END	= 0x00013FFF,	/* RAM start address */
		EXITOUSB_REG_RAM_SIZE	= 0x00004000,	/* RAM size */
	} EXITOUSB_REGISTER;

	/* USB_CSR Register */
	typedef enum tagEXITOUSB_CSR_BITS
	{
		EXITOUSB_CSR_SYS_HRESET			=	(1 << 7),	/* HReset */
		EXITOUSB_CSR_SYS_SRESET			=	(1 << 6),	/* SReset */
		EXITOUSB_CSR_SYS_DBG_HWRESET	=	(1 << 5),	/* Debug HW Reset */
		EXITOUSB_CSR_GPIO3				=	(1 << 4),	/* DI,AI�ʓd��Ԃ̂Ƃ� 1 */
		EXITOUSB_CSR_TX_RDY				=	(1 << 3),	/* Tx Ready 0�̎����M�\ (�d�l����� Rx Ready) */
		EXITOUSB_CSR_RX_RDY				=	(1 << 2),	/* Rx Ready 0�̎���M (�d�l����� Tx Ready) */
		EXITOUSB_CSR_CONCNT				=	(1 << 1),	/* 0.CONNECT�M��High�o�� 1.CONNECT�M���n�C�C���s�[�_���X */
		EXITOUSB_CSR_POWCNT				=	(1 << 0),	/* 0.POWER_SW�M��High�o�� 1.POWER_SW�M���n�C�C���s�[�_���X */
	} EXITOUSB_CSR_BITS;

	typedef enum tagEXITOUSB_RESET_BITS
	{
		EXITOUSB_RESET_HRESET	= EXITOUSB_CSR_SYS_HRESET,	/* HReset */
		EXITOUSB_RESET_SRESET	= EXITOUSB_CSR_SYS_SRESET,	/* SReset */
		EXITOUSB_RESET_DBG_HWRESET = EXITOUSB_CSR_SYS_DBG_HWRESET,	/* Debug HW Reset */
	} EXITOUSB_RESET_BITS;

	typedef struct tagEXITOUSB_DEVICE_INFO
	{
		DWORD Size;					/* ���̍\���̂̃T�C�Y */
		TCHAR DevicePath[260];		/* �f�o�C�X�p�X�� */
		EXITOUSB_DEVICE_TYPE Type;	/* �f�o�C�X�̎�� */
		DWORD Serial;				/* �V���A���ԍ� BCD8�� */
	} EXITOUSB_DEVICE_INFO,*PEXITOUSB_DEVICE_INFO;

	// EXITOUSB_EnumDevice �̃R�[���o�b�N�֐��^
	typedef BOOL (CALLBACK *EXITOUSB_ENUM_CALLBACK)(LPCTSTR PathName,EXITOUSB_DEVICE_TYPE Type,LPVOID Param);
	typedef BOOL (CALLBACK *EXITOUSB_ENUM_CALLBACK2)(PEXITOUSB_DEVICE_INFO Info,LPVOID Param);

	// Device handle
	typedef struct
	{
		UINT	unused;
	} *EXITOUSB_HANDLE;

	// EXITOUSB_GetStatus �Ŏ擾�����X�e�[�^�X�̔���
	// ���M�\�̂Ƃ� true
#define EXITOUSB_IS_TX_RDY(_csr_)	(((_csr_) & EXITOUSB_CSR_TX_RDY) == 0)
	// ��M���Ă���Ƃ� true
#define EXITOUSB_IS_RX_RDY(_csr_)	(((_csr_) & EXITOUSB_CSR_RX_RDY) == 0)

	INT WINAPI EXITOUSB_EnumDevice(EXITOUSB_DEVICE_TYPE Type,EXITOUSB_ENUM_CALLBACK Callback,LPVOID pParam);
	INT WINAPI EXITOUSB_EnumDevice2(EXITOUSB_DEVICE_TYPE Type,EXITOUSB_ENUM_CALLBACK2 Callback,LPVOID pParam);
	EXITOUSB_RESULT WINAPI EXITOUSB_Open(LPCTSTR pDevicePath,BOOL Shared,EXITOUSB_HANDLE* pHandle);
	EXITOUSB_RESULT WINAPI EXITOUSB_OpenEx(EXITOUSB_DEVICE_TYPE Type,LPCTSTR pDevicePath,BOOL Shared,EXITOUSB_HANDLE* pHandle);
	EXITOUSB_RESULT WINAPI EXITOUSB_Close(EXITOUSB_HANDLE Handle);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetDeviceType(EXITOUSB_HANDLE Handle,EXITOUSB_DEVICE_TYPE* pType);
	EXITOUSB_RESULT WINAPI EXITOUSB_WriteSharedMemory(EXITOUSB_HANDLE Handle,UINT Address,INT Length,LPCVOID pBuffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_ReadSharedMemory(EXITOUSB_HANDLE Handle,UINT Address,INT Length,LPVOID pBuffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetLastError(EXITOUSB_HANDLE Handle);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetWin32LastError(EXITOUSB_HANDLE Handle,LPDWORD pErrorCode);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetStatus(EXITOUSB_HANDLE Handle,LPWORD pBuffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_SetStatus(EXITOUSB_HANDLE Handle,WORD Value);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetRxD(EXITOUSB_HANDLE Handle,LPDWORD pBuffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_SetTxD(EXITOUSB_HANDLE Handle,DWORD Value);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetSystemVersion(EXITOUSB_HANDLE Handle,PEXITOUSB_VERSION_INFO pVersion);
	EXITOUSB_RESULT WINAPI EXITOUSB_SetReset(EXITOUSB_HANDLE Handle,EXITOUSB_RESET_BITS On,EXITOUSB_RESET_BITS Off);
	BOOL WINAPI EXITOUSB_IsValidDevice(EXITOUSB_HANDLE Handle);

	EXITOUSB_RESULT WINAPI EXITOUSB_WriteRegister(EXITOUSB_HANDLE Handle,UINT Address,INT Length,const WORD* Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_ReadRegister(EXITOUSB_HANDLE Handle,UINT Address,INT Length,PWORD Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_ReadEEPROM(EXITOUSB_HANDLE Handle,BYTE DeviceAddress,BOOL bWordAddress,WORD Address,WORD Length,LPVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_WriteEEPROM(EXITOUSB_HANDLE Handle,BYTE DeviceAddress,BOOL bWordAddress,WORD Address,WORD Length,LPCVOID Buffer);
	VOID WINAPI EXITOUSB_GetDeviceGuid(LPGUID pGuid);
	EXITOUSB_RESULT WINAPI EXITOUSB_WriteFlashMemory(EXITOUSB_HANDLE Handle,UINT Address,INT Length,LPCVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_ReadFlashMemory(EXITOUSB_HANDLE Handle,UINT Address,INT Length,LPVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_EraseMemory(EXITOUSB_HANDLE Handle);
	EXITOUSB_RESULT WINAPI EXITOUSB_ReadMemory(EXITOUSB_HANDLE Handle,WORD Address,WORD Length,LPVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_WriteMemory(EXITOUSB_HANDLE Handle,WORD Address,WORD Length,LPCVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_DownloadFirmware(EXITOUSB_HANDLE Handle,WORD Length,LPCVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_Configuration(EXITOUSB_HANDLE Handle,INT Length,LPCVOID Buffer);
	EXITOUSB_RESULT WINAPI EXITOUSB_GetSerialNumber(EXITOUSB_HANDLE Handle,LPDWORD Serial);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef LIBEXITOUSB_USE_NAMESPACE
}
#endif

#endif	/* __LIBEXITOUSB_H_INCLUDE__ */
