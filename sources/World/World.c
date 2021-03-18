#include "World.h"

// from std
#include <stdlib.h>
#include <math.h>

// from Entities
#include "Entities/GameEntity.h"
#include "Entities/Player.h"
#include "Entities/Tiles.h"
#include "Entities/Vegetations.h"

// from Base
#include "Base/CoreData.h"


static double LinearGenerator(double x, double multiplyer, double origoX);

struct World {
    CoreData coreData;
    Camera* camera;
    Entities_Player* player;
    int groundSize;
    GameEntity*** ground;
    //GameEntity**  vegetations;
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
    for(int i = 0; i < self->groundSize; ++i) {
        for(int j = 0; j < self->groundSize; ++j) {
            Entities_GameEntity_Destroy(self->ground[i][j]);
        }
        free(self->ground[i]);
    }
    free(self->ground);
    free((World*)self);
}


void World_Generate(World* self, int seed)
{
    const double tileSize = Entities_Tiles_GetSize();
    const double worldSize = 1920.0;
    const double worldX = -1000;
    const double worldY = 1000;
    self->coreData = (CoreData){.x = worldX, .y = worldY, .width = worldSize, .height = worldSize};
    const double worldOrigoX = worldSize / 2 + worldX; 

    self->groundSize = worldSize / tileSize;
    self->ground = malloc(sizeof *self->ground * self->groundSize);
    for(int i = 0; i < self->groundSize; ++i)
        self->ground[i] = malloc(sizeof *self->ground[i] * self->groundSize);

    for(int i = 0; i < self->groundSize; ++i) {
        for(int j = 0; j < self->groundSize; ++j) {
            double x = worldX + (j * tileSize);
            double y = worldY - (i * tileSize);

            if(abs(LinearGenerator(x, 0.5, worldOrigoX) - y) <= 150 || abs(LinearGenerator(-x, 0.5, worldOrigoX) - y) <= 150) {
                self->ground[i][j] = Entities_LightGrass_Create(x, y);
            } else {
                self->ground[i][j] = Entities_Void_Create(x, y);
            }
            
        }
    }

    self->player = Entities_Player_Create(0, 0);
    self->camera->x = Entities_GameEntity_GetCoreData(self->player).x - (self->camera->width / 2);
    self->camera->y = Entities_GameEntity_GetCoreData(self->player).y + (self->camera->height / 2);

    Entities_Player_SetCamera(self->player, self->camera);
}


void World_RenderEntities(World* self, Camera_RenderingData* renderingData)
{
    //Entities_GameEntity_Draw(self->singleGrass, renderingData);
    for(int i = 0; i < self->groundSize; ++i) {
        for(int j = 0; j <self->groundSize; ++j) {
            Entities_GameEntity_Draw(self->ground[i][j], renderingData);
        }
    }
    Entities_GameEntity_Draw(self->player, renderingData);
}


void World_UpdateEntities(World* self)
{
    // TODO
}


void World_HandleInput(World* self, const UInt8* keyboardState)
{
    Entities_GameEntity_HandleInput(self->player, keyboardState);
}


// static functions:
static double LinearGenerator(double x, double multiplyer, double origoX)
{
    return (multiplyer * x) - origoX;
}