cmake_minimum_required(VERSION 3.0)

project(libft)

file(GLOB SRC "srcs/*/*.c")

set(GCC_FLAGS "-Wall -Werror -Wextra")

add_definitions(${GCC_FLAGS})
add_library(ft STATIC ${SRC})

target_include_directories(ft PUBLIC ${PROJECT_SOURCE_DIR}/includes)
