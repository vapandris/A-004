#include "InputComponent.h"

// from std
#include <stdlib.h>

INPUT_COMPONENT_BASE

Input_InputComponent* Input_InputComponent_Create(
    Input_InputComponentType* type
)
{
    Input_InputComponent* result;
    size_t size = sizeof *result + type->typeSize;
    result = malloc(size);
    result->type = type;

    return result;
}

void Input_InputComponent_Destroy(const Input_InputComponent* self)
{
    self->type->destroy(self);
}


void Input_InputComponent_HandleInput(Input_InputComponent* self, CoreData* coreData, const UInt8* keyboardState)
{
    self->type->handleInput(self, coreData, keyboardState);
}