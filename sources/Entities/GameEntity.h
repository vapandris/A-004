#pragma once

// from Graphics
#include "Graphics/GraphicsComponent.h"
#include "Input/InputComponent.h"

// from Base
#include "Base/CoreData.h"

typedef struct GameEntity GameEntity;

#define GAMEENTITY_BASE                                         \
struct GameEntity                                               \
{                                                               \
    CoreData coreData;                                          \
    const Graphics_GraphicsComponent* graphicsComponent;        \
    Input_InputComponent* inputComponent;                       \
};                                                              \

GameEntity* Entities_GameEntity_Create(
                        CoreData coreData,
                        const Graphics_GraphicsComponent* graphics,
                        Input_InputComponent* input
);

void                Entities_GameEntity_Destroy(const GameEntity* self);


CoreData Entities_GameEntity_GetCoreData(const GameEntity* self);
void     Entities_GameEntity_SetCoreData(GameEntity* self, CoreData coreData);

void Entities_GameEntity_Draw(const GameEntity* self, Camera_RenderingData* renderingData);
void Entities_GameEntity_HandleInput(GameEntity* self, const UInt8* keyboardState);