#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

class Game
{
private:
    int _width;
    int _height;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The images that correspond to a keypress
    SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

    //Current displayed image
    SDL_Surface* gCurrentSurface = NULL;
    
    //The image we will load and show on the screen
    SDL_Surface* gXOut = NULL;
public:
    Game();
    Game(int width, int height);
    ~Game();
    void Run();
    void Update();

    bool init();
    //Loads individual image
    SDL_Surface* loadSurface( std::string path );
    bool loadMedia();
    void close();
};

#endif
