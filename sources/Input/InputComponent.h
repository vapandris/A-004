#pragma once

// from std
#include <stddef.h>

// from Base
#include "Base/CoreData.h"
#include "Base/Types.h"


typedef struct Input_InputComponent Input_InputComponent;

#define INPUT_COMPONENT_BASE                                                            \
typedef struct Input_InputComponentType Input_InputComponentType;                       \
                                                                                        \
struct Input_InputComponent                                                             \
{                                                                                       \
    Input_InputComponentType* type;                                                     \
    char bufferStart[];                                                                 \
};                                                                                      \
                                                                                        \
struct Input_InputComponentType                                                         \
{                                                                                       \
    size_t typeSize;                                                                    \
    void (*handleInput)(Input_InputComponent*, CoreData*, const UInt8*);                \
    void (*destroy)(const Input_InputComponent*);                                       \
};                                                                                      \
                                                                                        \
Input_InputComponent* Input_InputComponent_Create(                                      \
    Input_InputComponentType* type                                                      \
);                                                                                      \

void Input_InputComponent_Destroy(const Input_InputComponent* self);
void Input_InputComponent_HandleInput(Input_InputComponent* self, CoreData* coreData, const UInt8* keyboardState);