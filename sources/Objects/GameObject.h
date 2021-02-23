#pragma once

#include "../Graphics/GraphicsComponent.h"
#include "../Behaviour/BehaviourComponent.h"
#include "../Utils/Position.h"


typedef struct gameObject Objects_GameObject;

Objects_GameObject* Objects_GameObject_Create(
                        Position position,
                        Graphics_GraphicsComponent* graphics,
                        Behaviour_BehaviourComponent* behaviour);

void                Objects_GameObject_Destroy(const Objects_GameObject* self);


Position Objects_GameObject_GetPosition(const Objects_GameObject* self);
void     Objects_GameObject_SetPosition(Objects_GameObject* self, Position position);