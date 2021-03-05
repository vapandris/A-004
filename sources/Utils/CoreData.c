#include "CoreData.h"

void CoreData_Set(CoreData* coreData, const CoreData source)
{
    coreData->x = source.x;
    coreData->y = source.y;
    coreData->width = source.width;
    coreData->height = source.height;
}