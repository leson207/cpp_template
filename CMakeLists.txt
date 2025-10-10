cmake_minimum_required(VERSION 3.31.6)
project(cpp_sample LANGUAGES C CXX)

message("Building with CMake version: ${CMAKE_VERSION}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(src)