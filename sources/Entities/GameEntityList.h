#pragma once

#include "GameEntity.h"

// from Base
#include "Base/Types.h"

// from std
#include <stdbool.h>


typedef struct GameEntityList GameEntityList;

GameEntityList* Entities_GameEntityList_Create(UInt16 capacity);
void            Entities_GameEntityList_Destroy(const GameEntityList* self);

bool        Entities_GameEntityList_Add(GameEntityList* self, GameEntity* newElem);
void        Entities_GameEntityList_Remove(GameEntityList* self, UInt16 index);

UInt16      Entities_GameEntityList_GetSize(const GameEntityList* self);
UInt16      Entities_GameEntityList_GetCapacity(const GameEntityList* self);
GameEntity* Entities_GameEntityList_GetByIndex(const GameEntityList* self, UInt16 index);