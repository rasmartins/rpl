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

#ifndef RPL_PLATFORM_H_INCLUDED_
#define RPL_PLATFORM_H_INCLUDED_

/* ISO C headers. */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* Microsoft Windows headers. */
#if defined(__WIN32)
#  include <windows.h>
#endif

#if defined(__UCLIBC__)
/** Defined if C library is uClibc. */
#  define RPL_LIBC_UCLIBC    1

#elif defined(__GLIBC__)
/** Defined if C library is GLIBC. */
#  define RPL_LIBC_GNU       1

#elif defined(_NEWLIB_VERSION)
/** Defined if C library is Newlib. */
#  define RPL_LIBC_NEWLIB    1

#elif defined(__ECOS__)
/** Defined if C library is eCos. */
#  define RPL_LIBC_ECOS      1

#elif defined(__MINGW32_VERSION)
/** Defined if C library is MinGW. */
#  define RPL_LIBC_MINGW     1

#elif defined(_MSC_VER)
/** Defined if C library is Microsoft. */
#  define RPL_LIBC_MICROSOFT 1

#elif defined(__APPLE__)
/** Defined if C library is Apple. */
#  define RPL_LIBC_APPLE     1

#elif defined(__sun)
/** Defined if C library is SUN. */
#  define RPL_LIBC_SUN       1

#elif defined(_HAS_DINKUM_CLIB)
/** Defined if C library is Dinkum. */
#  define RPL_LIBC_DINKUM    1

#elif defined(__FreeBSD__)   
/** Defined if C library is FreeBSD. */
#  define RPL_LIBC_FREEBSD   1

#elif defined(__OpenBSD__)   
/** Defined if C library is OpenBSD. */
#  define RPL_LIBC_OPENBSD   1

#elif defined(__NetBSD__)    
/** Defined if C library is NetBSD. */
#  define RPL_LIBC_NETBSD    1

#elif defined(__DragonFly__)    
/** Defined if C library is DragonFly. */
#  define RPL_LIBC_DRAGONFLY 1

#else
/** Defined if C library is unknown. */
#  define RPL_LIBC_UNKNOWN   1
#endif

#if defined(__INTEL_COMPILER)
/** Defined if C compiler is Intel. */
#  define RPL_CC_INTEL       1

#elif defined(__SUNPRO_C)
/** Defined if C compiler is Sun Studio/Sun Pro compiler. */
#  define RPL_CC_SUN         1

#elif defined(__clang__)
/** Defined if C compiler is LLVM/Clang. */
#  define RPL_CC_CLANG       1

#elif defined(__GNUC__)
/** Defined if C compiler is GNU. */
#  define RPL_CC_GNU         1

#elif defined(_MSC_VER)
/** Defined if C compiler is Microsoft compiler. */
#  define RPL_CC_MICROSOFT   1

#else
/** Defined if C compiler is unknown. */
#  define RPL_CC_UNKNOWN     1
#endif

#if defined(__linux__)
/** Defined if operating system is Linux. */
#  define RPL_OS_LINUX       1
#  define RPL_OS_UNIX        1

#elif defined(__WIN32)
/** Defined if operating system is Microsoft Windows. */
#  define RPL_OS_WINDOWS     1

#elif defined(__APPLE__)
/** Defined if operating system is Mac OS X (Darwin). */
#  define RPL_OS_DARWIN      1
#  define RPL_OS_UNIX        1

#elif defined(__FreeBSD__)
/** Defined if operating system is OpenBSD. */
#  define RPL_OS_FREEBSD     1
#  define RPL_OS_UNIX        1
#  define RPL_OS_BSD         1

#elif defined(__OpenBSD__)
/** Defined if operating system is OpenBSD. */
#  define RPL_OS_OPENBSD     1
#  define RPL_OS_UNIX        1
#  define RPL_OS_BSD         1

#elif defined(__NetBSD__)
/** Defined if operating system is NetBSD. */
#  define RPL_OS_NETBSD      1
#  define RPL_OS_UNIX        1
#  define RPL_OS_BSD         1

#elif defined(__DragonFly__)    
/** Defined if operating system is DragonFly BSD. */
#  define RPL_OS_DRAGONFLY   1
#  define RPL_OS_UNIX        1
#  define RPL_OS_BSD         1

#elif defined(__QNXNTO__)
/** Defined if operating system is QNX Neutrino. */
#  define RPL_OS_QNX6        1
#  define RPL_OS_UNIX        1

#else
/** Defined if operating system is unknown. */
#  define RPL_OS_UNKNOWN     1
#endif

#if defined(__amd64__) || defined(_AMD64) || defined (__x86_64__) || defined(_M_X64)
/** Defined if CPU is x86-64/amd64. */
#  define RPL_CPU_X86        1
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__i386__) || defined(_M_IX86) || defined(__x86_32__)
/** Defined if CPU is x86. */
#  define RPL_CPU_X86        1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__powerpc64__)
/** Defined if CPU is PowerPC 64-bit. */
#  define RPL_CPU_POWERPC    1
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__powerpc__) || defined(__ppc__) || defined(PPC)
/** Defined if CPU is PowerPC 32-bit. */
#  define RPL_CPU_POWERPC    1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__ARM_ARCH_4T__)
/** Defined if CPU is ARM v4. */
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM4T      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__ARM_ARCH_5T__)
/** Defined if CPU is ARM v5. */
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM5T      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__ARM_ARCH_7A__)
/** Defined if CPU is ARM v7. */
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM7A      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__arm__)
/** Defined if CPU is generic ARM. */
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__sparcv9__)
/** Defined if CPU is SPARC v9. */
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__sparcv8__)
/** Defined if CPU is SPARC v8. */
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__sparc__)
/** Defined if CPU is SPARC. */
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__MIPSEL__)
/** Defined if CPU is MIPS. */
#  define RPL_CPU_MIPS       1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__MIPSEB__)
/** Defined if CPU is MIPS. */
#  define RPL_CPU_MIPS       1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__avr32__)
/** Defined if CPU is AVR32. */
#  define RPL_CPU_AVR32      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__alpha__)
/** Defined if CPU is Alpha. */
#  define RPL_CPU_ALPHA      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#else
/** Defined if CPU is unknown. */
#  define RPL_CPU_UNKNOWN    1
#endif

#endif
