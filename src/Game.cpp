#include "Game.h"

Game::Game(/* args */) :
    _width(640),
    _height(480)
{
}

Game::Game(int width, int height) :
    _width(width),
    _height(height)
{
}

Game::~Game()
{
}

void Game::Run()
{
    std::cout << "Game.Run()" << std::endl;
    //Load media
	if( !loadMedia() )
	{
		printf( "Failed to load media!\n" );
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
			}

			//Apply the image
			SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );

			//Update the surface
			SDL_UpdateWindowSurface( gWindow );
		}
	}

	//Free resources and close SDL
	close();
}

void Game::Update()
{
}

bool Game::init()
{
    std::cout << "Game.init()" << std::endl;
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
    }
    return success;
}

bool Game::loadMedia()
{
    std::cout << "Game.loadMedia()" << std::endl;
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP( "/home/aref/Dev/CppND-Capstone-Pacman/x.bmp" );
	if( gXOut == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "/home/aref/Dev/CppND-Capstone-Pacman/x.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}
void Game::close()
{
    std::cout << "Game.close()" << std::endl;
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
