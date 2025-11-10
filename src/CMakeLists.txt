cmake_minimum_required(VERSION 3.25)

project(balance C)

add_library(stack cm_stack.c)

add_executable(balance cm_balance.c)

target_link_libraries(balance stack)
