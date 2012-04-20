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
#include <rpl/types.h>

/**
 * @ingroup DLL
 * @{
 * @file dll.h
 * Dynamic-link Library (DLL) handling.
 * @example dll.c
 */

/**
 * Dynamic-link library (DLL) loader object.
 */
typedef struct rpl_dll* rpl_dll_t;


/**
 * Create a new DLL loader object.
 * @return DLL loader object.
 */
rpl_dll_t
rpl_dll_new(void);

/**
 * Free DLL loader object.
 * @param dll pointer to DLL loader object.
 */
void
rpl_dll_free(rpl_dll_t* dll);

/**
 * Open DLL file.
 * @param dll DLL loader object.
 * @param file path to DLL file.
 * @return RPL_TRUE if the operation succeeded, RPL_FALSE otherwise.
 * In the latter case the error code/message can be retrieved
 * using rpl_error_get/rpl_error_translate_last.
 */
rpl_bool_t
rpl_dll_open(rpl_dll_t dll, const char* file);

/**
 * Close a previously opened DLL file.
 * @param dll DLL loader object.
 * @return RPL_TRUE if the operation succeeded, RPL_FALSE otherwise.
 * In the latter case the error code/message can be retrieved
 * using rpl_error_get/rpl_error_translate_last.
 */
rpl_bool_t
rpl_dll_close(rpl_dll_t dll);

/**
 * Retrieve the address of a DLL symbol.
 * @param dll DLL loader object.
 * @param symbol name symbol name.
 * @return address of the symbol if the operation succeeded, NULL otherwise.
 * In the latter case the error code/message can be retrieved
 * using rpl_error_get/rpl_error_translate_last.
 */
void*
rpl_dll_get(rpl_dll_t dll, const char* symbol_name);

/** @} */

#endif
