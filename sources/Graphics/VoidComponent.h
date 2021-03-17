#pragma once

#include "GraphicsComponent.h"

typedef Graphics_GraphicsComponent Graphics_VoidComponent;

Graphics_VoidComponent* Graphics_VoidComponent_Create(SDL_Renderer* renderer);
void Graphics_VoidComponent_Destroy(const Graphics_VoidComponent* self);