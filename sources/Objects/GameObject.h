#pragma once

#include "Graphics/GraphicsComponent.h"
#include "Behaviour/BehaviourComponent.h"
#include "Utils/CoreData.h"

typedef struct gameObject Objects_GameObject;
Objects_GameObject* Objects_GameObject_Create(
                        CoreData data,
                        Graphics_GraphicsComponent* graphics,
                        Behaviour_BehaviourComponent* behaviour);

void                Objects_GameObject_Destroy(const Objects_GameObject* self);


CoreData Objects_GameObject_GetCoreData(const Objects_GameObject* self);
void     Objects_GameObject_SetCoreData(Objects_GameObject* self, CoreData position);