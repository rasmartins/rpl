#ifndef RPL_TIME_CLOCK_H_INCLUDED_
#define RPL_TIME_CLOCK_H_INCLUDED_

/* RPL headers. */
#include <rpl/integers.h>

rpl_uint64_t
rpl_clock_get(void);

rpl_uint64_t
rpl_clock_get_monotonic(void);

#endif
