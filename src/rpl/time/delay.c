/* ISO C headers. */
#include <time.h>
#include <stddef.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/time/delay.h>

void
rpl_delay(unsigned seconds)
{
  rpl_uint64_t nsec = seconds * 1000000000UL;
  rpl_delay_nsec(nsec);
}

void
rpl_delay_msec(unsigned milliseconds)
{
  rpl_uint64_t nsec = milliseconds * 1000000UL;
  rpl_delay_nsec(nsec);
}

void
rpl_delay_usec(unsigned microseconds)
{
  rpl_uint64_t nsec = microseconds * 1000UL;
  rpl_delay_nsec(nsec);
}

void
rpl_delay_nsec(rpl_uint64_t nanoseconds)
{
#if defined(RPL_OS_UNIX)
  struct timespec ts;
  ts.tv_sec = nanoseconds / 1000000000UL;
  ts.tv_nsec = nanoseconds - (ts.tv_sec * 1000000000UL);
  clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL);

#elif defined(RPL_OS_WINDOWS)
  HANDLE t = CreateWaitableTimer(0, TRUE, 0);
  LARGE_INTEGER dl;
  dl.QuadPart = (uint64_t)nanoseconds / 100;
  // Negative value means relative time.
  dl.QuadPart *= -1;
  SetWaitableTimer(t, &dl, 0, 0, 0, 0);
  WaitForSingleObject(t, INFINITE);
  CloseHandle(t);
#endif
}
