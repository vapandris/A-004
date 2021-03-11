#include "World.h"

// from std
#include <stdlib.h>

// from Entities
#include "Entities/GameEntity.h"
#include "Entities/Player.h"
#include "Entities/LightGrass.h"

// from Base
#include "Base/CoreData.h"

struct World {
    CoreData coreData;
    Camera* camera;
    Entities_Player* player;
    Entities_LightGrass* singleGrass;
};

World* World_Create(Camera* camera)
{
    World* result = malloc(sizeof *result);
    result->camera = camera;
    return result;
}


void   World_Destroy(const World* self)
{
    Entities_GameEntity_Destroy(self->player);
    free((World*)self);
}

void World_Generate(World* self, int seed)
{
    self->player = Entities_Player_Create((CoreData){.x = 0, .y = 0, .width = 24, .height = 48});
    self->singleGrass = Entities_LightGrass_Create((CoreData){.x = -100, .y = 10, .width = 1600, .height = 1600}); // lol
    self->coreData = (CoreData){.x = -100, .y = 100, .width = 1000, .height = 1000};
    self->camera->x = -50;
    self->camera->y = 50;
}


void World_RenderEntities(World* self, Camera_RenderingData* renderingData)
{
    Entities_GameEntity_Draw(self->singleGrass, renderingData);
    Entities_GameEntity_Draw(self->player, renderingData);
}


void World_UpdateEntities(World* self)
{
    // TODO
}