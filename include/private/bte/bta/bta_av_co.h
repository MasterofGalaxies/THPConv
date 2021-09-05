/*****************************************************************************
**
**  Name:           bta_av_co.h
**
**  Description:    This is the interface file for advanced audio/video call-out
**                  functions.
**
**  Copyright (c) 2003, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_AV_CO_H
#define BTA_AV_CO_H

#include <private/bte/bta/bta_av_api.h>

enum
{
    BTA_AV_CO_ST_INIT,
    BTA_AV_CO_ST_IN,
    BTA_AV_CO_ST_OUT,
    BTA_AV_CO_ST_OPEN,
    BTA_AV_CO_ST_STREAM
};

/* data type for the Video Codec Information Element*/
typedef struct
{
    UINT8   codec_type;     /* Codec type */
    UINT8   levels;         /* level mask */
} tBTA_AV_VIDEO_CFG;

/*******************************************************************************
**
** Function         bta_av_co_audio_init
**
** Description      This callout function is executed by AV when it is
**                  started by calling BTA_AvEnable().  This function can be
**                  used by the phone to initialize audio paths or for other
**                  initialization purposes.  
**                  
**
** Returns          Stream codec and content protection capabilities info.
**
*******************************************************************************/
BTA_API extern BOOLEAN bta_av_co_audio_init(UINT8 *p_codec_type, UINT8 *p_codec_info,
                                   UINT8 *p_num_protect, UINT8 *p_protect_info, UINT8 index);

/*******************************************************************************
**
** Function         bta_av_co_video_init
**
** Description      This callout function is executed by AV when it is
**                  started by calling BTA_AvEnable().  This function can be
**                  used by the phone to initialize video paths or for other
**                  initialization purposes.  
**                  
**
** Returns          Stream codec and content protection capabilities info.
**
*******************************************************************************/
BTA_API extern BOOLEAN bta_av_co_video_init(UINT8 *p_codec_type, UINT8 *p_codec_info,
                                   UINT8 *p_num_protect, UINT8 *p_protect_info, UINT8 index);

/*******************************************************************************
**
** Function         bta_av_co_audio_disc_res
**
** Description      This callout function is executed by AV to report the
**                  number of stream end points (SEP) were found during the
**                  AVDT stream discovery process.
**                  
**
** Returns          void.
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_disc_res(tBTA_AV_HNDL hndl, UINT8 num_seps,
                                             UINT8 num_snk, BD_ADDR addr);

/*******************************************************************************
**
** Function         bta_av_co_video_disc_res
**
** Description      This callout function is executed by AV to report the
**                  number of stream end points (SEP) were found during the
**                  AVDT stream discovery process.
**                  
**
** Returns          void.
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_disc_res(tBTA_AV_HNDL hndl, UINT8 num_seps,
                                             UINT8 num_snk, BD_ADDR addr);

/*******************************************************************************
**
** Function         bta_av_co_audio_getconfig
**
** Description      This callout function is executed by AV to retrieve the
**                  desired codec and content protection configuration for the
**                  audio stream.
**                  
**
** Returns          Stream codec and content protection configuration info.
**
*******************************************************************************/
BTA_API extern UINT8 bta_av_co_audio_getconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                         UINT8 *p_codec_info, UINT8 *p_sep_info_idx, UINT8 seid,
                                         UINT8 *p_num_protect, UINT8 *p_protect_info);

/*******************************************************************************
**
** Function         bta_av_co_video_getconfig
**
** Description      This callout function is executed by AV to retrieve the
**                  desired codec and content protection configuration for the
**                  video stream.
**                  
**
** Returns          Stream codec and content protection configuration info.
**
*******************************************************************************/
BTA_API extern UINT8 bta_av_co_video_getconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type,
                                         UINT8 *p_codec_info, UINT8 *p_sep_info_idx, UINT8 seid,
                                         UINT8 *p_num_protect, UINT8 *p_protect_info);

/*******************************************************************************
**
** Function         bta_av_co_audio_setconfig
**
** Description      This callout function is executed by AV to set the
**                  codec and content protection configuration of the audio stream.  
**                  
**
** Returns          void  
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_setconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type, UINT8 *p_codec_info,
                                        UINT8 seid, BD_ADDR addr,
                                        UINT8 num_protect, UINT8 *p_protect_info);

/*******************************************************************************
**
** Function         bta_av_co_video_setconfig
**
** Description      This callout function is executed by AV to set the
**                  codec and content protection configuration of the video stream.  
**                  
**
** Returns          void  
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_setconfig(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type, UINT8 *p_codec_info,
                                        UINT8 seid, BD_ADDR addr,
                                        UINT8 num_protect, UINT8 *p_protect_info);

/*******************************************************************************
**
** Function         bta_av_co_audio_open
**
** Description      This function is called by AV when the audio stream connection
**                  is opened.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_open(tBTA_AV_HNDL hndl, 
                                         tBTA_AV_CODEC codec_type, UINT8 *p_codec_info, 
                                         UINT16 mtu);

/*******************************************************************************
**
** Function         bta_av_co_video_open
**
** Description      This function is called by AV when the video stream connection
**                  is opened.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_open(tBTA_AV_HNDL hndl, 
                                         tBTA_AV_CODEC codec_type, UINT8 *p_codec_info, 
                                         UINT16 mtu);

/*******************************************************************************
**
** Function         bta_av_co_audio_close
**
** Description      This function is called by AV when the audio stream connection
**                  is closed.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_close(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_video_close
**
** Description      This function is called by AV when the video stream connection
**                  is closed.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_close(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_audio_start
**
** Description      This function is called by AV when the audio streaming data
**                  transfer is started.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_start(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_video_start
**
** Description      This function is called by AV when the video streaming data
**                  transfer is started.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_start(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_audio_stop
**
** Description      This function is called by AV when the audio streaming data
**                  transfer is stopped.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_audio_stop(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_video_stop
**
** Description      This function is called by AV when the video streaming data
**                  transfer is stopped.
**                  
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_stop(tBTA_AV_HNDL hndl, tBTA_AV_CODEC codec_type);

/*******************************************************************************
**
** Function         bta_av_co_audio_src_data_path
**
** Description      This function is called to get the next data buffer from
**                  the audio codec
**
** Returns          NULL if data is not ready.
**                  Otherwise, a GKI buffer (BT_HDR*) containing the audio data.
**
*******************************************************************************/
BTA_API extern void * bta_av_co_audio_src_data_path(tBTA_AV_CODEC codec_type,
                                                    UINT32 *p_len, UINT32 *p_timestamp);

/*******************************************************************************
**
** Function         bta_av_co_video_src_data_path
**
** Description      This function is called to get the next data buffer from
**                  the video codec.                 
**
** Returns          NULL if data is not ready.
**                  Otherwise, a video data buffer (UINT8*).
**
*******************************************************************************/
BTA_API extern void * bta_av_co_video_src_data_path(tBTA_AV_CODEC codec_type,
                                                    UINT32 *p_len, UINT32 *p_timestamp);

/*******************************************************************************
**
** Function         bta_av_co_video_report_conn
**
** Description      This function is called by AV when the reporting channel is
**                  opened (open=TRUE) or closed (open=FALSE).
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_report_conn (BOOLEAN open, UINT8 avdt_handle);

/*******************************************************************************
**
** Function         bta_av_co_video_report_rr
**
** Description      This function is called by AV when a Receiver Report is
**                  received
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void bta_av_co_video_report_rr (UINT32 packet_lost);

#endif /* BTA_AV_CO_H */

