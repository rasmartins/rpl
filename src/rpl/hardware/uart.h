/*--------------------------------------------------------------------+
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
 ---------------------------------------------------------------------*/

#ifndef RPL_UART_H_INCLUDED_
#define RPL_UART_H_INCLUDED_

/**
 * Opaque object representing a UART device.
 */
typedef struct rpl_uart* rpl_uart_t;

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
 * Create a new UART object.
 * @return UART object.
 */
rpl_uart_t
rpl_uart_new(void);

/**
 * Free UART object.
 * @param uart UART object.
 */
void
rpl_uart_free(rpl_uart_t* uart);

/**
 * Set UART device to use.
 * @param uart UART object.
 * @param dev device name.
 */
void
rpl_uart_set_device(rpl_uart_t uart, const char* dev);

/**
 * Open UART device.
 * @param uart UART object.
 * @param dev device name.
 */
void
rpl_uart_open(rpl_uart_t uart, const char* dev);

/**
 * Close UART device.
 * @param uart UART object.
 */
void
rpl_uart_close(rpl_uart_t uart);

/**
 * Set UART frame type.
 * @param uart UART object.
 * @param type frame type.
 */
void
rpl_uart_set_frame_type(rpl_uart_t uart, rpl_uart_frame_t type);

/**
 * Set UART flow control.
 * @param uart UART object.
 * @param fctl flow control type.
 */
void
rpl_uart_set_flow_control(rpl_uart_t uart, rpl_uart_fctl_t fctl);

/**
 * Set UART baud rate.
 * @param uart UART object.
 * @param baud baud rate.
 */
void
rpl_uart_set_baud_rate(rpl_uart_t uart, unsigned baud);

/**
 * Write data to UART.
 * @param uart UART object.
 * @param data data to write.
 * @param data_size amount of bytes.
 */
void
rpl_uart_write(rpl_uart_t uart, const char* data, unsigned data_size);

/**
 * Read data from UART.
 * @param uart UART object.
 * @param data data to write.
 * @param data_size amount of bytes.
 */
void
rpl_uart_read(rpl_uart_t uart, char* data, unsigned data_size);

/**
 * Send break.
 * @param uart UART object.
 * @param duration break duration.
 */
void
rpl_uart_send_break(rpl_uart_t uart, unsigned duration);

void
rpl_uart_flush(rpl_uart_t uart);

void
rpl_uart_flush_input(rpl_uart_t uart);

void
rpl_uart_flush_output(rpl_uart_t uart);

#endif
