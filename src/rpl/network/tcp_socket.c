/* ISO C headers. */
#include <errno.h>

/* RPL headers. */
#include <rpl/platform.h>
#include <rpl/memory/tlsf.h>
#include <rpl/network/tcp_socket.h>

#if defined(RPL_OS_WINDOWS)
#  include <winsock2.h>
#  include <ws2tcpip.h>
#elif defined(RPL_OS_UNIX)
#  include <arpa/inet.h>
#  include <fcntl.h>
#  include <netdb.h>
#  include <netinet/in.h>
#  include <netinet/tcp.h>
#  include <sys/socket.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#  include <unistd.h>
#  include <sys/signal.h>
#endif

#if !defined(INVALID_SOCKET)
#  define INVALID_SOCKET  (-1)
#endif

#if !defined(ECONNRESET) && defined(WSAECONNRESET)
#  define ECONNRESET WSAECONNRESET
#endif

struct rpl_tcp_socket
{
#if defined(RPL_OS_UNIX)
  int handle;
#elif defined(RPL_OS_WINDOWS)
  SOCKET handle;
#endif
};

rpl_tcp_socket_t
rpl_tcp_socket_new(void)
{
  rpl_tcp_socket_t sock = tlsf_calloc(sizeof(struct rpl_tcp_socket), 1);
  return sock;
}

void
rpl_tcp_socket_free(rpl_tcp_socket_t sock)
{

}

void
rpl_tcp_socket_open(rpl_tcp_socket_t sock)
{
  sock->handle = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock->handle == INVALID_SOCKET)
    return;
  
#if defined(SO_NOSIGPIPE)
  int set = 1;
  setsockopt(sock->handle, SOL_SOCKET, SO_NOSIGPIPE, (void*)&set, sizeof(int));
#endif
}

void
rpl_tcp_socket_close(rpl_tcp_socket_t sock)
{
#if defined(RPL_OS_UNIX)
  shutdown(sock->handle, SHUT_RDWR);
  close(sock->handle);
#elif defined(RPL_OS_WINDOWS)
  closesocket(sock->handle);
#endif
}

void
rpl_tcp_socket_bind(rpl_tcp_socket_t socket, rpl_address_t addr)
{
#if 0
  if (reuse)
  {
    int on = 1;

#if defined(RPLDUNE_OS_WINDOWS)
    
    setsockopt(m_handle, SOL_SOCKET, SO_EXCLUSIVEADDRUSE,
               (char*)&on, sizeof(int));
    on = 1;
#endif
    setsockopt(m_handle, SOL_SOCKET, SO_REUSEADDR,
               (char*)&on, sizeof(int));
  }
  
  struct sockaddr_in self;
  self.sin_family = AF_INET;
  self.sin_port = Utils::ByteCopy::toBE(port);
  self.sin_addr.s_addr = addr.toInteger();
  
  if (bind(sock->handle, (struct sockaddr*)&self, sizeof(self)) < 0)
    return;
#endif
}

void
rpl_tcp_socket_connect(rpl_tcp_socket_t sock, rpl_address_t addr)
{

}

void
rpl_tcp_socket_listen(rpl_tcp_socket_t sock, unsigned backlog)
{
  if (listen(sock->handle, backlog) < 0)
    return;
}

rpl_tcp_socket_t
rpl_tcp_socket_accept(rpl_tcp_socket_t sock, rpl_address_t* addr)
{

}

rpl_ssize_t
rpl_tcp_socket_write(rpl_tcp_socket_t sock, const char* data, rpl_size_t data_size)
{
  int flags = 0;
  rpl_ssize_t rv = 0;

#if defined(MSG_NOSIGNAL)
  flags = MSG_NOSIGNAL;
#endif

  rv = send(sock->handle, data, data_size, flags);
  if (rv == -1)
  {
    if (errno == EPIPE)
      return;
    /*   throw ConnectionClosed(); */
    /* throw NetworkError("error sending data", getLastErrorMessage()); */
  }

  return rv;
}

rpl_ssize_t
rpl_tcp_socket_read(rpl_tcp_socket_t sock, char* data, rpl_size_t data_size)
{
  rpl_ssize_t rv = recv(sock->handle, data, data_size, 0);
  if (rv == -1)
  {
    if (errno == ECONNRESET)
      return;
    /*   throw ConnectionClosed(); */
    /* throw NetworkError("error receiving data", getLastErrorMessage()); */
  }

  return rv;
}

void
rpl_tcp_socket_set_options(rpl_tcp_socket_t sock, unsigned options)
{
  if (options & RPL_TCP_SOCKET_REUSE_ADDR)
  {
    int on = 1;
#if defined(RPL_OS_WINDOWS)
    setsockopt(sock->handle, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&on, sizeof(int));
#endif
    setsockopt(sock->handle, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(int));
  }
}

void
rpl_tcp_socket_clear_options(rpl_tcp_socket_t sock, unsigned options)
{
  if (options & RPL_TCP_SOCKET_REUSE_ADDR)
  {
    int on = 0;
#if defined(RPL_OS_WINDOWS)
    setsockopt(sock->handle, SOL_SOCKET, SO_EXCLUSIVEADDRUSE, (char*)&on, sizeof(int));
#endif
    setsockopt(sock->handle, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(int));
  }
}
