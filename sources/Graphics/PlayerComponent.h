#pragma once

#include "GraphicsComponent.h"

// from SDL2
#include <SDL2/SDL_render.h>

typedef Graphics_GraphicsComponent Graphics_PlayerComponent;

Graphics_PlayerComponent* Graphics_PlayerComponent_Create();
void Graphics_PlayerComponent_Destroy(const Graphics_PlayerComponent* self);