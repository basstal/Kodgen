cmake_minimum_required(VERSION 3.13.5)

project(Kodgen)

# Information messages about cmake version and compiler
message("Cmake:		${CMAKE_VERSION}")
message("Compiler:	${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# Enable tests
include(CTest)

add_subdirectory(Kodgen)