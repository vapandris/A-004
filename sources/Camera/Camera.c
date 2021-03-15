#include "Camera.h"

// from std
#include <math.h>

CoreData Camera_CalculateCoreDataFromWindowData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const WindowData* windowData)
{
    CoreData result;

    double xDelta = windowWidth / camera->width;
    double yDelta = windowHeight / camera->height;

    result.x = (windowData->x / xDelta) + camera->x;
    result.y = camera->y - (windowData->y / yDelta);
    result.width = windowData->width / xDelta;
    result.height = windowData->height / yDelta;

    return result;
}


WindowData Camera_CalculateWindowDataFromCoreData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const CoreData* coreData)
{
    WindowData result;

    double xDelta = windowWidth / camera->width;
    double yDelta = windowHeight / camera->height;

    result.x = ceil((coreData->x - camera->x) * xDelta);
    result.y = ceil((coreData->y - camera->y) * -yDelta);
    result.width = ceil(coreData->width * xDelta);
    result.height = ceil(coreData->height * yDelta);

    return result;
}