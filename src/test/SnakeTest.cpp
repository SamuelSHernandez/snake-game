#include <catch2/catch.hpp>
#include "../main/Snake.h"
using namespace std;

TEST_CASE("Snake constructor sets length to 2 and lengthen() function incrementes it once", "[snake]") {
    // setup
    Snake testSnake('*');
    testSnake.lengthen();

    SECTION("Testing .lengthen() and .getLength() and Snake::Snake()") {
        REQUIRE(testSnake.getLength() == 3);
    }
    // Teardown
}