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

#ifndef RPL_TIME_CLOCK_H_INCLUDED_
#define RPL_TIME_CLOCK_H_INCLUDED_

/* RPL headers. */
#include <rpl/types.h>

/**
 * Retrieve the number of seconds elapsed since the Unix Epoch.
 * @return number of seconds since the Unix Epoch.
 */
rpl_uint64_t
rpl_clock_get(void);

/**
 * Retrieve the number of seconds elapsed since the Unix Epoch.
 * @return number of seconds since the Unix Epoch.
 */
rpl_uint64_t
rpl_clock_get_monotonic(void);

/**
 * Retrieve the number of milliseconds elapsed since the Unix Epoch.
 * @return number of milliseconds since the Unix Epoch.
 */
rpl_uint64_t
rpl_clock_get_msec(void);

/**
 * Retrieve the number of microseconds elapsed since the Unix Epoch.
 * @return number of microseconds since the Unix Epoch.
 */
rpl_uint64_t
rpl_clock_get_usec(void);

/**
 * Retrieve the number of nanoseconds elapsed since the Unix Epoch.
 * @return number of nanoseconds since the Unix Epoch.
 */
rpl_uint64_t
rpl_clock_get_nsec(void);

#endif
