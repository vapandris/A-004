#include "Camera.h"

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

    result.x = (coreData->x - camera->x) * xDelta;
    result.y = (coreData->y - camera->y) * -yDelta;
    result.width = coreData->width * xDelta;
    result.height = coreData->height * yDelta;

    return result;
}