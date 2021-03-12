#include "YellowFlowers.h"

// from Graphics
#include "Graphics/YellowFlowersComponent.h"

Entities_YellowFlowers* Entities_YellowFlowers_Create(CoreData coreData)
{
    Entities_YellowFlowers* result = Entities_GameEntity_Create(
        coreData,
        Graphics_YellowFlowersComponent_Create()
    );
    return result;
}