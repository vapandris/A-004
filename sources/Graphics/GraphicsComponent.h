#pragma once

// from std
#include <stddef.h>

// from SDL2
#include "Camera/RenderingData.h"

// from Base
#include "Base/CoreData.h"
#include <SDL2/SDL_rect.h>

typedef struct Graphics_GraphicsComponent Graphics_GraphicsComponent;

/*/
 * We want the content of the structs to be visible for every graphics-component.
 * But we don't want it to be wisible for the outside.
 * Also we don't want to be able to create & destroy them just anywhere.
/*/

#define GRAPHICS_COMPONENT_BASE                                                         \
typedef struct Graphics_GraphicsComponentType Graphics_GraphicsComponentType;           \
                                                                                        \
struct Graphics_GraphicsComponent                                                       \
{                                                                                       \
    Graphics_GraphicsComponentType* type;                                               \
    SDL_Renderer* renderer;                                                             \
    char bufferStart[];                                                                 \
};                                                                                      \
                                                                                        \
struct Graphics_GraphicsComponentType                                                   \
{                                                                                       \
    size_t typeSize;                                                                    \
    void (*draw)(const Graphics_GraphicsComponent*, SDL_Rect, Camera_RenderingData*);   \
    void (*destroy)(const Graphics_GraphicsComponent*);                                 \
};                                                                                      \
                                                                                        \
Graphics_GraphicsComponent* Graphics_GraphicsComponent_Create(                          \
    Graphics_GraphicsComponentType* type,                                               \
    SDL_Renderer* renderer                                                              \
);                                                                                      \


void Graphics_GraphicsComponent_Destroy(const Graphics_GraphicsComponent* self);
void Graphics_GraphicsComponent_Draw(const Graphics_GraphicsComponent* self, const CoreData* coreData, Camera_RenderingData* renderingData);