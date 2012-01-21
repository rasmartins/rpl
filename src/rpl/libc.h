#ifndef CONFIG_LIBC_H_INCLUDED_
#define CONFIG_LIBC_H_INCLUDED_

#include <stddef.h>
#include <stdio.h>

#if defined(__UCLIBC__)
#  define RPL_LIBC_UCLIBC    1

#elif defined(__GLIBC__)
#  define RPL_LIBC_GNU       1

#elif defined(_NEWLIB_VERSION)
#  define RPL_LIBC_NEWLIB    1

#elif defined(__ECOS__)
#  define RPL_LIBC_ECOS      1

#elif defined(_MINGW32_VERSION)
#  define RPL_LIBC_MINGW     1

#elif defined(_MSC_VER)
#  define RPL_LIBC_MICROSOFT 1

#elif defined(__APPLE__)
#  define RPL_LIBC_APPLE     1

#elif defined(__sun)
#  define RPL_LIBC_SUN       1

#elif defined(_HAS_DINKUM_CLIB)
#  define RPL_LIBC_DINKUM    1

#elif defined(__FreeBSD__)   
#  define RPL_LIBC_FREEBSD   1

#elif defined(__OpenBSD__)   
#  define RPL_LIBC_OPENBSD   1

#elif defined(__NetBSD__)    
#  define RPL_LIBC_NETBSD    1

#else
#  define RPL_LIBC_UNKNOWN   1

#endif

#endif
