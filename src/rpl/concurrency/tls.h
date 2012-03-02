#ifndef RPL_CONCURRENCY_TLS_KEY_H_INCLUDED_
#define RPL_CONCURRENCY_TLS_KEY_H_INCLUDED_

/* RPL headers. */
#include <rpl/platform.h>

/** TLS key object. */
typedef struct rpl_tls_key* rpl_tls_key_t;

/**
 * Create TLS key object.
 */
rpl_tls_key_t
rpl_tls_key_new(void);

/**
 * Free TLS key object.
 * @param key TLS key object.
 */
void
rpl_tls_key_free(rpl_tls_key_t key);

void*
rpl_tls_key_get_value(rpl_tls_key_t key);

void
rpl_tls_key_set_value(rpl_tls_key_t key, void*);

#endif
