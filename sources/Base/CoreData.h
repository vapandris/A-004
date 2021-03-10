#pragma once

typedef struct CoreData
{
    double x, y;
    double width, height;
} CoreData;

void    CoreData_Set (CoreData* coreData, const CoreData source);