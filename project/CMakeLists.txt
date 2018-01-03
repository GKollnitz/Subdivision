cmake_minimum_required(VERSION 3.8)
project(OptimizeSubdiv)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
set(CMAKE_CXX_STANDARD 11)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Ofast")
set(SOURCE_FILES main.cpp HE_Mesh.h HE_Mesh.cpp Mathlib3d.h HEdge.h)
add_executable(OptimizeSubdiv ${SOURCE_FILES})