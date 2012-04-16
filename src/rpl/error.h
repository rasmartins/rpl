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
 * Errors without a defined code.
 */
#define RPL_ERROR_NO_CODE 2147483647

/**
 * Initialize error reporting infrastructure.
 */
void
rpl_error_init(void);

/**
 * Free error reporting infrastructure.
 */
void
rpl_error_exit(void);

/**
 * Initialize thread specific error reporting infrastructure.
 */
void
rpl_error_thread_init(void);

/**
 * Free thread specific error reporting infrastructure.
 */
void
rpl_error_thread_exit(void);

/**
 * Retrieve code of last error.
 */
int
rpl_error_get(void);

/**
 * Set code of last error.
 * @param error error code.
 */
void
rpl_error_set(int error);

/**
 * Clear error code.
 */
void
rpl_error_clear(void);

/**
 * Set last error message.
 * @param message human-readable error message.
 */
void
rpl_error_set_message(const char* message);

/**
 * Translate error code to human-readable message.
 * @param error error code.
 * @return human-readable message.
 */
const char*
rpl_error_translate(int error);

/**
 * Translate last error code to human-readable message.
 * @return human-readable message.
 */
const char*
rpl_error_translate_last(void);

#endif
