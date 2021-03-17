#pragma once

#include "InputComponent.h"

// from Camera
#include "Camera/Camera.h"

typedef Input_InputComponent Input_PlayerComponent;

Input_PlayerComponent* Input_PlayerComponent_Create();
void Input_PlayerComponent_Destroy(const Input_PlayerComponent* self);

void Input_PlayerComponent_SetCamera(Input_PlayerComponent* self, Camera* camera);