#include "World.h"

// from std
#include <stdlib.h>

// from Entities
#include "Entities/GameEntity.h"
#include "Entities/Player.h"
#include "Entities/LightGrass.h"
#include "Entities/PineTree.h"
#include "Entities/YellowFlowers.h"

// from Base
#include "Base/CoreData.h"


struct World {
    CoreData coreData;
    Camera* camera;
    Entities_Player* player;
    int groundSize;
    GameEntity*** ground;
    Entities_PineTree* aTree;
    Entities_YellowFlowers* aFlower;

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
    Entities_GameEntity_Destroy(self->aTree);
    Entities_GameEntity_Destroy(self->aFlower);
    free(self->ground);
    free((World*)self);
}


void World_Generate(World* self, int seed)
{
    const double tileSize = 32.0;
    const double worldSize = 640.0;
    const double worldX = -100;
    const double worldY = 100;
    self->coreData = (CoreData){.x = worldX, .y = worldY, .width = worldSize, .height = worldSize};

    self->groundSize = worldSize / tileSize;
    self->ground = malloc(sizeof *self->ground * self->groundSize);
    for(int i = 0; i < self->groundSize; ++i)
        self->ground[i] = malloc(sizeof *self->ground[i] * self->groundSize);

    for(int i = 0; i < self->groundSize; ++i) {
        for(int j = 0; j < self->groundSize; ++j) {
            double x = worldX + (j * tileSize);
            double y = worldY - (i * tileSize);
            self->ground[i][j] = Entities_LightGrass_Create((CoreData){.x = x, .y = y, .width = tileSize, .height = tileSize});
        }
    }

    self->aTree = Entities_PineTree_Create((CoreData){.x = 20, .y=-20, .width = 34, .height = 51});
    self->aFlower = Entities_YellowFlowers_Create((CoreData){.x = 50, .y=-50, .width = 32, .height = 32});

    self->player = Entities_Player_Create((CoreData){.x = 0, .y = 0, .width = 24, .height = 48});
    self->camera->x = -100;
    self->camera->y = 100;
}


void World_RenderEntities(World* self, Camera_RenderingData* renderingData)
{
    //Entities_GameEntity_Draw(self->singleGrass, renderingData);
    for(int i = 0; i < self->groundSize; ++i) {
        for(int j = 0; j <self->groundSize; ++j) {
            Entities_GameEntity_Draw(self->ground[i][j], renderingData);
        }
    }
    Entities_GameEntity_Draw(self->aFlower, renderingData);
    Entities_GameEntity_Draw(self->player, renderingData);
    Entities_GameEntity_Draw(self->aTree, renderingData);
}


void World_UpdateEntities(World* self)
{
    // TODO
}


void World_MovePlayerTmp(World* self, double distance, char dir)
{
    if(dir == 0) {
        Entities_Player_MoveLeft(self->player, distance);
    } else if(dir == 1) {
        Entities_Player_MoveRight(self->player, distance);
    } else if(dir == 2) {
        Entities_Player_MoveUp(self->player, distance);
    } else if(dir == 3) {
        Entities_Player_MoveDown(self->player, distance);
    }
}