cmake_minimum_required(VERSION 3.25)

project(hello C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(hello hello.c)
