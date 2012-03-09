cmake_minimum_required(VERSION 2.8)
include(Toolchain.cmake)

project("RPL")

set(LIBS pthread rt)
#set(LIBS ws2_32)

include_directories(src)
file(GLOB_RECURSE RPL_SRCS src/*.c)
add_library(rpl ${RPL_SRCS})

add_executable(test_udp_socket test/test_udp_socket.c)
target_link_libraries(test_udp_socket rpl ${LIBS})

add_executable(test_tcp_socket test/test_tcp_socket.c)
target_link_libraries(test_tcp_socket rpl ${LIBS})

add_executable(test_address test/test_address.c)
target_link_libraries(test_address rpl ${LIBS})

add_executable(test_thread test/test_thread.c)
target_link_libraries(test_thread rpl ${LIBS})

add_executable(test_time_clock test/test_time_clock.c)
target_link_libraries(test_time_clock rpl ${LIBS})
