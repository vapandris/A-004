#pragma once

#include <stddef.h>

#include "Utils/CoreData.h"

typedef struct graphicsComponent Graphics_GraphicsComponent;

/*/
 * We want the content of the structs to be visible for every graphics-component.
 * But we don't want it to be wisible for the outside.
 * Also we don't want to be able to create & destroy them just anywhere.
/*/
#define GRAPHICS_COMPONENT_BASE                                                                      \
typedef struct graphicsComponentType Graphics_GraphicsComponentType;                                 \
                                                                                                     \
struct graphicsComponent                                                                             \
{                                                                                                    \
    Graphics_GraphicsComponentType* type;                                                            \
    char bufferStart[];                                                                              \
};                                                                                                   \
                                                                                                     \
struct graphicsComponentType                                                                         \
{                                                                                                    \
    size_t typeSize;                                                                                 \
    void (*update)(CoreData*);                                                                       \
    void (*destroy)(const Graphics_GraphicsComponent*);                                              \
};                                                                                                   \
                                                                                                     \
Graphics_GraphicsComponent* Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type); \
void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self);                     \


void Graphics_GraphicsComponent_Update(Graphics_GraphicsComponent* self, CoreData* data);