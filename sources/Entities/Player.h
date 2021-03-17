#pragma once

#include "GameEntity.h"

#include "Base/CoreData.h"

typedef GameEntity Entities_Player;

Entities_Player* Entities_Player_Create(double x, double y);

void Entities_Player_SetCamera(Entities_Player* self, Camera* camera);