#include "Player.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"
#include "Input/PlayerComponent.h"

GAMEENTITY_BASE

Entities_Player* Entities_Player_Create(double x, double y)
{
    Entities_Player* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = 24, .height = 48},
        Graphics_ComponentManager_GetPlayerComponent(),
        Input_PlayerComponent_Create()
    );
    return result;
}


void Entities_Player_SetCamera(Entities_Player* self, Camera* camera)
{
    Input_PlayerComponent_SetCamera(self->inputComponent, camera);
}