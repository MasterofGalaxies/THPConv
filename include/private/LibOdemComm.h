
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
	// 正常終了
	ODEMCOMM_ERROR_SUCCESS	= 0,
	// 不正なハンドル
	ODEMCOMM_ERROR_INVALID_HANDLE,
	// 不正なパラメータ
	ODEMCOMM_ERROR_INVALID_PARAMETER,
	// その他のエラー
	ODEMCOMM_ERROR,
	// タイムアウトエラー
	ODEMCOMM_ERROR_TIMEOUT,
	// ソケットエラー
	ODEMCOMM_ERROR_SOCKET,
	// ホストアドレスが見つからない
	ODEMCOMM_ERROR_HOST_NOT_FOUND,
	// コネクトできなかった
	ODEMCOMM_ERROR_CONNECT,
	// スレッドが起動できなかった
	ODEMCOMM_ERROR_THREAD,
};

typedef enum _ODEMCOMM_EVENT_ID
{
	// リード
	ODEMCOMM_EVENT_READ,
	// ライト
	ODEMCOMM_EVENT_WRITE,
	// 切断
	ODEMCOMM_EVENT_DISCONNECT,
} ODEMCOMM_EVENT_ID;

typedef struct _ODEMCOMM_CALLBACK_PARAM
{
	ODEMCOMM_EVENT_ID	Event;
	union
	{
		// リードコマンド
		struct Read
		{
			// コマンドパケット
			BYTE Command[12];
			// レスポンスパケット(アプリ側でレスポンスパケットへのポインタを指定する)
			LPCVOID pResponse;
			// レスポンスパケットのバイト数(アプリ側で設定する)
			INT Length;
		} r;
		// ライトコマンド
		struct Write
		{
			// コマンドパケット
			BYTE Command[12];
			// データ(ライトレスポンスパケット)
			LPCVOID pData;
			// データのバイト数
			INT Length;
		} w;
		// 切断
		struct Disconnect
		{
		} d;
	};
	// ユーザーパラメータ
	LPVOID pUserParam;
} ODEMCOMM_CALLBACK_PARAM,*PODEMCOMM_CALLBACK_PARAM;

// コールバック関数
typedef void (WINAPI * ODEMCOMM_Callback)(PODEMCOMM_CALLBACK_PARAM pParam);

// UINT Serial     接続するデバイスのシリアル番号(シリアルを指定しない場合はUINT_MAXを指定する)
// ODEMCOMM_Callback Callback   コールバック関数
// LPVOID pParam   コールバック関数のパラメータに渡す任意のユーザーパラメータ
HODEMCOMM WINAPI ODEMCOMM_Open(UINT Serial,ODEMCOMM_Callback Callback,LPVOID pParam);
//HODEMCOMM WINAPI ODEMCOMM_OpenTcpIp(UINT Serial,INT Port,ODEMCOMM_Callback Callback,LPVOID pParam);
// クローズ
void WINAPI ODEMCOMM_Close(HODEMCOMM Handle);
// PINGコマンドを発行してODEMの応答を確認する
ODEMCOMM_RESULT WINAPI ODEMCOMM_Ping(HODEMCOMM Handle);


#ifdef __cplusplus
}
#endif

#endif /* __LIBODEMCOMM__H__ */

