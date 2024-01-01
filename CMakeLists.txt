cmake_minimum_required(VERSION 3.22)
project(LeetCodeGrind)

set(LeetCode75_Artur_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LeetCode75_Artur)

include_directories(${LeetCode75_Artur_DIR})
add_subdirectory(${LeetCode75_Artur_DIR})


set(DCC2024_Artur_DIR ${CMAKE_CURRENT_SOURCE_DIR}/DCC2024_Artur)

include_directories(${DCC2024_Artur_DIR})
add_subdirectory(${DCC2024_Artur_DIR})