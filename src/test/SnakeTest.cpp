#include <catch2/catch.hpp>
#include "../main/Snake.h"
using namespace std;

TEST_CASE("Snake constructor sets length to 2 and lengthen() function incrementes it once", "[snake]") {
    // setup
    Snake testSnake;
    testSnake.lengthen();

    SECTION("Testing .lengthen() and .getLength() and Snake::Snake()") {
        REQUIRE(testSnake.getLength() == 3);
    }
    // Teardown
}

TEST_CASE("Snake::move() increments snake based on snake's direction", "[snake]") {
    // setup
    Snake northSnake;
    northSnake.setPosition(0, 0);
    northSnake.changeDirection(NORTH);
    northSnake.move();
    Snake westSnake;
    westSnake.setPosition(0, 0);
    westSnake.changeDirection(WEST);
    westSnake.move();
    Snake eastSnake;
    eastSnake.setPosition(0, 0);
    eastSnake.changeDirection(EAST);
    eastSnake.move();
    Snake southSnake;
    southSnake.setPosition(0, 0);
    southSnake.changeDirection(SOUTH);
    southSnake.move();

    SECTION("Testing Snake::move() with direction north") {
        REQUIRE(northSnake.getPosition().y == -1);
    }
    SECTION("Testing Snake::move() with direction west") {
        REQUIRE(westSnake.getPosition().x == -1);
    }
    SECTION("Testing Snake::move() with direction east") {
        REQUIRE(eastSnake.getPosition().x == 1);
    }
    SECTION("Testing Snake::move() with direction south") {
        REQUIRE(southSnake.getPosition().y == 1);
    }
}
