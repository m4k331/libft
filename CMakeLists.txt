cmake_minimum_required(VERSION 3.0)

project(test)

file(GLOB SRC_TEST "main.c")

add_subdirectory(libft)
add_executable(test ${SRC_TEST})

target_include_directories(test PUBLIC inc)
target_link_libraries(test PRIVATE ft)
