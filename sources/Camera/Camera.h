#pragma once

// from Base
#include "Base/CoreData.h"
#include "Base/Types.h"

// from SDL2
#include <SDL2/SDL_rect.h>

typedef CoreData Camera;

CoreData  Camera_CalculateCoreFromDataRect(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const SDL_Rect* rect);
SDL_Rect  Camera_CalculateRectFromCoreData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const CoreData* coreData);