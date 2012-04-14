#include <stdio.h>
#include <rpl/rpl.h>

#define THREADS 10

void
thread_func(rpl_thread_t thread)
{
  int i = 0;
  int nr = (int)rpl_thread_get_data(thread);

  while (!rpl_thread_is_stopping(thread))
  {
    rpl_error_set(i++);
    rpl_delay(1);
    fprintf(stderr, "Thread %d: %d\n", nr, rpl_error_get());
    rpl_delay(1);
  }
}

int
main(void)
{
  rpl_init(NULL, 0);

  int i = 0;
  rpl_thread_t threads[THREADS];
  for (i = 0; i < THREADS; ++i)
  {
    threads[i] = rpl_thread_new();
    rpl_thread_set_function(threads[i], thread_func);
    rpl_thread_set_data(threads[i], (void*)i);
    rpl_thread_start(threads[i]);
  }

  rpl_delay(20);

  for (i = 0; i < THREADS; ++i)
  {
    rpl_thread_stop_and_join(threads[i]);
    rpl_thread_free(threads[i]);
  }

  rpl_exit();

  return 0;
}
