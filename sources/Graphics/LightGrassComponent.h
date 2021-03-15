#pragma once

#include "GraphicsComponent.h"

typedef Graphics_GraphicsComponent Graphics_LightGrassComponent;

Graphics_LightGrassComponent* Graphics_LightGrassComponent_Create(SDL_Renderer* renderer);
void Graphics_LightGrassComponent_Destroy(const Graphics_LightGrassComponent* self);