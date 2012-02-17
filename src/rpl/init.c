#include <rpl/init.h>
#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

void
rpl_init(void* memory, size_t memory_size)
{
  init_memory_pool(memory_size, memory);
  rpl_error_init();
  rpl_error_thread_init();
}

void
rpl_exit(void)
{
  rpl_error_thread_exit();
  rpl_error_exit();
}
