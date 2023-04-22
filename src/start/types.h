#pragma once
#ifndef HF_TYPES_H
#define HF_TYPES_H
#include<stddef.h>
#include<stdint.h>
// integer type
typedef int8_t  tt_int8;
typedef int16_t tt_int16;
typedef int32_t tt_int32;
typedef int64_t tt_int64;
#define M_INT8_MIN  ((tt_int8 )(INT8_MIN ))
#define M_INT16_MIN ((tt_int16)(INT16_MIN))
#define M_INT32_MIN ((tt_int32)(INT32_MIN))
#define M_INT64_MIN ((tt_int64)(INT64_MIN))
#define M_INT8_MAX  ((tt_int8 )(INT8_MAX ))
#define M_INT16_MAX ((tt_int16)(INT16_MAX))
#define M_INT32_MAX ((tt_int32)(INT32_MAX))
#define M_INT64_MAX ((tt_int64)(INT64_MAX))
typedef uint8_t  tt_uint8;
typedef uint16_t tt_uint16;
typedef uint32_t tt_uint32;
typedef uint64_t tt_uint64;
#define M_UINT8_MIN  ((tt_uint8 )(0))
#define M_UINT16_MIN ((tt_uint16)(0))
#define M_UINT32_MIN ((tt_uint32)(0))
#define M_UINT64_MIN ((tt_uint64)(0))
#define M_UINT8_MAX  ((tt_uint8 )(UINT8_MAX ))
#define M_UINT16_MAX ((tt_uint16)(UINT16_MAX))
#define M_UINT32_MAX ((tt_uint32)(UINT32_MAX))
#define M_UINT64_MAX ((tt_uint64)(UINT64_MAX))
#define MF_INTEGER_MAX(MFP_INTEGER_VARIABLE_NAME) \
	_Generic((MFP_INTEGER_VARIABLE_NAME), \
		int8_t:M_ \
		 \
		 \
		 \
	)
// size type
typedef tt_uint64 tt_size;
// pointer difference type
typedef tt_int64 tt_ptrdiff;
// floating point number type
#endif//!HF_TYPES_H
