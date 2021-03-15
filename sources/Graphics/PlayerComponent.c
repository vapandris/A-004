#include "PlayerComponent.h"

// from Camera 
#include "Camera/Camera.h"

// from std
#include <stdlib.h>
#include <stdio.h>

// from SDL2
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>

GRAPHICS_COMPONENT_BASE

typedef struct ComponentData {
    SDL_Texture* tmpTexture;
} ComponentData;

static ComponentData* GetComponentData(const Graphics_PlayerComponent* self);
static void LoadTextures(Graphics_PlayerComponent* self, SDL_Renderer* renderer);

void PlayerComponent_Destroy_override(const Graphics_GraphicsComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    
    SDL_DestroyTexture(componentData->tmpTexture);
    free((Graphics_GraphicsComponent*)self);
}


void PlayerComponent_Draw_override(const Graphics_GraphicsComponent* self, SDL_Rect textureRect, Camera_RenderingData* renderingData)
{
    ComponentData* componentData = GetComponentData(self);

    if(componentData->tmpTexture != NULL)
        SDL_RenderCopy(renderingData->renderer, componentData->tmpTexture, NULL, &textureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize   = sizeof(ComponentData),
    .destroy    = &PlayerComponent_Destroy_override,
    .draw       = &PlayerComponent_Draw_override
};


Graphics_PlayerComponent* Graphics_PlayerComponent_Create(SDL_Renderer* renderer)
{
    Graphics_PlayerComponent* result = Graphics_GraphicsComponent_Create(&type, renderer);
    
    LoadTextures(result, renderer);

    return result;
}


void Graphics_PlayerComponent_Destroy(const Graphics_PlayerComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}


// static functions:
static ComponentData* GetComponentData(const Graphics_PlayerComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void LoadTextures(Graphics_PlayerComponent* self, SDL_Renderer* renderer)
{
    ComponentData* componentData = GetComponentData(self);

    const char* imgLocation = "assets/Player/Player_tmp.png";
    componentData->tmpTexture = IMG_LoadTexture(renderer, imgLocation);

    if(componentData->tmpTexture == NULL)
        fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
}