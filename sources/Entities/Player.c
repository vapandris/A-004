#include "Player.h"

// from Graphics
#include "Graphics/GraphicsComponentManager.h"

Entities_Player* Entities_Player_Create(double x, double y)
{
    Entities_Player* result = Entities_GameEntity_Create(
        (CoreData){.x = x, .y = y, .width = 24, .height = 48},
        Graphics_ComponentManager_GetPlayerComponent()
    );
    return result;
}


void Entities_Player_MoveLeft(Entities_Player* self, double distance)
{
    CoreData coreData = Entities_GameEntity_GetCoreData(self);
    Entities_GameEntity_SetCoreData(self, (CoreData){.x = coreData.x - distance, .y = coreData.y, .width = coreData.width, .height = coreData.height});
}


void Entities_Player_MoveRight(Entities_Player* self, double distance)
{
    CoreData coreData = Entities_GameEntity_GetCoreData(self);
    Entities_GameEntity_SetCoreData(self, (CoreData){.x = coreData.x + distance, .y = coreData.y, .width = coreData.width, .height = coreData.height});
}


void Entities_Player_MoveUp(Entities_Player* self, double distance)
{
    CoreData coreData = Entities_GameEntity_GetCoreData(self);
    Entities_GameEntity_SetCoreData(self, (CoreData){.x = coreData.x, .y = coreData.y + distance, .width = coreData.width, .height = coreData.height});
}


void Entities_Player_MoveDown(Entities_Player* self, double distance)
{
    CoreData coreData = Entities_GameEntity_GetCoreData(self);
    Entities_GameEntity_SetCoreData(self, (CoreData){.x = coreData.x, .y = coreData.y - distance, .width = coreData.width, .height = coreData.height});
}