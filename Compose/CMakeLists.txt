cmake_minimum_required(VERSION 3.0)

project(ASPECT CXX)

add_compile_options(-g -Wall -Werror)
set(CMAKE_CXX_COMPILER g++)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(main main.cc aspect.hpp)
