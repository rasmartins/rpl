#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
  rpl_clock_get();
  rpl_clock_get_monotonic();

  return 0;
}
