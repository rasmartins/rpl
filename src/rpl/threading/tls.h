#ifndef RPL_THREADING_TLS_H_INCLUDED_
#define RPL_THREADING_TLS_H_INCLUDED_

/* RPL headers. */
#include <rpl/platform.h>

typedef struct rpl_tls_key* rpl_tls_key_t;

rpl_tls_key_t
rpl_tls_key_new(void);

void
rpl_tls_key_free(rpl_tls_key_t key);

void*
rpl_tls_key_get_value(rpl_tls_key_t key);

void
rpl_tls_key_set_value(rpl_tls_key_t key, void*);

#endif
