#ifndef RPL_ERROR_H_INCLUDED_
#define RPL_ERROR_H_INCLUDED_

#include <rpl/concurrency/tls.h>

extern rpl_tls_key_t rpl_error_key;

void
rpl_error_init(void);

void
rpl_error_exit(void);

void
rpl_error_thread_init(void);

void
rpl_error_thread_exit(void);

int
rpl_error_get(void);

void
rpl_error_set(int error);

#endif
