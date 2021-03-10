#pragma once

// from std
#include <stddef.h>

// from SDL2
#include <SDL2/SDL_render.h>

// from Base
#include "Base/CoreData.h"

typedef struct Graphics_GraphicsComponent Graphics_GraphicsComponent;

/*/
 * We want the content of the structs to be visible for every graphics-component.
 * But we don't want it to be wisible for the outside.
 * Also we don't want to be able to create & destroy them just anywhere.
/*/

#define GRAPHICS_COMPONENT_BASE                                                                         \
typedef struct Graphics_GraphicsComponentType Graphics_GraphicsComponentType;                           \
                                                                                                        \
struct Graphics_GraphicsComponent                                                                       \
{                                                                                                       \
    Graphics_GraphicsComponentType* type;                                                               \
    char bufferStart[];                                                                                 \
};                                                                                                      \
                                                                                                        \
struct Graphics_GraphicsComponentType                                                                   \
{                                                                                                       \
    size_t typeSize;                                                                                    \
    void (*draw)(const Graphics_GraphicsComponent*, const CoreData*, SDL_Renderer*);                    \
    void (*destroy)(const Graphics_GraphicsComponent*);                                                 \
};                                                                                                      \
                                                                                                        \
Graphics_GraphicsComponent* Graphics_GraphicsComponent_Create(Graphics_GraphicsComponentType* type);    \


void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self);
void Graphics_GraphicsComponent_Draw(Graphics_GraphicsComponent* self, const CoreData* data, SDL_Renderer* renderer);