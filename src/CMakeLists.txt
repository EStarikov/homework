cmake_minimum_required(VERSION 3.25)

project(station C)

add_library(stack cm_stack.c)

add_executable(station cm_station.c)

target_link_libraries(station stack)