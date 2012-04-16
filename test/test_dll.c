#include <stdio.h>
#include <rpl/rpl.h>

int
main(int argc, char** argv)
{
  rpl_dll_t dll = NULL;

  rpl_init(NULL, 0);

  dll = rpl_dll_new();
  if (!rpl_dll_open(dll, "/"))
    fprintf(stderr, "%s\n", rpl_error_translate_last());

  rpl_exit();

  return 0;
}
