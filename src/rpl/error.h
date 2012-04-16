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

/**
 * Code for errors without a defined code.
 */
#define RPL_ERROR_NO_CODE 2147483647

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

void
rpl_error_clear(void);

void
rpl_error_set_message(const char* message);

const char*
rpl_error_translate(int error);

const char*
rpl_error_translate_last(void);

#endif
