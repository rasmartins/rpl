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

#ifndef RPL_UART_H_INCLUDED_
#define RPL_UART_H_INCLUDED_

/* RPL headers. */
#include <rpl/types.h>
#include <rpl/streams/handle.h>

/** Frame type. */
typedef enum
{
  /** 7 data bits, 1 stop bit, odd parity. */
  RPL_UART_FRAME_7O1,
  /** 7 data bits, 1 stop bit, even parity. */
  RPL_UART_FRAME_7E1,
  /** 8 data bits, 1 stop bit, no parity. */
  RPL_UART_FRAME_8N1
} rpl_uart_frame_t;

/** Flow-control type.*/
typedef enum
{
  /** No flow control. */
  RPL_UART_FCTL_NONE,
  /** XON/XOFF (software) flow control. */
  RPL_UART_FCTL_XONXOFF,
  /** CTS/RTS (hardware) flow control. */
  RPL_UART_FCTL_CTSRTS
} rpl_uart_fctl_t;

/**
 * Create a new UART handle.
 * @return handle object.
 */
rpl_handle_t
rpl_uart_new(const char* device);

/**
 * Set UART device to use.
 * @param uart UART object.
 * @param dev device name.
 */
rpl_bool_t
rpl_uart_set_device(rpl_handle_t handle, const char* dev);

/**
 * Set UART baud rate.
 * @param uart UART object.
 * @param baud baud rate.
 */
rpl_bool_t
rpl_uart_set_baud_rate(rpl_handle_t handle, unsigned baud);

/**
 * Set UART frame type.
 * @param uart UART object.
 * @param type frame type.
 */
rpl_bool_t
rpl_uart_set_frame_type(rpl_handle_t handle, rpl_uart_frame_t type);

/**
 * Set UART flow control.
 * @param uart UART object.
 * @param fctl flow control type.
 */
rpl_bool_t
rpl_uart_set_flow_control(rpl_handle_t handle, rpl_uart_fctl_t fctl);

/**
 * Send break.
 * @param uart UART object.
 * @param duration break duration.
 */
rpl_bool_t
rpl_uart_send_break(rpl_handle_t handle, unsigned duration);

#endif
