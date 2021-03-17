#include "Vegetations.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"


Entities_YellowFlowers* Entities_YellowFlowers_Create(double x, double y)
{
    double flowerSize = 32.0;
    Entities_YellowFlowers* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = flowerSize, .height = flowerSize},
        Graphics_ComponentManager_GetYellowFlowersComponent(),
        NULL
    );
    return result;
}


Entities_PineTree* Entities_PineTree_Create(double x, double y)
{
    Entities_PineTree* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = 34.0, .height = 51.0},
        Graphics_ComponentManager_GetPineTreeComponent(),
        NULL
    );
    return result;
}