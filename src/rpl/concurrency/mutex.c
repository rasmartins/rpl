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

/* ISO C headers. */
#include <stdlib.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/concurrency/mutex.h>

#if defined(RPL_OS_UNIX)
#  include <pthread.h>
#endif

#if defined(RPL_OS_WINDOWS)
#  include <windows.h>
#endif

struct rpl_mutex
{
#if defined(RPL_OS_UNIX)
  pthread_mutex_t handle;
#elif defined(RPL_OS_WINDOWS)
  CRITICAL_SECTION handle;
#endif
};

rpl_mutex_t
rpl_mutex_new(void)
{
  rpl_mutex_t mutex = calloc(1, sizeof(struct rpl_mutex));

#if defined(RPL_OS_UNIX)
  pthread_mutex_init(&mutex->handle, NULL);

#elif defined(RPL_OS_WINDOWS)
  InitializeCriticalSection(&mutex->handle);
#endif

  return mutex;
}

void
rpl_mutex_free(rpl_mutex_t* mutex)
{
#if defined(RPL_OS_UNIX)
  pthread_mutex_destroy(&((*mutex)->handle));

#elif defined(RPL_OS_WINDOWS)
  DeleteCriticalSection(&((*mutex)->handle));
#endif

  free(*mutex);
  *mutex = NULL;
}

void
rpl_mutex_lock(rpl_mutex_t mutex)
{
#if defined(RPL_OS_UNIX)
  pthread_mutex_lock(&mutex->handle);

#elif defined(RPL_OS_WINDOWS)
  EnterCriticalSection(&mutex->handle);

#endif
}

int
rpl_mutex_try_lock(rpl_mutex_t mutex)
{
#if defined(RPL_UNIX)
  return pthread_mutex_trylock(&mutex->handle) == 0;

#elif defined(RPL_OS_WINDOWS)
  return TryEnterCriticalSection(&mutex->handle) == TRUE;

#endif
}

void
rpl_mutex_unlock(rpl_mutex_t mutex)
{
#if defined(RPL_OS_UNIX)
  pthread_mutex_unlock(&mutex->handle);

#elif defined(RPL_OS_WINDOWS)
  LeaveCriticalSection(&mutex->handle);

#endif
}
