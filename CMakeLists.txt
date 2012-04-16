cmake_minimum_required(VERSION 2.8)
include(Toolchain.cmake)
include(CheckSymbolExists)

project("RPL")

include_directories(src)

set(CMAKE_REQUIRED_INCLUDES ${PROJECT_SOURCE_DIR}/src)
check_symbol_exists(RPL_OS_LINUX "rpl/platform.h" RPL_OS_LINUX)
check_symbol_exists(RPL_OS_WINDOWS "rpl/platform.h" RPL_OS_WINDOWS)

if (RPL_OS_LINUX)
  set(RPL_LIBS pthread rt dl)
elseif(RPL_OS_WINDOWS)
  set(RPL_LIBS wsock32 ws2_32)
endif()

file(GLOB_RECURSE RPL_SRCS src/*.c src/*.h)
add_library(rpl ${RPL_SRCS})

add_executable(test_platform test/test_platform.c)
target_link_libraries(test_platform rpl ${RPL_LIBS})

add_executable(test_error test/test_error.c)
target_link_libraries(test_error rpl ${RPL_LIBS})

add_executable(test_dll test/test_dll.c)
target_link_libraries(test_dll rpl ${RPL_LIBS})

add_executable(test_udp_socket test/test_udp_socket.c)
target_link_libraries(test_udp_socket rpl ${RPL_LIBS})

add_executable(test_tcp_socket test/test_tcp_socket.c)
target_link_libraries(test_tcp_socket rpl ${RPL_LIBS})

add_executable(test_address test/test_address.c)
target_link_libraries(test_address rpl ${RPL_LIBS})

add_executable(test_thread test/test_thread.c)
target_link_libraries(test_thread rpl ${RPL_LIBS})

add_executable(test_time_clock test/test_time_clock.c)
target_link_libraries(test_time_clock rpl ${RPL_LIBS})

add_executable(test_uart test/test_uart.c)
target_link_libraries(test_uart rpl ${RPL_LIBS})
