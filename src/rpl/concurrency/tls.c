#include <rpl/platform.h>
#include <rpl/memory/tlsf.h>
#include <rpl/concurrency/tls.h>

#if defined(RPL_OS_WINDOWS)
#  include <windows.h>
#endif

#if defined(RPL_OS_UNIX)
#  include <pthread.h>
#endif

struct rpl_tls_key
{
#if defined(RPL_OS_WINDOWS)
  DWORD key;
#elif defined(RPL_OS_UNIX)
  pthread_key_t key;
#endif
};

rpl_tls_key_t
rpl_tls_key_new(void)
{
  rpl_tls_key_t key = tlsf_calloc(sizeof(struct rpl_tls_key), 1);
  
#if defined(RPL_OS_WINDOWS)
  key->key = TlsAlloc();
#elif defined(RPL_OS_UNIX)
  pthread_key_create(&key->key, NULL);
#endif
  
  return key;
}

void
rpl_tls_key_free(rpl_tls_key_t key)
{
#if defined(RPL_OS_WINDOWS)
  TlsFree(key->key);
#elif defined(RPL_OS_UNIX)
  pthread_key_delete(key->key);
#endif

  tlsf_free(key);
}

void*
rpl_tls_key_get_value(rpl_tls_key_t key)
{
  void* data = NULL;
  
#if defined(RPL_OS_WINDOWS)
  data = TlsGetValue(key->key);
#elif defined(RPL_OS_UNIX)
  data = pthread_getspecific(key->key);
#endif

  return data;
}

void
rpl_tls_key_set_value(rpl_tls_key_t key, void* data)
{
#if defined(RPL_OS_WINDOWS)
  TlsSetValue(key->key, data);
#elif defined(RPL_OS_UNIX)
  pthread_setspecific(key->key, data);
#endif
}
