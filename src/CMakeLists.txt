cmake_minimum_required(VERSION 3.10)
project(double)

option(TESTS OFF)

add_library(double STATIC double.c)
target_link_libraries(double m)

add_executable(main main.c)
target_link_libraries(main double)

if(TESTS)
    add_executable(test tests.c)
    target_link_libraries(test double)
endif()
