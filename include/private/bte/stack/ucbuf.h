#ifndef UCBUF_H
#define UCBUF_H


typedef struct {
    /* public data-- these variables are set by the client after calling ucbuf_init() */
    UINT8           *p;         /* pointer to data buffer */
    UINT16          size;       /* data buffer size in bytes */
    /* private data-- this variables shall not be modified by the user */
    UINT16          w_s;        /* write start */
    UINT16          w_e;        /* write end */
    UINT16          r_s;        /* read start */
    UINT16          r_e;        /* read end */
    UINT8           nesting;    /* nesting level */
} tUCBUF_CB;


void UCBUF_Init(tUCBUF_CB *p_cb);
UINT8 *UCBUF_ReadStart(tUCBUF_CB *p_cb, UINT16 *p_len);
void UCBUF_ReadEnd(tUCBUF_CB *p_cb, UINT16 len);
UINT16 UCBUF_Read(tUCBUF_CB *p_cb, UINT8 *p_data, UINT16 len);

UINT8 *UCBUF_WriteStart(tUCBUF_CB *p_cb, UINT16 *p_len);
void UCBUF_WriteEnd(tUCBUF_CB *p_cb);
UINT16 UCBUF_Write(tUCBUF_CB *p_cb, UINT8 *p_data, UINT16 len);



#endif /* UCBUF_H */
