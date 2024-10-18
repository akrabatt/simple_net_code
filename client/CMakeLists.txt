cmake_minimum_required(VERSION 3.10)
project(Cclient)

set(SOURCE main.c)

add_executable(Cserver ${SOURCE})

set(CMAKE_BUILD_TYPE Debug)
