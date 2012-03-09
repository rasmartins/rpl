/**********************************************************************
 * Copyright (C) 2012 Ricardo Martins                                 *
 **********************************************************************
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public License *
 * as published by the Free Software Foundation; either version 2.1   *
 * of the License, or (at your option) any later version.             *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        *
 * Boston, MA 02110-1301 USA                                          *
 **********************************************************************
 * Platform identification macros.                                    *
 **********************************************************************/

#ifndef RPL_INTEGERS_H_INCLUDED_
#define RPL_INTEGERS_H_INCLUDED_

/**
 * @defgroup INTEGERS Integers
 * @{
 */

/* ISO C headers. */
#include <stddef.h>

/* RPL headers. */
#include <rpl/platform.h>

#if defined(RPL_OS_UNIX) || defined(RPL_LIBC_MINGW)
#  include <stdint.h>
/** 8 bit signed integer. */
typedef int8_t rpl_int8_t;
/** 8 bit unsigned integer. */
typedef uint8_t rpl_uint8_t;
/** 16 bit signed integer. */
typedef int16_t rpl_int16_t;
/** 16 bit unsigned integer. */
typedef uint16_t rpl_uint16_t;
/** 32 bit signed integer. */
typedef int32_t rpl_int32_t;
/** 32 bit unsigned integer. */
typedef uint32_t rpl_uint32_t;
/** 64 bit signed integer. */
typedef int64_t rpl_int64_t;
/** 64 bit unsigned integer. */
typedef uint64_t rpl_uint64_t;
/** Integer capable of holding the maximum size of any object. */
typedef size_t rpl_size_t;
/** Signed version of rpl_size_t. */
typedef ssize_t rpl_ssize_t;

#elif defined(RPL_OS_WINDOWS)
#  include <windows.h>
/** 8 bit signed integer. */
typedef INT8 rpl_int8_t;
/** 8 bit unsigned integer. */
typedef UINT8 rpl_uint8_t;
/** 16 bit signed integer. */
typedef INT16 rpl_int16_t;
/** 16 bit unsigned integer. */
typedef UINT16 rpl_uint16_t;
/** 32 bit signed integer. */
typedef INT32 rpl_int32_t;
/** 32 bit unsigned integer. */
typedef UINT32 rpl_uint32_t;
/** 64 bit signed integer. */
typedef INT64 rpl_int64_t;
/** 64 bit unsigned integer. */
typedef UINT64 rpl_uint64_t;
/** Integer capable of holding the maximum size of any object. */
typedef SIZE_T rpl_size_t;
/** Signed version of rpl_size_t. */
typedef SSIZE_T rpl_ssize_t;
#endif

/** Boolean type. */
typedef enum
{
  /** False. */
  RPL_FALSE = 0,
  /** True. */
  RPL_TRUE = 1
} rpl_boolean_t;

/** @} */

#endif
