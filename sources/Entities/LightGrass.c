#include "LightGrass.h"

// from Graphics
#include "Graphics/LightGrassComponent.h"

Entities_LightGrass* Entities_LightGrass_Create(CoreData coreData)
{
    Entities_LightGrass* result = Entities_GameEntity_Create(
        coreData,
        Graphics_LightGrassComponent_Create()
    );
    return result;
}