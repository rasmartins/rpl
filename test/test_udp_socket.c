#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
  rpl_init(memory, sizeof(memory));
  rpl_udp_socket_t udp = rpl_udp_socket_new();
  rpl_udp_socket_free(udp);

  return 0;
}
