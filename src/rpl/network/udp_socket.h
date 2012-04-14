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
#include <rpl/types.h>
#include <rpl/network/address.h>

/**
 * UDP socket object.
 */
typedef struct rpl_udp_socket* rpl_udp_socket_t;

/**
 * Create a new UDP socket object.
 * @return UDP socket object.
 */
RPL_SYM rpl_udp_socket_t
rpl_udp_socket_new(void);

/**
 * Free an UDP socket object.
 * @param socket UDP socket object.
 */
RPL_SYM void
rpl_udp_socket_free(rpl_udp_socket_t socket);

/**
 * Set Free an UDP socket object.
 * @param socket UDP socket object.
 */
RPL_SYM void
rpl_udp_socket_free(rpl_udp_socket_t socket);

RPL_SYM void
rpl_udp_bcast_enable(rpl_udp_socket_t socket, rpl_bool_t enable);

RPL_SYM void
rpl_udp_set_mcast_ttl(rpl_udp_socket_t socket, rpl_uint8_t ttl);

RPL_SYM void
rpl_udp_set_mcast_loop(rpl_udp_socket_t socket, rpl_bool_t loop);

RPL_SYM void
rpl_udp_set_mcast_join(rpl_udp_socket_t socket, rpl_address_t group, rpl_address_t interface);

RPL_SYM void
rpl_udp_bind(rpl_udp_socket_t socket, rpl_address_t address);


/* RPL_SYM void */
/* rpl_udp_socket_open(rpl_udp_socket_t socket); */

/* RPL_SYM void */
/* rpl_udp_socket_close(rpl_udp_socket_t socket); */

/* RPL_SYM void */
/* rpl_udp_socket_write(rpl_udp_socket_t socket); */

/* RPL_SYM void */
/* rpl_udp_socket_read(rpl_udp_socket_t socket); */

#endif
