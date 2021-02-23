#include "GraphicsComponent.h"

#include <stdlib.h>


GRAPHICS_COMPONENT_BASE

Graphics_GraphicsComponent*     Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type)
{
    Graphics_GraphicsComponent* result;
    size_t size = sizeof *result + type->typeSize;
    result = malloc(size);
    result->type = type;
    return type;
}


void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self)
{
    if(self != NULL) {
        self->type->destroy((Graphics_GraphicsComponent*)self);
    }
}


void Graphics_GraphicsComponent_Update(Graphics_GraphicsComponent* self)
{
    self->type->update(self);
}