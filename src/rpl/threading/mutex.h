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

#ifndef RPL_THREADING_MUTEX_H_INCLUDED_
#define RPL_THREADING_MUTEX_H_INCLUDED_

#include <rpl/config.h>

typedef struct rpl_mutex* rpl_mutex_t;

RPL_SYM rpl_mutex_t
rpl_mutex_new(void);

RPL_SYM void
rpl_mutex_free(rpl_mutex_t mutex);

RPL_SYM void
rpl_mutex_lock(rpl_mutex_t mutex);

RPL_SYM void
rpl_mutex_try_lock(rpl_mutex_t mutex);

RPL_SYM void
rpl_mutex_unlock(rpl_mutex_t mutex);

#endif
