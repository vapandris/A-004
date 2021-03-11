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

static ComponentData* GetComponentData(const Graphics_PlayerComponent* self)
{
    return (ComponentData*)self->bufferStart;
}

void PlayerComponent_Destroy_override(const Graphics_GraphicsComponent* self)
{
    ComponentData* componentData = GetComponentData(self);
    
    SDL_DestroyTexture(componentData->tmpTexture);
    free((Graphics_GraphicsComponent*)self);
}


void PlayerComponent_Draw_override(const Graphics_GraphicsComponent* self, const CoreData* data, Camera_RenderingData* renderingData)
{
    WindowData windowData = Camera_CalculateWindowDataFromCoreData(renderingData->camera, renderingData->widowWidth, renderingData->windowHeight, data);
    ComponentData* componentData = GetComponentData(self);
    if(componentData->tmpTexture == NULL) { // ez nem tetszik
        const char* imgLocation = "assets/Player/Player_tmp.png";
        componentData->tmpTexture = IMG_LoadTexture(renderingData->renderer, imgLocation);

        if(componentData->tmpTexture == NULL) {
            fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
            return;
        }
    }

    SDL_Rect playerTextureRect = (SDL_Rect){.x = windowData.x, .y = windowData.y, .w = windowData.width, .h = windowData.height};
    SDL_RenderCopy(renderingData->renderer, componentData->tmpTexture, NULL, &playerTextureRect);
}


static Graphics_GraphicsComponentType type = {
    .typeSize   = sizeof(ComponentData),
    .destroy    = &PlayerComponent_Destroy_override,
    .draw       = &PlayerComponent_Draw_override
};


Graphics_PlayerComponent* Graphics_PlayerComponent_Create()
{
    Graphics_PlayerComponent* result = Graphics_GraphicsComponent_Create(&type);
    ComponentData* componentData = GetComponentData(result);
    componentData->tmpTexture = NULL;

    return result;
}


void Graphics_PlayerComponent_Destroy(const Graphics_PlayerComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}