#pragma once

#include "GameEntity.h"

#include "Base/CoreData.h"

double Entities_Tiles_GetSize();

// --------------------------------------- //
typedef GameEntity Entities_LightGrass;

Entities_LightGrass* Entities_LightGrass_Create(double x, double y);


// --------------------------------------- //
typedef GameEntity Entities_Void;

Entities_Void* Entities_Void_Create(double x, double y);