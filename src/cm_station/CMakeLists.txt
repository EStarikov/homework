cmake_minimum_required(VERSION 3.25)

project(station C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(stack cm_stack.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(station cm_station.c)

target_link_libraries(station stack)