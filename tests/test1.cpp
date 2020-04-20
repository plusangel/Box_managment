//
// Created by angelos on 20/04/2020.
//
#define CATCH_CONFIG_MAIN
#include "Box.h"
#include "catch.hpp"
#include "Truckload.h"

inline unsigned random(size_t count) {
  return 1 + static_cast<unsigned>(std::rand() / (RAND_MAX / count + 1));
}

inline SharedBox randomBox() {
  const size_t dimLimit{99};
  return std::make_shared<Box>(random(dimLimit), random(dimLimit),
                               random(dimLimit));
}

TEST_CASE("out of range subscript operator") {
  const size_t nBoxes{6};
  Truckload load1;
  for (size_t i{}; i < nBoxes; ++i)
    load1.addBox(randomBox());

  REQUIRE_THROWS_AS(load1[6], std::out_of_range);
}