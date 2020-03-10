#include <catch2/catch.hpp>
#include "../../main/Snake.h"

TEST_CASE("points are equal", "[snake]") {
    // Setup
    Snake snake;

    snake.setPosition(0, 0);
    snake.changeDirection(EAST);
    snake.move();
    snake.move();
    snake.changeDirection(NORTH);
    snake.move();
    
    REQUIRE((snake.getPosition().x == 2) && snake.getPosition().y == 1);
}