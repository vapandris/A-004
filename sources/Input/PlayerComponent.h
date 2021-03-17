#pragma once

#include "InputComponent.h"

typedef Input_InputComponent Input_PlayerComponent;

Input_PlayerComponent* Input_PlayerComponent_Create();
void Input_PlayerComponent_Destroy(const Input_PlayerComponent* self);