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

/* RPL headers. */
#include <rpl/platform.h>

#if defined(RPL_OS_UNIX) || defined(RPL_LIBC_MINGW)
#  include <stdint.h>
typedef int8_t rpl_int8_t;
typedef uint8_t rpl_uint8_t;
typedef int16_t rpl_int16_t;
typedef uint16_t rpl_uint16_t;
typedef int32_t rpl_int32_t;
typedef uint32_t rpl_uint32_t;
typedef int64_t rpl_int64_t;
typedef uint64_t rpl_uint64_t;

#elif defined(RPL_OS_WINDOWS)
#  include <windows.h>
typedef INT8 rpl_int8_t;
typedef UINT8 rpl_uint8_t;
typedef INT16 rpl_int16_t;
typedef UINT16 rpl_uint16_t;
typedef INT32 rpl_int32_t;
typedef UINT32 rpl_uint32_t;
typedef INT64 rpl_int64_t;
typedef UINT64 rpl_uint64_t;
#endif

#endif
