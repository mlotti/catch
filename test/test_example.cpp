#include <catch2/catch_test_macros.hpp>

TEST_CASE("Basic arithmetic", "[math]") {
    REQUIRE(2 + 2 == 4);
    REQUIRE(6 / 3 == 2);
}
