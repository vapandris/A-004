#include "GraphicsComponent.h"

#include <stdlib.h>


GRAPHICS_COMPONENT_BASE

Graphics_GraphicsComponent* Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type)
{
    Graphics_GraphicsComponent* result;
    size_t size = sizeof *result + type->typeSize;
    result = malloc(size);
    result->type = type;
    return result;
}


void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self)
{
    if(self != NULL) {
        self->type->destroy((Graphics_GraphicsComponent*)self);
    }
}


void Graphics_GraphicsComponent_Draw(Graphics_GraphicsComponent* self, const CoreData* data, Camera_RenderingData* renderingData)
{
    self->type->draw(self, data, renderingData);
}