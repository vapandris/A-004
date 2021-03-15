#pragma once

#include "GameEntity.h"

#include "Base/CoreData.h"

typedef GameEntity Entities_Player;

Entities_Player* Entities_Player_Create(double x, double y);

void Entities_Player_MoveLeft(Entities_Player* self, double distance);
void Entities_Player_MoveRight(Entities_Player* self, double distance);
void Entities_Player_MoveUp(Entities_Player* self, double distance);
void Entities_Player_MoveDown(Entities_Player* self, double distance);