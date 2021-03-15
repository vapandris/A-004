#include "Camera.h"

// from std
#include <math.h>

CoreData  Camera_CalculateCoreFromDataRect(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const SDL_Rect* rect)
{
    CoreData result;

    double xDelta = windowWidth / camera->width;
    double yDelta = windowHeight / camera->height;

    result.x = (rect->x / xDelta) + camera->x;
    result.y = camera->y - (rect->y / yDelta);
    result.width = rect->w / xDelta;
    result.height = rect->h / yDelta;

    return result;
}


SDL_Rect  Camera_CalculateRectFromCoreData(const Camera* camera, UInt16 windowWidth, UInt16 windowHeight, const CoreData* coreData)
{
    SDL_Rect result;

    double xDelta = windowWidth / camera->width;
    double yDelta = windowHeight / camera->height;

    result.x = ceil((coreData->x - camera->x) * xDelta);
    result.y = ceil((coreData->y - camera->y) * -yDelta);
    result.w = ceil(coreData->width * xDelta);
    result.h = ceil(coreData->height * yDelta);

    return result;
}