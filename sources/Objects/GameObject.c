#include "GameObject.h"

#include <stdlib.h>

struct Objects_GameObject
{
    CoreData coreData;
    Graphics_GraphicsComponent* graphics;
    Behaviour_BehaviourComponent* behaviour;
};


Objects_GameObject* Objects_GameObject_Create(
                        CoreData coreData,
                        Graphics_GraphicsComponent* graphics,
                        Behaviour_BehaviourComponent* behaviour)
{
    Objects_GameObject* result = malloc(sizeof *result);
    CoreData_Set (&result->coreData, coreData);

    result->graphics = graphics;
    result->behaviour = behaviour;
    return result;
}

void Objects_GameObject_Destroy(const Objects_GameObject* self)
{
    Objects_GameObject* selfNotConst = (Objects_GameObject*)self;
    free(selfNotConst->graphics);
    free(selfNotConst->behaviour);
    free(selfNotConst);
}


CoreData Objects_GameObject_GetcoreData(const Objects_GameObject* self)
{
    return self->coreData;
}


void Objects_GameObject_SetCoreData(Objects_GameObject* self, CoreData coreData)
{
    CoreData_Set(&self->coreData, coreData);
}