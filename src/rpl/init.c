#include <rpl/init.h>
#include <rpl/memory/tlsf.h>
#include <rpl/error.h>

#define DEFAULT_POOL_SIZE (1024 * 1024)
static char c_default_pool[DEFAULT_POOL_SIZE];

void
rpl_init(void* memory, size_t memory_size)
{
  if (memory == NULL)
  {
    memory = c_default_pool;
    memory_size = DEFAULT_POOL_SIZE;
  }

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
