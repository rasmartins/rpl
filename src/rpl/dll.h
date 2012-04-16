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

#ifndef RPL_DLL_H_INCLUDED_
#define RPL_DLL_H_INCLUDED_

/* ISO C headers. */
#include <stddef.h>
#include <string.h>

/* RPL headers. */
#include <rpl/platform.h>

/** Dynamic-link Library object. */
typedef struct rpl_dll* rpl_dll_t;

rpl_dll_t
rpl_dll_new(void);

void
rpl_dll_free(rpl_dll_t* dll);

void
rpl_dll_open(rpl_dll_t dll, const char* file);

void
rpl_dll_close(rpl_dll_t dll);

void*
rpl_dll_get(rpl_dll_t dll, const char* symbol_name);

#endif
