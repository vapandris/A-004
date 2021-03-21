#include "GameEntityList.h"

// from std
#include <stdlib.h>

struct GameEntityList
{
    GameEntity** array;
    UInt16 capacity;
    UInt32 size;
};


GameEntityList* Entities_GameEntityList_Create(UInt16 capacity)
{
    GameEntityList* result = malloc(sizeof *result);
    result->array = malloc(sizeof *result->array * capacity);
    result->capacity = capacity;
    result->size = 0;

    return result;
}


void Entities_GameEntityList_Destroy(const GameEntityList* self)
{
    for(Uint16 i = 0; i < self->size; ++i)
        Entities_GameEntity_Destroy(self->array[i]);

    free(self->array);
    free((GameEntityList*)self);
}


bool Entities_GameEntityList_Add(GameEntityList* self, GameEntity* newElem)
{
    if(self->capacity == self->size) {
        UInt16 capacity = self->capacity * 2;
        GameEntity** array = realloc(self->array, sizeof *array * capacity);

        if(array == NULL)
            return false;

        self->array = array;
        self->capacity = capacity;
    }

    self->array[self->size] = newElem;
    self->size++;

    return true;
}


void Entities_GameEntityList_Remove(GameEntityList* self, UInt16 index)
{
    GameEntity* removedEntity = self->array[index];
    self->size--;
    self->array[index] = self->array[self->size];

    Entities_GameEntity_Destroy(removedEntity);
}


UInt16 Entities_GameEntityList_GetSize(const GameEntityList* self)
{
    return self->size;
}


UInt16 Entities_GameEntityList_GetCapacity(const GameEntityList* self)
{
    return self->capacity;
}


GameEntity* Entities_GameEntityList_GetByIndex(const GameEntityList* self, UInt16 index)
{
    return self->array[index];
}