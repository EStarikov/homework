cmake_minimum_required(VERSION 3.10)
project(list)

option(TESTS OFF)

add_library(sortedlist STATIC sortedlist.c)
target_link_libraries(sortedlist)

add_executable(main main.c)
target_link_libraries(main sortedlist)

if(TESTS)
    add_executable(test tests.c)
    target_link_libraries(test sortedlist)
endif()
