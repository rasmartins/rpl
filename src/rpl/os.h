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
 **********************************************************************/

#ifndef RPL_OS_H_INCLUDED_
#define RPL_OS_H_INCLUDED_

/* Linux. */
#if defined(__linux__)
#  define RPL_OS_LINUX   1
#  define RPL_OS_UNIX    1

/* Microsoft Windows. */
#elif defined(__WIN32)
#  define RPL_OS_WINDOWS 1

/* Apple Mac OS X (Darwin). */
#elif defined(__APPLE__)
#  define RPL_OS_DARWIN  1
#  define RPL_OS_UNIX    1

/* FreeBSD. */
#elif defined(__FreeBSD__)
#  define RPL_OS_FREEBSD 1
#  define RPL_OS_UNIX    1

/* OpenBSD. */
#elif defined(__OpenBSD__)
#  define RPL_OS_OPENBSD 1
#  define RPL_OS_UNIX    1

/* NetBSD. */
#elif defined(__NetBSD__)
#  define RPL_OS_NETBSD  1
#  define RPL_OS_UNIX    1

/* QNX Neutrino. */
#elif defined(__QNXNTO__)
#  define RPL_OS_QNX6    1
#  define RPL_OS_UNIX    1

/* Unknown operating system. */
#else
#  define RPL_OS_UNKNOWN 1
#endif

#endif
