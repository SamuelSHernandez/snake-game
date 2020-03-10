#include <catch2/catch.hpp>
#include "../../main/Type.h"

TEST_CASE("points are equal", "[type]") {
    // Setup
    Point a;
    a.x = 5;
    a.y = 5;

    Point b;
    b.x = 5;
    b.y = 5;

    REQUIRE(a == b);
}

TEST_CASE("points are not equal", "[type]") {
    // Setup
    Point a;
    a.x = 5;
    a.y = 5;

    Point b;
    b.x = 5;
    b.y = 4;


    REQUIRE(!(a == b));
}
