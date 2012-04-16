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
#include <errno.h>
#include <stdlib.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/error.h>
#include <rpl/dll.h>

/* Platform headers. */
#if defined(RPL_OS_UNIX)
#  include <dlfcn.h>
#  define GET_LAST_ERROR dlerror()
#elif defined(RPL_OS_WINDOWS)
#  include <windows.h>
#  define GET_LAST_ERROR Error::getLastMessage()
#endif

struct rpl_dll
{
#if defined(RPL_OS_UNIX)
  void* handle;
#elif defined(RPL_OS_WINDOWS)
  HMODULE handle;
#endif
};

rpl_dll_t
rpl_dll_new(void)
{
  rpl_dll_t dll = calloc(1, sizeof(struct rpl_dll));
  return dll;
}

void
rpl_dll_free(rpl_dll_t* dll)
{
  rpl_dll_close(*dll);
  free(*dll);
  *dll = NULL;
}

rpl_bool_t
rpl_dll_open(rpl_dll_t dll, const char* file)
{
  rpl_dll_close(dll);

#if defined(RPL_OS_WINDOWS)
  dll->handle = LoadLibrary(file);
  if (dll->handle != NULL)
    return RPL_TRUE;

  rpl_error_set(GetLastError());

#elif defined(RPL_OS_UNIX)
  dll->handle = dlopen(file, RTLD_NOW);
  if (dll->handle != NULL)
    return RPL_TRUE;

  rpl_error_set(RPL_ERROR_NO_CODE);
  rpl_error_set_message(dlerror());
#endif

  return RPL_FALSE;
}

void
rpl_dll_close(rpl_dll_t dll)
{
  int rv = 0;

#if defined(RPL_OS_WINDOWS)
  if (dll->handle != NULL)
    {
      rv = FreeLibrary(dll->handle);
      dll->handle = NULL;
    }

#elif defined(RPL_OS_UNIX)
  if (dll->handle != 0)
    {
      rv = dlclose(dll->handle);
      dll->handle = 0;
    }

#endif
}

void*
rpl_dll_get(rpl_dll_t dll, const char* symbol_name)
{
  void* symbol = NULL;

#if defined(RPL_OS_WINDOWS)
  symbol = (void*)GetProcAddress(dll->handle, symbol_name);

#elif defined(RPL_OS_UNIX)
  symbol = dlsym(dll->handle, symbol_name);

#endif

  return symbol;
}

