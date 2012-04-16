/*--------------------------------------------------------------------+
 | Copyright (C) 2012 Ricardo Martins                                 |
 +--------------------------------------------------------------------+
 | This library is free software; you can redistribute it and/or      |
 | modify it under the terms of the GNU Lesser General Public License |
 | as published by the Free Software Foundation; either version 2.1   |
 | of the License, or (at your option) any later version.             |
 |                                                                    |
 | This library is distributed in the hope that it will be useful,    |
 | but WITHOUT ANY WARRANTY; without even the implied warranty of     |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  |
 | Lesser General Public License for more details.                    |
 |                                                                    |
 | You should have received a copy of the GNU Lesser General Public   |
 | License along with this library; if not, write to the Free         |
 | Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        |
 | Boston, MA 02110-1301 USA                                          |
 ---------------------------------------------------------------------*/

/* RPL headers. */
#include <rpl/platform.h>

const char*
rpl_os_get_name(void)
{
  return
#if defined(RPL_OS_LINUX)
  "linux";
#elif defined(RPL_OS_WINDOWS)
  "windows";
#elif defined(RPL_OS_QNX6)
  "qnx6";
#else
  "unknown";
#endif
}

const char*
rpl_cpu_get_name(void)
{
  return
#if defined(RPL_CPU_X86)
  "x86"
#elif defined(RPL_CPU_ARM)
  "arm"
#else
  "unknown"
#endif

  "-"

#if defined(RPL_CPU_32_BIT)
  "32";
#elif defined(RPL_CPU_64_BIT)
  "64";
#endif
}

const char*
rpl_libc_get_name(void)
{
  return
#if defined(RPL_LIBC_GNU)
  "glibc";
#elif defined(RPL_LIBC_MINGW)
  "mingw";
#elif defined(RPL_LIBC_MICROSOFT)
  "msvc";
#else
  "unknown";
#endif
}

const char*
rpl_cc_get_name(void)
{
  return
#if defined(RPL_CC_GNU)
  "gcc";
#elif defined(RPL_CC_MICROSOFT)
  "msvc";
#else
  "unknown";
#endif
}
