
/*
 * NNGC Optical Disc EMulator Communication Library.
 *
 * (C)2006 HUDSON SOFT
 *
 * $Revision: 1.2 $
 *
 */

#ifndef __LIBODEMCOMM__H__
#define __LIBODEMCOMM__H__

#ifdef __cplusplus
extern "C"
{
#endif

enum ODEM_NET_COMMANDS
{
	ODEM_NET_PING,
	ODEM_NET_GET_SERIAL,
	ODEM_NET_DI_RESPONSE,
	ODEM_NET_DI_WRITERES,
	ODEM_NET_DI_COMMAND,
	ODEM_NET_DISCONNECT,
};

typedef struct _ODEM_COM_HEADER
{
	UINT Command;
	UINT Length;
} ODEM_COM_HEADER,*PODEM_COM_HEADER;

#define DI_FILE_MAPPING_NAME_FORMAT	_T("NNGC_DITOUSB_MAP#%08x{2FAF9047-2091-4ce5-B668-02789604466E}")
#define DI_MUTEX_NAME_FORMAT		_T("NNGC_DITOUSB_MTX#%08x{2FAF9047-2091-4ce5-B668-02789604466E}")
#define DI_RECV_EVENT_NAME_FORMAT	_T("NNGC_DITOUSB_RCV#%08x{2FAF9047-2091-4ce5-B668-02789604466E}")
#define DI_SEND_EVENT_NAME_FORMAT	_T("NNGC_DITOUSB_SND#%08x{2FAF9047-2091-4ce5-B668-02789604466E}")
#define SHARED_BUFFER_SIZE	(1024*1024*32+1024)

typedef struct { unsigned _unused; } *HODEMCOMM;

enum ODEMCOMM_RESULT
{
	// ����I��
	ODEMCOMM_ERROR_SUCCESS	= 0,
	// �s���ȃn���h��
	ODEMCOMM_ERROR_INVALID_HANDLE,
	// �s���ȃp�����[�^
	ODEMCOMM_ERROR_INVALID_PARAMETER,
	// ���̑��̃G���[
	ODEMCOMM_ERROR,
	// �^�C���A�E�g�G���[
	ODEMCOMM_ERROR_TIMEOUT,
	// �\�P�b�g�G���[
	ODEMCOMM_ERROR_SOCKET,
	// �z�X�g�A�h���X��������Ȃ�
	ODEMCOMM_ERROR_HOST_NOT_FOUND,
	// �R�l�N�g�ł��Ȃ�����
	ODEMCOMM_ERROR_CONNECT,
	// �X���b�h���N���ł��Ȃ�����
	ODEMCOMM_ERROR_THREAD,
};

typedef enum _ODEMCOMM_EVENT_ID
{
	// ���[�h
	ODEMCOMM_EVENT_READ,
	// ���C�g
	ODEMCOMM_EVENT_WRITE,
	// �ؒf
	ODEMCOMM_EVENT_DISCONNECT,
} ODEMCOMM_EVENT_ID;

typedef struct _ODEMCOMM_CALLBACK_PARAM
{
	ODEMCOMM_EVENT_ID	Event;
	union
	{
		// ���[�h�R�}���h
		struct Read
		{
			// �R�}���h�p�P�b�g
			BYTE Command[12];
			// ���X�|���X�p�P�b�g(�A�v�����Ń��X�|���X�p�P�b�g�ւ̃|�C���^���w�肷��)
			LPCVOID pResponse;
			// ���X�|���X�p�P�b�g�̃o�C�g��(�A�v�����Őݒ肷��)
			INT Length;
		} r;
		// ���C�g�R�}���h
		struct Write
		{
			// �R�}���h�p�P�b�g
			BYTE Command[12];
			// �f�[�^(���C�g���X�|���X�p�P�b�g)
			LPCVOID pData;
			// �f�[�^�̃o�C�g��
			INT Length;
		} w;
		// �ؒf
		struct Disconnect
		{
		} d;
	};
	// ���[�U�[�p�����[�^
	LPVOID pUserParam;
} ODEMCOMM_CALLBACK_PARAM,*PODEMCOMM_CALLBACK_PARAM;

// �R�[���o�b�N�֐�
typedef void (WINAPI * ODEMCOMM_Callback)(PODEMCOMM_CALLBACK_PARAM pParam);

// UINT Serial     �ڑ�����f�o�C�X�̃V���A���ԍ�(�V���A�����w�肵�Ȃ��ꍇ��UINT_MAX���w�肷��)
// ODEMCOMM_Callback Callback   �R�[���o�b�N�֐�
// LPVOID pParam   �R�[���o�b�N�֐��̃p�����[�^�ɓn���C�ӂ̃��[�U�[�p�����[�^
HODEMCOMM WINAPI ODEMCOMM_Open(UINT Serial,ODEMCOMM_Callback Callback,LPVOID pParam);
//HODEMCOMM WINAPI ODEMCOMM_OpenTcpIp(UINT Serial,INT Port,ODEMCOMM_Callback Callback,LPVOID pParam);
// �N���[�Y
void WINAPI ODEMCOMM_Close(HODEMCOMM Handle);
// PING�R�}���h�𔭍s����ODEM�̉������m�F����
ODEMCOMM_RESULT WINAPI ODEMCOMM_Ping(HODEMCOMM Handle);


#ifdef __cplusplus
}
#endif

#endif /* __LIBODEMCOMM__H__ */

