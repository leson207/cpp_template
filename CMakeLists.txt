cmake_minimum_required(VERSION 3.31.6)
project(cpp_template LANGUAGES C CXX)

message("Building with CMake version: ${CMAKE_VERSION}")

# -----------------------------------------------------------------------

add_subdirectory(app)
add_subdirectory(src)

include(CTest)
enable_testing()
add_subdirectory(tests)
