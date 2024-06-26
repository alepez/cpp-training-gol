#include <catch2/catch_test_macros.hpp>
#include <gol/bar.hpp>

#include "catch2/catch_approx.hpp"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

TEST_CASE("bar test example") {
    REQUIRE(bar() == 17);
    REQUIRE(0.99999 == Catch::Approx(1));
    REQUIRE_THAT("C++ is magic", Catch::Matchers::EndsWith("magic"));
}
