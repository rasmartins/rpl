#ifndef RPL_INIT_H_INCLUDED_
#define RPL_INIT_H_INCLUDED_

/* ISO C headers. */
#include <stddef.h>

/* RPL headers. */
#include <rpl/memory/tlsf.h>

void
rpl_init(void* memory, size_t memory_size);

void
rpl_exit(void);

#endif
