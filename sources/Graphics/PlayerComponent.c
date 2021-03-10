#include "PlayerComponent.h"

// from std
#include <stdlib.h>
#include <stdio.h>

// from SDL2
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

GRAPHICS_COMPONENT_BASE

typedef struct PlayerData {
    SDL_Texture* tmpTexture;
} PlayerData;

static PlayerData* GetPlayerData(const Graphics_PlayerComponent* self)
{
    return (PlayerData*)self->bufferStart;
}

void PlayerComponent_Destroy_override(const Graphics_GraphicsComponent* self)
{
    PlayerData* playerData = GetPlayerData(self);
    
    SDL_DestroyTexture(playerData->tmpTexture);
    free((Graphics_GraphicsComponent*)self);
}


void PlayerComponent_Draw_override(const Graphics_GraphicsComponent* self, const CoreData* data, SDL_Renderer* renderer)
{
    PlayerData* playerData = GetPlayerData(self);
    if(playerData->tmpTexture == NULL) { // ez nem tetszik
        const char* imgLocation = "assets/Player/Player_tmp.png";
        playerData->tmpTexture = IMG_LoadTexture(renderer, imgLocation);

        if(playerData->tmpTexture == NULL) {
            fprintf(stderr, "[%s] NOT FOUND!\n", imgLocation);
        }
    }
}

Graphics_GraphicsComponentType type = {
    .typeSize   = sizeof(PlayerData),
    .destroy    = &PlayerComponent_Destroy_override,
    .draw       = &PlayerComponent_Draw_override
};


Graphics_PlayerComponent* Graphics_PlayerComponent_Create()
{
    Graphics_PlayerComponent* result = Graphics_GraphicsComponent_Create(&type);
    PlayerData* playerData = GetPlayerData(result);
    playerData->tmpTexture = NULL;

    return result;
}


void Graphics_PlayerComponent_Destroy(const Graphics_PlayerComponent* self)
{
    Graphics_GraphicsComponent_Destroy(self);
}