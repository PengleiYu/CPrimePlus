cmake_minimum_required(VERSION 3.7)
project(CPrimePlus)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES list.h film3.c list.c queue.c queue.h mall.c tree.c tree.h)
add_executable(CPrimePlus ${SOURCE_FILES})