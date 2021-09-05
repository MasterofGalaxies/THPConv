/*
 * Name: BteWavInt.h
 * Description: Wave File Interface
 *
 *
 *
 */

#ifndef _BTE_WAV_INT_H
#define _BTE_WAV_INT_H

#include <sys/types.h>

/* Definitions for Microsoft WAVE format */

#define WAV_RIFF		0x46464952
#define WAV_WAVE		0x45564157
#define WAV_FMT			0x20746D66
#define WAV_DATA		0x61746164
#define WAV_DATA_1		0x74636166 /* Hack hack hack! */
#define WAV_PCM_CODE		1

#define WAV_MAX_FILE_LIST	15
#define MAX_FILENAME_LEN    25
#define MAX_PATH_SIZE		225
#define FAKE_READ_SIZE 4608


typedef struct 
{
	unsigned int   fmt_id;		/* 'fmt' */
	unsigned int   fmt_chunk_size;
	unsigned short wFormatTag;
	unsigned short wChannels;
	unsigned int   dwSamplesPerSec;
	unsigned int   dwAvgBytesPerSec;
	unsigned short wBlockAlign;
	unsigned short wBitsPerSample;
} tWavFormatChunk;

typedef struct 
{
	unsigned int data_id;		  /* 'data' */
	unsigned int data_chunk_size; /* size of wave data left in file */
} tWavDataChunk;

typedef struct 
{
	unsigned int riff_id;		/* 'RIFF'  */
	unsigned int file_len;		/* file len - 8 bytes */
	unsigned int wav_id;		/* 'WAVE'  */
	tWavFormatChunk  fmt;
} tWavChunk;

typedef struct 
{
	unsigned int riff_id;		/* 'RIFF'  */
	unsigned int file_len;		/* file len - 8 bytes */
	unsigned int wav_id;		/* 'WAVE'  */
	tWavFormatChunk  fmt;
	tWavDataChunk	 data;
} tWavHeaders;


#endif				/* _BTE_WAV_INT_H */
