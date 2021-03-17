#include "VoidComponent.h"

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
    SDL_Texture* voidFull;
} ComponentData;


static ComponentData* GetComponentData(const Graphics_VoidComponent* self);
static void LoadTextures(Graphics_VoidComponent* self, SDL_Renderer* renderer);


void VoidComponent_Destroy_override(const Graphics_VoidComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    SDL_DestroyTexture(componentData->voidFull);

    free((Graphics_VoidComponent*)self);
}


void VoidComponent_Draw_override(const Graphics_GraphicsComponent* self, SDL_Rect textureRect, Camera_RenderingData* renderingData)
{
    ComponentData* componentData = GetComponentData(self);
    
    if(componentData->voidFull != NULL)
        SDL_RenderCopy(renderingData->renderer, componentData->voidFull, NULL, &textureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize = sizeof(ComponentData),
    .destroy = &VoidComponent_Destroy_override,
    .draw = &VoidComponent_Draw_override
};


Graphics_VoidComponent* Graphics_VoidComponent_Create(SDL_Renderer* renderer)
{
    Graphics_VoidComponent* result = Graphics_GraphicsComponent_Create(&type, renderer);
    
    LoadTextures(result, renderer);

    return result;
}


void Graphics_VoidComponent_Destroy(const Graphics_VoidComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}

// static functions:
static ComponentData* GetComponentData(const Graphics_VoidComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void LoadTextures(Graphics_VoidComponent* self, SDL_Renderer* renderer)
{
    ComponentData* componentData = GetComponentData(self);

    const char* imgLocation = "assets/Tiles/void_1.png";
    componentData->voidFull = IMG_LoadTexture(renderer, imgLocation);

    if(componentData->voidFull == NULL)
        fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
}