#include "GameEntity.h"

// from std
#include <stdlib.h>

// from SDL2
#include <SDL2/SDL_render.h>

struct GameEntity
{
    CoreData coreData;
    Graphics_GraphicsComponent* graphicsComponent;
};


GameEntity* Entities_GameEntity_Create(
                        CoreData coreData,
                        Graphics_GraphicsComponent* graphicsComponent
)
{
    GameEntity* result = malloc(sizeof *result);
    CoreData_Set(&result->coreData, coreData);

    result->graphicsComponent = graphicsComponent;
    return result;
}


void Entities_GameEntity_Destroy(const GameEntity* self)
{
    Graphics_GraphicsComponent_Destroy(self->graphicsComponent);
    free((GameEntity*)self);
}


CoreData Entities_GameEntity_GetCoreData(const GameEntity* self)
{
    return self->coreData;
}


void Entities_GameEntity_SetCoreData(GameEntity* self, CoreData coreData)
{
    CoreData_Set(&self->coreData, coreData);
}


void Entities_GameEntity_Draw(const GameEntity* self, Camera_RenderingData* renderingData)
{
    Graphics_GraphicsComponent_Draw(self->graphicsComponent, &self->coreData, renderingData);
}