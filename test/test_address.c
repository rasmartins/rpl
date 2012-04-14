#include <stdio.h>
#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
  rpl_init(memory, sizeof(memory));

  rpl_address_t addr = rpl_address_new();

  rpl_address_set_port(addr, 1234);
  rpl_address_set_host(addr, "whale.fe.up.pt");
  rpl_address_resolve(addr);
  rpl_uint32_t a = rpl_address_get_addr_ho(addr);
  printf("%u.%u.%u.%u\n", (a >> 24) & 0xff, (a >> 16) & 0xff, (a >> 8) & 0xff, (a & 0xff));

  rpl_address_set_port(addr, 1234);
  rpl_address_set_host(addr, "192.168.106.199");
  rpl_address_resolve(addr);
  a = rpl_address_get_addr_ho(addr);
  printf("%u.%u.%u.%u\n", (a >> 24) & 0xff, (a >> 16) & 0xff, (a >> 8) & 0xff, (a & 0xff));

  rpl_address_free(&addr);

  rpl_exit();

  return 0;
}
