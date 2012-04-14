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

#ifndef RPL_ADDRESS_H_INCLUDED_
#define RPL_ADDRESS_H_INCLUDED_

/* RPL headers. */
#include <rpl/config.h>
#include <rpl/types.h>

typedef struct rpl_address* rpl_address_t;

/**
 * Create network address object.
 * @return network address object.
 */
rpl_address_t
rpl_address_new(void);

/**
 * Free a previously allocated network address object.
 * @param address network address object.
 */
void
rpl_address_free(rpl_address_t* address);

/**
 * Set port.
 * @param address network address object.
 * @param port port.
 */
void
rpl_address_set_port(rpl_address_t address, short port);

/**
 * Get port.
 * @param address network address object.
 * @return port.
 */
short
rpl_address_get_port(const rpl_address_t address);

/**
 * Set IPv4 address.
 * @param address network address object.
 * @param addr IPv4 address in network byte order.
 */
void
rpl_address_set_addr4(rpl_address_t address, rpl_uint32_t addr);

/**
 * Set IPv4 address.
 * @param address network address object.
 * @param addr IPv4 address in host byte order.
 */
void
rpl_address_set_addr4_ho(rpl_address_t address, rpl_uint32_t addr);

/**
 * Get IPv4 address.
 * @param address network address object.
 * @return IPv4 address in network byte order.
 */
rpl_uint32_t
rpl_address_get_addr4(const rpl_address_t address);

/**
 * Get IPv4 address.
 * @param address network address object.
 * @return IPv4 address in network byte order.
 */
rpl_uint32_t
rpl_address_get_addr4(const rpl_address_t address);

/**
 * Get IPv4 address.
 * @param address network address object.
 * @return IPv4 address in host byte order.
 */
rpl_uint32_t
rpl_address_get_addr4_ho(const rpl_address_t address);

/**
 * Set IPv6 address.
 * @param address network address object.
 * @param addr IPv6 address in network byte order.
 */
void
rpl_address_set_addr6(rpl_address_t address, rpl_uint64_t addr);

/**
 * Set IPv6 address.
 * @param address network address object.
 * @param addr IPv6 address in host byte order.
 */
void
rpl_address_set_addr6_ho(rpl_address_t address, rpl_uint64_t addr);

/**
 * Get IPv6 address.
 * @param address network address object.
 * @return IPv6 address in network byte order.
 */
rpl_uint64_t
rpl_address_get_addr6(const rpl_address_t address);

/**
 * Get IPv6 address.
 * @param address network address object.
 * @return IPv6 address in network byte order.
 */
rpl_uint64_t
rpl_address_get_addr6(const rpl_address_t address);

/**
 * Get IPv6 address.
 * @param address network address object.
 * @return IPv6 address in host byte order.
 */
rpl_uint64_t
rpl_address_get_addr6_ho(const rpl_address_t address);

/**
 * Set address by name.
 * @param address network address object.
 * @param host name.
 */
void
rpl_address_set_host(rpl_address_t address, const char* host);

/**
 * Get address by name.
 * @param address network address object.
 * @param host name.
 */
const char*
rpl_address_get_host(const rpl_address_t address);

/**
 * Resolve address by name.
 * @param address network address object.
 * @param host name.
 */
int
rpl_address_resolve(rpl_address_t address);

#endif
