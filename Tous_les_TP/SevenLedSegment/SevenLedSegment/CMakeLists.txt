project(SevenLedSegment)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)

add_library(STM100Register STMF100RegisterConfiguration.h STMF100RegisterConfiguration.c STMF100Register.h stm32f103_testDriver.h)

target_compile_definitions(STM100Register PUBLIC TESTING)

add_subdirectory(test)


