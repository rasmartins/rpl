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

#ifndef RPL_STREAMS_HANDLE_H_INCLUDED_
#define RPL_STREAMS_HANDLE_H_INCLUDED_

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/types.h>

/* Handle object. */
typedef struct rpl_handle* rpl_handle_t;

/** Freer. */
typedef void (*rpl_handle_freer_t)(rpl_handle_t handle);
/** Reader. */
typedef rpl_ssize_t (*rpl_handle_reader_t)(rpl_handle_t handle, char* buffer, rpl_ssize_t buffer_size);
/** Writer. */
typedef rpl_ssize_t (*rpl_handle_writer_t)(rpl_handle_t handle, const char* buffer, rpl_ssize_t buffer_size);
/** Opener. */
typedef void (*rpl_handle_opener_t)(rpl_handle_t handle);
/** Closer. */
typedef void (*rpl_handle_closer_t)(rpl_handle_t handle);
/** Synchronizer. */
typedef void (*rpl_handle_syncer_t)(rpl_handle_t handle);

#define RPL_HANDLE(obj) ((rpl_handle_t)obj)

struct rpl_handle
{
  /** Implementation's unique ID. */
  rpl_uint32_t impl_uid;
  /** Implementation's specific data. */
  void* impl_data;
  rpl_handle_freer_t free;
  rpl_handle_opener_t open;
  rpl_handle_closer_t close;
  rpl_handle_reader_t read;
  rpl_handle_writer_t write;
  rpl_handle_syncer_t sync;
};

/**
 * Create handle object.
 */
rpl_handle_t
rpl_handle_new(void);

/**
 * Free handle object.
 */
void
rpl_handle_free(rpl_handle_t* handle);

/**
 * Open handle.
 * @param handle handle.
 */
void
rpl_handle_open(rpl_handle_t handle);

/**
 * Close handle.
 * @param handle handle.
 */
void
rpl_handle_close(rpl_handle_t handle);

/**
 * Read data from handle.
 * @param handle handle.
 * @param buffer destination buffer.
 * @param buffer_size amount of bytes to read.
 */
rpl_ssize_t
rpl_handle_read(rpl_handle_t handle, char* buffer, rpl_ssize_t buffer_size);

/**
 * Write data to handle.
 * @param handle handle.
 * @param buffer source buffer.
 * @param buffer_size amount of bytes to write.
 */
rpl_ssize_t
rpl_handle_write(rpl_handle_t handle, const char* buffer, rpl_ssize_t buffer_size);

#endif
