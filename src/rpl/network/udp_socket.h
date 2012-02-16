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

#ifndef RPL_UDP_SOCKET_H_INCLUDED_
#define RPL_UDP_SOCKET_H_INCLUDED_

/* RPL headers. */
#include <rpl/config.h>

typedef struct rpl_udp_socket* rpl_udp_socket_t;

RPL_SYM rpl_udp_socket_t
rpl_udp_socket_new(void);

RPL_SYM void
rpl_udp_socket_free(rpl_udp_socket_t socket);

RPL_SYM void
rpl_udp_socket_open(rpl_udp_socket_t socket);

RPL_SYM void
rpl_udp_socket_close(rpl_udp_socket_t socket);

RPL_SYM void
rpl_udp_socket_write(rpl_udp_socket_t socket);

RPL_SYM void
rpl_udp_socket_read(rpl_udp_socket_t socket);

#endif
