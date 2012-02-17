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

#ifndef RPL_TCP_SOCKET_H_INCLUDED_
#define RPL_TCP_SOCKET_H_INCLUDED_

/* RPL headers. */
#include <rpl/config.h>
#include <rpl/network/address.h>

enum rpl_tcp_socket_options
{
  RPL_TCP_SOCKET_REUSE_ADDR = (1 << 0)
};

typedef struct rpl_tcp_socket* rpl_tcp_socket_t;

RPL_SYM rpl_tcp_socket_t
rpl_tcp_socket_new(void);

RPL_SYM void
rpl_tcp_socket_free(rpl_tcp_socket_t socket);

RPL_SYM void
rpl_tcp_socket_open(rpl_tcp_socket_t socket);

RPL_SYM void
rpl_tcp_socket_close(rpl_tcp_socket_t socket);

RPL_SYM void
rpl_tcp_socket_set_options(rpl_tcp_socket_t socket, unsigned options);

RPL_SYM void
rpl_tcp_socket_clear_options(rpl_tcp_socket_t socket, unsigned options);

RPL_SYM void
rpl_tcp_socket_bind(rpl_tcp_socket_t socket, rpl_address_t addr);

RPL_SYM void
rpl_tcp_socket_connect(rpl_tcp_socket_t socket, rpl_address_t addr);

RPL_SYM void
rpl_tcp_socket_listen(rpl_tcp_socket_t socket, unsigned backlog);

RPL_SYM rpl_tcp_socket_t
rpl_tcp_socket_accept(rpl_tcp_socket_t socket, rpl_address_t* addr);

RPL_SYM ssize_t
rpl_tcp_socket_write(rpl_tcp_socket_t socket, const char* data, size_t data_size);

RPL_SYM ssize_t
rpl_tcp_socket_read(rpl_tcp_socket_t socket, char* data, size_t data_size);

#endif
