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


static ComponentData* GetComponentData(const Graphics_LightGrassComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


void LightGrassComponent_Destroy_override(const Graphics_LightGrassComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    SDL_DestroyTexture(componentData->lightGrassFull);

    free((Graphics_LightGrassComponent*)self);
}


void LightGrassComponent_Draw_override(const Graphics_GraphicsComponent* self, const CoreData* data, Camera_RenderingData* renderingData)
{
    WindowData windowData =  Camera_CalculateWindowDataFromCoreData(renderingData->camera, renderingData->widowWidth, renderingData->windowHeight, data);
    ComponentData* componentData = GetComponentData(self);
    if(componentData->lightGrassFull == NULL) {
        const char* imgLocation = "assets/Tiles/light_grass_1.png";
        componentData->lightGrassFull = IMG_LoadTexture(renderingData->renderer, imgLocation);

        if(componentData->lightGrassFull == NULL) {
            fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
            return;
        }
    }

    SDL_Rect playerTextureRect = (SDL_Rect){.x = windowData.x, .y = windowData.y, .w = windowData.width, .h = windowData.height};
    SDL_RenderCopy(renderingData->renderer, componentData->lightGrassFull, NULL, &playerTextureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize = sizeof(ComponentData),
    .destroy = &LightGrassComponent_Destroy_override,
    .draw = &LightGrassComponent_Draw_override
};


Graphics_LightGrassComponent* Graphics_LightGrassComponent_Create()
{
    Graphics_LightGrassComponent* result = Graphics_GraphicsComponent_Create(&type);
    ComponentData* componentData = GetComponentData(result);
    componentData->lightGrassFull = NULL;

    return result;
}


void Graphics_LightGrassComponent_Destroy(const Graphics_LightGrassComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}