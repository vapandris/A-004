#include "GraphicsComponent.h"

// from std
#include <stdlib.h>


// from Camera
#include "Camera/Camera.h"

GRAPHICS_COMPONENT_BASE

Graphics_GraphicsComponent* Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type, SDL_Renderer* renderer)
{
    Graphics_GraphicsComponent* result;
    size_t size = sizeof *result + type->typeSize;
    result = malloc(size);
    result->type = type;
    result->renderer = renderer;
    return result;
}


void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self)
{
    if(self != NULL) {
        self->type->destroy((Graphics_GraphicsComponent*)self);
    }
}


void Graphics_GraphicsComponent_Draw(const Graphics_GraphicsComponent* self, const CoreData* coreData, Camera_RenderingData* renderingData)
{
    SDL_Rect textureRect = Camera_CalculateRectFromCoreData(
        renderingData->camera,
        renderingData->windowWidth,
        renderingData->windowHeight,
        coreData
    );
    self->type->draw(self, textureRect, renderingData);
}