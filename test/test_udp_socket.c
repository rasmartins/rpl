#include <rpl/rpl.h>

int
main(void)
{
    rpl_udp_socket_t sock = NULL;

    rpl_init(NULL, 0);
    
    sock = rpl_udp_socket_new();
    rpl_udp_socket_free(sock);

    rpl_exit();

  return 0;
}
