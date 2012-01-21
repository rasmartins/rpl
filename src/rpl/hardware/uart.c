// ISO C99 headers.
#include <stdlib.h>

// RPL headers.
#include <rpl/config.h>
#include <rpl/hardware/uart.h>

// POSIX headers.
#if defined(RPL_OS_UNIX)
#  include <unistd.h>
#  include <termios.h>
#endif

struct rpl_uart
{
#if defined(RPL_OS_UNIX)
  int handle;
  struct termios options;
  
#elif defined(RPL_OS_WINDOWS)
  HANDLE handle;
  DCB options;
#endif
};

rpl_uart_t
rpl_uart_new(void)
{
  rpl_uart_t rpl_uart = calloc(1, sizeof(struct rpl_uart));
  return rpl_uart;
}

void
rpl_uart_free(rpl_uart_t* rpl_uart)
{
  if (rpl_uart == NULL)
    return;
  
  if (*rpl_uart != NULL)
  {
    free(*rpl_uart);
    *rpl_uart = NULL;
  }
}

void
rpl_uart_open(rpl_uart_t rpl_uart, const char* dev)
{
  rpl_uart->options.c_iflag &= ~(BRKINT | ICRNL | INLCR | PARMRK | IXOFF | IXON | PARMRK | ISTRIP | INPCK);
  rpl_uart->options.c_oflag &= ~(OPOST | ONLCR | OCRNL | ONOCR | ONLRET | OFILL | NLDLY | CRDLY | TABDLY | BSDLY | VTDLY | FFDLY);
  rpl_uart->options.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON | IEXTEN | ISIG | NOFLSH | TOSTOP);
}

void
rpl_uart_close(rpl_uart_t rpl_uart)
{
  rpl_uart_flush(rpl_uart);
  close(rpl_uart->handle);
}

void
rpl_uart_set_frame_type(rpl_uart_t rpl_uart, rpl_uart_frame_t type)
{
  switch (type)
  {
    case RPL_UART_FRAME_8N1:
      rpl_uart->options.c_cflag &= ~(PARENB | PARODD | CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= CS8;
      rpl_uart->options.c_iflag |= IGNPAR;
      rpl_uart->options.c_iflag &= ~(PARMRK);
      break;
      
    case RPL_UART_FRAME_7E1:
      rpl_uart->options.c_cflag &= ~(PARODD | CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= (PARENB | CS7);
      break;
      
    case RPL_UART_FRAME_7O1:
      rpl_uart->options.c_cflag &= ~(CSTOPB | CSIZE);
      rpl_uart->options.c_cflag |= (PARENB | PARODD | CS7);
      break;
  }
}

void
rpl_uart_set_baud_rate(rpl_uart_t rpl_uart, unsigned baud)
{
  speed_t speed = B4800;

  switch (baud)
  {
    case 4800:
      speed = B4800;
      break;

    case 9600:
      speed = B9600;
      break;

    case 19200:
      speed = B19200;
      break;

    case 38400:
      speed = B38400;
      break;

    case 57600:
      speed = B57600;
      break;

    case 115200:
      speed = B115200;
      break;

    case 230400:
      speed = B230400;
      break;
  }
}
