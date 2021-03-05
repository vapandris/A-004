#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest>
#include <iostream>

#include "Utils/CoreData.h"

TEST_CASE("testing CoreData_Set function") {
    CoreData coreData;
    CoreData_Set(&coreData, {.x = 10, .y = 15, .width = 32, .height = 64});
    
    CHECK(coreData.x == 10);
    CHECK(coreData.y == 15);
    CHECK(coreData.width == 32);
    CHECK(coreData.height == 64);
}