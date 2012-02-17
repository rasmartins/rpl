#include <stddef.h>

#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

rpl_tls_key_t rpl_error_key;

void
rpl_error_init(void)
{
  rpl_error_key = rpl_tls_key_new();
}

void
rpl_error_exit(void)
{
  rpl_tls_key_free(rpl_error_key);
}

void
rpl_error_free(void)
{
  rpl_tls_key_free(rpl_error_key);
}

void
rpl_error_thread_init(void)
{
  int* e = tlsf_calloc(sizeof(int), 1);
  rpl_tls_key_set_value(rpl_error_key, e);
}

void
rpl_error_thread_exit(void)
{
  void* e = rpl_tls_key_get_value(rpl_error_key);
  if (e != NULL)
    tlsf_free(e);
}

int
rpl_error_get(void)
{
  int* e = rpl_tls_key_get_value(rpl_error_key);
  return *e;
}

void
rpl_error_set(int error)
{
  int* e = rpl_tls_key_get_value(rpl_error_key);
  *e = error;
}
