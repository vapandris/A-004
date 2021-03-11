#include "World.h"

// from std
#include <stdlib.h>

// from Entities
#include "Entities/GameEntity.h"
#include "Entities/Player.h"

// from Base
#include "Base/CoreData.h"

struct World {
    CoreData coreData;
    Camera* camera;
    Entities_Player* player;
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
    self->coreData = (CoreData){.x = -100, .y = 100, .width = 1000, .height = 1000};
}


void World_RenderEntities(World* self, Camera_RenderingData* renderingData)
{
    Entities_GameEntity_Draw(self->player, renderingData);
}


void World_UpdateEntities(World* self)
{
    // TODO
}