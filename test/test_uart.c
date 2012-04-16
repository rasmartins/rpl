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

/* RPL headers. */
#include <rpl/rpl.h>

int
main(void)
{
  rpl_handle_t handle = NULL;

  rpl_init(NULL, 0);

  handle = rpl_uart_new("/dev/ttyS0");
  rpl_uart_set_frame_type(handle, RPL_UART_FRAME_8N1);
  rpl_uart_set_baud_rate(handle, 115200);
  rpl_uart_set_flow_control(handle, RPL_UART_FCTL_NONE);
  rpl_handle_free(handle);

  rpl_exit();

  return 0;
}
