cmake_minimum_required(VERSION 3.10)
project(birepresent)

option(TESTS OFF)

add_library(birepresent STATIC birepresent.c)
target_link_libraries(birepresent m)

add_executable(main main.c)
target_link_libraries(main birepresent)

if(TESTS)
    add_executable(test tests.c)
    target_link_libraries(test birepresent)
endif()