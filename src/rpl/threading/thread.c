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
#include <rpl/error.h>
#include <rpl/threading/mutex.h>
#include <rpl/threading/thread.h>

/* Platform specific headers. */
#if defined(RPL_OS_UNIX)
#  include <pthread.h>
#endif

typedef enum
{
  RPL_THREAD_STATE_NONE,
  RPL_THREAD_STATE_RUNNING,
  RPL_THREAD_STATE_STOPPING,
  RPL_THREAD_STATE_STOPPED
} rpl_thread_state_t;

struct rpl_thread
{
#if defined(RPL_OS_UNIX)
  pthread_t handle;
  pthread_attr_t attributes;

#elif defined(RPL_OS_WINDOWS)
  HANDLE handle;
  
#endif

  rpl_thread_state_t state;
  rpl_mutex_t state_lock;
  rpl_thread_function_t function;
  void* data;
};

#if defined(RPL_OS_UNIX)
static void*
#elif defined(RPL_OS_WINDOWS)
static DWORD WINAPI
#endif
thread_entry_point(void* data)
{
  rpl_thread_t thread = (rpl_thread_t)data;

  rpl_error_thread_init();

  rpl_mutex_lock(thread->state_lock);
  thread->state = RPL_THREAD_STATE_RUNNING;
  rpl_mutex_unlock(thread->state_lock);

  thread->function(thread);

  rpl_mutex_lock(thread->state_lock);
  thread->state = RPL_THREAD_STATE_STOPPED;
  rpl_mutex_unlock(thread->state_lock);

  rpl_error_thread_exit();

#if defined(RPL_OS_WINDOWS)
  ExitThread(0);
  return 0;
#elif defined(RPL_OS_UNIX)
  pthread_exit(NULL);
  return NULL;
#endif
}

rpl_thread_t
rpl_thread_new(void)
{
  rpl_thread_t thread = calloc(1, sizeof(struct rpl_thread));

#if defined(RPL_OS_UNIX)
  int rv = pthread_attr_init(&thread->attributes);
  if (rv != 0)
    return;

  rv = pthread_attr_setinheritsched(&thread->attributes, PTHREAD_EXPLICIT_SCHED);
  if (rv != 0)
    return;
  
  rv = pthread_attr_setdetachstate(&thread->attributes, PTHREAD_CREATE_JOINABLE);
  if (rv != 0)
    return;
  
  pthread_attr_setstacksize(&thread->attributes, 128 * 1024);

#elif defined(RPL_OS_WINDOWS)
  thread->handle = 0;

#endif

  thread->state_lock = rpl_mutex_new();

  return thread;
}

void
rpl_thread_free(rpl_thread_t thread)
{
#if defined(RPL_OS_UNIX)
  pthread_attr_destroy(&thread->attributes);
#endif

  rpl_thread_stop(thread);
  rpl_thread_join(thread);
  rpl_mutex_free(thread->state_lock);
  free(thread);
}

void
rpl_thread_set_function(rpl_thread_t thread, rpl_thread_function_t function)
{
  thread->function = function;
}

void
rpl_thread_set_data(rpl_thread_t thread, void* data)
{
  thread->data = data;
}

void*
rpl_thread_get_data(const rpl_thread_t thread)
{
  return thread->data;
}

void
rpl_thread_start(rpl_thread_t thread)
{
#if defined(RPL_OS_UNIX)
  pthread_create(&thread->handle, &thread->attributes, thread_entry_point, thread);

#elif defined(RPL_OS_WINDOWS)
  thread->handle = CreateThread(NULL, 0, thread_entry_point, thread, 0, NULL);

#endif
}

void
rpl_thread_join(rpl_thread_t thread)
{
#if defined(RPL_OS_UNIX)
  int rv = pthread_join(thread->handle, NULL);
  if (rv != 0)
    return;

#elif defined(RPL_OS_WINDOWS)
  WaitForSingleObject(thread->handle, INFINITE);
#endif
}

void
rpl_thread_stop(rpl_thread_t thread)
{
  rpl_mutex_lock(thread->state_lock);
  thread->state = RPL_THREAD_STATE_STOPPING;
  rpl_mutex_unlock(thread->state_lock);
}

int
rpl_thread_is_stopping(rpl_thread_t thread)
{
  rpl_thread_state_t state = RPL_THREAD_STATE_NONE;

  rpl_mutex_lock(thread->state_lock);
  state = thread->state;
  rpl_mutex_unlock(thread->state_lock);

  return state == RPL_THREAD_STATE_STOPPING;
}

void
rpl_thread_stop_and_join(rpl_thread_t thread)
{
  rpl_thread_stop(thread);
  rpl_thread_join(thread);
}
