cmake_minimum_required(VERSION 3.0)

project(ASPECT)

add_compile_options(-g)
set(CMAKE_CXX_COMPILER "g++")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.cc logaspect.hpp timeaspect.hpp aspect.hpp)