#include <iostream>

#include "Game.h"


//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main() {

    Game game(SCREEN_WIDTH,SCREEN_HEIGHT);
    //Initialize SDL
    if( game.init() )
    {
        game.Run();
    }
    return 0;
}
