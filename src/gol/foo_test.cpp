#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>
#include <fmt/format.h>

#include <gol/foo.hpp>

TEST_CASE("foo test example") {
  REQUIRE(foo() == 42);
  REQUIRE(0.99999 == Catch::Approx(1));
  REQUIRE_THAT("C++ is magic", Catch::Matchers::EndsWith("magic"));
}
