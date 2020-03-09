#include "Player.h"

Player::Player() {
    name = "NULL";
    score = 0;
    asciiChar = '.';
}

Player::Player(string myName, char myChar) {
    myName = name;
    myChar = asciiChar;
}
