#include "Tiles.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"

Entities_LightGrass* Entities_LightGrass_Create(double x, double y)
{
    double tileSize = 32.0;
    Entities_LightGrass* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = tileSize, .height = tileSize},
        Graphics_ComponentManager_GetLightGrassComponent()
    );
    return result;
}