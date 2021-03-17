#pragma once

// from Camera
#include "Camera/Camera.h"

// from SDL2
#include "Camera/RenderingData.h"

typedef struct World World;

World* World_Create(Camera* camera);
void   World_Destroy(const World* self);

void World_Generate(World* self, int seed);
void World_RenderEntities(World* self, Camera_RenderingData* renderingData);
void World_UpdateEntities(World* self);
void World_HandleInput(World* self, const UInt8* keyboardState);
