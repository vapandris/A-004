#include "PineTreeComponent.h"

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
    SDL_Texture* pineSmall;
} ComponentData;


static ComponentData* GetComponentData(const Graphics_PineTreeComponent* self);
static void LoadTextures(Graphics_PineTreeComponent* self, SDL_Renderer* renderer);


void Graphics_PineTreeComponent_Destroy_override(const Graphics_GraphicsComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    SDL_DestroyTexture(componentData->pineSmall);

    free((Graphics_GraphicsComponent*)self);
}


void Graphics_PineTreeComponent_Draw_override(const Graphics_GraphicsComponent* self, SDL_Rect textureRect, Camera_RenderingData* renderingData)
{
    ComponentData* componentData = GetComponentData(self);

    if(componentData->pineSmall != NULL)
        SDL_RenderCopy(renderingData->renderer, componentData->pineSmall, NULL, &textureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize = sizeof(ComponentData),
    .destroy = &Graphics_PineTreeComponent_Destroy_override,
    .draw = &Graphics_PineTreeComponent_Draw_override
};


Graphics_PineTreeComponent* Graphics_PineTreeComponent_Create(SDL_Renderer* renderer)
{
    Graphics_PineTreeComponent* result = Graphics_GraphicsComponent_Create(&type, renderer);
    
    LoadTextures(result, renderer);

    return result;
}


void Graphics_PineTreeComponent_Destroy(const Graphics_PineTreeComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}


// static functions:
static ComponentData* GetComponentData(const Graphics_PineTreeComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void LoadTextures(Graphics_PineTreeComponent* self, SDL_Renderer* renderer)
{
    ComponentData* componentData = GetComponentData(self);
    const char* imgLocation = "assets/Tree_1.png";
    componentData->pineSmall = IMG_LoadTexture(renderer, imgLocation);

    if(componentData->pineSmall == NULL)
        fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
}