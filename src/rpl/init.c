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

#include <rpl/init.h>
#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

#define DEFAULT_POOL_SIZE (1024 * 1024)
static char c_default_pool[DEFAULT_POOL_SIZE];

void
rpl_init(void* memory, size_t memory_size)
{
  if (memory == NULL)
  {
    memory = c_default_pool;
    memory_size = DEFAULT_POOL_SIZE;
  }

  init_memory_pool(memory_size, memory);
  rpl_error_init();
  rpl_error_thread_init();
}

void
rpl_exit(void)
{
  rpl_error_thread_exit();
  rpl_error_exit();
}
