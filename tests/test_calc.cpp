#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

#include "project/calc.hpp"


TEST_CASE("Add are computed", "[add, subtract]")
{
    REQUIRE(add(1, 2) == 3);
    REQUIRE(subtract(1, 2) == -1);
}