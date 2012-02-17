#include <stdio.h>
#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
  rpl_init(memory, sizeof(memory));

  rpl_address_t addr = rpl_address_new();
  rpl_address_set_port(addr, 1234);
  rpl_address_set_host(addr, "www.google.com");
  rpl_address_free(addr);

  rpl_exit();
  
  return 0;
}
