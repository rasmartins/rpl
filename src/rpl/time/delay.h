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

#ifndef RPL_TIME_DELAY_H_INCLUDED_
#define RPL_TIME_DELAY_H_INCLUDED_

/* RPL headers. */
#include <rpl/types.h>

/**
 * Delay execution of the calling thread by a given amount of seconds.
 * @param seconds amount of delay seconds.
 */
void
rpl_delay(unsigned seconds);

/**
 * Delay execution of the calling thread by a given amount of milliseconds.
 * @param milliseconds amount of delay milliseconds.
 */
void
rpl_delay_msec(unsigned milliseconds);

/**
 * Delay execution of the calling thread by a given amount of microseconds.
 * @param microseconds amount of delay microseconds.
 */
void
rpl_delay_usec(unsigned microseconds);

/**
 * Delay execution of the calling thread by a given amount of nanoseconds.
 * @param nanoseconds amount of delay nanoseconds.
 */
void
rpl_delay_nsec(rpl_uint64_t nanoseconds);

#endif
