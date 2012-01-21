/**********************************************************************
 * one line to give the library's name and an idea of what it does.   *
 * Copyright (C) 2012 Ricardo Martins                                 *
 *                                                                    *
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

#ifndef RPL_UART_H_INCLUDED_
#define RPL_UART_H_INCLUDED_

typedef struct rpl_uart* rpl_uart_t;

typedef enum
{
  RPL_UART_FRAME_7O1,
  RPL_UART_FRAME_7E1,
  RPL_UART_FRAME_8N1
} rpl_uart_frame_t;

typedef enum
{
  RPL_UART_FCTL_NONE,
  RPL_UART_FCTL_XONXOFF,
  RPL_UART_FCTL_CTSRTS
} rpl_uart_fctl_t;

rpl_uart_t
rpl_uart_new(void);

void
rpl_uart_free(rpl_uart_t* rpl_uart);

void
rpl_uart_open(rpl_uart_t rpl_uart, const char* dev);

void
rpl_uart_close(rpl_uart_t rpl_uart);

void
rpl_uart_set_frame_type(rpl_uart_t rpl_uart, rpl_uart_frame_t type);

void
rpl_uart_set_flow_control(rpl_uart_t rpl_uart, rpl_uart_fctl_t fctl);

void
rpl_uart_set_baud_rate(rpl_uart_t rpl_uart, unsigned baud);

void
rpl_uart_write(rpl_uart_t rpl_uart, const char* data, unsigned data_size);

void
rpl_uart_read(rpl_uart_t rpl_uart, char* data, unsigned data_size);

void
rpl_uart_send_break(rpl_uart_t rpl_uart, unsigned duration);

void
rpl_uart_flush(rpl_uart_t rpl_uart);

void
rpl_uart_flush_input(rpl_uart_t rpl_uart);

void
rpl_uart_flush_output(rpl_uart_t rpl_uart);

#endif
