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

/* ISO C headers. */
#include <stdlib.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/memory/tlsf.h>
#include <rpl/network/udp_socket.h>

/* Microsoft Windows headers. */
#if defined(RPL_OS_WINDOWS)
#  include <windows.h>
#  include <winsock2.h>
#  include <ws2tcpip.h>
#endif

/* POSIX headers. */
#if defined(RPL_OS_UNIX)
#  include <unistd.h>
#  include <netinet/in.h>
#  include <sys/socket.h>
#  include <arpa/inet.h>
#  include <netdb.h>
#endif

#if !defined(INVALID_SOCKET)
#  define INVALID_SOCKET -1
#endif

struct rpl_udp_socket
{
#if defined(RPL_OS_UNIX)
  int handle;
#elif defined(RPL_OS_WINDOWS)
  SOCKET handle;
#endif
};

rpl_udp_socket_t
rpl_udp_socket_new(void)
{
  rpl_udp_socket_t sock = tlsf_calloc(sizeof(struct rpl_udp_socket), 1);
  return sock;
}

void
rpl_udp_socket_free(rpl_udp_socket_t sock)
{
  tlsf_free(sock);
}

void
rpl_udp_socket_open(rpl_udp_socket_t sock)
{
  sock->handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock->handle == INVALID_SOCKET)
    return;
  
#if defined(RPL_OS_WINDOWS)
  DWORD t = 0;
  BOOL b = FALSE;
  
#  if defined(SIO_UDP_CONNRESET)
  if (WSAIoctl(sock->handle, SIO_UDP_CONNRESET, &b, sizeof(b), 0, 0, &tmp, 0, 0) == SOCKET_ERROR)
  {
    if (GetLastError() != WSAEOPNOTSUPP)
      return;
  }
#  endif
#endif
}

void
rpl_udp_socket_close(rpl_udp_socket_t sock)
{
#if defined(RPL_OS_UNIX)
  close(sock->handle);
  
#elif defined(RPL_OS_WINDOWS)
  closesocket(sock->handle);
#endif
}
