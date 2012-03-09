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
#include <string.h>

/* RPL headers. */
#include <rpl/memory/tlsf.h>
#include <rpl/platform.h>
#include <rpl/string.h>
#include <rpl/network/address.h>

/* Platform specific headers. */
#if defined(RPL_OS_UNIX)
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  include <netdb.h>
#endif

#if defined(DUNE_SYS_HAS_WINSOCK2_H)
#  include <winsock2.h>
#  include <ws2tcpip.h>
#endif

struct rpl_address
{
  struct sockaddr_in addr;
  char* host;
  int resolved;
};

static int
translate_address(rpl_address_t address, int resolve)
{
#if _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE
  struct addrinfo* res = NULL;
  struct addrinfo* itr = NULL;
  struct addrinfo hints;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_flags = AI_CANONNAME | ((resolve) ? 0 : AI_NUMERICHOST);
  hints.ai_family = AF_INET;
  
  int rv = getaddrinfo(address->host, NULL, &hints, &res);
  if (rv != 0)
    return 0;
  
  for (itr = res; itr; itr = itr->ai_next)
  {
    struct sockaddr_in* in = (struct sockaddr_in*)itr->ai_addr;
    address->addr.sin_addr.s_addr = in->sin_addr.s_addr;
    address->resolved = 1;
    freeaddrinfo(res);
    return 1;
  }
#endif
  
  return 0;
}

rpl_address_t
rpl_address_new(void)
{
  rpl_address_t address = tlsf_calloc(1, sizeof(struct rpl_address));
  address->addr.sin_family = AF_INET;
}

void
rpl_address_free(rpl_address_t address)
{
  if (address->host != NULL)
    tlsf_free(address->host);
  tlsf_free(address);
}

void
rpl_address_set_port(rpl_address_t address, short port)
{
  address->addr.sin_port = htons(port);
}

short
rpl_address_get_port(const rpl_address_t address)
{
  return ntohs(address->addr.sin_port);
}

void
rpl_address_set_addr(rpl_address_t address, rpl_uint32_t addr)
{
  address->addr.sin_addr.s_addr = addr;
}

void
rpl_address_set_addr_ho(rpl_address_t address, rpl_uint32_t addr)
{
  address->addr.sin_addr.s_addr = htonl(addr);
}

rpl_uint32_t
rpl_address_get_addr(const rpl_address_t address)
{
  return address->addr.sin_addr.s_addr;
}

rpl_uint32_t
rpl_address_get_addr_ho(const rpl_address_t address)
{
  return ntohl(rpl_address_get_addr(address));
}

void
rpl_address_set_host(rpl_address_t address, const char* host)
{
  if (address->host != NULL)
  {
    tlsf_free(address->host);
    address->resolved = 0;
  }
  address->host = rpl_string_clone(host);
  translate_address(address, 0);
}

const char*
rpl_address_get_host(const rpl_address_t address)
{
  return address->host;
}

int
rpl_address_resolve(rpl_address_t address)
{
  if (address->resolved)
    return 1;

  return translate_address(address, 1);
}
