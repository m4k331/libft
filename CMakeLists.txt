cmake_minimum_required(VERSION 3.0)

project(libft)

file(GLOB SRC "srcs/*/*.c")

set(GCC_FLAGS "-Wall -Werror -Wextra")

add_definitions(${GCC_FLAGS})
add_library(ft STATIC ${SRC} srcs/vector/ft_vnext_con.c srcs/vector/ft_vback_con.c srcs/vector/ft_vcurr_con.c)

target_include_directories(ft PUBLIC ${PROJECT_SOURCE_DIR}/includes)
