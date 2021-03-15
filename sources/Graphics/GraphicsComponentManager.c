#include "GraphicsComponentManager.h"

// from std
#include <stdlib.h>

// from Graphics
#include "LightGrassComponent.h"
#include "PineTreeComponent.h"
#include "PlayerComponent.h"
#include "YellowFlowersComponent.h"

typedef struct Graphics_ComponentManager Graphics_ComponentManager;

struct Graphics_ComponentManager
{
    Graphics_LightGrassComponent*       lightGrassComponent;
    Graphics_PineTreeComponent*         pineTreeComponent;
    Graphics_PlayerComponent*           playerComponent;
    Graphics_YellowFlowersComponent*    yellowFlowersComponent;
};

static Graphics_ComponentManager* componentManager = NULL;

void Graphics_ComponentManager_Create(SDL_Renderer* renderer)
{
    if(componentManager == NULL) {
        componentManager = malloc(sizeof *componentManager);

        componentManager->lightGrassComponent = Graphics_LightGrassComponent_Create(renderer);
        componentManager->pineTreeComponent = Graphics_PineTreeComponent_Create(renderer);
        componentManager->playerComponent = Graphics_PlayerComponent_Create(renderer);
        componentManager->yellowFlowersComponent = Graphics_YellowFlowersComponent_Create(renderer);
    }
}


void Graphics_ComponentManager_Destroy()
{
    if(componentManager != NULL) {
        Graphics_LightGrassComponent_Destroy(componentManager->lightGrassComponent);
        Graphics_PineTreeComponent_Destroy(componentManager->pineTreeComponent);
        Graphics_PlayerComponent_Destroy(componentManager->playerComponent);
        Graphics_YellowFlowersComponent_Destroy(componentManager->yellowFlowersComponent);

        free(componentManager);
    }
}

const Graphics_GraphicsComponent* Graphics_ComponentManager_GetLightGrassComponent()
{
    if(componentManager != NULL) {
        return componentManager->lightGrassComponent;
    }

    return NULL;
}


const Graphics_GraphicsComponent* Graphics_ComponentManager_GetPineTreeComponent()
{
    if(componentManager != NULL) {
        return componentManager->pineTreeComponent;
    }

    return NULL;
}


const Graphics_GraphicsComponent* Graphics_ComponentManager_GetPlayerComponent()
{
    if(componentManager != NULL) {
        return componentManager->playerComponent;
    }

    return NULL;
}


const Graphics_GraphicsComponent* Graphics_ComponentManager_GetYellowFlowersComponent()
{
    if(componentManager != NULL) {
        return componentManager->yellowFlowersComponent;
    }

    return NULL;
}