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

#ifndef RPL_THREADING_THREAD_H_INCLUDED_
#define RPL_THREADING_THREAD_H_INCLUDED_

#include <rpl/config.h>

typedef struct rpl_thread* rpl_thread_t;
typedef void (*rpl_thread_function_t)(rpl_thread_t);

RPL_SYM rpl_thread_t
rpl_thread_new(void);

RPL_SYM void
rpl_thread_free(rpl_thread_t thread);

RPL_SYM void
rpl_thread_set_function(rpl_thread_t thread, rpl_thread_function_t function);

RPL_SYM void
rpl_thread_set_data(rpl_thread_t thread, void* data);

RPL_SYM void*
rpl_thread_get_data(const rpl_thread_t thread);

RPL_SYM void
rpl_thread_start(rpl_thread_t thread);

RPL_SYM void
rpl_thread_join(rpl_thread_t thread);

RPL_SYM void
rpl_thread_stop(rpl_thread_t thread);

RPL_SYM int
rpl_thread_is_stopping(rpl_thread_t thread);

RPL_SYM void
rpl_thread_stop_and_join(rpl_thread_t thread);

#endif
