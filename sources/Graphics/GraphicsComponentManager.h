#pragma once

// from SDL2
#include <SDL2/SDL_render.h>

// from Graphics
#include "GraphicsComponent.h"

void Graphics_ComponentManager_Create(SDL_Renderer* renderer);
void Graphics_ComponentManager_Destroy();

const Graphics_GraphicsComponent* Graphics_ComponentManager_GetLightGrassComponent();
const Graphics_GraphicsComponent* Graphics_ComponentManager_GetPineTreeComponent();
const Graphics_GraphicsComponent* Graphics_ComponentManager_GetPlayerComponent();
const Graphics_GraphicsComponent* Graphics_ComponentManager_GetYellowFlowersComponent();
const Graphics_GraphicsComponent* Graphics_ComponentManager_VoidComponent();