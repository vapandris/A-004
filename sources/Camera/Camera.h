#pragma once

// from Base
#include "Base/CoreData.h"
#include "Base/WindowData.h"
#include "Base/Types.h"

typedef CoreData Camera;

CoreData    Camera_CalculateCoreDataFromWindowData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const WindowData* windowData);
WindowData  Camera_CalculateWindowDataFromCoreData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const CoreData* coreData);