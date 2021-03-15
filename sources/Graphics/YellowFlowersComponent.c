#include "YellowFlowersComponent.h"

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
    SDL_Texture* yellowFlowers;
} ComponentData;


static ComponentData* GetComponentData(const Graphics_YellowFlowersComponent* self);
static void LoadTextures(Graphics_YellowFlowersComponent* self, SDL_Renderer* renderer);


void Graphics_YellowFlowersComponent_Destroy_override(const Graphics_GraphicsComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    SDL_DestroyTexture(componentData->yellowFlowers);

    free((Graphics_GraphicsComponent*)self);
}


void Graphics_YellowFlowersComponent_Draw_override(const Graphics_GraphicsComponent* self, SDL_Rect textureRect, Camera_RenderingData* renderingData)
{
    ComponentData* componentData = GetComponentData(self);

    if(componentData->yellowFlowers != NULL)
        SDL_RenderCopy(renderingData->renderer, componentData->yellowFlowers, NULL, &textureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize = sizeof(ComponentData),
    .destroy = &Graphics_YellowFlowersComponent_Destroy_override,
    .draw = &Graphics_YellowFlowersComponent_Draw_override
};



Graphics_YellowFlowersComponent* Graphics_YellowFlowersComponent_Create(SDL_Renderer* renderer)
{
    Graphics_YellowFlowersComponent* result = Graphics_GraphicsComponent_Create(&type, renderer);
    
    LoadTextures(result, renderer);

    return result;
}


void Graphics_YellowFlowersComponent_Destroy(const Graphics_YellowFlowersComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}


// static functions:
static ComponentData* GetComponentData(const Graphics_YellowFlowersComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void LoadTextures(Graphics_YellowFlowersComponent* self, SDL_Renderer* renderer)
{
    ComponentData* componentData = GetComponentData(self);

    const char* imgLocation = "assets/Yellow_Flowers_1.png";
    componentData->yellowFlowers = IMG_LoadTexture(renderer, imgLocation);

    if(componentData->yellowFlowers == NULL)
        fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
}