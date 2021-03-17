#include "GameView.h"

// from Base
#include "Base/Types.h"

// from Camera
#include "Camera/Camera.h"
#include "Camera/RenderingData.h"

// from World
#include "World/World.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"

// from std
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

    Graphics_ComponentManager_Create(result->renderer);
    return result;
}


void View_GameView_Destroy(const View_GameView* self)
{
    Graphics_ComponentManager_Destroy();
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

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    double ratio = (double)w / h;
    self->camera->width = 640.0;
    self->camera->height = self->camera->width / ratio;

    srand(time(NULL));
    World_Generate(self->world, rand());

    bool done = false;
    do {
        SDL_SetRenderDrawColor(renderer, 15, 0, 60, 255);
        SDL_RenderClear(renderer);

        done = ProcessEvents(self);

        // update world
        
        Camera_RenderingData renderingData = (Camera_RenderingData){
                                                .camera = self->camera,
                                                .renderer = renderer,
                                                .windowWidth = w,
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

    const UInt8* keyboardState = SDL_GetKeyboardState(NULL);

    World_HandleInput(self->world, keyboardState);

    return done;
}