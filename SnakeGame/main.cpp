#include "Game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    Game game("images/map.png");
    game.run();

    return 0;
}