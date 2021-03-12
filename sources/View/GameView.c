#include "GameView.h"

// from Base
#include "Base/Types.h"

// from Camera
#include "Camera/Camera.h"
#include "Camera/RenderingData.h"

// from World
#include "World/World.h"

// from std
#include <stdlib.h>
#include <stdbool.h>

// from SDL2
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

struct View_GameView
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    Camera* camera;
    World* world;
};

static bool ProcessEvents(View_GameView* self);


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

    result->camera = malloc(sizeof *result->camera);
    result->world = World_Create(result->camera);

    return result;
}


void View_GameView_Destroy(const View_GameView* self)
{
    SDL_DestroyWindow(self->window);
    SDL_DestroyRenderer(self->renderer);

    free(self->camera);
    World_Destroy(self->world);

    free((View_GameView*)self);
}


void View_GameView_Loop(View_GameView* self)
{
    SDL_Window* window = self->window;
    SDL_Renderer* renderer = self->renderer;

    World_Generate(self->world, 0);

    bool done = false;
    do {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        done = ProcessEvents(self);

        // update world

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
        double ratio = (double)w / h;
        self->camera->width = 1000.0;
        self->camera->height = self->camera->width / ratio;
        Camera_RenderingData renderingData = (Camera_RenderingData){
                                                .camera = self->camera,
                                                .renderer = renderer,
                                                .widowWidth = w,
                                                .windowHeight = h
        };
        World_RenderEntities(self->world, &renderingData);

        SDL_RenderPresent(renderer);
    } while(!done);
    
}


static bool ProcessEvents(View_GameView* self)
{
    bool done = false;

    SDL_Event event;
    while(SDL_PollEvent(&event) == true) {
        if(event.type == SDL_WINDOWEVENT_CLOSE ||
           event.type == SDL_QUIT ||
           (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)) {
            done = true;
        }
    }

    const UInt8* state = SDL_GetKeyboardState(NULL);

    double distance = 2;
    if(state[SDL_SCANCODE_LEFT] != 0 || state[SDL_SCANCODE_A] != 0) {
        World_MovePlayerTmp(self->world, distance, 0);
    } else if(state[SDL_SCANCODE_RIGHT] != 0 || state[SDL_SCANCODE_D] != 0) {
        World_MovePlayerTmp(self->world, distance, 1);
    } else if(state[SDL_SCANCODE_UP] != 0 || state[SDL_SCANCODE_W] != 0) {
        World_MovePlayerTmp(self->world, distance, 2);
    } else if(state[SDL_SCANCODE_DOWN] != 0 || state[SDL_SCANCODE_S] != 0) {
        World_MovePlayerTmp(self->world, distance, 3);
    }

    return done;
}