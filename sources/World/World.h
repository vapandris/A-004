#pragma once

// from Camera
#include "Camera/Camera.h"

// from SDL2
#include <SDL2/SDL_render.h>

typedef struct World World;

World* World_Create(Camera* camera);
void   World_Destroy(const World* self);

void World_Generate(World* self, int seed);
void World_RenderEntities(World* self, SDL_Renderer* renderer);
void World_UpdateEntities(World* self);