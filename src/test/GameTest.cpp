#include <catch2/catch.hpp>
#include "../main/Game.h"
using namespace std;

TEST_CASE("Snake constructor sets length to 2 and lengthen() function incrementes it once", "[game]") {
    // setup
    Game testGame(2);

    SECTION("Testing Game::getGameDifficulty, Game::setGameDifficulty") {
        REQUIRE(((testGame.getGameDifficulty() == L_MEDIUM) && (testGame.getMapWidth() == 40)) &&
                (testGame.getMapHeight() == 40));
    }
    // Teardown
}
