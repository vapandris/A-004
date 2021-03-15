#include "LightGrassComponent.h"

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
    SDL_Texture* lightGrassFull;
} ComponentData;


static ComponentData* GetComponentData(const Graphics_LightGrassComponent* self);
static void LoadTextures(Graphics_LightGrassComponent* self, SDL_Renderer* renderer);


void LightGrassComponent_Destroy_override(const Graphics_LightGrassComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    SDL_DestroyTexture(componentData->lightGrassFull);

    free((Graphics_LightGrassComponent*)self);
}


void LightGrassComponent_Draw_override(const Graphics_GraphicsComponent* self, SDL_Rect textureRect, Camera_RenderingData* renderingData)
{
    ComponentData* componentData = GetComponentData(self);
    
    if(componentData->lightGrassFull != NULL)
        SDL_RenderCopy(renderingData->renderer, componentData->lightGrassFull, NULL, &textureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize = sizeof(ComponentData),
    .destroy = &LightGrassComponent_Destroy_override,
    .draw = &LightGrassComponent_Draw_override
};


Graphics_LightGrassComponent* Graphics_LightGrassComponent_Create(SDL_Renderer* renderer)
{
    Graphics_LightGrassComponent* result = Graphics_GraphicsComponent_Create(&type, renderer);
    
    LoadTextures(result, renderer);

    return result;
}


void Graphics_LightGrassComponent_Destroy(const Graphics_LightGrassComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}

// static functions:
static ComponentData* GetComponentData(const Graphics_LightGrassComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void LoadTextures(Graphics_LightGrassComponent* self, SDL_Renderer* renderer)
{
    ComponentData* componentData = GetComponentData(self);

    const char* imgLocation = "assets/Tiles/light_grass_1.png";
    componentData->lightGrassFull = IMG_LoadTexture(renderer, imgLocation);

    if(componentData->lightGrassFull == NULL)
        fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
}