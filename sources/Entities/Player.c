#include "Player.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"
#include "Input/PlayerComponent.h"

Entities_Player* Entities_Player_Create(double x, double y)
{
    Entities_Player* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = 24, .height = 48},
        Graphics_ComponentManager_GetPlayerComponent(),
        Input_PlayerComponent_Create()
    );
    return result;
}