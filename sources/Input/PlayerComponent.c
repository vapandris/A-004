#include "PlayerComponent.h"

// from std
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// from SDL2
#include <SDL2/SDL_scancode.h>

INPUT_COMPONENT_BASE

typedef enum Direction {
    NONE    = 0x000000,
    LEFT    = 0x000001,
    RIGHT   = 0x000002,
    UP      = 0x000004,
    DOWN    = 0x000008
} Direction;


typedef struct ComponentData {
    Direction direction;
    double momentum;
    Camera* camera;
} ComponentData;

static ComponentData* GetComponentData(const Input_PlayerComponent* self);
static void CalculateComponentData(Input_PlayerComponent* self, const UInt8* keyboardState);

void Input_PlayerComponent_Destroy_override(const Input_PlayerComponent* self)
{
    free((Input_PlayerComponent*)self);
}


void Input_PlayerComponent_HandleInput_override(Input_PlayerComponent* self, CoreData* coreData, const UInt8* keyboardState)
{
    ComponentData* componentData = GetComponentData(self);
    CalculateComponentData(self, keyboardState);
    
    Direction direction = componentData->direction;
    Camera* camera = componentData->camera;
    
    const double travelDistance = 2 * componentData->momentum;
    const double diagonalDistance = sqrt(travelDistance);
    if((direction & LEFT) == LEFT && (direction & UP) == UP) {
        coreData->x -= diagonalDistance;
        coreData->y += diagonalDistance;

        camera->x -= diagonalDistance;
        camera->y += diagonalDistance;
    } else if((direction & LEFT) == LEFT && (direction & DOWN) == DOWN) {
        coreData->x -= diagonalDistance;
        coreData->y -= diagonalDistance;
        
        camera->x -= diagonalDistance;
        camera->y -= diagonalDistance;
    } else if((direction & RIGHT) == RIGHT && (direction & UP) == UP) {
        coreData->x += diagonalDistance;
        coreData->y += diagonalDistance;

        camera->x += diagonalDistance;
        camera->y += diagonalDistance;
    } else if((direction & RIGHT) == RIGHT && (direction & DOWN) == DOWN) {
        coreData->x += diagonalDistance;
        coreData->y -= diagonalDistance;

        camera->x += diagonalDistance;
        camera->y -= diagonalDistance;
    } else if(direction == LEFT) {
        coreData->x -= travelDistance;

        camera->x -= travelDistance;
    } else if(direction == RIGHT) {
        coreData->x += travelDistance;

        camera->x += travelDistance;
    } else if(direction == UP) {
        coreData->y += travelDistance;

        camera->y += travelDistance;
    } else if(direction == DOWN) {
        coreData->y -= travelDistance;

        camera->y -= travelDistance;
    }
}


static Input_InputComponentType type = {
    .typeSize = sizeof(ComponentData),
    .handleInput = &Input_PlayerComponent_HandleInput_override,
    .destroy = &Input_PlayerComponent_Destroy_override
};


Input_PlayerComponent* Input_PlayerComponent_Create()
{
    Input_PlayerComponent* result = Input_InputComponent_Create(&type);

    ComponentData* componentData = GetComponentData(result);
    componentData->direction = NONE;
    componentData->momentum = 1.0;

    return result;
}


void Input_PlayerComponent_Destroy(const Input_PlayerComponent* self)
{
    Input_InputComponent_Destroy(self);
}


void Input_PlayerComponent_SetCamera(Input_PlayerComponent* self, Camera* camera)
{
    GetComponentData(self)->camera = camera;
}


// static function:

static ComponentData* GetComponentData(const Input_PlayerComponent* self)
{
    return (ComponentData*)self->bufferStart;
}


static void CalculateComponentData(Input_PlayerComponent* self, const UInt8* keyboardState)
{
    ComponentData* componentData = GetComponentData(self);

    Direction direction = NONE;

    if(keyboardState[SDL_SCANCODE_LEFT] != 0 || keyboardState[SDL_SCANCODE_A] != 0) {
        direction |= LEFT;
    }
    if(keyboardState[SDL_SCANCODE_RIGHT] != 0 || keyboardState[SDL_SCANCODE_D] != 0) {
        direction |= RIGHT;
    }
    if(keyboardState[SDL_SCANCODE_UP] != 0 || keyboardState[SDL_SCANCODE_W] != 0) {
        direction |= UP;
    }
    if(keyboardState[SDL_SCANCODE_DOWN] != 0 || keyboardState[SDL_SCANCODE_S] != 0) {
        direction |= DOWN;
    }

    if(((direction & LEFT) == LEFT && (direction & RIGHT) == RIGHT) || ((direction & UP) == UP && (direction & DOWN) == DOWN)) {
        direction = NONE;
    }

    if(keyboardState[SDL_SCANCODE_LSHIFT] != 0) {
        componentData->momentum = 0.50;
    } else if(keyboardState[SDL_SCANCODE_LCTRL] != 0) {
        componentData->momentum = 2.50;
    } else {
        componentData->momentum = 1;
    }

    componentData->direction = direction;
}