find_package(Catch2 3 REQUIRED)

add_executable(test_calc ${CMAKE_SOURCE_DIR}/tests/test_calc.cpp)
target_link_libraries(test_calc PRIVATE
    calc
    Catch2::Catch2WithMain
)
add_test(NAME test_calc COMMAND test_calc)