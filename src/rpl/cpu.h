/**********************************************************************
 * RPL is a small and standalone platform abstraction layer.          *
 * Copyright (C) 2012 Ricardo Martins                                 *
 *                                                                    *
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

#ifndef RPL_CPU_H_INCLUDED_
#define RPL_CPU_H_INCLUDED_

// ISO C99 headers.
#include <stdio.h>

// RPL headers.
#include <rpl/os.h>

// Platform dependent headers.
#if defined(RPL_OS_WINDOWS)
#  include <windows.h>
#endif

#if defined(__amd64__) || defined(_AMD64) || defined (__x86_64__) || defined(_M_X64)
#  define RPL_CPU_X86        1
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__i386__) || defined(_M_IX86) || defined(__x86_32__)
#  define RPL_CPU_X86        1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__powerpc64__)
#  define RPL_CPU_POWERPC    1
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__powerpc__) || defined(__ppc__) || defined(PPC)
#  define RPL_CPU_POWERPC    1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__ARM_ARCH_4T__)
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM5T      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__ARM_ARCH_5T__)
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM5T      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__ARM_ARCH_7A__)
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_ARM7A      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__arm__)
#  define RPL_CPU_ARM        1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__sparcv9__)
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_64_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__sparcv8__)
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__sparc__)
#  define RPL_CPU_SPARC      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__MIPSEL__)
#  define RPL_CPU_MIPS       1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_LEND       1

#elif defined(__MIPSEB__)
#  define RPL_CPU_MIPS       1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__avr32__)
#  define RPL_CPU_AVR32      1 
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#elif defined(__alpha__)
#  define RPL_CPU_ALPHA      1
#  define RPL_CPU_32_BIT     1
#  define RPL_CPU_BEND       1

#else
#  define RPL_CPU_UNKNOWN    1

#endif

#endif
