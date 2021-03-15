#pragma once

#include "GraphicsComponent.h"

typedef Graphics_GraphicsComponent Graphics_YellowFlowersComponent;

Graphics_YellowFlowersComponent* Graphics_YellowFlowersComponent_Create(SDL_Renderer* renderer);
void Graphics_YellowFlowersComponent_Destroy(const Graphics_YellowFlowersComponent* self);