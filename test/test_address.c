#include <stdio.h>
#include <rpl/rpl.h>

char memory[1024 * 1024];

int
main(void)
{
    rpl_address_t addr = NULL;
    rpl_uint32_t addr_raw = 0;

    rpl_init(memory, sizeof(memory));

    addr = rpl_address_new();
    rpl_address_set_port(addr, 1234);
    rpl_address_set_host(addr, "whale.fe.up.pt");
    rpl_address_resolve(addr);
    addr_raw = rpl_address_get_addr_ho(addr);
    printf("%u.%u.%u.%u\n", (addr_raw >> 24) & 0xff, (addr_raw >> 16) & 0xff,
                            (addr_raw >> 8) & 0xff, (addr_raw & 0xff));

    rpl_address_set_port(addr, 1234);
    rpl_address_set_host(addr, "192.168.106.199");
    rpl_address_resolve(addr);
    addr_raw = rpl_address_get_addr_ho(addr);
    printf("%u.%u.%u.%u\n", (addr_raw >> 24) & 0xff, (addr_raw >> 16) & 0xff,
                            (addr_raw >> 8) & 0xff, (addr_raw & 0xff));

    rpl_address_free(&addr);

    rpl_exit();

    return 0;
}
