/* ISO C headers. */
#include <string.h>

/* RPL headers. */
#include <rpl/memory/tlsf.h>
#include <rpl/string.h>

char*
rpl_string_clone(const char* string)
{
  size_t len = strlen(string);
  char* clone = tlsf_malloc(len + 1);
  memcpy(clone, string, len + 1);
  return clone;
}
