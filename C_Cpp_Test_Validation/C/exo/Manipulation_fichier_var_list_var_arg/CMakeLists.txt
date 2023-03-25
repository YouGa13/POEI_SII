cmake_minimum_required(VERSION 3.14)

project(Project_LangageC)

set(CMAKE_C_STANDARD 11)

add_library(console console.c)

add_library(fichier fichier.c)

add_executable(test main.c calc.c calc.h io.h)

target_link_libraries(test  PUBLIC console)

add_executable(test2 main.c calc.c calc.h io.h)

target_link_libraries(test2  PUBLIC fichier)

add_executable(var_ext var_ext.c)