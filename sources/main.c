#include "View/GameView.h"
#include <SDL2/SDL.h>


int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    View_GameView* gameView = View_GameView_Create();
    View_GameView_Start(gameView);
    View_GameView_Destroy(gameView);
    
    SDL_Quit();
    return 0;
}