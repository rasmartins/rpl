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

// ISO C headers.
#include <stdlib.h>

// RPL headers.
#include <rpl/platform.h>
#include <rpl/threading/thread.h>

#if defined(RPL_OS_UNIX)
#  include <pthread.h>
#endif

struct rpl_thread
{
#if defined(RPL_OS_UNIX)
  pthread_t handle;
#endif
};

rpl_thread_t
rpl_thread_new(void)
{
  rpl_thread_t thread = calloc(1, sizeof(struct rpl_thread));
  
  return thread;
}

void
rpl_thread_free(rpl_thread_t thread)
{
  rpl_thread_stop(thread);
  rpl_thread_join(thread);
  free(thread);
}

void
rpl_thread_start(rpl_thread_t thread, void* function, void* function_arg)
{
#if defined(RPL_UNIX)
  pthread_create(&thread->handle, NULL, function, function_arg);
#endif
}

void
rpl_thread_join(rpl_thread_t thread)
{

}

void
rpl_thread_stop(rpl_thread_t thread)
{

}
