#include "GameObject.h"

#include <stdlib.h>

struct gameObject
{
    Position position;
    Graphics_GraphicsComponent* graphics;
    Behaviour_BehaviourComponent* behaviour;
};


Objects_GameObject* Objects_GameObject_Create(
                        Position position,
                        Graphics_GraphicsComponent* graphics,
                        Behaviour_BehaviourComponent* behaviour)
{
    Objects_GameObject* result = malloc(sizeof *result);
    result->position.x = position.x;
    result->position.y = position.y;
    result->position.width = position.width;
    result->position.height = position.height;

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


Position Objects_GameObject_GetPosition(const Objects_GameObject* self)
{
    return self->position;
}


void Objects_GameObject_SetPosition(Objects_GameObject* self, Position position)
{
    self->position.x = position.x;
    self->position.y = position.y;
    self->position.width = position.width;
    self->position.height = position.height;
}