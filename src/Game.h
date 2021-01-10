#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>

class Game
{
private:
    int _width;
    int _height;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The image we will load and show on the screen
    SDL_Surface* gXOut = NULL;
public:
    Game();
    Game(int width, int height);
    ~Game();
    void Run();
    void Update();

    bool init();
    bool loadMedia();
    void close();
};

#endif
