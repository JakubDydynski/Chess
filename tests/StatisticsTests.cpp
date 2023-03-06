#include <Statistics.h>

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Created aggregator is empty", "[statistics]") {
  swo::stats::Statistics a;
  REQUIRE(a.count() == 0);
  REQUIRE(a.sum() == 0);
}

// Collect
TEST_CASE("Collecting results in incrementing count", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  REQUIRE(a.count() == 1);
}

// Sum
TEST_CASE("Statistics accumulates added values", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  a.collect(4);
  REQUIRE(a.sum() == 10);
}

// Average
TEST_CASE("Statistics averages added values", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  a.collect(4);
  a.collect(5);
  REQUIRE(a.average() == Catch::Approx(3));
}

// Count
TEST_CASE("Statistics counts number of added values", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  a.collect(4);
  a.collect(5);
  REQUIRE(a.count() == 5);
}

// Maximum
TEST_CASE("Statistics finds maximum value added", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  a.collect(4);
  a.collect(5);
  REQUIRE(a.max() == 5);
}

// Minimum
TEST_CASE("Statistics finds minimum value added", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  a.collect(4);
  a.collect(5);
  REQUIRE(a.min() == 1);
}

// Median
TEST_CASE("Statistics median of 0 elements is 0.0") {
  swo::stats::Statistics a;
  REQUIRE(a.median() == 0.0);
}

TEST_CASE("Statistics calculates median properly", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(5);
  a.collect(10);
  REQUIRE(a.median() == 5.0);
}
// Standard deviation
TEST_CASE("Statistics calculates standard deviation of all the same values added", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(1);
  a.collect(1);
  REQUIRE(a.standard_deviation() == 0.0);
}

TEST_CASE("Statistics calculates standard deviation of different values added", "[statistics]") {
  swo::stats::Statistics a;
  a.collect(1);
  a.collect(2);
  a.collect(3);
  REQUIRE(a.standard_deviation() == Catch::Approx(0.81649658092773));
}