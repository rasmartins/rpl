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

/* ISO C headers. */
#include <stddef.h>
#include <string.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

/* Maximum size of an error message. */
#if defined(MAX_MESSAGE_SIZE)
#  undef MAX_MESSAGE_SIZE
#endif
#define MAX_MESSAGE_SIZE 1024

/* TLS Error Key. */
rpl_tls_key_t rpl_error_key;

/* Error data-structure. */
struct rpl_error
{
  /* Error code. */
  int code;
  /* Human-readable error message. */
  char message[MAX_MESSAGE_SIZE + 1];
};

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
  struct rpl_error* e = tlsf_calloc(sizeof(struct rpl_error), 1);
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
  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);
  return e->code;
}

void
rpl_error_set(int error)
{
  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);
  e->code = error;
}

void
rpl_error_clear(void)
{
  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);
  e->code = 0;
}

void
rpl_error_set_message(const char* message)
{
  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);
  e->code = RPL_ERROR_NO_CODE;
  strncpy(e->message, message, MAX_MESSAGE_SIZE);
}

const char*
rpl_error_translate(int error)
{
  /* Use POSIX compliant strerror_r. */
  #if defined(RPL_LIBC_GNU)
  #  if defined(_POSIX_C_SOURCE)
  #    undef _POSIX_C_SOURCE
  #  endif
  #  define _POSIX_C_SOURCE 200112L
  #  if defined(_GNU_SOURCE)
  #    undef _GNU_SOURCE
  #  endif
  #endif

  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);

#if defined(RPL_OS_UNIX)
  if (e->code == RPL_ERROR_NO_CODE)
    return e->message;

  if (strerror_r(error, e->message, MAX_MESSAGE_SIZE) == 0)
    return e->message;

#elif defined(RPL_OS_WINDOWS)
  WORD lang = 0;
  DWORD size = 0;

  if (e->code == RPL_ERROR_NO_CODE)
    return e->message;

  lang = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);
  size = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, "%0",
                       error, lang, e->message, MAX_MESSAGE_SIZE,
                       NULL);
  if (size > 0)
  {
      for (--size; size >= 0; --size)
        {
          if (e->message[size] != '\r' && e->message[size] != '\n' && e->message[size] != '.')
            break;
          e->message[size] = '\0';
        }

      return e->message;
  }
#endif

  return "unable to translate error";
}

const char*
rpl_error_translate_last(void)
{
  struct rpl_error* e = rpl_tls_key_get_value(rpl_error_key);
  return rpl_error_translate(e->code);
}
