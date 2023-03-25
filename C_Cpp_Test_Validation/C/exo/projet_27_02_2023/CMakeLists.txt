cmake_minimum_required(VERSION 3.14)

project(Project_LangageC)

set(CMAKE_C_STANDARD 11)

add_executable(test main.c modifyX.c modifyY.c modify.h)
