#ifndef RPL_TIME_DELAY_H_INCLUDED_
#define RPL_TIME_DELAY_H_INCLUDED_

/* RPL headers. */
#include <rpl/integers.h>

void
rpl_delay(unsigned seconds);

void
rpl_delay_until(unsigned seconds);

void
rpl_delay_msec(unsigned milliseconds);

void
rpl_delay_usec(unsigned microseconds);

void
rpl_delay_nsec(rpl_uint64_t nanoseconds);

#endif
