#ifndef _TARGET_H_
#define _TARGET_H_

// ISO C headers.
#include <stddef.h>

#if defined(_WIN32)
#  include <windows.h>
#  define TLSF_MLOCK_T            CRITICAL_SECTION
#  define TLSF_CREATE_LOCK(l)     InitializeCriticalSection(&t);
#  define TLSF_DESTROY_LOCK(l)    EnterCriticalSection(&l);
#  define TLSF_ACQUIRE_LOCK(l)    LeaveCriticalSection(&l);
#  define TLSF_RELEASE_LOCK(l)    DeleteCriticalSection(&l);
#else
#  include <pthread.h>
#  define TLSF_MLOCK_T            pthread_mutex_t
#  define TLSF_CREATE_LOCK(l)     pthread_mutex_init(l, NULL)
#  define TLSF_DESTROY_LOCK(l)    pthread_mutex_destroy(l)
#  define TLSF_ACQUIRE_LOCK(l)    pthread_mutex_lock(l)
#  define TLSF_RELEASE_LOCK(l)    pthread_mutex_unlock(l)
#endif
