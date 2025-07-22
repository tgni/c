/*
 * Copyright: (c) 2006-2007, 2008 Triductor Technology, Inc.
 * All Rights Reserved.
 *
 * File:        types.h
 * Purpose:     The primitive types for the whole project.
 * History:     10/15/2006, created by andyzhou
 */

#ifndef _TYPES_H
#define _TYPES_H

typedef unsigned char		BOOLEAN;
typedef unsigned char		INT8U;
typedef signed char		INT8S;
typedef unsigned short		INT16U;
typedef signed short		INT16S;
typedef unsigned int		INT32U;
typedef signed int		INT32S;
typedef float			FP32;
typedef double			FP64;

typedef long long		INT64S;
typedef unsigned long long	INT64U;
typedef long long		int64_t;
typedef unsigned long long	uint64_t;



typedef unsigned long		ulong_t;
typedef unsigned short		uint16_t;
typedef unsigned char		uint8_t;


typedef long			long_t;
typedef short			int16_t;
typedef signed char		int8_t;

#ifndef _UINT32_T_DECLARED
#define _UINT32_T_DECLARED
typedef unsigned int		uint32_t;
#endif

#ifndef _INT32_T_DECLARED
#define _INT32_T_DECLARED
typedef int			int32_t;
#endif

#define htons(n)		((uint16_t)(((n) & 0xff) << 8) | (((n) & 0xff00) >> 8))
#define htonl(n)		((uint32_t)( \
				(((uint32_t)(n) & (uint32_t)0x000000ffUL) << 24) | \
				(((uint32_t)(n) & (uint32_t)0x0000ff00UL) <<  8) | \
				(((uint32_t)(n) & (uint32_t)0x00ff0000UL) >>  8) | \
				(((uint32_t)(n) & (uint32_t)0xff000000UL) >> 24)))
#define ntohs(n)		htons(n)
#define ntohl(n)		htonl(n)


#define __isr__
#define __plc__
#define __tmr__

#define __PACKED		__attribute__ ((__packed__))

#if defined(D233L)
#if defined(ROLAND1M) || defined(ROLAND1_1M) || defined(MIZAR1M) || defined(VENUS2M) || defined(FPGA_VERSION)
#define __LOCALBSS
#define __LOCALDATA
#define __LOCALTEXT
#if defined(IDLING_TEXT_IN_ROM)
#define __SLOWRODATA		__attribute__ ((section(".srom.rodata")))
#define __SLOWLITERAL		__attribute__ ((section(".srom.literal")))
#define __SLOWTEXT		__attribute__ ((section(".srom.text")))
#define __SLOWTEXT1		__attribute__ ((section(".srom.text")))
#else
#define __SLOWRODATA
#define __SLOWLITERAL
#define __SLOWTEXT
#define __SLOWTEXT1
#endif
#else
#if defined(IDLING_TEXT_IN_ROM)
#define __SLOWRODATA		__attribute__ ((section(".srom.rodata")))
#define __SLOWLITERAL		__attribute__ ((section(".srom.literal")))
#define __SLOWTEXT		__attribute__ ((section(".srom.text")))
#define __SLOWTEXT1		__attribute__ ((section(".srom.text")))
#else
#define __SLOWRODATA
#define __SLOWLITERAL
#define __SLOWTEXT
#define __SLOWTEXT1
#endif
#define __LOCALBSS		__attribute__ ((section(".dram0.bss")))
#define __LOCALDATA		__attribute__ ((section(".dram0.data")))
#if !defined(XTENSA_LINUX_GCC)
#define __LOCALTEXT		__attribute__ ((section(".iram0.text"), rodata_section(".dram0.rodata")))
#else
#define __LOCALTEXT		__attribute__ ((section(".iram0.text")))
#endif
#endif

#elif defined(RISCV)
#define __LOCALBSS		__attribute__ ((section(".dram0.bss")))
#define __LOCALDATA		__attribute__ ((section(".dram0.data")))
#define __LOCALTEXT		__attribute__ ((section(".iram0.text")))

#define __SLOWRODATA
#define __SLOWLITERAL
#if defined(IDLING_TEXT_IN_ROM)
#if defined(VENUS8M)
#define __SLOWTEXT		__attribute__ ((section(".slowtext")))
#define __SLOWTEXT1		__attribute__ ((section(".slowtext1")))
#else
#define __SLOWTEXT		__attribute__ ((section(".slowtext")))
#define __SLOWTEXT1		__attribute__ ((section(".slowtext")))
#endif
#else
#if defined(VENUS8M)
#define __SLOWTEXT		__attribute__ ((section(".slowtext")))
#define __SLOWTEXT1		__attribute__ ((section(".slowtext")))
#else
#define __SLOWTEXT		
#define __SLOWTEXT1
#endif
#endif

#elif defined(ARMCM33)
#define __LOCALBSS		__attribute__ ((section(".local.bss")))
#define __LOCALDATA		__attribute__ ((section(".local.data")))
#define __LOCALTEXT		__attribute__ ((section(".local.text")))
#define __SLOWRODATA
#define __SLOWLITERAL
#if defined(IDLING_TEXT_IN_ROM) || defined(VENUS8M)
#define __SLOWTEXT		__attribute__((section(".slowtext")))
#define __SLOWTEXT1		__attribute__((section(".slowtext")))
#else
#define __SLOWTEXT
#define __SLOWTEXT1
#endif
#endif

#define DISPLAY_MSG		0

#define DISABLE			0
#define ENABLE			1

#define MAX(a,b)		((a) >= (b) ? (a) : (b))
#define MIN(a,b)		((a) <= (b) ? (a) : (b))
#define US_SWAP(a)		((a) = (INT16U)(((INT16U)(a) >> 8) | ((INT16U)(a) << 8)))
#define mod_ceiling(a, b)	(((a) + (b) - 1) / (b))
#define mod_floor(a, b)		((a) / (b))

#ifndef NULL
#define NULL			(void *)0
#endif

#ifndef TRUE
#define TRUE			(1 == 1)
#endif

#ifndef FALSE
#define FALSE			(!TRUE)
#endif

#ifndef OK
#define OK			0
#endif

#ifndef ERROR
#define ERROR			-1
#endif

#ifndef REG32
    #define REG32(x)                    (*(volatile unsigned int *)(x))
    #define REG32_WR(x,v)               (REG32(x) = v)
#endif

#ifndef _REG_FLD_OP_
#define _REG_FLD_OP_

// Register Field Mask
#define FLD_MASK(s,e)              ((0xffffffff >> (31-(e)+(s))) << (s))

// Register Field Mask Write-Data
// s -- Start of Bit  e -- End   of Bit
// v -- Value
#define FLD_MWD(s,e,v)              (((v) << (s)) & FLD_MASK((s),(e)))

// Register Field Mask Read-Data
// s -- Start of Bit  e -- End   of Bit
// v -- Value
#define FLD_MRD(s,e,v)              (((v) & FLD_MASK((s),(e))) >> (s))

// Register Field Write operation
// a -- Address   s -- Start of Bit
// v -- Value     e -- End   of Bit
#define OP_FLD_WR(a,s,e,v)          (REG32_WR((a),((((v) << (s)) & FLD_MASK((s),(e))) | (REG32((a)) & ~FLD_MASK((s),(e))))))
#define OP_FLD_WR_EXC(a,s,e,v)      (REG32_WR((a), (((v) << (s)) & FLD_MASK((s),(e)))))

// Register Field Read operation
#define OP_FLD_RD(a,s,e)            ((REG32((a)) & FLD_MASK((s),(e))) >> (s))

#endif

#ifndef REG8
    #define REG8(x)                    (*(volatile unsigned char *)(x))
#endif

static __inline__ void split_write_two(uint8_t *addr, uint16_t two, uint8_t endian)
{
	uint8_t byte0, byte1;
	
	byte0 = (two & 0xff);
	byte1 = (two & 0xff00) >> 8;

	if (endian) {
		*addr = byte1;
		*(addr+1) = byte0;
	} else {
		*addr = byte0;
		*(addr+1) = byte1;
	}
	
	return;
}

#define split_read_two(addr, endian)			\
	((endian) ?					\
	 (uint16_t)((*(addr) << 8) | (*(addr+1))) :	\
	 (uint16_t)((*(addr)) | (*(addr+1) << 8)))

static __inline__ void split_write_four(uint8_t *addr, uint32_t four, uint8_t endian)
{
	uint8_t byte0, byte1, byte2, byte3;
	
	byte0 = (four & 0xff);
	byte1 = (four & 0xff00) >> 8;
	byte2 = (four & 0xff0000) >> 16;
	byte3 = (four & 0xff000000) >> 24;

	if (endian) {
		*addr     = byte3;
		*(addr+1) = byte2;
		*(addr+2) = byte1;
		*(addr+3) = byte0;
	} else {
		*addr     = byte0;
		*(addr+1) = byte1;
		*(addr+2) = byte2;
		*(addr+3) = byte3;
	}
	return;
}


#define split_read_four(addr, endian)					\
	((endian) ?							\
	 (uint32_t)((*(addr) << 24) | (*(addr+1) << 16) | (*(addr+2) << 8) | (*(addr+3))) : \
	 (uint32_t)((*(addr)) | (*(addr+1) << 8) | (*(addr+2) << 16) | (*(addr+3) << 24)))

/* 0 <= n <= 99 */
#define DEC2BCD(n)	((((n) / 10) << 4) | ((n) % 10))
#define BCD2DEC(n)	(((n) & 0xF) + ((((n) >> 4) & 0xF) * 10))

/* param(len <= 10) is guaranteed by user */
static __inline__ uint64_t nbcd_dec(uint8_t *data, uint8_t len)
{
	uint64_t val = 0;

	while (--len) {
		val += BCD2DEC(data[len]);
		val *= 100;
	}
	val += BCD2DEC(data[len]);

	return val;
}

/* 2-4 bcd to uint32 */
static __inline__ uint32_t nBCD_UHEX(uint8_t *data, uint8_t len)
{
	uint32_t value = 0;
	while (--len) {
		value += BCD2DEC(data[len]);
		value *= 100;
	}
	
	value += BCD2DEC(data[0]);
	return value;
}

/* 2-4 bcd to int32 */
static __inline__ int32_t nBCD_SHEX(uint8_t *data, uint8_t len)
{
	int32_t value = 0;

	if (data[len - 1] & 0x80) {
		data[len - 1] &= 0x7f;
		value = nBCD_UHEX(data, len);
		value = 0 - value;
	} else {
		value = nBCD_UHEX(data, len);
	}

	return value;
}

#endif	/* end of _TYPES_H */
