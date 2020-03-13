#include "Player.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
Player::Player() {
    name = "NULL";
    score = 0;
    asciiChar = '.';
}

Player::Player(string myName, char asciiChar) {
    myName = name;
}



