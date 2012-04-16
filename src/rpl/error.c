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

#include <stddef.h>

#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

rpl_tls_key_t rpl_error_key;

void
rpl_error_init(void)
{
  rpl_error_key = rpl_tls_key_new();
}

void
rpl_error_exit(void)
{
  rpl_tls_key_free(rpl_error_key);
}

void
rpl_error_free(void)
{
  rpl_tls_key_free(rpl_error_key);
}

void
rpl_error_thread_init(void)
{
  int* e = tlsf_calloc(sizeof(int), 1);
  rpl_tls_key_set_value(rpl_error_key, e);
}

void
rpl_error_thread_exit(void)
{
  void* e = rpl_tls_key_get_value(rpl_error_key);
  if (e != NULL)
    tlsf_free(e);
}

int
rpl_error_get(void)
{
  int* e = rpl_tls_key_get_value(rpl_error_key);
  return *e;
}

void
rpl_error_set(int error)
{
  int* e = rpl_tls_key_get_value(rpl_error_key);
  *e = error;
}
