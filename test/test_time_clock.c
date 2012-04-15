#include <rpl/rpl.h>

int
main(void)
{
  rpl_init(NULL, 0);

  printf("%llu\n", rpl_clock_get());
  //  printf("%lu\n", rpl_clock_get_monotonic());

  rpl_exit();

  return 0;
}
