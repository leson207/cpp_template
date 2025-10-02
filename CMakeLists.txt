cmake_minimum_required(VERSION 3.31.6)
project(my_project LANGUAGES C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(src)

# cmake --preset default -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# cmake --build build -j 8