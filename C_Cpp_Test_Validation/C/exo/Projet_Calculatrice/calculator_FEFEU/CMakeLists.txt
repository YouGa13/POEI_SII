cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)

project(calculator)

add_library(arithmetic arithmetic.h arithmetic.c)
add_library(console io.h io_console.c)
add_library(file io.h io_file.c)

add_executable(calculator_f calculator.c)
add_executable(calculator_c calculator.c)

target_link_libraries(calculator_f PUBLIC arithmetic file)
target_link_libraries(calculator_c PUBLIC arithmetic console)
