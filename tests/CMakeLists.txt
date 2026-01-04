find_package(Catch2 REQUIRED)

add_executable(test_calc ${PROJECT_SOURCE_DIR}/tests/test_calc.cpp)
target_link_libraries(test_calc PRIVATE
    ${PROJECT_NAME}::calc
    Catch2::Catch2WithMain
)
add_test(NAME test_calc COMMAND test_calc)
