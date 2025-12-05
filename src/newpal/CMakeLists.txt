cmake_minimum_required(VERSION 3.10)
project(newpalindrom)

option(TESTS OFF)

add_library(palindrom STATIC palindrom.c)

add_executable(main main.c)
target_link_libraries(main palindrom)

if(TESTS)
    add_executable(test tests.c)
    target_link_libraries(test palindrom)
endif()