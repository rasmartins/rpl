#ifndef RPL_PLATFORM_OS_H_INCLUDED_
#define RPL_PLATFORM_OS_H_INCLUDED_

// Linux.
#if defined(__linux__)
#  define RPL_OS_LINUX   1
#  define RPL_OS_UNIX    1

// Microsoft Windows.
#elif defined(__WIN32)
#  define RPL_OS_WINDOWS 1

// Apple Mac OS X (Darwin).
#elif defined(__APPLE__)
#  define RPL_OS_DARWIN  1
#  define RPL_OS_UNIX    1

// FreeBSD.
#elif defined(__FreeBSD__)
#  define RPL_OS_FREEBSD 1
#  define RPL_OS_UNIX    1

// OpenBSD.
#elif defined(__OpenBSD__)
#  define RPL_OS_OPENBSD 1
#  define RPL_OS_UNIX    1

// NetBSD.
#elif defined(__NetBSD__)
#  define RPL_OS_NETBSD  1
#  define RPL_OS_UNIX    1

// QNX Neutrino.
#elif defined(__QNXNTO__)
#  define RPL_OS_QNX6    1
#  define RPL_OS_UNIX    1

// Unknown operating system.
#else
#  define RPL_OS_UNKNOWN 1
#endif

#endif
