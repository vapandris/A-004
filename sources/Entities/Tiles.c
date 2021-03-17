#include "Tiles.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"

static const double tileSize = 32.0;

double Entities_Tiles_GetSize()
{
    return tileSize;
}

Entities_LightGrass* Entities_LightGrass_Create(double x, double y)
{
    return Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = tileSize, .height = tileSize},
        Graphics_ComponentManager_GetLightGrassComponent()
    );
}


Entities_Void* Entities_Void_Create(double x, double y)
{
    return Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = tileSize, .height = tileSize},
        Graphics_ComponentManager_VoidComponent()
    );
}