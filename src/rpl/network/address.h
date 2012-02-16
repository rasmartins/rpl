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

typedef struct rpl_address* rpl_address_t;

rpl_address_t
rpl_address_new(void);

void
rpl_address_free(rpl_address_t address);

void
rpl_address_set_port(rpl_address_t address, unsigned port);

unsigned
rpl_address_get_port(const rpl_address_t address);

void
rpl_address_set_host(rpl_address_t address, const char* host);

const char*
rpl_address_get_host(const rpl_address_t address);

#endif
