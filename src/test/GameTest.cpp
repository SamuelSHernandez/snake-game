#include <catch2/catch.hpp>
#include "../main/Game.h"
using namespace std;

TEST_CASE("setGameDifficulty sets member difficulty, mapHeight, and mapWidth variables", "[game]") {
    // setup
    Game testGame(2);

    SECTION("Testing setGameDifficulty sets gameDifficulty") {
        REQUIRE(testGame.getGameDifficulty() == L_MEDIUM);
    }
    SECTION("Testing setGameDifficulty sets mapWidth") {
        REQUIRE(testGame.getMapWidth() == 40);
    }
    SECTION("Testing setGameDifficulty sets mapHeight") {
        REQUIRE(testGame.getMapHeight() == 40);
    }
    // Teardown
}
