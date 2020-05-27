#pragma once
#include <iostream>
#include <string>
#include "Soldier.hpp"

using namespace std;

class FootCommander : public FootSoldier{
	
	public:
        FootCommander(int player){
            Soldier::Player = player;
            Soldier::Maximum_Health = 150;
            Soldier::HP = 150;
            Soldier::DP = 20;
            Soldier::instance = "FootCommander";
        }
        
        virtual void abillity(){}
};