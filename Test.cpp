#include "doctest.h"
#include "DemoGame.hpp"  
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <iostream>
#include <string>


using namespace WarGame;
using namespace std;

TEST_CASE("true"){
    for (int i = 0; i < 100; i++){
        CHECK(true);
    }
}



