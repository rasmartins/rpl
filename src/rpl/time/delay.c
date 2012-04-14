/**********************************************************************
 * Copyright (C) 2012 Ricardo Martins                                 *
 **********************************************************************
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public License *
 * as published by the Free Software Foundation; either version 2.1   *
 * of the License, or (at your option) any later version.             *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        *
 * Boston, MA 02110-1301 USA                                          *
 **********************************************************************/

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
