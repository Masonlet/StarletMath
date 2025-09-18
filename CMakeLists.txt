cmake_minimum_required(VERSION 3.20)

set(MATH_NAME StarletMath)

if(NOT TARGET ${MATH_NAME})
  add_library(${MATH_NAME} INTERFACE)
  target_include_directories(${MATH_NAME} INTERFACE inc)
endif()
