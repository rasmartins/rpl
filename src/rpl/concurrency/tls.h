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

#ifndef RPL_CONCURRENCY_TLS_KEY_H_INCLUDED_
#define RPL_CONCURRENCY_TLS_KEY_H_INCLUDED_

/* RPL headers. */
#include <rpl/platform.h>

/** TLS key object. */
typedef struct rpl_tls_key* rpl_tls_key_t;

/**
 * Create TLS key object.
 */
rpl_tls_key_t
rpl_tls_key_new(void);

/**
 * Free TLS key object.
 * @param key TLS key object.
 */
void
rpl_tls_key_free(rpl_tls_key_t key);

void*
rpl_tls_key_get_value(rpl_tls_key_t key);

void
rpl_tls_key_set_value(rpl_tls_key_t key, void*);

#endif
