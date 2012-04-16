/*------------------------------------------------------------------*\
| Copyright (C) 2012 Ricardo Martins                                 |
+--------------------------------------------------------------------+
| This library is free software; you can redistribute it and/or      |
| modify it under the terms of the GNU Lesser General Public License |
| as published by the Free Software Foundation; either version 2.1   |
| of the License, or (at your option) any later version.             |
|                                                                    |
| This library is distributed in the hope that it will be useful,    |
| but WITHOUT ANY WARRANTY; without even the implied warranty of     |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  |
| Lesser General Public License for more details.                    |
|                                                                    |
| You should have received a copy of the GNU Lesser General Public   |
| License along with this library; if not, write to the Free         |
| Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        |
| Boston, MA 02110-1301 USA                                          |
\*------------------------------------------------------------------*/

// ISO C headers.
#include <stdlib.h>
#include <string.h>

// RPL headers.
#include <rpl/platform.h>
#include <rpl/streams/handle.h>
#include <rpl/hardware/uart.h>

// POSIX headers.
#if defined(RPL_OS_UNIX)
#  include <unistd.h>
#  include <termios.h>
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <fcntl.h>
#endif

/* Implementation's UID. */
#define IMPL_UID 0xe161a1a5U

/* Implementation's cast. */
#define IMPL_GET(handle) ((struct impl*)handle->impl_data)

/* Implementation's data structure. */
struct impl
{
  char* device;

#if defined(RPL_OS_UNIX)
  int fd;
  struct termios options;
#elif defined(RPL_OS_WINDOWS)
  HANDLE fd;
  DCB options;
#endif
};

static void
uart_free(rpl_handle_t handle)
{
//  if (handle->impl_uid != IMPL_UID)
//    return RPL_FALSE;

  free(IMPL_GET(handle)->device);
  free(handle->impl_data);
  handle->impl_data = NULL;
}

static rpl_ssize_t
uart_read(rpl_handle_t handle, char* buffer, rpl_ssize_t buffer_size)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;


  return -1;
}

static rpl_ssize_t
uart_write(rpl_handle_t handle, const char* buffer, rpl_ssize_t buffer_size)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;

#if defined(RPL_OS_UNIX)
  return write(IMPL_GET(handle)->fd, buffer, buffer_size);
#elif defined(RPL_OS_WINDOWS)
#endif

  return -1;
}

static void
uart_open(rpl_handle_t handle)
{
//  if (handle->impl_uid != IMPL_UID)
//    return RPL_FALSE;

#if defined(RPL_OS_UNIX)
  open(IMPL_GET(handle)->device, O_RDWR);
#elif defined(RPL_OS_WINDOWS)
#endif
}

static void
uart_close(rpl_handle_t handle)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;

#if defined(RPL_OS_UNIX)
  return close(IMPL_GET(handle)->fd);
#elif defined(RPL_OS_WINDOWS)
#endif

}

static void
uart_sync(rpl_handle_t handle)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;
}

rpl_handle_t
rpl_uart_new(const char* dev)
{
  size_t dev_len = strlen(dev);
  char* dev_dup = NULL;
  rpl_handle_t handle = rpl_handle_new();

  handle->impl_uid = IMPL_UID;
  handle->impl_data = calloc(1, sizeof(struct impl));
  handle->free = uart_free;
  handle->open = uart_open;
  handle->close = uart_close;
  handle->write = uart_write;
  handle->read = uart_read;

  dev_dup = calloc(1, strlen(dev) + 1);
  memcpy(dev_dup, dev, dev_len);
  IMPL_GET(handle)->device = dev_dup;

  return handle;
}

rpl_bool_t
rpl_uart_set_frame_type(rpl_handle_t handle, rpl_uart_frame_t type)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;

}

rpl_bool_t
rpl_uart_set_baud_rate(rpl_handle_t handle, unsigned baud)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;

#if defined(RPL_OS_UNIX)
  speed_t speed = B4800;

  switch (baud)
  {
    case 4800:
      speed = B4800;
      break;

    case 9600:
      speed = B9600;
      break;

    case 19200:
      speed = B19200;
      break;

    case 38400:
      speed = B38400;
      break;

    case 57600:
      speed = B57600;
      break;

    case 115200:
      speed = B115200;
      break;

    case 230400:
      speed = B230400;
      break;

    case 460800:
      speed = B460800;
      break;

    case 500000:
      speed = B500000;
      break;

    case 576000:
      speed = B576000;
      break;

    case 921600:
      speed = B921600;

    default:
      break;
  }
#endif
}

rpl_bool_t
rpl_uart_set_flow_control(rpl_handle_t handle, rpl_uart_fctl_t fctl)
{
  if (handle->impl_uid != IMPL_UID)
    return RPL_FALSE;

}

