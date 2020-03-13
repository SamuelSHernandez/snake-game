#include <catch2/catch.hpp>
#include "../main/Game.h"
using namespace std;

TEST_CASE("setGameDifficulty sets member difficulty, mapHeight, and mapWidth variables", "[game]") {
    // setup
    Game testGame(2, '*', "Luke");

    SECTION("Testing setGameDifficulty sets mapWidth") {
        REQUIRE(testGame.getMapWidth() == 20);
    }
    SECTION("Testing setGameDifficulty sets mapHeight") {
        REQUIRE(testGame.getMapHeight() == 20);
    }
    // Teardown
}
