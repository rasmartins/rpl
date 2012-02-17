#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
  rpl_init(memory, sizeof(memory));
  rpl_tcp_socket_t tcp = rpl_tcp_socket_new();
  rpl_tcp_socket_free(tcp);

  return 0;
}
