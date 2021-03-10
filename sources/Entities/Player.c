#include "Player.h"

// from Graphics
#include "Graphics/PlayerComponent.h"

Entities_Player* Entities_Player_Create(CoreData coreData)
{
    Entities_Player* result = Entities_GameEntity_Create(
        coreData,
        Graphics_PlayerComponent_Create()
    );
    return result;
}