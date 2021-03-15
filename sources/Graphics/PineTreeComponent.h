#pragma once

#include "GraphicsComponent.h"

typedef Graphics_GraphicsComponent Graphics_PineTreeComponent;

Graphics_PineTreeComponent* Graphics_PineTreeComponent_Create(SDL_Renderer* renderer);
void Graphics_PineTreeComponent_Destroy(const Graphics_PineTreeComponent* self);