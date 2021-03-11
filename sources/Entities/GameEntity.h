#pragma once

// from Graphics
#include "Graphics/GraphicsComponent.h"

// from Base
#include "Base/CoreData.h"

typedef struct GameEntity GameEntity;
GameEntity* Entities_GameEntity_Create(
                        CoreData coreData,
                        Graphics_GraphicsComponent* graphics
);

void                Entities_GameEntity_Destroy(const GameEntity* self);


CoreData Entities_GameEntity_GetCoreData(const GameEntity* self);
void     Entities_GameEntity_SetCoreData(GameEntity* self, CoreData coreData);

void Entities_GameEntity_Draw(const GameEntity* self, Camera_RenderingData* renderingData);