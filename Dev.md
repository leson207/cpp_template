tests/catches

# Automatically add each source file that has a matching header in include/project
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/project/*.hpp)
set(SOURCES "")

foreach(HEADER ${HEADERS})
    get_filename_component(NAME ${HEADER} NAME_WE)
    set(SRC_FILE "${CMAKE_SOURCE_DIR}/src/project/${NAME}.cpp")
    if(EXISTS ${SRC_FILE})
        list(APPEND SOURCES ${SRC_FILE})
    endif()
endforeach()

add_library(project STATIC ${SOURCES})
