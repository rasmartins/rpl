/* ISO C headers. */
#include <time.h>
#include <string.h>

/* RPL headers. */
#include <rpl/time/clock.h>

/* Platform specific headers. */
#if defined(RPL_OS_WINDOWS)
#  include <windows.h>
#endif

rpl_uint64_t
rpl_clock_get(void)
{
  rpl_uint64_t now = 0;
  
#if defined(RPL_OS_UNIX)
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  now = ts.tv_sec * 1000000000UL;
  now += ts.tv_nsec;
  
#elif defined(RPL_OS_WINDOWS)
  FILETIME ft;
  GetSystemTimeAsFileTime(&ft);
  memcpy(&now, &ft, sizeof(now));
  
  /* Subtract number of 100-nanosecond intervals between the beginning
   * of the Windows epoch (Jan. 1, 1601) and the Unix epoch (Jan. 1, 
   * 1970). */
  now -= 116444736000000000ULL;
  now *= 100;
  
#else
#  error Unsupported platform.
#endif
  
  return now;
}

rpl_uint64_t
rpl_clock_get_monotonic(void)
{
  rpl_uint64_t now = 0;

#if defined(RPL_OS_UNIX)
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  now = ts.tv_sec * 1000000000UL;
  now += ts.tv_nsec;

#elif defined(RPL_OS_WINDOWS)
  LARGE_INTEGER val;
  QueryPerformanceCounter(&val);
  fprintf(stderr, "%lld\n", val.QuadPart);
  
  LARGE_INTEGER frq;
  QueryPerformanceFrequency(&frq);

  /* if (frq.QuadPart < 1000000) */
  /*   frq.QuadPart *=  */

  fprintf(stderr, "%lld\n", frq.QuadPart);
  //  frq.QuadPart /= 1000000000;
  
#else
#  error Unsupported platform.
#endif

  return now;
}
