cmake_minimum_required(VERSION 3.10)
project(socketutil C)

set(CMAKE_C_STANDARD 99)


add_library(socketutil STATIC socketutil.c)

target_include_directories(socketutil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})