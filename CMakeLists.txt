cmake_minimum_required(VERSION 3.20)

set(MATH_NAME StarletMath)

add_library(${MATH_NAME} INTERFACE)
target_include_directories(${MATH_NAME} INTERFACE inc)
