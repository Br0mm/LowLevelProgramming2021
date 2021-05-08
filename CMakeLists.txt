cmake_minimum_required(VERSION 3.19)
project(untitled2 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled2 src/main.c src/graph.c include/graph.h src/tests.c include/tests.h)