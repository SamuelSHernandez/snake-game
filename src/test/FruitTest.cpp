#include <catch2/catch.hpp>
#include "../main/Fruit.h"
#include "../main/Type.h"
using namespace std;

TEST_CASE("Snake::getPosition() returns the fruit's position as a struct Point", "[fruit]") {
    // setup
    Fruit testFruit;
    Point snakeHead;
    snakeHead.x = 5;
    snakeHead.y = 5;
    int board[100][100];

    SECTION("Test that fruit position does not equal snake head position") {
        for (int i = 0; i < 100; ++i) {
            testFruit.setPosition(6, 6, snakeHead, board);
            REQUIRE(testFruit.getPosition().x != snakeHead.x && testFruit.getPosition().y != snakeHead.y);
        }
    }
    // Teardown
}
