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

/* ISO C headers. */
#include <stdlib.h>

/* RPL headers. */
#include <rpl/streams/handle.h>

rpl_handle_t
rpl_handle_new(void)
{
  rpl_handle_t handle = calloc(1, sizeof(struct rpl_handle));
  return handle;
}

void
rpl_handle_free(rpl_handle_t* handle)
{
  rpl_handle_close(*handle);
  (*handle)->free(*handle);
  free(*handle);
  *handle = NULL;
}

void
rpl_handle_open(rpl_handle_t handle)
{
  handle->open(handle);
}

void
rpl_handle_close(rpl_handle_t handle)
{
  handle->close(handle);
}
