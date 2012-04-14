#include <stdio.h>
#include <rpl/rpl.h>

int
main(void)
{
  rpl_init(NULL, 0);

  printf("%-20s: %s\n", "Operating System", rpl_os_get_name());
  printf("%-20s: %s\n", "CPU Architecture", rpl_cpu_get_name());
  printf("%-20s: %s\n", "C Compiler", rpl_cc_get_name());
  printf("%-20s: %s\n", "C Library", rpl_libc_get_name());

  rpl_exit();

  return 0;
}
