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
 * This header identifies the C library being used.                   *
 **********************************************************************/

#ifndef RPL_LIBC_H_INCLUDED_
#define RPL_LIBC_H_INCLUDED_

/* ISO C headers. */
#include <stddef.h>
#include <stdio.h>

#  if defined(__UCLIBC__)
#    define RPL_LIBC_UCLIBC    1

#  elif defined(__GLIBC__)
#    define RPL_LIBC_GNU       1

#  elif defined(_NEWLIB_VERSION)
#    define RPL_LIBC_NEWLIB    1

#  elif defined(__ECOS__)
#    define RPL_LIBC_ECOS      1

#  elif defined(_MINGW32_VERSION)
#    define RPL_LIBC_MINGW     1

#  elif defined(_MSC_VER)
#    define RPL_LIBC_MICROSOFT 1

#  elif defined(__APPLE__)
#    define RPL_LIBC_APPLE     1

#  elif defined(__sun)
#    define RPL_LIBC_SUN       1

#  elif defined(_HAS_DINKUM_CLIB)
#    define RPL_LIBC_DINKUM    1

#  elif defined(__FreeBSD__)   
#    define RPL_LIBC_FREEBSD   1

#  elif defined(__OpenBSD__)   
#    define RPL_LIBC_OPENBSD   1

#  elif defined(__NetBSD__)    
#    define RPL_LIBC_NETBSD    1

#  else
#    define RPL_LIBC_UNKNOWN   1

#  endif

#endif
