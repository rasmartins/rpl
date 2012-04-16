#include <errno.h>
#include <stdio.h>

#include <rpl/rpl.h>

int
main(int argc, char** argv)
{
  rpl_init(NULL, 0);

  puts(rpl_error_translate(ERROR_INVALID_FUNCTION));


  rpl_exit();

  return 0;
}
