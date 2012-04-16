/*--------------------------------------------------------------------+
 | Copyright (C) 2012 Ricardo Martins                                 |
 +--------------------------------------------------------------------+
 | This library is free software; you can redistribute it and/or      |
 | modify it under the terms of the GNU Lesser General Public License |
 | as published by the Free Software Foundation; either version 2.1   |
 | of the License, or (at your option) any later version.             |
 |                                                                    |
 | This library is distributed in the hope that it will be useful,    |
 | but WITHOUT ANY WARRANTY; without even the implied warranty of     |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  |
 | Lesser General Public License for more details.                    |
 |                                                                    |
 | You should have received a copy of the GNU Lesser General Public   |
 | License along with this library; if not, write to the Free         |
 | Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        |
 | Boston, MA 02110-1301 USA                                          |
 ---------------------------------------------------------------------*/

#ifndef RPL_ERROR_H_INCLUDED_
#define RPL_ERROR_H_INCLUDED_

/* RPL headers. */
#include <rpl/concurrency/tls.h>

extern rpl_tls_key_t rpl_error_key;

void
rpl_error_init(void);

void
rpl_error_exit(void);

void
rpl_error_thread_init(void);

void
rpl_error_thread_exit(void);

int
rpl_error_get(void);

void
rpl_error_set(int error);

const char*
rpl_error_translate(int error);

#endif
