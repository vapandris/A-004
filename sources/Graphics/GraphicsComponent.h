#pragma once

#include <stddef.h>

#include "Utils/CoreData.h"

typedef struct graphicsComponent Graphics_GraphicsComponent;
typedef struct graphicsComponentType Graphics_GraphicsComponentType;

/*/
 * We want the content of the structs to be visible for every graphics-component.
 * But we don't want it to be wisible for the outside.
/*/
#define GRAPHICS_COMPONENT_BASE                                         \
                                                                        \
struct graphicsComponent                                                \
{                                                                       \
    Graphics_GraphicsComponentType* type;                               \
    char bufferStart[];                                                 \
};                                                                      \
                                                                        \
struct graphicsComponentType                                            \
{                                                                       \
    size_t typeSize;                                                    \
    void (*update)(CoreData*);                                          \
    void (*destroy)(const Graphics_GraphicsComponent*);                 \
};                                                                      \


Graphics_GraphicsComponent*     Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type);
void                            Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self);

void Graphics_GraphicsComponent_Update(Graphics_GraphicsComponent* self, CoreData* data);