#include <catch2/catch_test_macros.hpp>
#include <gol/foo.hpp>

#include "catch2/catch_approx.hpp"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

TEST_CASE("foo test example") {
    REQUIRE(foo() == 42);
    REQUIRE(0.99999 == Catch::Approx(1));
    REQUIRE_THAT("C++ is magic", Catch::Matchers::EndsWith("magic"));
}
