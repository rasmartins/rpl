#include <rpl/rpl.h>

int
main(void)
{
    rpl_tcp_socket_t tcp = NULL;

    rpl_init(NULL, 0);
    tcp = rpl_tcp_socket_new();
    rpl_tcp_socket_free(tcp);

    rpl_exit();

    return 0;
}
