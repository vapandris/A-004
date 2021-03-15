#pragma once

#include "GraphicsComponent.h"

typedef Graphics_GraphicsComponent Graphics_PlayerComponent;

Graphics_PlayerComponent* Graphics_PlayerComponent_Create(SDL_Renderer* renderer);
void Graphics_PlayerComponent_Destroy(const Graphics_PlayerComponent* self);