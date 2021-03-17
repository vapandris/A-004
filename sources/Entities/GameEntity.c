#include "GameEntity.h"

// from std
#include <stdlib.h>

// from SDL2
#include <SDL2/SDL_render.h>

struct GameEntity
{
    CoreData coreData;
    const Graphics_GraphicsComponent* graphicsComponent;
    Input_InputComponent* inputComponent;
};


GameEntity* Entities_GameEntity_Create(
                        CoreData coreData,
                        const Graphics_GraphicsComponent* graphicsComponent,
                        Input_InputComponent* inputComponent
)
{
    GameEntity* result = malloc(sizeof *result);
    CoreData_Set(&result->coreData, coreData);

    result->graphicsComponent = graphicsComponent;
    result->inputComponent = inputComponent;
    return result;
}


void Entities_GameEntity_Destroy(const GameEntity* self)
{
    Input_InputComponent_Destroy(self->inputComponent);
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
    if(self->graphicsComponent != NULL)
        Graphics_GraphicsComponent_Draw(self->graphicsComponent, &self->coreData, renderingData);
}


void Entities_GameEntity_HandleInput(GameEntity* self, const UInt8* keyboardState)
{
    if(self->inputComponent != NULL)
        Input_InputComponent_HandleInput(self->inputComponent, &self->coreData, keyboardState);
}