find_package(CLI11 REQUIRED)

# -----------------------------------------------------------------------

add_executable(main ${CMAKE_SOURCE_DIR}/app/main.cpp)
target_link_libraries(main PRIVATE
        ${PROJECT_NAME}::logger
        CLI11::CLI11
)

