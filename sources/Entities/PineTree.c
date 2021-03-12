#include "PineTree.h"

// from Graphics
#include "Graphics/PineTreeComponent.h"

Entities_PineTree* Entities_PineTree_Create(CoreData coreData)
{
    Entities_PineTree* result = Entities_GameEntity_Create(
        coreData,
        Graphics_PineTreeComponent_Create()
    );
    return result;
}