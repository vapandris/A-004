#include "GameView.h"

// from Utils
#include "Utils/Types.h"

// from std
#include <stdlib.h>
#include <stdbool.h>

// from SDL
//#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

struct gameView
{
    SDL_Window* window;
    SDL_Renderer* renderer;
};

static bool ProcessEvents();


View_GameView* View_GameView_Create()
{
    View_GameView* result = malloc(sizeof *result);
    result->window = SDL_CreateWindow(
        "POG game",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        720, 482,
        SDL_WINDOW_MAXIMIZED | SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    result->renderer = SDL_CreateRenderer(result->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // create/generate/whatever GameState

    return result;
}


void View_GameView_Destroy(const View_GameView* self)
{
    SDL_DestroyWindow(self->window);
    SDL_DestroyRenderer(self->renderer);

    // free GameState

    free((View_GameView*)self);
}


void View_GameView_Start(View_GameView* self)
{
    //SDL_Window* window = self->window;
    SDL_Renderer* renderer = self->renderer;

    bool done = false;
    do {
        SDL_SetRenderDrawColor(renderer, 50, 250, 50, 255);
        SDL_RenderClear(renderer);

        done = ProcessEvents();

        // update world

        SDL_RenderPresent(renderer);
    } while(!done);
    
}


static bool ProcessEvents()
{
    bool done = false;

    SDL_Event event;
    while(SDL_PollEvent(&event) == true) {
        if(event.type == SDL_WINDOWEVENT_CLOSE ||
           event.type == SDL_QUIT ||
           ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)) {
            done = true;
        }
        //const UInt8* state = SDL_GetKeyboardState(NULL);
    }

    return done;
}